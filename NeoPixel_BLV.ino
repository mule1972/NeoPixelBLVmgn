#include <Adafruit_NeoPixel.h>

//#define DEBUGLEVEL1_ACTIVE
//#define DEBUGLEVEL2_ACTIVE

static uint32_t  ConvertColor(uint8_t red, uint8_t green, uint8_t blue) {
  return ((uint32_t)red << 16) | ((uint32_t)green <<  8) | blue;
}

// ***************************************
// ********** User-Config Begin **********

//NeoPixel1A (Hotend)
bool NeoPixel1A_Active= true; //NeoPixel showing the hotend temperature (true = activated / false = deactivated)
bool NeoPixel1A_Hotend1= true; //Use for Hotend1 (true = activated / false = deactivated)
bool NeoPixel1A_Hotend2= false; //Use for Hotend2 (true = activated / false = deactivated)
neoPixelType NeoPixel1A_Type= NEO_GRB + NEO_KHZ800; //Neopixel type (do not change if using NeoPixel from the BOM)
uint16_t NeoPixel1A_Count= 16; //Count of Neopixel-LEDs (do not change if using Neopixel from the BOM)
uint8_t NeoPixel1A_ArduinoPin= 6; //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
int NeoPixel1A_PixelOffset= 0; //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
int NeoPixel1A_TempOffset= 0; //Minimum Temperature at which the first LED lights up
int NeoPixel1A_Scale= 20; //Temperature steps at which the following LEDs light up
bool NeoPixel1A_AnimationActive= true; //Animation when the Hotend heats up (true = activated / false = deactivated)
uint8_t NeoPixel1A_Brightness= 8; //Overall brightness of the Neopixel-LEDs
uint32_t NeoPixel1A_ColorIdle= ConvertColor(255,255,255); //RGB values for specified status
uint32_t NeoPixel1A_ColorHeatUp= ConvertColor(255,64,64); //RGB values for specified status
uint32_t NeoPixel1A_ColorHeatUpDone= ConvertColor(255,0,0); //RGB values for specified status
uint32_t NeoPixel1A_ColorCoolDown= ConvertColor(0,0,255); //RGB values for specified status
uint32_t NeoPixel1A_ColorAnimation= ConvertColor(0,0,0); //RGB values for specified status

//NeoPixel1B (Hotend)
bool NeoPixel1B_Active= false; //NeoPixel showing the hotend temperature (true = activated / false = deactivated)
bool NeoPixel1B_Hotend1= false; //Use for Hotend1 (true = activated / false = deactivated)
bool NeoPixel1B_Hotend2= false; //Use for Hotend2 (true = activated / false = deactivated)
neoPixelType NeoPixel1B_Type= NEO_GRB + NEO_KHZ800; //Neopixel type (do not change if using NeoPixel from the BOM)
uint16_t NeoPixel1B_Count= 16; //Count of Neopixel-LEDs (do not change if using Neopixel from the BOM)
uint8_t NeoPixel1B_ArduinoPin= 6; //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
int NeoPixel1B_PixelOffset= 0; //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
int NeoPixel1B_TempOffset= 0; //Minimum Temperature at which the first LED lights up
int NeoPixel1B_Scale= 20; //Temperature steps at which the following LEDs light up
bool NeoPixel1B_AnimationActive= true; //Animation when the Hotend heats up (true = activated / false = deactivated)
uint8_t NeoPixel1B_Brightness= 8; //Overall brightness of the Neopixel-LEDs
uint32_t NeoPixel1B_ColorIdle= ConvertColor(255,255,255); //RGB values for specified status
uint32_t NeoPixel1B_ColorHeatUp= ConvertColor(255,64,64); //RGB values for specified status
uint32_t NeoPixel1B_ColorHeatUpDone= ConvertColor(255,0,0); //RGB values for specified status
uint32_t NeoPixel1B_ColorCoolDown= ConvertColor(0,0,255); //RGB values for specified status
uint32_t NeoPixel1B_ColorAnimation= ConvertColor(0,0,0); //RGB values for specified status

//NeoPixel2 (Printer status)
bool NeoPixel2_Active= true; //NeoPixel showing the printer status (true = activated / false = deactivated)
neoPixelType NeoPixel2_Type= NEO_GRB + NEO_KHZ800; //Neopixel type (do not change if using NeoPixel from the BOM)
uint16_t NeoPixel2_Count= 16; //Count of NeoPixel-LEDs (do not change if using Neopixel from the BOM)
uint8_t NeoPixel2_ArduinoPin= 7; //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
int NeoPixel2_PixelOffset= 0; //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the startpoint clockwise (positive offset) or anti-clockwise (negative offset).
bool NeoPixel2_AnimationActive= true; ///Animation for print progress (true = activated / false = deactivated)
uint8_t NeoPixel2_Brightness= 8; //Overall brightness of the Neopixel-LEDs
uint32_t NeoPixel2_ColorIdle= ConvertColor(255,255,255); //RGB values for specified status
uint32_t NeoPixel2_ColorPrinting= ConvertColor(64,255,64); //RGB values for specified status
uint32_t NeoPixel2_ColorPrintingDone= ConvertColor(0,255,0); //RGB values for specified status
uint32_t NeoPixel2_ColorStopped= ConvertColor(0,0,255); //RGB values for specified status
uint32_t NeoPixel2_ColorConfiguring= ConvertColor(255,255,0); //RGB values for specified status
uint32_t NeoPixel2_ColorPaused= ConvertColor(160,32,240); //RGB values for specified status
uint32_t NeoPixel2_ColorBusy= ConvertColor(255,255,0); //RGB values for specified status
uint32_t NeoPixel2_ColorPausing= ConvertColor(160,32,240); //RGB values for specified status
uint32_t NeoPixel2_ColorResuming= ConvertColor(255,255,0); //RGB values for specified status
uint32_t NeoPixel2_ColorFlashing= ConvertColor(255,255,0); //RGB values for specified status
uint32_t NeoPixel2_ColorDefault= ConvertColor(255,255,255); //RGB values for specified status
uint32_t NeoPixel2_ColorAnimation= ConvertColor(0,0,0); //RGB values for specified status

