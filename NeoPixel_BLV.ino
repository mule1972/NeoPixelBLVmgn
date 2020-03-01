#include <Adafruit_NeoPixel.h>

//#define DEBUGLEVEL1_ACTIVE
//#define DEBUGLEVEL2_ACTIVE

#define MaxHeaters 5
#define SerialTimeout 100
#define NeopixelRefreshSpeed 200

// Initialize global variables
int ShowHeater;
int StringPos;
int HeaterDelimiterPos;
int HeaterID;
int SetTempHeater;
int ActTempHeater;
bool NeoPixelStartupAnimation;
int NeoPixelsUsedForHeaters;
unsigned long NeoPixelTimerRefresh = millis();
String SerialMessage;
bool SerialMessageComplete;

int Heater_Scale[MaxHeaters];

bool NeoPixelHeater_Active[MaxHeaters];
String NeoPixelHeater_ShowHeaters[MaxHeaters];
int NeoPixelHeater_StartupAnimationType[MaxHeaters];
neoPixelType NeoPixelHeater_Type[MaxHeaters];
uint16_t NeoPixelHeater_LEDs[MaxHeaters];
uint8_t NeoPixelHeater_ArduinoPin[MaxHeaters];
int NeoPixelHeater_PixelOffset[MaxHeaters];
int NeoPixelHeater_TempOffset[MaxHeaters];
bool NeoPixelHeater_AnimationActive[MaxHeaters];
bool NeoPixelHeater_AnimationReverse[MaxHeaters];
uint8_t NeoPixelHeater_Brightness[MaxHeaters];
uint32_t NeoPixelHeater_ColorIdle[MaxHeaters];
uint32_t NeoPixelHeater_ColorHeatUp[MaxHeaters];
uint32_t NeoPixelHeater_ColorHeatUpDone[MaxHeaters];
uint32_t NeoPixelHeater_ColorCoolDown[MaxHeaters];
uint32_t NeoPixelHeater_ColorAnimation[MaxHeaters];

bool NeoPixelPrinterstatus_Active;
int NeoPixelPrinterstatus_StartupAnimationType;
neoPixelType NeoPixelPrinterstatus_Type;
uint16_t NeoPixelPrinterstatus_LEDs;
uint8_t NeoPixelPrinterstatus_ArduinoPin;
int NeoPixelPrinterstatus_PixelOffset;
bool NeoPixelPrinterstatus_AnimationActive;
bool NeoPixelPrinterstatus_AnimationReverse;
uint8_t NeoPixelPrinterstatus_Brightness;
uint32_t NeoPixelPrinterstatus_ColorIdle;
uint32_t NeoPixelPrinterstatus_ColorPrinting;
uint32_t NeoPixelPrinterstatus_ColorPrintingDone;
uint32_t NeoPixelPrinterstatus_ColorStopped;
uint32_t NeoPixelPrinterstatus_ColorConfiguring;
uint32_t NeoPixelPrinterstatus_ColorPaused;
uint32_t NeoPixelPrinterstatus_ColorBusy;
uint32_t NeoPixelPrinterstatus_ColorPausing;
uint32_t NeoPixelPrinterstatus_ColorResuming;
uint32_t NeoPixelPrinterstatus_ColorFlashing;
uint32_t NeoPixelPrinterstatus_ColorDefault;
uint32_t NeoPixelPrinterstatus_ColorAnimation;

struct NeoPixelAnimationMemory{
  public:
  int Position;
  int Position_Memory;
  int RangeBegin;
  int RangeEnd;
  int Running;
  int ShowHeater_Memory;
};
NeoPixelAnimationMemory NeoPixelAnimationMemory_Heater[MaxHeaters];
NeoPixelAnimationMemory NeoPixelAnimationMemory_Printerstatus;

Adafruit_NeoPixel NeoPixelHeater[MaxHeaters];
Adafruit_NeoPixel NeoPixelPrinterstatus;

class PanelDueMessage {
  public:
  char Status;
  float ActTempHeater[MaxHeaters];
  float ActiveTempHeater[MaxHeaters];
  float StandbyTempHeater[MaxHeaters];
  int HeaterStatus[MaxHeaters];
  float FractionPrinted;
  bool UpdatePending;
  int Tool;
};
PanelDueMessage Printer;
#if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL1_ACTIVE)
  PanelDueMessage DebugPrinter;
#endif

static int ConvertPosition2PixelIndex(int PixelCount, int PixelOffset, int Position, bool ReverseDirection) {
  int newposition;
  int newpixeloffset;
  if (ReverseDirection == false) {
    newpixeloffset = PixelOffset;
  }
  else{
    newpixeloffset = -PixelOffset;
  }
  if ((Position + newpixeloffset) > PixelCount) {
    newposition = (Position + newpixeloffset) - PixelCount;
  }
  else if ((Position + newpixeloffset) < 1) {
    newposition = PixelCount + (Position + newpixeloffset);
  }
  else {
    newposition = (Position + newpixeloffset);
  }  
  if (ReverseDirection == false) {
    return (PixelCount - newposition);
  }
  else {  
    return (newposition - 1);
  }  
}

static uint32_t  ConvertColor(uint8_t red, uint8_t green, uint8_t blue) {
  return ((uint32_t)red << 16) | ((uint32_t)green <<  8) | blue;
}

void AnalyzeSerialMessage() {
  Printer.UpdatePending = false;
  if (JsonParseRoot(SerialMessage,"status",0) != ""){
	  Printer.Status = JsonParseRoot(SerialMessage,"status",0).charAt(0);
	  Printer.UpdatePending = true;
	}
  for (int i = 0; i <= NeoPixelsUsedForHeaters; i++) {
    if (JsonParseRoot(SerialMessage,"heaters",(i+1)) != ""){
  	  Printer.ActTempHeater[i] = JsonParseRoot(SerialMessage,"heaters",(i+1)).toFloat();
  	  Printer.UpdatePending = true;
  	}
  } 
  for (int i = 0; i <= NeoPixelsUsedForHeaters; i++) {
    if (JsonParseRoot(SerialMessage,"active",(i+1)) != ""){
      Printer.ActiveTempHeater[i] = JsonParseRoot(SerialMessage,"active",(i+1)).toFloat();
      Printer.UpdatePending = true;
    }
  }  
  for (int i = 0; i <= NeoPixelsUsedForHeaters; i++) {
    if (JsonParseRoot(SerialMessage,"standby",(i+1)) != ""){
      Printer.StandbyTempHeater[i] = JsonParseRoot(SerialMessage,"standby",(i+1)).toFloat();
      Printer.UpdatePending = true;
    }
  }  
  // HeaterStatus 0= Off / 1= Standby / 2= Active / 3= Fault / 4= Tuning
  for (int i = 0; i <= NeoPixelsUsedForHeaters; i++) {
    if (JsonParseRoot(SerialMessage,"hstat",(i+1)) != ""){
      Printer.HeaterStatus[i] = JsonParseRoot(SerialMessage,"hstat",(i+1)).toInt();
      Printer.UpdatePending = true;
    }
  }  
  if (JsonParseRoot(SerialMessage,"fraction_printed",0) != ""){
	  Printer.FractionPrinted = JsonParseRoot(SerialMessage,"fraction_printed",0).toFloat();
	  Printer.UpdatePending = true;
	}
  if (JsonParseRoot(SerialMessage,"tool",0) != ""){
    Printer.Tool = JsonParseRoot(SerialMessage,"tool",0).toInt();
    Printer.UpdatePending = true;
  }
  #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL2_ACTIVE)
  	if (Printer.UpdatePending == true){
 		  Serial.println("StatusUpdate: Status= "+String(Printer.Status)+" / ActualTHb= "+Printer.ActTempHeater[0]+" / ActualTHe1= "+Printer.ActTempHeater[1]+" / ActualTHe2= "+Printer.ActTempHeater[2]+" / ActiveTHb= "+Printer.ActiveTempHeater[0]+" / ActiveTHe1= "+Printer.ActiveTempHeater[1]+" / ActiveTHe2= "+Printer.ActiveTempHeater[2]+" / StandbyTHb= "+Printer.StandbyTempHeater[0]+" / StandbyTHe1= "+Printer.StandbyTempHeater[1]+" / StandbyTHe2= "+Printer.StandbyTempHeater[2]+" / StatusHb= "+Printer.HeaterStatus[0]+" / StatusHe1= "+Printer.HeaterStatus[1]+" / StatusHe2= "+Printer.HeaterStatus[2]+" / PrintProgress= "+Printer.FractionPrinted);
  	}
  	else{
//  		  Serial.println("Error: JsonObjectValue");
    }
  #endif 
}


// Example-Json-Message: {"status":"I","heaters":[31.5,28.1],"active":[0.0,0.0],"standby":[0.0,0.0],"hstat":[0,0],"pos":[0.000,0.000,0.000],"machine":[0.000,0.000,0.000],"sfactor":100.00,"efactor":[100.00],"babystep":0.000,"Heater":-1,"probe":"0","fanPercent":[0.0,0.0,100.0,100.0,0.0,0.0,0.0,0.0,0.0,0.0],"fanRPM":0,"homed":[0,0,0],"msgBox.mode":-1,"geometry":"coreXY","axes":3,"totalAxes":3,"axisNames":"XYZ","volumes":2,"numHeaters":1,"myName":"BLV mgn Cube","firmwareName":"RepRapFirmware for Duet 2 WiFi/Ethernet"}
String JsonParseRoot(String JsonMessage, String JsonRootObject,int JsonObjectIndex){
  long PositionBegin = -1;
  long PositionEnd = -1;
  int JsonValueIndex = 0;
  String JsonValue = "";

  //Remove Quotes
  JsonMessage.replace("\"","");

  PositionBegin = JsonMessage.indexOf(JsonRootObject+":");
  //Object found?
  if (PositionBegin == -1){
    return "";
  }
  else{
    PositionBegin = (PositionBegin + JsonRootObject.length()) + 1;
    if (JsonMessage.charAt(PositionBegin) == '['){
        PositionEnd = JsonMessage.indexOf("]",PositionBegin);
        if (PositionEnd == -1){
          //StartBracket without StopBracket found
          return "";
        }
        else{
          JsonValue = JsonMessage.substring((PositionBegin + 1),PositionEnd);
          if (JsonObjectIndex == 0){
            PositionBegin = 0;
            if (JsonValue.indexOf(",",PositionBegin) == -1){
              return JsonValue;
            }
            else{
            //SingleValue expected, but MultiValue found 
              return "";
            }
          }
          else{
            PositionBegin = 0;
            if (JsonValue.indexOf(",",PositionBegin) == -1){
              //MultiValue expected, but Singlevalue found
              return "";
            }
            else{
              for (int JsonValueIndex = 1; JsonValueIndex < JsonObjectIndex; JsonValueIndex++){
                if (JsonValue.indexOf(",",PositionBegin) == -1){
                    //Fewer Values found than expected
                    return "";
                }
                else{
                  PositionBegin = JsonValue.indexOf(",",PositionBegin);
                  PositionBegin++;
                }
              }
              String test = JsonValue.substring(PositionBegin,PositionBegin + 1);
              if (JsonValue.indexOf(",",PositionBegin) != -1){
                PositionEnd = JsonValue.indexOf(",",PositionBegin);
              }
              else{
                PositionEnd = JsonValue.length();
              }
              JsonValue = JsonValue.substring(PositionBegin,PositionEnd);
              return JsonValue;
            }
          }
        }
      }
    else
    if (JsonObjectIndex != 0){
      //Multivalue expected but not found
      return "";
    }
    else{
      if (JsonMessage.indexOf(",",PositionBegin) != -1){
        PositionEnd = JsonMessage.indexOf(",",PositionBegin);
        JsonValue = JsonMessage.substring(PositionBegin,PositionEnd);
        return JsonValue;
      }
      else if (JsonMessage.indexOf("}",PositionBegin) != -1){
        PositionEnd = JsonMessage.indexOf("}",PositionBegin);
        JsonValue = JsonMessage.substring(PositionBegin,PositionEnd);
        return JsonValue;
      }
      else{
        //No EndPoint , or } for SingleValue found
        return "";          
      }
    }
  }
}

void GetSerialMessage(){
  unsigned long timer = millis();
  bool BeginMessage=false;
  SerialMessageComplete=false;
  SerialMessage=""; 
  while(SerialMessageComplete==false && ((millis() - timer) <= SerialTimeout))
  {    
    //Arduino-Mega only
    #if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
      while(SerialMessageComplete==false && Serial2.available() > 0) 
    #endif 
    
    //Arduino-Pro only
    #if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
      while(SerialMessageComplete==false && Serial.available() > 0) 
    #endif 

	//Arduino-Leonardo only
	#if defined(__AVR_ATmega32U4__)
      while(SerialMessageComplete==false && Serial1.available() > 0) 
    #endif 
    {
      //Arduino-Mega only
      #if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
        char inChar = Serial2.read();
      #endif 
      
      //Arduino-Pro only
      #if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
        char inChar = Serial.read();
      #endif 
	  
	  //Arduino-Leonardo only
	  #if defined(__AVR_ATmega32U4__)
        char inChar = Serial1.read();
      #endif 

      if(BeginMessage==false){
        if(inChar=='{')
        {
          BeginMessage=true;
          SerialMessage = inChar;
        }
      }
      else{
        if(inChar=='}'){
          SerialMessage += inChar;
          SerialMessageComplete=true;
          
          //Arduino-Mega only
          #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL2_ACTIVE)
            Serial.println(SerialMessage);
          #endif 

          AnalyzeSerialMessage();
        }
        else{
          SerialMessage += inChar;
        }
      }
    }
  }  
}