//NeoPixel3 (Heatbed)
bool NeoPixel3_Active= true; //NeoPixel showing the heatbed temperature (true = activated / false = deactivated)
neoPixelType NeoPixel3_Type= NEO_GRB + NEO_KHZ800; //Neopixel type (do not change if using NeoPixel from the BOM)
uint16_t NeoPixel3_Count= 16; //Count of NeoPixel-LEDs (do not change if using Neopixel from the BOM)
uint8_t NeoPixel3_ArduinoPin= 8; //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
int NeoPixel3_PixelOffset= 0; //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
int NeoPixel3_TempOffset= 0; //Minimum Temperature at which the first LED lights up
int NeoPixel3_Scale= 10; //Temperature steps at which the following LEDs light up
bool NeoPixel3_AnimationActive= true; //Animation when the Heatbed heats up (true = activated / false = deactivated)
uint8_t NeoPixel3_Brightness= 8; //Overall brightness of the Neopixel-LEDs
uint32_t NeoPixel3_ColorIdle= ConvertColor(255,255,255); //RGB values for specified status
uint32_t NeoPixel3_ColorHeatUp= ConvertColor(255,64,64); //RGB values for specified status
uint32_t NeoPixel3_ColorHeatUpDone= ConvertColor(255,0,0); //RGB values for specified status
uint32_t NeoPixel3_ColorCoolDown= ConvertColor(0,0,255); //RGB values for specified status
uint32_t NeoPixel3_ColorAnimation= ConvertColor(0,0,0); //RGB values for specified status

// ********** User-Config End **********
// *************************************


// Initialize global variables
unsigned long SerialTimeout= 100;
unsigned long NeopixelRefreshSpeed= 200;
unsigned long NeoPixelTimerRefresh = millis();

String SerialMessage;
bool SerialMessageComplete = false;

int SetTempHotend=0;
int ActTempHotend=0;
int SetTempHeatbed=0;

void NeoPixelComplete();
// NeoPattern Class - derived from the Adafruit_NeoPixel class
class NeoPatterns : public Adafruit_NeoPixel
{
    public:

    // Member Variables:  

    // Constructor - calls base-class constructor to initialize strip
    NeoPatterns(uint16_t pixels, uint8_t pin, uint8_t type, void (*)())
    :Adafruit_NeoPixel(pixels, pin, type)
    {
    }
};

NeoPatterns NeoPixel1A(NeoPixel1A_Count, NeoPixel1A_ArduinoPin, NeoPixel1A_Type, &NeoPixelComplete);
NeoPatterns NeoPixel1B(NeoPixel1A_Count, NeoPixel1B_ArduinoPin, NeoPixel1B_Type, &NeoPixelComplete);
NeoPatterns NeoPixel2(NeoPixel2_Count, NeoPixel2_ArduinoPin, NeoPixel2_Type, &NeoPixelComplete);
NeoPatterns NeoPixel3(NeoPixel3_Count, NeoPixel3_ArduinoPin, NeoPixel3_Type, &NeoPixelComplete);

class NeoPixelAnimation {
  public:
  int Position;
  int Position_Memory;
  int RangeBegin;
  int RangeEnd;
  int Running;
};
NeoPixelAnimation NeoPixel1A_Animation;
NeoPixelAnimation NeoPixel1B_Animation;
NeoPixelAnimation NeoPixel2_Animation;
NeoPixelAnimation NeoPixel3_Animation;

class PanelDueMessage {
  public:
  char Status;
  float ActTempHeatbed;
  float ActTempHotend1;
  float ActTempHotend2;
  float ActiveTempHeatbed;
  float ActiveTempHotend1;
  float ActiveTempHotend2;
  float StandbyTempHeatbed;
  float StandbyTempHotend1;
  float StandbyTempHotend2;
  int HeaterStatusHeatbed;
  int HeaterStatusHotend1;
  int HeaterStatusHotend2;
  float FractionPrinted;
  bool UpdatePending;
};
PanelDueMessage Printer;
#if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL1_ACTIVE)
  PanelDueMessage DebugPrinter;
#endif

static int ConvertPosition2PixelIndex(int PixelCount, int PixelOffset, int Position) {
  if ((PixelCount - Position)+(PixelOffset * -1) >= PixelCount){
    return (((PixelCount - Position) + (PixelOffset * -1)) - PixelCount);
  }
  else{
    if ((PixelCount - Position) + (PixelOffset * -1) >= 0) {
      return ((PixelCount - Position) + (PixelOffset * -1));
    }
    else{
      return (((PixelCount - Position) + (PixelOffset * -1)) + PixelCount);
    }
  }
}