// Initialize everything and prepare to start
void setup()
{   
  for (int i = 0; i < MaxHeaters; i++) {
    NeoPixelHeater_LEDs[i]= -1;
  }  

  // ***************************************
  // ********** User-Config Begin **********

  //General
  NeoPixelStartupAnimation= true; //Show StartupAnimation for all Neopixels (true = activated / false = deactivated) !!Attention!! Animation will only be shown if all Neopixels have the same amount of LEDs

  //Heater-Scaling (0= Heatbed)
  Heater_Scale[0] = 10; //Temperature steps at which the following LEDs light up
  Heater_Scale[1] = 20; //Temperature steps at which the following LEDs light up
//Heater_Scale[2] = 20; //Temperature steps at which the following LEDs light up
  
  //NeoPixel#1 - Printer status
  NeoPixelPrinterstatus_Active= true; //NeoPixel showing the printer status (true = activated / false = deactivated)
  NeoPixelPrinterstatus_StartupAnimationType= 2; //Startup animation type (1-3)
  NeoPixelPrinterstatus_Type= NEO_GRB + NEO_KHZ800; //Neopixel type (do not change if using NeoPixel from the BOM)
  NeoPixelPrinterstatus_LEDs= 16; //Count of NeoPixel-LEDs (do not change if using Neopixel from the BOM)
  NeoPixelPrinterstatus_ArduinoPin= 8; //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
  NeoPixelPrinterstatus_PixelOffset= 0; //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the startpoint clockwise (positive offset) or anti-clockwise (negative offset).
  NeoPixelPrinterstatus_AnimationActive= true; //Animation for print progress (true = activated / false = deactivated)
  NeoPixelPrinterstatus_AnimationReverse= false; //Reverse Direction of Animation (false = default / true = reversed)
  NeoPixelPrinterstatus_Brightness= 8; //Overall brightness of the Neopixel-LEDs
  NeoPixelPrinterstatus_ColorIdle= ConvertColor(255,255,255); //RGB values for specified status
  NeoPixelPrinterstatus_ColorPrinting= ConvertColor(64,255,64); //RGB values for specified status
  NeoPixelPrinterstatus_ColorPrintingDone= ConvertColor(0,255,0); //RGB values for specified status
  NeoPixelPrinterstatus_ColorStopped= ConvertColor(0,0,255); //RGB values for specified status
  NeoPixelPrinterstatus_ColorConfiguring= ConvertColor(255,255,0); //RGB values for specified status
  NeoPixelPrinterstatus_ColorPaused= ConvertColor(160,32,240); //RGB values for specified status
  NeoPixelPrinterstatus_ColorBusy= ConvertColor(255,255,0); //RGB values for specified status
  NeoPixelPrinterstatus_ColorPausing= ConvertColor(160,32,240); //RGB values for specified status
  NeoPixelPrinterstatus_ColorResuming= ConvertColor(255,255,0); //RGB values for specified status
  NeoPixelPrinterstatus_ColorFlashing= ConvertColor(255,255,0); //RGB values for specified status
  NeoPixelPrinterstatus_ColorDefault= ConvertColor(255,255,255); //RGB values for specified status
  NeoPixelPrinterstatus_ColorAnimation= ConvertColor(0,0,0); //RGB values for specified status
  
  //NeoPixel#2 - Heater #0 (Heatbed)
  NeoPixelHeater_Active[0]= true; //NeoPixel showing the heatbed temperature (true = activated / false = deactivated)
  NeoPixelHeater_StartupAnimationType[0]= 3; //Startup animation type (1-3)
  NeoPixelHeater_ShowHeaters[0]= "0"; //Show temp of Heater n (multiple Heaters seperated by & / 0= Heatbed)
  NeoPixelHeater_Type[0]= NEO_GRB + NEO_KHZ800; //Neopixel type (do not change if using NeoPixel from the BOM)
  NeoPixelHeater_LEDs[0]= 16; //Count of Neopixel-LEDs (do not change if using Neopixel from the BOM)
  NeoPixelHeater_ArduinoPin[0]= 6; //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
  NeoPixelHeater_PixelOffset[0]= 0; //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
  NeoPixelHeater_TempOffset[0]= 0; //Minimum Temperature at which the first LED lights up
  NeoPixelHeater_AnimationActive[0]= true; //Animation when the Hotend heats up (true = activated / false = deactivated)
  NeoPixelHeater_AnimationReverse[0]= false; //Reverse Direction of Animation (false = default / true = reversed)
  NeoPixelHeater_Brightness[0]= 8; //Overall brightness of the Neopixel-LEDs
  NeoPixelHeater_ColorIdle[0]= ConvertColor(255,255,255); //RGB values for specified status
  NeoPixelHeater_ColorHeatUp[0]= ConvertColor(255,64,64); //RGB values for specified status
  NeoPixelHeater_ColorHeatUpDone[0]= ConvertColor(255,0,0); //RGB values for specified status
  NeoPixelHeater_ColorCoolDown[0]= ConvertColor(0,0,255); //RGB values for specified status
  NeoPixelHeater_ColorAnimation[0]= ConvertColor(0,0,0); //RGB values for specified status

  //NeoPixel#3
  NeoPixelHeater_Active[1]= true; //NeoPixel showing the temperature of Heater1 (true = activated / false = deactivated)
  NeoPixelHeater_StartupAnimationType[1]= 1; //Startup animation type (1-3)
  NeoPixelHeater_ShowHeaters[1]= "1"; //Show temp of Heater n (multiple Heaters seperated by & / 0= Heatbed)
  NeoPixelHeater_Type[1]= NEO_GRB + NEO_KHZ800; //Neopixel type (do not change if using NeoPixel from the BOM)
  NeoPixelHeater_LEDs[1]= 16; //Count of Neopixel-LEDs (do not change if using Neopixel from the BOM)
  NeoPixelHeater_ArduinoPin[1]= 7; //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
  NeoPixelHeater_PixelOffset[1]= 0; //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
  NeoPixelHeater_TempOffset[1]= 0; //Minimum Temperature at which the first LED lights up
  NeoPixelHeater_AnimationActive[1]= true; //Animation when the Hotend heats up (true = activated / false = deactivated)
  NeoPixelHeater_AnimationReverse[1]= false; //Reverse Direction of Animation (false = default / true = reversed)
  NeoPixelHeater_Brightness[1]= 8; //Overall brightness of the Neopixel-LEDs
  NeoPixelHeater_ColorIdle[1]= ConvertColor(255,255,255); //RGB values for specified status
  NeoPixelHeater_ColorHeatUp[1]= ConvertColor(255,64,64); //RGB values for specified status
  NeoPixelHeater_ColorHeatUpDone[1]= ConvertColor(255,0,0); //RGB values for specified status
  NeoPixelHeater_ColorCoolDown[1]= ConvertColor(0,0,255); //RGB values for specified status
  NeoPixelHeater_ColorAnimation[1]= ConvertColor(0,0,0); //RGB values for specified status
  
/*
  //NeoPixel#4
  NeoPixelHeater_Active[2]= false; //NeoPixel showing the temperature of Heater2 (true = activated / false = deactivated)
  NeoPixelHeater_StartupAnimationType[2]= 1; //Startup animation type (1-3)
  NeoPixelHeater_ShowHeaters[2]= "2&3"; //Show temp of Heater n (multiple Heaters seperated by & / 0= Heatbed)
  NeoPixelHeater_Type[2]= NEO_GRB + NEO_KHZ800; //Neopixel type (do not change if using NeoPixel from the BOM)
  NeoPixelHeater_LEDs[2]= 16; //Count of Neopixel-LEDs (do not change if using Neopixel from the BOM)
  NeoPixelHeater_ArduinoPin[2]= 5; //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
  NeoPixelHeater_PixelOffset[2]= 0; //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
  NeoPixelHeater_TempOffset[2]= 0; //Minimum Temperature at which the first LED lights up
  NeoPixelHeater_AnimationActive[2]= true; //Animation when the Hotend heats up (true = activated / false = deactivated)
  NeoPixelHeater_AnimationReverse[2]= false; //Reverse Direction of Animation (false = default / true = reversed)
  NeoPixelHeater_Brightness[2]= 8; //Overall brightness of the Neopixel-LEDs
  NeoPixelHeater_ColorIdle[2]= ConvertColor(255,255,255); //RGB values for specified status
  NeoPixelHeater_ColorHeatUp[2]= ConvertColor(255,64,64); //RGB values for specified status
  NeoPixelHeater_ColorHeatUpDone[2]= ConvertColor(255,0,0); //RGB values for specified status
  NeoPixelHeater_ColorCoolDown[2]= ConvertColor(0,0,255); //RGB values for specified status
  NeoPixelHeater_ColorAnimation[2]= ConvertColor(0,0,0); //RGB values for specified status
*/  
  // ********** User-Config End **********
  // *************************************

  NeoPixelsUsedForHeaters= -1;
  for (int i = 0; NeoPixelHeater_LEDs[i] != -1; i++)
  {
    NeoPixelsUsedForHeaters++;
    NeoPixelHeater[i].updateLength(NeoPixelHeater_LEDs[i]);
    NeoPixelHeater[i].setPin(NeoPixelHeater_ArduinoPin[i]);
    NeoPixelHeater[i].updateType(NeoPixelHeater_Type[i]);
  }  
  NeoPixelPrinterstatus.updateLength(NeoPixelPrinterstatus_LEDs);
  NeoPixelPrinterstatus.setPin(NeoPixelPrinterstatus_ArduinoPin);
  NeoPixelPrinterstatus.updateType(NeoPixelPrinterstatus_Type);

  //Arduino-Mega only
  #if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    Serial.begin(38400);  
    while(!Serial)
    {;}
    Serial2.begin(57600);
    while(!Serial2)
    {;}
    #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL1_ACTIVE)
      Serial.println("Start");
    #endif 
  #endif 
  
  //Arduino-Pro only
  #if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
    Serial.begin(57600);
    while(!Serial)
    {;}
  #endif 
  
  //Arduino-Leonardo only
  #if defined(__AVR_ATmega32U4__)
    Serial1.begin(57600);
    while(!Serial1)
    {;}
  #endif 

  // Initialize Neopixels
  for(int i = 0; i <= NeoPixelsUsedForHeaters; i++) {
    if (NeoPixelHeater_Active[i] == true) { 
      NeoPixelHeater[i].begin();
      NeoPixelHeater[i].show();
    }
  }  
  if (NeoPixelPrinterstatus_Active == true){
    NeoPixelPrinterstatus.begin();
    NeoPixelPrinterstatus.show();
  }

  //Set start values
  Printer.Status = ' ';
  for (int i = 0; i <= NeoPixelsUsedForHeaters; i++)
  {
    NeoPixelAnimationMemory_Heater[i].Position = 0;
    NeoPixelAnimationMemory_Heater[i].Position_Memory = 0;
    NeoPixelAnimationMemory_Heater[i].RangeBegin = 0;
    NeoPixelAnimationMemory_Heater[i].RangeEnd = 0;
    NeoPixelAnimationMemory_Heater[i].Running = false;
    Printer.ActTempHeater[i] = 0.0;
    Printer.ActiveTempHeater[i] = 0.0;
    Printer.StandbyTempHeater[i] = 0.0;
    Printer.HeaterStatus[i] = 0.0;
  }  
  NeoPixelAnimationMemory_Printerstatus.Position = 0;
  NeoPixelAnimationMemory_Printerstatus.Position_Memory = 0;
  NeoPixelAnimationMemory_Printerstatus.RangeBegin = 0;
  NeoPixelAnimationMemory_Printerstatus.RangeEnd = 0;
  NeoPixelAnimationMemory_Printerstatus.Running = false;
  Printer.FractionPrinted = 0.0;
  Printer.UpdatePending = false;

  #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL1_ACTIVE)
    for (int i = 0; i <= NeoPixelsUsedForHeaters; i++)
    {
      DebugPrinter.ActTempHeater[i] = 0.0;
      DebugPrinter.ActiveTempHeater[i] = 0.0;
      DebugPrinter.StandbyTempHeater[i] = 0.0;
      DebugPrinter.HeaterStatus[i] = 0.0;
    }  
    DebugPrinter.FractionPrinted = 0.0;
  #endif 

  // Startup-Animation
  int NeoPixelCount = 0;
  bool NeoPixelStartupAnimation_Consistency = true;
  if (NeoPixelStartupAnimation == true)
  {
    for (int i = 0; i <= NeoPixelsUsedForHeaters; i++)
    {
      if (NeoPixelHeater_Active[i] == true) {
        if (NeoPixelCount == 0) {
          NeoPixelCount = NeoPixelHeater_LEDs[i];
        }
        else {
          if (NeoPixelHeater_LEDs[i] != NeoPixelCount) {
            NeoPixelStartupAnimation_Consistency = false;
          }
        }
      }
    }  
  	if (NeoPixelPrinterstatus_Active == true) {
  	  if (NeoPixelCount == 0) {
    		NeoPixelCount = NeoPixelPrinterstatus_LEDs;
  	  }
  	  else {
    		if (NeoPixelPrinterstatus_LEDs != NeoPixelCount) {
    			NeoPixelStartupAnimation_Consistency = false;
    		}
  	  }
  	}
  	
    //Activate startup sequence only if all activated NeoPixels have the same number of LEDs
  	if (NeoPixelCount > 0 && NeoPixelStartupAnimation_Consistency == true) {

      //Initialize Neopixels
      for (int i = 0; i <= NeoPixelsUsedForHeaters; i++)
      {
        NeoPixelHeater[i].setBrightness(255);
      }  
      NeoPixelPrinterstatus.setBrightness(255);
     
      //Startup Animation #1a
  		for (int i = 0; i < NeoPixelCount; i++) {
        for(int j = 0; j <= NeoPixelsUsedForHeaters; j++) {
          if (NeoPixelHeater_Active[j] == true) { 
            NeoPixelHeater[j].clear();
            if (NeoPixelHeater_StartupAnimationType[j] == 1) {NeoPixelHeater[j].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[j],NeoPixelHeater_PixelOffset[j],(i+1),NeoPixelHeater_AnimationReverse[j]), ConvertColor(255, 0, 0));}
            if (NeoPixelHeater_StartupAnimationType[j] == 2) {NeoPixelHeater[j].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[j],NeoPixelHeater_PixelOffset[j],(i+1),NeoPixelHeater_AnimationReverse[j]), ConvertColor(0, 255, 0));}
            if (NeoPixelHeater_StartupAnimationType[j] == 3) {NeoPixelHeater[j].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[j],NeoPixelHeater_PixelOffset[j],(i+1),NeoPixelHeater_AnimationReverse[j]), ConvertColor(0, 0, 255));}
            NeoPixelHeater[j].show();
          }
        }  
        if (NeoPixelPrinterstatus_Active == true) {
          NeoPixelPrinterstatus.clear();
          if (NeoPixelPrinterstatus_StartupAnimationType == 1) {NeoPixelPrinterstatus.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,(i+1),NeoPixelPrinterstatus_AnimationReverse), ConvertColor(255, 0, 0));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 2) {NeoPixelPrinterstatus.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,(i+1),NeoPixelPrinterstatus_AnimationReverse), ConvertColor(0, 255, 0));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 3) {NeoPixelPrinterstatus.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,(i+1),NeoPixelPrinterstatus_AnimationReverse), ConvertColor(0, 0, 255));}
          NeoPixelPrinterstatus.show();
        }
        delay(30);
  		}
      //Startup Animation #1b
			for(int i = 0; i < NeoPixelCount; i++) {
        for(int j = 0; j <= NeoPixelsUsedForHeaters; j++) {
          if (NeoPixelHeater_Active[j] == true) { 
            NeoPixelHeater[j].clear();
            if (NeoPixelHeater_StartupAnimationType[j] == 1) {NeoPixelHeater[j].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[j],NeoPixelHeater_PixelOffset[j],(i+1),NeoPixelHeater_AnimationReverse[j]), ConvertColor(0, 255, 0));}
            if (NeoPixelHeater_StartupAnimationType[j] == 2) {NeoPixelHeater[j].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[j],NeoPixelHeater_PixelOffset[j],(i+1),NeoPixelHeater_AnimationReverse[j]), ConvertColor(0, 0, 255));}
            if (NeoPixelHeater_StartupAnimationType[j] == 3) {NeoPixelHeater[j].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[j],NeoPixelHeater_PixelOffset[j],(i+1),NeoPixelHeater_AnimationReverse[j]), ConvertColor(255, 0, 0));}
            NeoPixelHeater[j].show();
          }
        }  
        if (NeoPixelPrinterstatus_Active == true) {
          NeoPixelPrinterstatus.clear();
          if (NeoPixelPrinterstatus_StartupAnimationType == 1) {NeoPixelPrinterstatus.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,(i+1),NeoPixelPrinterstatus_AnimationReverse), ConvertColor(0, 255, 0));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 2) {NeoPixelPrinterstatus.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,(i+1),NeoPixelPrinterstatus_AnimationReverse), ConvertColor(0, 0, 255));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 3) {NeoPixelPrinterstatus.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,(i+1),NeoPixelPrinterstatus_AnimationReverse), ConvertColor(255, 0, 0));}
          NeoPixelPrinterstatus.show();
        }
        delay(30);
  		}
      //Startup Animation #1c
      for(int i = 0; i < NeoPixelCount; i++) {
        for(int j = 0; j <= NeoPixelsUsedForHeaters; j++) {
          if (NeoPixelHeater_Active[j] == true) { 
            NeoPixelHeater[j].clear();
            if (NeoPixelHeater_StartupAnimationType[j] == 1) {NeoPixelHeater[j].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[j],NeoPixelHeater_PixelOffset[j],(i+1),NeoPixelHeater_AnimationReverse[j]), ConvertColor(0, 0, 255));}
            if (NeoPixelHeater_StartupAnimationType[j] == 2) {NeoPixelHeater[j].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[j],NeoPixelHeater_PixelOffset[j],(i+1),NeoPixelHeater_AnimationReverse[j]), ConvertColor(255, 0, 0));}
            if (NeoPixelHeater_StartupAnimationType[j] == 3) {NeoPixelHeater[j].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[j],NeoPixelHeater_PixelOffset[j],(i+1),NeoPixelHeater_AnimationReverse[j]), ConvertColor(0, 255, 0));}
            NeoPixelHeater[j].show();
          }
        }  
        if (NeoPixelPrinterstatus_Active == true) {
          NeoPixelPrinterstatus.clear();
          if (NeoPixelPrinterstatus_StartupAnimationType == 1) {NeoPixelPrinterstatus.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,(i+1),NeoPixelPrinterstatus_AnimationReverse), ConvertColor(0, 0, 255));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 2) {NeoPixelPrinterstatus.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,(i+1),NeoPixelPrinterstatus_AnimationReverse), ConvertColor(255, 0, 0));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 3) {NeoPixelPrinterstatus.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,(i+1),NeoPixelPrinterstatus_AnimationReverse), ConvertColor(0, 255, 0));}
          NeoPixelPrinterstatus.show();
        }
        delay(30);
      }
      //Startup Animation #2a1
  		for(int i = 0; i < 255; i++)
  		{
        for(int j = 0; j <= NeoPixelsUsedForHeaters; j++) {
          if (NeoPixelHeater_Active[j] == true) { 
            NeoPixelHeater[j].clear();
            NeoPixelHeater[j].setBrightness(i);
            if (NeoPixelHeater_StartupAnimationType[j] == 1) {NeoPixelHeater[j].fill(ConvertColor(255, 0, 0));}
            if (NeoPixelHeater_StartupAnimationType[j] == 2) {NeoPixelHeater[j].fill(ConvertColor(0, 255, 0));}
            if (NeoPixelHeater_StartupAnimationType[j] == 3) {NeoPixelHeater[j].fill(ConvertColor(0, 0, 255));}
            NeoPixelHeater[j].show();
          }
        }  
        if (NeoPixelPrinterstatus_Active == true) {
          NeoPixelPrinterstatus.clear();
          NeoPixelPrinterstatus.setBrightness(i);
          if (NeoPixelPrinterstatus_StartupAnimationType == 1) {NeoPixelPrinterstatus.fill(ConvertColor(255, 0, 0));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 2) {NeoPixelPrinterstatus.fill(ConvertColor(0, 255, 0));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 3) {NeoPixelPrinterstatus.fill(ConvertColor(0, 0, 255));}
          NeoPixelPrinterstatus.show();
        }
  		  delay(1);
  		}
      //Startup Animation #2a2
      for(int i = 255; i >= 0; i--)
      {
        for(int j = 0; j <= NeoPixelsUsedForHeaters; j++) {
          if (NeoPixelHeater_Active[j] == true) { 
            NeoPixelHeater[j].clear();
            NeoPixelHeater[j].setBrightness(i);
            if (NeoPixelHeater_StartupAnimationType[j] == 1) {NeoPixelHeater[j].fill(ConvertColor(255, 0, 0));}
            if (NeoPixelHeater_StartupAnimationType[j] == 2) {NeoPixelHeater[j].fill(ConvertColor(0, 255, 0));}
            if (NeoPixelHeater_StartupAnimationType[j] == 3) {NeoPixelHeater[j].fill(ConvertColor(0, 0, 255));}
            NeoPixelHeater[j].show();
          }
        }  
        if (NeoPixelPrinterstatus_Active == true) {
          NeoPixelPrinterstatus.clear();
          NeoPixelPrinterstatus.setBrightness(i);
          if (NeoPixelPrinterstatus_StartupAnimationType == 1) {NeoPixelPrinterstatus.fill(ConvertColor(255, 0, 0));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 2) {NeoPixelPrinterstatus.fill(ConvertColor(0, 255, 0));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 3) {NeoPixelPrinterstatus.fill(ConvertColor(0, 0, 255));}
          NeoPixelPrinterstatus.show();
        }
        delay(1);
      }
      //Startup Animation #2b1
      for(int i = 0; i < 255; i++)
      {
        for(int j = 0; j <= NeoPixelsUsedForHeaters; j++) {
          if (NeoPixelHeater_Active[j] == true) { 
            NeoPixelHeater[j].clear();
            NeoPixelHeater[j].setBrightness(i);
            if (NeoPixelHeater_StartupAnimationType[j] == 1) {NeoPixelHeater[j].fill(ConvertColor(0, 255, 0));}
            if (NeoPixelHeater_StartupAnimationType[j] == 2) {NeoPixelHeater[j].fill(ConvertColor(0, 0, 255));}
            if (NeoPixelHeater_StartupAnimationType[j] == 3) {NeoPixelHeater[j].fill(ConvertColor(255, 0, 0));}
            NeoPixelHeater[j].show();
          }
        }  
        if (NeoPixelPrinterstatus_Active == true) {
          NeoPixelPrinterstatus.clear();
          NeoPixelPrinterstatus.setBrightness(i);
          if (NeoPixelPrinterstatus_StartupAnimationType == 1) {NeoPixelPrinterstatus.fill(ConvertColor(0, 255, 0));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 2) {NeoPixelPrinterstatus.fill(ConvertColor(0, 0, 255));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 3) {NeoPixelPrinterstatus.fill(ConvertColor(255, 0, 0));}
          NeoPixelPrinterstatus.show();
        }
        delay(1);
      }
      //Startup Animation #2b2
      for(int i = 255; i >= 0; i--)
      {
        for(int j = 0; j <= NeoPixelsUsedForHeaters; j++) {
          if (NeoPixelHeater_Active[j] == true) { 
            NeoPixelHeater[j].clear();
            NeoPixelHeater[j].setBrightness(i);
            if (NeoPixelHeater_StartupAnimationType[j] == 1) {NeoPixelHeater[j].fill(ConvertColor(0, 255, 0));}
            if (NeoPixelHeater_StartupAnimationType[j] == 2) {NeoPixelHeater[j].fill(ConvertColor(0, 0, 255));}
            if (NeoPixelHeater_StartupAnimationType[j] == 3) {NeoPixelHeater[j].fill(ConvertColor(255, 0, 0));}
            NeoPixelHeater[j].show();
          }
        }  
        if (NeoPixelPrinterstatus_Active == true) {
          NeoPixelPrinterstatus.clear();
          NeoPixelPrinterstatus.setBrightness(i);
          if (NeoPixelPrinterstatus_StartupAnimationType == 1) {NeoPixelPrinterstatus.fill(ConvertColor(0, 255, 0));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 2) {NeoPixelPrinterstatus.fill(ConvertColor(0, 0, 255));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 3) {NeoPixelPrinterstatus.fill(ConvertColor(255, 0, 0));}
          NeoPixelPrinterstatus.show();
        }
        delay(1);
      }

      //Startup Animation #2c1
      for(int i = 0; i < 255; i++)
      {
        for(int j = 0; j <= NeoPixelsUsedForHeaters; j++) {
          if (NeoPixelHeater_Active[j] == true) { 
            NeoPixelHeater[j].clear();
            NeoPixelHeater[j].setBrightness(i);
            if (NeoPixelHeater_StartupAnimationType[j] == 1) {NeoPixelHeater[j].fill(ConvertColor(0, 0, 255));}
            if (NeoPixelHeater_StartupAnimationType[j] == 2) {NeoPixelHeater[j].fill(ConvertColor(255, 0, 0));}
            if (NeoPixelHeater_StartupAnimationType[j] == 3) {NeoPixelHeater[j].fill(ConvertColor(0, 255, 0));}
            NeoPixelHeater[j].show();
          }
        }  
        if (NeoPixelPrinterstatus_Active == true) {
          NeoPixelPrinterstatus.clear();
          NeoPixelPrinterstatus.setBrightness(i);
          if (NeoPixelPrinterstatus_StartupAnimationType == 1) {NeoPixelPrinterstatus.fill(ConvertColor(0, 0, 255));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 2) {NeoPixelPrinterstatus.fill(ConvertColor(255, 0, 0));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 3) {NeoPixelPrinterstatus.fill(ConvertColor(0, 255, 0));}
          NeoPixelPrinterstatus.show();
        }
        delay(1);
      }
      //Startup Animation #2c2
      for(int i = 255; i >= 0; i--)
      {
        for(int j = 0; j <= NeoPixelsUsedForHeaters; j++) {
          if (NeoPixelHeater_Active[j] == true) { 
            NeoPixelHeater[j].clear();
            NeoPixelHeater[j].setBrightness(i);
            if (NeoPixelHeater_StartupAnimationType[j] == 1) {NeoPixelHeater[j].fill(ConvertColor(0, 0, 255));}
            if (NeoPixelHeater_StartupAnimationType[j] == 2) {NeoPixelHeater[j].fill(ConvertColor(255, 0, 0));}
            if (NeoPixelHeater_StartupAnimationType[j] == 3) {NeoPixelHeater[j].fill(ConvertColor(0, 255, 0));}
            NeoPixelHeater[j].show();
          }
        }  
        if (NeoPixelPrinterstatus_Active == true) {
          NeoPixelPrinterstatus.clear();
          NeoPixelPrinterstatus.setBrightness(i);
          if (NeoPixelPrinterstatus_StartupAnimationType == 1) {NeoPixelPrinterstatus.fill(ConvertColor(0, 0, 255));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 2) {NeoPixelPrinterstatus.fill(ConvertColor(255, 0, 0));}
          if (NeoPixelPrinterstatus_StartupAnimationType == 3) {NeoPixelPrinterstatus.fill(ConvertColor(0, 255, 0));}
          NeoPixelPrinterstatus.show();
        }
        delay(1);
      }
  	}	
  }  
  //Initial Neopixel for Loop
  for (int i = 0; i <= NeoPixelsUsedForHeaters; i++)
  {
    NeoPixelHeater[i].clear();
    NeoPixelHeater[i].show();
    NeoPixelHeater[i].setBrightness(NeoPixelHeater_Brightness[i]);
  }  
  NeoPixelPrinterstatus.clear();
  NeoPixelPrinterstatus.show();
  NeoPixelPrinterstatus.setBrightness(NeoPixelPrinterstatus_Brightness);
}