void AnalyzeSerialMessage() {
  Printer.UpdatePending = false;
  // HeaterStatus 0= Off / 1= Standby / 2= Active / 3= Fault / 4= Tuning
  if (JsonParseRoot(SerialMessage,"status",0) != ""){
	  Printer.Status = JsonParseRoot(SerialMessage,"status",0).charAt(0);
	  Printer.UpdatePending = true;
	}
  if (JsonParseRoot(SerialMessage,"heaters",1) != ""){
	  Printer.ActTempHeatbed = JsonParseRoot(SerialMessage,"heaters",1).toFloat();
	  Printer.UpdatePending = true;
	}
  if (JsonParseRoot(SerialMessage,"heaters",2) != ""){
    Printer.ActTempHotend1 = JsonParseRoot(SerialMessage,"heaters",2).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"heaters",3) != ""){
    Printer.ActTempHotend2 = JsonParseRoot(SerialMessage,"heaters",3).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"active",1) != ""){
    Printer.ActiveTempHeatbed = JsonParseRoot(SerialMessage,"active",1).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"active",2) != ""){
    Printer.ActiveTempHotend1 = JsonParseRoot(SerialMessage,"active",2).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"active",3) != ""){
    Printer.ActiveTempHotend2 = JsonParseRoot(SerialMessage,"active",3).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"standby",1) != ""){
    Printer.StandbyTempHeatbed = JsonParseRoot(SerialMessage,"standby",1).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"standby",2) != ""){
    Printer.StandbyTempHotend1 = JsonParseRoot(SerialMessage,"standby",2).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"standby",3) != ""){
    Printer.StandbyTempHotend2 = JsonParseRoot(SerialMessage,"standby",3).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"hstat",1) != ""){
    Printer.HeaterStatusHeatbed = JsonParseRoot(SerialMessage,"hstat",1).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"hstat",2) != ""){
    Printer.HeaterStatusHotend1 = JsonParseRoot(SerialMessage,"hstat",2).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"hstat",3) != ""){
    Printer.HeaterStatusHotend2 = JsonParseRoot(SerialMessage,"hstat",3).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"fraction_printed",0) != ""){
	  Printer.FractionPrinted = JsonParseRoot(SerialMessage,"fraction_printed",0).toFloat();
	  Printer.UpdatePending = true;
	}
  #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL2_ACTIVE)
  	if (Printer.UpdatePending == true){
 		  Serial.println("StatusUpdate: Status= "+String(Printer.Status)+" / ActualTHb= "+Printer.ActTempHeatbed+" / ActualTHe1= "+Printer.ActTempHotend1+" / ActualTHe2= "+Printer.ActTempHotend2+" / ActiveTHb= "+Printer.ActiveTempHeatbed+" / ActiveTHe1= "+Printer.ActiveTempHotend1+" / ActiveTHe2= "+Printer.ActiveTempHotend2+" / StandbyTHb= "+Printer.StandbyTempHeatbed+" / StandbyTHe1= "+Printer.StandbyTempHotend1+" / StandbyTHe2= "+Printer.StandbyTempHotend2+" / StatusHb= "+Printer.HeaterStatusHeatbed+" / StatusHe1= "+Printer.HeaterStatusHotend1+" / StatusHe2= "+Printer.HeaterStatusHotend2+" / PrintProgress= "+Printer.FractionPrinted);
  	}
  	else{
//  		  Serial.println("Error: JsonObjectValue");
    }
  #endif 
}


// Example-Json-Message: {"status":"I","heaters":[31.5,28.1],"active":[0.0,0.0],"standby":[0.0,0.0],"hstat":[0,0],"pos":[0.000,0.000,0.000],"machine":[0.000,0.000,0.000],"sfactor":100.00,"efactor":[100.00],"babystep":0.000,"tool":-1,"probe":"0","fanPercent":[0.0,0.0,100.0,100.0,0.0,0.0,0.0,0.0,0.0,0.0],"fanRPM":0,"homed":[0,0,0],"msgBox.mode":-1,"geometry":"coreXY","axes":3,"totalAxes":3,"axisNames":"XYZ","volumes":2,"numTools":1,"myName":"BLV mgn Cube","firmwareName":"RepRapFirmware for Duet 2 WiFi/Ethernet"}
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

  //Default start values for animations
  NeoPixel1A_Animation.Position = 0;
  NeoPixel1A_Animation.Position_Memory = 0;
  NeoPixel1A_Animation.RangeBegin = 0;
  NeoPixel1A_Animation.RangeEnd = 0;
  NeoPixel1A_Animation.Running = false;

  NeoPixel1B_Animation.Position = 0;
  NeoPixel1B_Animation.Position_Memory = 0;
  NeoPixel1B_Animation.RangeBegin = 0;
  NeoPixel1B_Animation.RangeEnd = 0;
  NeoPixel1B_Animation.Running = false;
  
  NeoPixel2_Animation.Position = 0;
  NeoPixel2_Animation.Position_Memory = 0;
  NeoPixel2_Animation.RangeBegin = 0;
  NeoPixel2_Animation.RangeEnd = 0;
  NeoPixel2_Animation.Running = false;
  
  NeoPixel3_Animation.Position = 0;
  NeoPixel3_Animation.Position_Memory = 0;
  NeoPixel3_Animation.RangeBegin = 0;
  NeoPixel3_Animation.RangeEnd = 0;
  NeoPixel3_Animation.Running = false;

  Printer.Status = ' ';
  Printer.ActTempHeatbed = 0.0;
  Printer.ActTempHotend1 = 0.0;
  Printer.ActTempHotend2 = 0.0;
  Printer.ActiveTempHeatbed = 0.0;
  Printer.ActiveTempHotend1 = 0.0;
  Printer.ActiveTempHotend2 = 0.0;
  Printer.StandbyTempHeatbed = 0.0;
  Printer.StandbyTempHotend1 = 0.0;
  Printer.StandbyTempHotend2 = 0.0;
  Printer.HeaterStatusHeatbed = 0.0;
  Printer.HeaterStatusHotend1 = 0.0;
  Printer.HeaterStatusHotend2 = 0.0;
  Printer.FractionPrinted = 0.0;
  Printer.UpdatePending = false;

  #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL1_ACTIVE)
    DebugPrinter.ActTempHeatbed = 0.0;
    DebugPrinter.ActTempHotend1 = 0.0;
    DebugPrinter.ActTempHotend2 = 0.0;
    DebugPrinter.ActiveTempHeatbed = 0.0;
    DebugPrinter.ActiveTempHotend1 = 0.0;
    DebugPrinter.ActiveTempHotend2 = 0.0;
    DebugPrinter.StandbyTempHeatbed = 0.0;
    DebugPrinter.StandbyTempHotend1 = 0.0;
    DebugPrinter.StandbyTempHotend2 = 0.0;
    DebugPrinter.HeaterStatusHeatbed = 0.0;
    DebugPrinter.HeaterStatusHotend1 = 0.0;
    DebugPrinter.HeaterStatusHotend2 = 0.0;
    DebugPrinter.FractionPrinted = 0.0;
  #endif 

  // Initialize Neopixels
  if (NeoPixel1A_Active == true){
    NeoPixel1A.begin();
    NeoPixel1A.setBrightness(NeoPixel1A_Brightness);
    NeoPixel1A.fill(ConvertColor(0,0,0));
    NeoPixel1A.show();
  }
  if (NeoPixel1B_Active == true){
    NeoPixel1B.begin();
    NeoPixel1B.setBrightness(NeoPixel1B_Brightness);
    NeoPixel1B.fill(ConvertColor(0,0,0));
    NeoPixel1B.show();
  }
  if (NeoPixel2_Active == true){
    NeoPixel2.begin();
    NeoPixel2.setBrightness(NeoPixel2_Brightness);
    NeoPixel2.fill(ConvertColor(0,0,0));
    NeoPixel2.show();
  }
  if (NeoPixel3_Active == true){
    NeoPixel3.begin();
    NeoPixel3.setBrightness(NeoPixel3_Brightness);
    NeoPixel3.fill(ConvertColor(0,0,0));
    NeoPixel3.show();
  }
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
        if (((Printer.ActTempHeatbed > DebugPrinter.ActTempHeatbed) && (Printer.ActTempHeatbed / DebugPrinter.ActTempHeatbed) > 2) || ((Printer.ActTempHeatbed < DebugPrinter.ActTempHeatbed) && (DebugPrinter.ActTempHeatbed / Printer.ActTempHeatbed) > 2)){
          Serial.println("High Delta ActTempHeatbed: Act="+String(Printer.ActTempHeatbed) + " / Memory= "+String(DebugPrinter.ActTempHeatbed));
          Serial.println("SerialMessage= "+SerialMessage);
          Serial.println("");
        }
        if (((Printer.ActTempHotend1 > DebugPrinter.ActTempHotend1) && (Printer.ActTempHotend1 / DebugPrinter.ActTempHotend1) > 2) || ((Printer.ActTempHotend1 < DebugPrinter.ActTempHotend1) && (DebugPrinter.ActTempHotend1 / Printer.ActTempHotend1) > 2)){
           Serial.println("High Delta ActTempHotend: Act="+String(Printer.ActTempHotend1) + " / Memory= "+String(DebugPrinter.ActTempHotend1));
           Serial.println("SerialMessage= "+SerialMessage);
           Serial.println("");
        }
        if (((Printer.ActTempHotend2 > DebugPrinter.ActTempHotend2) && (Printer.ActTempHotend2 / DebugPrinter.ActTempHotend2) > 2) || ((Printer.ActTempHotend2 < DebugPrinter.ActTempHotend2) && (DebugPrinter.ActTempHotend2 / Printer.ActTempHotend2) > 2)){
           Serial.println("High Delta ActTempHotend: Act="+String(Printer.ActTempHotend2) + " / Memory= "+String(DebugPrinter.ActTempHotend2));
           Serial.println("SerialMessage= "+SerialMessage);
           Serial.println("");
        }
        if (((Printer.ActiveTempHeatbed > DebugPrinter.ActiveTempHeatbed) && (Printer.ActiveTempHeatbed / DebugPrinter.ActiveTempHeatbed) > 2) || ((Printer.ActiveTempHeatbed < DebugPrinter.ActiveTempHeatbed) && (DebugPrinter.ActiveTempHeatbed / Printer.ActiveTempHeatbed) > 2)){
          Serial.println("High Delta ActiveTempHeatbed: Act="+String(Printer.ActiveTempHeatbed) + " / Memory= "+String(DebugPrinter.ActiveTempHeatbed));
          Serial.println("SerialMessage= "+SerialMessage);
          Serial.println("");
        }
        if (((Printer.ActiveTempHotend1 > DebugPrinter.ActiveTempHotend1) && (Printer.ActiveTempHotend1 / DebugPrinter.ActiveTempHotend1) > 2) || ((Printer.ActiveTempHotend1 < DebugPrinter.ActiveTempHotend1) && (DebugPrinter.ActiveTempHotend1 / Printer.ActiveTempHotend1) > 2)){
          Serial.println("High Delta ActiveTempHotend: Act="+String(Printer.ActiveTempHotend1) + " / Memory= "+String(DebugPrinter.ActiveTempHotend1));
          Serial.println("SerialMessage= "+SerialMessage);
          Serial.println("");
        }
        if (((Printer.ActiveTempHotend2 > DebugPrinter.ActiveTempHotend2) && (Printer.ActiveTempHotend2 / DebugPrinter.ActiveTempHotend2) > 2) || ((Printer.ActiveTempHotend2 < DebugPrinter.ActiveTempHotend2) && (DebugPrinter.ActiveTempHotend2 / Printer.ActiveTempHotend2) > 2)){
          Serial.println("High Delta ActiveTempHotend: Act="+String(Printer.ActiveTempHotend2) + " / Memory= "+String(DebugPrinter.ActiveTempHotend2));
          Serial.println("SerialMessage= "+SerialMessage);
          Serial.println("");
        }
        if (((Printer.StandbyTempHeatbed > DebugPrinter.StandbyTempHeatbed) && (Printer.StandbyTempHeatbed / DebugPrinter.StandbyTempHeatbed) > 2) || ((Printer.StandbyTempHeatbed < DebugPrinter.StandbyTempHeatbed) && (DebugPrinter.StandbyTempHeatbed / Printer.StandbyTempHeatbed) > 2)){
          Serial.println("High Delta StandbyTempHeatbed: Act="+String(Printer.StandbyTempHeatbed) + " / Memory= "+String(DebugPrinter.StandbyTempHeatbed));
          Serial.println("SerialMessage= "+SerialMessage);
          Serial.println("");
        }
        if (((Printer.StandbyTempHotend1 > DebugPrinter.StandbyTempHotend1) && (Printer.StandbyTempHotend1 / DebugPrinter.StandbyTempHotend1) > 2) || ((Printer.StandbyTempHotend1 < DebugPrinter.StandbyTempHotend1) && (DebugPrinter.StandbyTempHotend1 / Printer.StandbyTempHotend1) > 2)){
          Serial.println("High Delta StandbyTempHotend1: Act="+String(Printer.StandbyTempHotend1) + " / Memory= "+String(DebugPrinter.StandbyTempHotend1));
          Serial.println("SerialMessage= "+SerialMessage);
          Serial.println("");
        }
        if (((Printer.StandbyTempHotend2 > DebugPrinter.StandbyTempHotend2) && (Printer.StandbyTempHotend2 / DebugPrinter.StandbyTempHotend2) > 2) || ((Printer.StandbyTempHotend2 < DebugPrinter.StandbyTempHotend2) && (DebugPrinter.StandbyTempHotend2 / Printer.StandbyTempHotend2) > 2)){
          Serial.println("High Delta StandbyTempHotend2: Act="+String(Printer.StandbyTempHotend2) + " / Memory= "+String(DebugPrinter.StandbyTempHotend2));
          Serial.println("SerialMessage= "+SerialMessage);
          Serial.println("");
        }
        if (((Printer.FractionPrinted > DebugPrinter.FractionPrinted) && (Printer.FractionPrinted / DebugPrinter.FractionPrinted) > 2) || ((Printer.FractionPrinted < DebugPrinter.FractionPrinted) && (DebugPrinter.FractionPrinted / Printer.FractionPrinted) > 2)){
          Serial.println("High Delta FractionPrinted: Act="+String(Printer.FractionPrinted) + " / Memory= "+String(DebugPrinter.FractionPrinted));
          Serial.println("SerialMessage= "+SerialMessage);
          Serial.println("");
        }
        DebugPrinter.ActTempHeatbed = Printer.ActTempHeatbed;
        DebugPrinter.ActTempHotend1 = Printer.ActTempHotend1;
        DebugPrinter.ActTempHotend2 = Printer.ActTempHotend2;
        DebugPrinter.ActiveTempHeatbed = Printer.ActiveTempHeatbed;
        DebugPrinter.ActiveTempHotend1 = Printer.ActiveTempHotend1;
        DebugPrinter.ActiveTempHotend2 = Printer.ActiveTempHotend2;
        DebugPrinter.StandbyTempHeatbed = Printer.StandbyTempHeatbed;
        DebugPrinter.StandbyTempHotend1 = Printer.StandbyTempHotend1;
        DebugPrinter.StandbyTempHotend2 = Printer.StandbyTempHotend2;
        DebugPrinter.FractionPrinted = Printer.FractionPrinted;
      #endif 
      
      //Update Neopixel Hotend1A
      if (NeoPixel1A_Active == true){
        //Initialize AnimationRange
        NeoPixel1A_Animation.RangeBegin = 0;
        NeoPixel1A_Animation.RangeEnd = 0;

        SetTempHotend=0;
        ActTempHotend=0;
        if (NeoPixel1A_Hotend1 == true){
          if (Printer.HeaterStatusHotend1 == 2){
            SetTempHotend=Printer.ActiveTempHotend1;
            ActTempHotend=Printer.ActTempHotend1;
          }
          else if (Printer.HeaterStatusHotend1 == 1){
            SetTempHotend=Printer.StandbyTempHotend1;
            ActTempHotend=Printer.ActTempHotend1;
          }
          else if (Printer.HeaterStatusHotend1 == 0){
            if (NeoPixel1A_Hotend2 == true){
              if (Printer.HeaterStatusHotend2 == 2){
                SetTempHotend=Printer.ActiveTempHotend2;
                ActTempHotend=Printer.ActTempHotend2;
              }
              else if (Printer.HeaterStatusHotend2 == 1){
                SetTempHotend=Printer.StandbyTempHotend2;
                ActTempHotend=Printer.ActTempHotend2;
              }
              else if (Printer.HeaterStatusHotend2 == 0){
				ActTempHotend=Printer.ActTempHotend1;
			  }
			  
            }  
          }  
        }
        else if (NeoPixel1A_Hotend2 == true)
        {
          if (Printer.HeaterStatusHotend2 == 2)
          {
            SetTempHotend=Printer.ActiveTempHotend2;
            ActTempHotend=Printer.ActTempHotend2;
          }
          else if (Printer.HeaterStatusHotend2 == 1){
            SetTempHotend=Printer.StandbyTempHotend2;
            ActTempHotend=Printer.ActTempHotend2;
		  }
          else if (Printer.HeaterStatusHotend2 == 0){
            ActTempHotend=Printer.ActTempHotend2;
          }
        }  
  
        for (int NeoPixelPosition = 1; NeoPixelPosition <= NeoPixel1A_Count; NeoPixelPosition++)
        {
          if((((ActTempHotend - NeoPixel1A_TempOffset) / NeoPixel1A_Scale) < NeoPixelPosition) && (((SetTempHotend - NeoPixel1A_TempOffset) / NeoPixel1A_Scale) >= NeoPixelPosition)){
            NeoPixel1A.setPixelColor(ConvertPosition2PixelIndex(NeoPixel1A_Count,NeoPixel1A_PixelOffset,NeoPixelPosition),NeoPixel1A_ColorHeatUp);
            //Define Animation-Range
            if (NeoPixel1A_Animation.RangeBegin == 0) {
              NeoPixel1A_Animation.RangeBegin = NeoPixelPosition;
              NeoPixel1A_Animation.RangeEnd = NeoPixelPosition;
            } else {
              NeoPixel1A_Animation.RangeEnd++;
            }
          }
          else if((((ActTempHotend - NeoPixel1A_TempOffset) / NeoPixel1A_Scale) >= NeoPixelPosition) && (((SetTempHotend - NeoPixel1A_TempOffset) / NeoPixel1A_Scale) >= NeoPixelPosition)){
            NeoPixel1A.setPixelColor(ConvertPosition2PixelIndex(NeoPixel1A_Count,NeoPixel1A_PixelOffset,NeoPixelPosition),NeoPixel1A_ColorHeatUpDone);
          }
          else if((((ActTempHotend - NeoPixel1A_TempOffset) / NeoPixel1A_Scale) >= NeoPixelPosition) && (((SetTempHotend - NeoPixel1A_TempOffset) / NeoPixel1A_Scale) < NeoPixelPosition)){
            NeoPixel1A.setPixelColor(ConvertPosition2PixelIndex(NeoPixel1A_Count,NeoPixel1A_PixelOffset,NeoPixelPosition),NeoPixel1A_ColorCoolDown);
          }
          else{
            NeoPixel1A.setPixelColor(ConvertPosition2PixelIndex(NeoPixel1A_Count,NeoPixel1A_PixelOffset,NeoPixelPosition),NeoPixel1A_ColorIdle);
          }
        }
      }

      //Update Neopixel Hotend1B
      if (NeoPixel1B_Active == true){
        //Initialize AnimationRange
        NeoPixel1B_Animation.RangeBegin = 0;
        NeoPixel1B_Animation.RangeEnd = 0;
  
        SetTempHotend=0;
        ActTempHotend=0;
        if (NeoPixel1B_Hotend1 == true){
          if (Printer.HeaterStatusHotend1 == 2){
            SetTempHotend=Printer.ActiveTempHotend1;
            ActTempHotend=Printer.ActTempHotend1;
          }
          else if (Printer.HeaterStatusHotend1 == 1){
            SetTempHotend=Printer.StandbyTempHotend1;
            ActTempHotend=Printer.ActTempHotend1;
          }
          else if (Printer.HeaterStatusHotend1 == 0){
            if (NeoPixel1B_Hotend2 == true){
              if (Printer.HeaterStatusHotend2 == 2)
              {
                SetTempHotend=Printer.ActiveTempHotend2;
                ActTempHotend=Printer.ActTempHotend2;
              }
              else if (Printer.HeaterStatusHotend2 == 1){
                SetTempHotend=Printer.StandbyTempHotend2;
                ActTempHotend=Printer.ActTempHotend2;
              }
              else if (Printer.HeaterStatusHotend2 == 0){
				ActTempHotend=Printer.ActTempHotend1;
			  }
            }
          }    
        }
        else if (NeoPixel1B_Hotend2 == true){
          if (Printer.HeaterStatusHotend2 == 2){
            SetTempHotend=Printer.ActiveTempHotend2;
            ActTempHotend=Printer.ActTempHotend2;
          }
          else if (Printer.HeaterStatusHotend2 == 1){
            SetTempHotend=Printer.StandbyTempHotend2;
            ActTempHotend=Printer.ActTempHotend2;
          }
          else if (Printer.HeaterStatusHotend2 == 0){
            ActTempHotend=Printer.ActTempHotend2;
          }
        }  

        for (int NeoPixelPosition = 1; NeoPixelPosition <= NeoPixel1B_Count; NeoPixelPosition++)
        {
          if((((ActTempHotend - NeoPixel1B_TempOffset) / NeoPixel1B_Scale) < NeoPixelPosition) && (((SetTempHotend - NeoPixel1B_TempOffset) / NeoPixel1B_Scale) >= NeoPixelPosition)){
            NeoPixel1B.setPixelColor(ConvertPosition2PixelIndex(NeoPixel1B_Count,NeoPixel1B_PixelOffset,NeoPixelPosition),NeoPixel1B_ColorHeatUp);
            //Define Animation-Range
            if (NeoPixel1B_Animation.RangeBegin == 0) {
              NeoPixel1B_Animation.RangeBegin = NeoPixelPosition;
              NeoPixel1B_Animation.RangeEnd = NeoPixelPosition;
            } else {
              NeoPixel1B_Animation.RangeEnd++;
            }
          }
          else if((((ActTempHotend - NeoPixel1B_TempOffset) / NeoPixel1B_Scale) >= NeoPixelPosition) && (((SetTempHotend - NeoPixel1B_TempOffset) / NeoPixel1B_Scale) >= NeoPixelPosition)){
            NeoPixel1B.setPixelColor(ConvertPosition2PixelIndex(NeoPixel1B_Count,NeoPixel1B_PixelOffset,NeoPixelPosition),NeoPixel1B_ColorHeatUpDone);
          }
          else if((((ActTempHotend - NeoPixel1B_TempOffset) / NeoPixel1B_Scale) >= NeoPixelPosition) && (((SetTempHotend - NeoPixel1B_TempOffset) / NeoPixel1B_Scale) < NeoPixelPosition)){
            NeoPixel1B.setPixelColor(ConvertPosition2PixelIndex(NeoPixel1B_Count,NeoPixel1B_PixelOffset,NeoPixelPosition),NeoPixel1B_ColorCoolDown);
          }
          else{
            NeoPixel1B.setPixelColor(ConvertPosition2PixelIndex(NeoPixel1B_Count,NeoPixel1B_PixelOffset,NeoPixelPosition),NeoPixel1B_ColorIdle);
          }
        }
      }
        
      //Update Neopixel PrinterStatus
      if (NeoPixel2_Active == true){
        //Initialize AnimationRange Hotend
        NeoPixel2_Animation.RangeBegin = 0;
        NeoPixel2_Animation.RangeEnd = 0;
  
        //NeoPixel: Printer-Status & Print-Progress
        if(Printer.Status == 'P'){ 
          //Display Print-Progress
          for (int NeoPixelPosition = 1; NeoPixelPosition <= NeoPixel2_Count; NeoPixelPosition++)
          {
            if(NeoPixelPosition < (Printer.FractionPrinted * NeoPixel2_Count)){
              NeoPixel2.setPixelColor(ConvertPosition2PixelIndex(NeoPixel2_Count,NeoPixel2_PixelOffset,NeoPixelPosition),NeoPixel2_ColorPrintingDone);
            }
            else{
              NeoPixel2.setPixelColor(ConvertPosition2PixelIndex(NeoPixel2_Count,NeoPixel2_PixelOffset,NeoPixelPosition),NeoPixel2_ColorPrinting);
              //Define Animation-Range
              if (NeoPixel2_Animation.RangeBegin == 0) {
                NeoPixel2_Animation.RangeBegin = NeoPixelPosition;
                NeoPixel2_Animation.RangeEnd = NeoPixelPosition;
              } else {
                NeoPixel2_Animation.RangeEnd++;
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
              NeoPixel2.fill(NeoPixel2_ColorIdle);
              break;
            case 'P':
              NeoPixel2.fill(NeoPixel2_ColorPrinting);
              break;
            case 'S':
              NeoPixel2.fill(NeoPixel2_ColorStopped);
              break;
            case 'C':
              NeoPixel2.fill(NeoPixel2_ColorConfiguring);
              break;
            case 'A':
              NeoPixel2.fill(NeoPixel2_ColorPaused);
              break;
            case 'D':
              NeoPixel2.fill(NeoPixel2_ColorBusy);
              break;
            case 'R':
              NeoPixel2.fill(NeoPixel2_ColorPausing);
              break;
            case 'B':
              NeoPixel2.fill(NeoPixel2_ColorResuming);
              break;
            case 'F':
              NeoPixel2.fill(NeoPixel2_ColorFlashing);
              break;
            default:
              NeoPixel2.fill(NeoPixel2_ColorDefault);
              break;
          }
        }
      }    
  
      //Update Neopixel Heatbed
      if (NeoPixel3_Active == true){
        //Initialize AnimationRange
        NeoPixel3_Animation.RangeBegin = 0;
        NeoPixel3_Animation.RangeEnd = 0;
  
        //NeoPixel: Bed-Temperature   
        SetTempHeatbed=0;
        if (Printer.HeaterStatusHeatbed == 2)
        {
          SetTempHeatbed=Printer.ActiveTempHeatbed;
        }
        else if (Printer.HeaterStatusHeatbed == 1){
          SetTempHeatbed=Printer.StandbyTempHeatbed;
        }
        for (int NeoPixelPosition = 1; NeoPixelPosition <= NeoPixel3_Count; NeoPixelPosition++)
        {
          if((((Printer.ActTempHeatbed - NeoPixel3_TempOffset) / NeoPixel3_Scale) < NeoPixelPosition) && (((SetTempHeatbed - NeoPixel3_TempOffset) / NeoPixel3_Scale) >= NeoPixelPosition)){
            NeoPixel3.setPixelColor(ConvertPosition2PixelIndex(NeoPixel3_Count,NeoPixel3_PixelOffset,NeoPixelPosition),NeoPixel3_ColorHeatUp);
            //Define Animation-Range
            if (NeoPixel3_Animation.RangeBegin == 0) {
              NeoPixel3_Animation.RangeBegin = NeoPixelPosition;
              NeoPixel3_Animation.RangeEnd = NeoPixelPosition;
            } else {
              NeoPixel3_Animation.RangeEnd++;
            }
          }
          else if((((Printer.ActTempHeatbed - NeoPixel3_TempOffset) / NeoPixel3_Scale) >= NeoPixelPosition) && (((SetTempHeatbed - NeoPixel3_TempOffset) / NeoPixel3_Scale) >= NeoPixelPosition)){
            NeoPixel3.setPixelColor(ConvertPosition2PixelIndex(NeoPixel3_Count,NeoPixel3_PixelOffset,NeoPixelPosition),NeoPixel3_ColorHeatUpDone);
          }
          else if((((Printer.ActTempHeatbed - NeoPixel3_TempOffset) / NeoPixel3_Scale) >= NeoPixelPosition) && (((SetTempHeatbed - NeoPixel3_TempOffset) / NeoPixel3_Scale) < NeoPixelPosition)){
            NeoPixel3.setPixelColor(ConvertPosition2PixelIndex(NeoPixel3_Count,NeoPixel3_PixelOffset,NeoPixelPosition),NeoPixel3_ColorCoolDown);
          }
          else{
            NeoPixel3.setPixelColor(ConvertPosition2PixelIndex(NeoPixel3_Count,NeoPixel3_PixelOffset,NeoPixelPosition),NeoPixel3_ColorIdle);
          }
        }
      }
    }  

    //Animation Hotend1
    if (NeoPixel1A_AnimationActive == true){
      //AnimationRange exists?
      if (NeoPixel1A_Animation.RangeBegin == 0){
        NeoPixel1A_Animation.Running = false;
      }
      else{
        //Animation initialize?
        if (NeoPixel1A_Animation.Running == false){
            NeoPixel1A_Animation.Running = true;
            NeoPixel1A_Animation.Position = NeoPixel1A_Animation.RangeBegin;
            NeoPixel1A_Animation.Position_Memory = 0;
        }
        //Restart animation at new position?
        if (NeoPixel1A_Animation.Position < NeoPixel1A_Animation.RangeBegin){
          NeoPixel1A_Animation.Position = NeoPixel1A_Animation.RangeBegin;
        }
        if (NeoPixel1A_Animation.Position_Memory != NeoPixel1A_Animation.Position && NeoPixel1A_Animation.Position_Memory >= NeoPixel1A_Animation.RangeBegin){
          NeoPixel1A.setPixelColor(ConvertPosition2PixelIndex(NeoPixel1A_Count,NeoPixel1A_PixelOffset,NeoPixel1A_Animation.Position_Memory),NeoPixel1A_ColorHeatUp);
        }
        if (NeoPixel1A.getPixelColor(ConvertPosition2PixelIndex(NeoPixel1A_Count,NeoPixel1A_PixelOffset,NeoPixel1A_Animation.Position)) == NeoPixel1A_ColorAnimation){
            NeoPixel1A.setPixelColor(ConvertPosition2PixelIndex(NeoPixel1A_Count,NeoPixel1A_PixelOffset,NeoPixel1A_Animation.Position),NeoPixel1A_ColorHeatUp);
        }
        else{
          NeoPixel1A_Animation.Position_Memory = NeoPixel1A_Animation.Position;
          NeoPixel1A.setPixelColor(ConvertPosition2PixelIndex(NeoPixel1A_Count,NeoPixel1A_PixelOffset,NeoPixel1A_Animation.Position),NeoPixel1A_ColorAnimation);
        }
        NeoPixel1A_Animation.Position++;
        if (NeoPixel1A_Animation.Position > NeoPixel1A_Animation.RangeEnd){
          NeoPixel1A_Animation.Position = NeoPixel1A_Animation.RangeBegin;
        }
      }
    }

    //Animation Hotend2
    if (NeoPixel1B_AnimationActive == true){
      //AnimationRange exists?
      if (NeoPixel1B_Animation.RangeBegin == 0){
        NeoPixel1B_Animation.Running = false;
      }
      else{
        //Animation initialize?
        if (NeoPixel1B_Animation.Running == false){
            NeoPixel1B_Animation.Running = true;
            NeoPixel1B_Animation.Position = NeoPixel1B_Animation.RangeBegin;
            NeoPixel1B_Animation.Position_Memory = 0;
        }
        //Restart animation at new position?
        if (NeoPixel1B_Animation.Position < NeoPixel1B_Animation.RangeBegin){
          NeoPixel1B_Animation.Position = NeoPixel1B_Animation.RangeBegin;
        }
        if (NeoPixel1B_Animation.Position_Memory != NeoPixel1B_Animation.Position && NeoPixel1B_Animation.Position_Memory >= NeoPixel1B_Animation.RangeBegin){
          NeoPixel1B.setPixelColor(ConvertPosition2PixelIndex(NeoPixel1B_Count,NeoPixel1B_PixelOffset,NeoPixel1B_Animation.Position_Memory),NeoPixel1B_ColorHeatUp);
        }
        if (NeoPixel1B.getPixelColor(ConvertPosition2PixelIndex(NeoPixel1B_Count,NeoPixel1B_PixelOffset,NeoPixel1B_Animation.Position)) == NeoPixel1B_ColorAnimation){
            NeoPixel1B.setPixelColor(ConvertPosition2PixelIndex(NeoPixel1B_Count,NeoPixel1B_PixelOffset,NeoPixel1B_Animation.Position),NeoPixel1B_ColorHeatUp);
        }
        else{
          NeoPixel1B_Animation.Position_Memory = NeoPixel1B_Animation.Position;
          NeoPixel1B.setPixelColor(ConvertPosition2PixelIndex(NeoPixel1B_Count,NeoPixel1B_PixelOffset,NeoPixel1B_Animation.Position),NeoPixel1B_ColorAnimation);
        }
        NeoPixel1B_Animation.Position++;
        if (NeoPixel1B_Animation.Position > NeoPixel1B_Animation.RangeEnd){
          NeoPixel1B_Animation.Position = NeoPixel1B_Animation.RangeBegin;
        }
      }
    }

    //Animation PrinterStatus
    if (NeoPixel2_AnimationActive == true){
      //AnimationRange exists?
      if (NeoPixel2_Animation.RangeBegin == 0){
        NeoPixel2_Animation.Running = false;
      }
      else{
        //Animation initialize?
        if (NeoPixel2_Animation.Running == false){
            NeoPixel2_Animation.Running = true;
            NeoPixel2_Animation.Position = NeoPixel2_Animation.RangeBegin;
            NeoPixel2_Animation.Position_Memory = 0;
        }
        //Restart animation at new position?
        if (NeoPixel2_Animation.Position < NeoPixel2_Animation.RangeBegin){
          NeoPixel2_Animation.Position = NeoPixel2_Animation.RangeBegin;
        }
        if (NeoPixel2_Animation.Position_Memory != NeoPixel2_Animation.Position && NeoPixel2_Animation.Position_Memory >= NeoPixel2_Animation.RangeBegin){
          NeoPixel2.setPixelColor(ConvertPosition2PixelIndex(NeoPixel2_Count,NeoPixel2_PixelOffset,NeoPixel2_Animation.Position_Memory),NeoPixel2_ColorPrinting);
        }
        if (NeoPixel2.getPixelColor(ConvertPosition2PixelIndex(NeoPixel2_Count,NeoPixel2_PixelOffset,NeoPixel2_Animation.Position)) == NeoPixel2_ColorAnimation){
            NeoPixel2.setPixelColor(ConvertPosition2PixelIndex(NeoPixel2_Count,NeoPixel2_PixelOffset,NeoPixel2_Animation.Position),NeoPixel2_ColorPrinting);
        }
        else{
          NeoPixel2_Animation.Position_Memory = NeoPixel2_Animation.Position;
          NeoPixel2.setPixelColor(ConvertPosition2PixelIndex(NeoPixel2_Count,NeoPixel2_PixelOffset,NeoPixel2_Animation.Position),NeoPixel2_ColorAnimation);
        }
        NeoPixel2_Animation.Position++;
        if (NeoPixel2_Animation.Position > NeoPixel2_Animation.RangeEnd){
          NeoPixel2_Animation.Position = NeoPixel2_Animation.RangeBegin;
        }
      }
    }
            
    //Animation Heatbed
    if (NeoPixel3_AnimationActive == true){
      //AnimationRange exists?
      if (NeoPixel3_Animation.RangeBegin == 0){
        NeoPixel3_Animation.Running = false;
      }
      else{
        //Animation initialize?
        if (NeoPixel3_Animation.Running == false){
            NeoPixel3_Animation.Running = true;
            NeoPixel3_Animation.Position = NeoPixel3_Animation.RangeBegin;
            NeoPixel3_Animation.Position_Memory = 0;
        }
        //Restart animation at new position?
        if (NeoPixel3_Animation.Position < NeoPixel3_Animation.RangeBegin){
          NeoPixel3_Animation.Position = NeoPixel3_Animation.RangeBegin;
        }
        if (NeoPixel3_Animation.Position_Memory != NeoPixel3_Animation.Position && NeoPixel3_Animation.Position_Memory >= NeoPixel3_Animation.RangeBegin){
          NeoPixel3.setPixelColor(ConvertPosition2PixelIndex(NeoPixel3_Count,NeoPixel3_PixelOffset,NeoPixel3_Animation.Position_Memory),NeoPixel3_ColorHeatUp);
        }
        if (NeoPixel3.getPixelColor(ConvertPosition2PixelIndex(NeoPixel3_Count,NeoPixel3_PixelOffset,NeoPixel3_Animation.Position)) == NeoPixel3_ColorAnimation){
            NeoPixel3.setPixelColor(ConvertPosition2PixelIndex(NeoPixel3_Count,NeoPixel3_PixelOffset,NeoPixel3_Animation.Position),NeoPixel3_ColorHeatUp);
        }
        else{
          NeoPixel3_Animation.Position_Memory = NeoPixel3_Animation.Position;
          NeoPixel3.setPixelColor(ConvertPosition2PixelIndex(NeoPixel3_Count,NeoPixel3_PixelOffset,NeoPixel3_Animation.Position),NeoPixel3_ColorAnimation);
        }
        NeoPixel3_Animation.Position++;
        if (NeoPixel3_Animation.Position > NeoPixel3_Animation.RangeEnd){
          NeoPixel3_Animation.Position = NeoPixel3_Animation.RangeBegin;
        }
      }
    }

    //Neopixel refresh
    if (NeoPixel1A_Active == true){
      NeoPixel1A.show();
    }  
    if (NeoPixel1B_Active == true){
      NeoPixel1B.show();
    }  
    if (NeoPixel2_Active == true){
      NeoPixel2.show();   
    }   
    if (NeoPixel3_Active == true){
      NeoPixel3.show();
    }  
  }
}