// Main loop
void loop()
{
  //Read serial
  //Arduino-Mega only
  #if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    if (Serial2.available() > 0){
      GetSerialMessage();
    }  
  #endif 
  
  //Arduino-Pro only
  #if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
    if (Serial.available() > 0){
      GetSerialMessage();
    }  
  #endif 

  //Arduino-Leonardo only
  #if defined(__AVR_ATmega32U4__)
    if (Serial1.available() > 0){
      GetSerialMessage();
    }  
  #endif 

  //NeopixelRefresh?
  if ((millis() - NeoPixelTimerRefresh) >= NeopixelRefreshSpeed){
    NeoPixelTimerRefresh = millis();
    
     //New PrinterStatusUpdate?
    if (Printer.UpdatePending == true){
      Printer.UpdatePending = false;
      #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL1_ACTIVE)
        for(int i = 0; i <= NeoPixelsUsedForHeaters; i++) {
          if (((Printer.ActTempHeater[i] > DebugPrinter.ActTempHeater[i]) && (Printer.ActTempHeater[i] / DebugPrinter.ActTempHeater[i]) > 2) || ((Printer.ActTempHeater[i] < DebugPrinter.ActTempHeater[i]) && (DebugPrinter.ActTempHeater[i] / Printer.ActTempHeater[i]) > 2)){
            Serial.println("High Delta ActTempHeater: Act="+String(Printer.ActTempHeater[i]) + " / Memory= "+String(DebugPrinter.ActTempHeater[i]));
            Serial.println("SerialMessage= "+SerialMessage);
            Serial.println("");
          }
          if (((Printer.ActiveTempHeater[i] > DebugPrinter.ActiveTempHeater[i]) && (Printer.ActiveTempHeater[i] / DebugPrinter.ActiveTempHeater[i]) > 2) || ((Printer.ActiveTempHeater[i] < DebugPrinter.ActiveTempHeater[i]) && (DebugPrinter.ActiveTempHeater[i] / Printer.ActiveTempHeater[i]) > 2)){
            Serial.println("High Delta ActiveTempHeater: Act="+String(Printer.ActiveTempHeater[i]) + " / Memory= "+String(DebugPrinter.ActiveTempHeater[i]));
            Serial.println("SerialMessage= "+SerialMessage);
            Serial.println("");
          }
          if (((Printer.StandbyTempHeater[i] > DebugPrinter.StandbyTempHeater[i]) && (Printer.StandbyTempHeater[i] / DebugPrinter.StandbyTempHeater[i]) > 2) || ((Printer.StandbyTempHeater[i] < DebugPrinter.StandbyTempHeater[i]) && (DebugPrinter.StandbyTempHeater[i] / Printer.StandbyTempHeater[i]) > 2)){
            Serial.println("High Delta StandbyTempHeater: Act="+String(Printer.StandbyTempHeater[i]) + " / Memory= "+String(DebugPrinter.StandbyTempHeater[i]));
            Serial.println("SerialMessage= "+SerialMessage);
            Serial.println("");
          }
        }
        if (((Printer.FractionPrinted > DebugPrinter.FractionPrinted) && (Printer.FractionPrinted / DebugPrinter.FractionPrinted) > 2) || ((Printer.FractionPrinted < DebugPrinter.FractionPrinted) && (DebugPrinter.FractionPrinted / Printer.FractionPrinted) > 2)){
          Serial.println("High Delta FractionPrinted: Act="+String(Printer.FractionPrinted) + " / Memory= "+String(DebugPrinter.FractionPrinted));
          Serial.println("SerialMessage= "+SerialMessage);
          Serial.println("");
        }
        for(int i = 0; i <= NeoPixelsUsedForHeaters; i++) {
          DebugPrinter.ActTempHeater[i] = Printer.ActTempHeater[i];
          DebugPrinter.ActiveTempHeater[i] = Printer.ActiveTempHeater[i];
          DebugPrinter.StandbyTempHeater[i] = Printer.StandbyTempHeater[i];
        }  
        DebugPrinter.FractionPrinted = Printer.FractionPrinted;
      #endif 

      //Update Neopixels - Heaters
      for (int i= 0; i <= NeoPixelsUsedForHeaters; i++) {
        if (NeoPixelHeater_Active[i] == true && NeoPixelHeater_ShowHeaters[i].length() > 0){
          //Initialize AnimationRange
          NeoPixelAnimationMemory_Heater[i].RangeBegin = 0;
          NeoPixelAnimationMemory_Heater[i].RangeEnd = 0;
  
          //Find heater to show
          ShowHeater = -1;
          StringPos= 0;
          HeaterDelimiterPos= 0;
          HeaterID= 0;
          // Find first "active" heater
          while (ShowHeater == -1 && StringPos < NeoPixelHeater_ShowHeaters[i].length()) {
            HeaterDelimiterPos= NeoPixelHeater_ShowHeaters[i].indexOf('&', StringPos);
            if (HeaterDelimiterPos == -1) {
              HeaterID= NeoPixelHeater_ShowHeaters[i].substring(StringPos, NeoPixelHeater_ShowHeaters[i].length()).toInt();
              StringPos++;
            }
            else {
              HeaterID= (NeoPixelHeater_ShowHeaters[i].substring(StringPos, HeaterDelimiterPos)).toInt();
              StringPos = HeaterDelimiterPos + 1;
            }
            #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL2_ACTIVE)
              Serial.println("=> FindHeater: NeoPixel["+String(i)+"] / HeaterID= "+String(HeaterID)+ " / StringPos= "+String(StringPos) + " / HeaterDelimiterPos= "+String(HeaterDelimiterPos));
            #endif
            if (Printer.HeaterStatus[HeaterID] == 2) {
              ShowHeater= HeaterID;
            }
          }
          //Find first "standby" heater
          StringPos= 0;
          HeaterDelimiterPos= 0;
          HeaterID= 0;
          while (ShowHeater == -1 && StringPos <= NeoPixelHeater_ShowHeaters[i].length()) {
            HeaterDelimiterPos= NeoPixelHeater_ShowHeaters[i].indexOf('&', StringPos);
            if (HeaterDelimiterPos == -1) {
              HeaterID= NeoPixelHeater_ShowHeaters[i].substring(StringPos, NeoPixelHeater_ShowHeaters[i].length()).toInt();
              StringPos++;
            }
            else {
              HeaterID= (NeoPixelHeater_ShowHeaters[i].substring(StringPos, HeaterDelimiterPos)).toInt();
              StringPos = HeaterDelimiterPos + 1;
            }
            if (Printer.HeaterStatus[HeaterID] == 1) {
              ShowHeater= HeaterID;
            }
          }
          //Find first "off" heater
          StringPos= 0;
          HeaterDelimiterPos= 0;
          HeaterID= 0;
          while (ShowHeater == -1 && StringPos <= NeoPixelHeater_ShowHeaters[i].length()) {
            HeaterDelimiterPos= NeoPixelHeater_ShowHeaters[i].indexOf('&', StringPos);
            if (HeaterDelimiterPos == -1) {
              HeaterID= NeoPixelHeater_ShowHeaters[i].substring(StringPos, NeoPixelHeater_ShowHeaters[i].length()).toInt();
              StringPos++;
            }
            else {
              HeaterID= (NeoPixelHeater_ShowHeaters[i].substring(StringPos, HeaterDelimiterPos)).toInt();
              StringPos = HeaterDelimiterPos + 1;
            }
            if (Printer.HeaterStatus[HeaterID] == 0) {
              ShowHeater= HeaterID;
            }
          }
        }
        #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL2_ACTIVE)
          Serial.println("=> ShowHeater: Neopixelheater["+String(i)+"] / FoundShowHeater= "+String(ShowHeater));
        #endif
        //Display heater status
        if (ShowHeater >= 0) {
          //If HeaterID has changed, reset AnimationMemory
          if (ShowHeater != NeoPixelAnimationMemory_Heater[i].ShowHeater_Memory) {
            NeoPixelAnimationMemory_Heater[i].ShowHeater_Memory = ShowHeater;
            NeoPixelHeater[i].clear();
            NeoPixelAnimationMemory_Heater[i].Position = 0;
            NeoPixelAnimationMemory_Heater[i].Position_Memory = 0;
            NeoPixelAnimationMemory_Heater[i].RangeBegin = 0;
            NeoPixelAnimationMemory_Heater[i].RangeEnd = 0;
            NeoPixelAnimationMemory_Heater[i].Running = false;
          }  

          SetTempHeater=0;
          ActTempHeater=Printer.ActTempHeater[ShowHeater];
          if (Printer.HeaterStatus[ShowHeater] == 2){
            SetTempHeater=Printer.ActiveTempHeater[ShowHeater];
          }
          else if (Printer.HeaterStatus[ShowHeater] == 1){
            SetTempHeater=Printer.StandbyTempHeater[ShowHeater];
          }
          for (int NeoPixelPosition = 1; NeoPixelPosition <= NeoPixelHeater_LEDs[i]; NeoPixelPosition++)
          {
            if((((ActTempHeater - NeoPixelHeater_TempOffset[i]) / Heater_Scale[ShowHeater]) < NeoPixelPosition) && (((SetTempHeater - NeoPixelHeater_TempOffset[i]) / Heater_Scale[ShowHeater]) >= NeoPixelPosition)){
              NeoPixelHeater[i].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[i],NeoPixelHeater_PixelOffset[i],NeoPixelPosition,NeoPixelHeater_AnimationReverse[i]),NeoPixelHeater_ColorHeatUp[i]);
              //Define Animation-Range
              if (NeoPixelAnimationMemory_Heater[i].RangeBegin == 0) {
                NeoPixelAnimationMemory_Heater[i].RangeBegin = NeoPixelPosition;
                NeoPixelAnimationMemory_Heater[i].RangeEnd = NeoPixelPosition;
              } else {
                NeoPixelAnimationMemory_Heater[i].RangeEnd++;
              }
            }
            else if((((ActTempHeater - NeoPixelHeater_TempOffset[i]) / Heater_Scale[ShowHeater]) >= NeoPixelPosition) && (((SetTempHeater - NeoPixelHeater_TempOffset[i]) / Heater_Scale[ShowHeater]) >= NeoPixelPosition)){
              NeoPixelHeater[i].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[i],NeoPixelHeater_PixelOffset[i],NeoPixelPosition,NeoPixelHeater_AnimationReverse[i]),NeoPixelHeater_ColorHeatUpDone[i]);
            }
            else if((((ActTempHeater - NeoPixelHeater_TempOffset[i]) / Heater_Scale[ShowHeater]) >= NeoPixelPosition) && (((SetTempHeater - NeoPixelHeater_TempOffset[i]) / Heater_Scale[ShowHeater]) < NeoPixelPosition)){
              NeoPixelHeater[i].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[i],NeoPixelHeater_PixelOffset[i],NeoPixelPosition,NeoPixelHeater_AnimationReverse[i]),NeoPixelHeater_ColorCoolDown[i]);
            }
            else{
              NeoPixelHeater[i].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[i],NeoPixelHeater_PixelOffset[i],NeoPixelPosition,NeoPixelHeater_AnimationReverse[i]),NeoPixelHeater_ColorIdle[i]);
            }
          }
        }
      }  
      
      //Update Neopixel - PrinterStatus
      if (NeoPixelPrinterstatus_Active == true){
        //Initialize AnimationRange
        NeoPixelAnimationMemory_Printerstatus.RangeBegin = 0;
        NeoPixelAnimationMemory_Printerstatus.RangeEnd = 0;
  
        //NeoPixel: Printer-Status & Print-Progress
        if(Printer.Status == 'P'){ 
          //Display Print-Progress
          for (int NeoPixelPosition = 1; NeoPixelPosition <= NeoPixelPrinterstatus_LEDs; NeoPixelPosition++)
          {
            if(NeoPixelPosition < (Printer.FractionPrinted * NeoPixelPrinterstatus_LEDs)){
              NeoPixelPrinterstatus.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,NeoPixelPosition,NeoPixelPrinterstatus_AnimationReverse),NeoPixelPrinterstatus_ColorPrintingDone);
            }
            else{
              NeoPixelPrinterstatus.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,NeoPixelPosition,NeoPixelPrinterstatus_AnimationReverse),NeoPixelPrinterstatus_ColorPrinting);
              //Define Animation-Range
              if (NeoPixelAnimationMemory_Printerstatus.RangeBegin == 0) {
                NeoPixelAnimationMemory_Printerstatus.RangeBegin = NeoPixelPosition;
                NeoPixelAnimationMemory_Printerstatus.RangeEnd = NeoPixelPosition;
              } else {
                NeoPixelAnimationMemory_Printerstatus.RangeEnd++;
              }
            }
          }
        }
        else{
          // Display Printer-Status:
          // I = idle
          // P = printing
          // S = stopped
          // C = configuring
          // A = paused
          // D = busy
          // R = pausing
          // B = resuming
          // F = flashing
          switch (Printer.Status)
          {
            case 'I':
              NeoPixelPrinterstatus.fill(NeoPixelPrinterstatus_ColorIdle);
              break;
            case 'P':
              NeoPixelPrinterstatus.fill(NeoPixelPrinterstatus_ColorPrinting);
              break;
            case 'S':
              NeoPixelPrinterstatus.fill(NeoPixelPrinterstatus_ColorStopped);
              break;
            case 'C':
              NeoPixelPrinterstatus.fill(NeoPixelPrinterstatus_ColorConfiguring);
              break;
            case 'A':
              NeoPixelPrinterstatus.fill(NeoPixelPrinterstatus_ColorPaused);
              break;
            case 'D':
              NeoPixelPrinterstatus.fill(NeoPixelPrinterstatus_ColorBusy);
              break;
            case 'R':
              NeoPixelPrinterstatus.fill(NeoPixelPrinterstatus_ColorPausing);
              break;
            case 'B':
              NeoPixelPrinterstatus.fill(NeoPixelPrinterstatus_ColorResuming);
              break;
            case 'F':
              NeoPixelPrinterstatus.fill(NeoPixelPrinterstatus_ColorFlashing);
              break;
            default:
              NeoPixelPrinterstatus.fill(NeoPixelPrinterstatus_ColorDefault);
              break;
          }
        }
      }
    }  
    
    //Animation Heaters
    for (int i= 0; i <= NeoPixelsUsedForHeaters; i++) {
      if (NeoPixelHeater_Active[i] == true && NeoPixelHeater_AnimationActive[i] == true){
        //AnimationRange exists?
        if (NeoPixelAnimationMemory_Heater[i].RangeBegin == 0){
          NeoPixelAnimationMemory_Heater[i].Running = false;
        }
        else{
          //Animation initialize?
          if (NeoPixelAnimationMemory_Heater[i].Running == false){
              NeoPixelAnimationMemory_Heater[i].Running = true;
              NeoPixelAnimationMemory_Heater[i].Position = NeoPixelAnimationMemory_Heater[i].RangeBegin;
              NeoPixelAnimationMemory_Heater[i].Position_Memory = 0;
          }
          //Restart animation at new position?
          if (NeoPixelAnimationMemory_Heater[i].Position < NeoPixelAnimationMemory_Heater[i].RangeBegin) {
            NeoPixelAnimationMemory_Heater[i].Position = NeoPixelAnimationMemory_Heater[i].RangeBegin;
          }
          if (NeoPixelAnimationMemory_Heater[i].Position_Memory != NeoPixelAnimationMemory_Heater[i].Position && NeoPixelAnimationMemory_Heater[i].Position_Memory >= NeoPixelAnimationMemory_Heater[i].RangeBegin){
            NeoPixelHeater[i].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[i],NeoPixelHeater_PixelOffset[i],NeoPixelAnimationMemory_Heater[i].Position_Memory,NeoPixelHeater_AnimationReverse[i]),NeoPixelHeater_ColorHeatUp[i]);
          }
          if (NeoPixelHeater[i].getPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[i],NeoPixelHeater_PixelOffset[i],NeoPixelAnimationMemory_Heater[i].Position,NeoPixelHeater_AnimationReverse[i])) == NeoPixelHeater_ColorAnimation[i]){
              NeoPixelHeater[i].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[i],NeoPixelHeater_PixelOffset[i],NeoPixelAnimationMemory_Heater[i].Position,NeoPixelHeater_AnimationReverse[i]),NeoPixelHeater_ColorHeatUp[i]);
          }
          else{
            NeoPixelAnimationMemory_Heater[i].Position_Memory = NeoPixelAnimationMemory_Heater[i].Position;
            NeoPixelHeater[i].setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater_LEDs[i],NeoPixelHeater_PixelOffset[i],NeoPixelAnimationMemory_Heater[i].Position,NeoPixelHeater_AnimationReverse[i]),NeoPixelHeater_ColorAnimation[i]);
          }
          NeoPixelAnimationMemory_Heater[i].Position++;
          if (NeoPixelAnimationMemory_Heater[i].Position > NeoPixelAnimationMemory_Heater[i].RangeEnd) {
            NeoPixelAnimationMemory_Heater[i].Position = NeoPixelAnimationMemory_Heater[i].RangeBegin;
          }
        }
      }
    }  
  
    //Animation PrinterStatus
    if (NeoPixelPrinterstatus_Active == true && NeoPixelPrinterstatus_AnimationActive == true){
      //AnimationRange exists?
      if (NeoPixelAnimationMemory_Printerstatus.RangeBegin == 0){
        NeoPixelAnimationMemory_Printerstatus.Running = false;
      }
      else{
        //Animation initialize?
        if (NeoPixelAnimationMemory_Printerstatus.Running == false){
            NeoPixelAnimationMemory_Printerstatus.Running = true;
            NeoPixelAnimationMemory_Printerstatus.Position = NeoPixelAnimationMemory_Printerstatus.RangeBegin;
            NeoPixelAnimationMemory_Printerstatus.Position_Memory = 0;
        }
        //Restart animation at new position?
        if (NeoPixelAnimationMemory_Printerstatus.Position < NeoPixelAnimationMemory_Printerstatus.RangeBegin) {
          NeoPixelAnimationMemory_Printerstatus.Position = NeoPixelAnimationMemory_Printerstatus.RangeBegin;
        }
        if (NeoPixelAnimationMemory_Printerstatus.Position_Memory != NeoPixelAnimationMemory_Printerstatus.Position && NeoPixelAnimationMemory_Printerstatus.Position_Memory >= NeoPixelAnimationMemory_Printerstatus.RangeBegin){
          NeoPixelPrinterstatus.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,NeoPixelAnimationMemory_Printerstatus.Position_Memory,NeoPixelPrinterstatus_AnimationReverse),NeoPixelPrinterstatus_ColorPrinting);
        }
        if (NeoPixelPrinterstatus.getPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,NeoPixelAnimationMemory_Printerstatus.Position,NeoPixelPrinterstatus_AnimationReverse)) == NeoPixelPrinterstatus_ColorAnimation){
            NeoPixelPrinterstatus.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,NeoPixelAnimationMemory_Printerstatus.Position,NeoPixelPrinterstatus_AnimationReverse),NeoPixelPrinterstatus_ColorPrinting);
        }
        else{
          NeoPixelAnimationMemory_Printerstatus.Position_Memory = NeoPixelAnimationMemory_Printerstatus.Position;
          NeoPixelPrinterstatus.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterstatus_LEDs,NeoPixelPrinterstatus_PixelOffset,NeoPixelAnimationMemory_Printerstatus.Position,NeoPixelPrinterstatus_AnimationReverse),NeoPixelPrinterstatus_ColorAnimation);
        }
        NeoPixelAnimationMemory_Printerstatus.Position++;
        if (NeoPixelAnimationMemory_Printerstatus.Position > NeoPixelAnimationMemory_Printerstatus.RangeEnd) {
          NeoPixelAnimationMemory_Printerstatus.Position = NeoPixelAnimationMemory_Printerstatus.RangeBegin;
        }
      }
    }

    //Neopixel refresh
    for (int i= 0; i <= NeoPixelsUsedForHeaters; i++) {
      if (NeoPixelHeater_Active[i] == true){
        NeoPixelHeater[i].show();
      }  
    }  
    if (NeoPixelPrinterstatus_Active == true){
      NeoPixelPrinterstatus.show();   
    }
  }
}
