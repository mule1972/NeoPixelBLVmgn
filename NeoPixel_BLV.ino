#include <Adafruit_NeoPixel.h>

//#define DEBUGLEVEL1_ACTIVE
//#define DEBUGLEVEL2_ACTIVE

static uint32_t  ConvertColor(uint8_t red, uint8_t green, uint8_t blue) {
  return ((uint32_t)red << 16) | ((uint32_t)green <<  8) | blue;
}

// ***************************************
// ********** User-Config Begin **********

//Hotend
bool NeoPixelTempHotendActive= true; //NeoPixel showing the hotend temperature (true = activated / false = deactivated)
neoPixelType NeoPixelTempHotendType= NEO_GRB + NEO_KHZ800; //Neopixel type (do not change if using NeoPixel from the BOM)
uint16_t NeoPixelTempHotendCount= 16; //Count of Neopixel-LEDs (do not change if using Neopixel from the BOM)
uint8_t NeoPixeTempHotendArduinoPin= 6; //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
int NeoPixelTempHotendPixelOffset= 0; //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
int NeoPixelTempHotendTempOffset= 0; //Minimum Temperature at which the first LED lights up
int NeoPixelTempHotendScale= 20; //Temperature steps at which the following LEDs light up
bool NeoPixelTempHotendAnimationActive= true; //Animation when the Hotend heats up (true = activated / false = deactivated)
uint8_t NeopixelTempHotendBrightness= 8; //Overall brightness of the Neopixel-LEDs
uint32_t NeoPixelTempHotendColorIdle= ConvertColor(255,255,255); //RGB values for specified status
uint32_t NeoPixelTempHotendColorHeatUp= ConvertColor(255,64,64); //RGB values for specified status
uint32_t NeoPixelTempHotendColorHeatUpDone= ConvertColor(255,0,0); //RGB values for specified status
uint32_t NeoPixelTempHotendColorCoolDown= ConvertColor(0,0,255); //RGB values for specified status
uint32_t NeoPixelTempHotendColorAnimation= ConvertColor(0,0,0); //RGB values for specified status

//Printer status
bool NeoPixelPrinterStatActive= true; //NeoPixel showing the printer status (true = activated / false = deactivated)
neoPixelType NeoPixelPrinterStatType= NEO_GRB + NEO_KHZ800; //Neopixel type (do not change if using NeoPixel from the BOM)
uint16_t NeoPixelPrinterStatCount= 16; //Count of NeoPixel-LEDs (do not change if using Neopixel from the BOM)
uint8_t NeoPixePrinterStatArduinoPin= 7; //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
int NeoPixelPrinterStatPixelOffset= 0; //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the startpoint clockwise (positive offset) or anti-clockwise (negative offset).
bool NeoPixelPrinterStatAnimationActive= true; ///Animation for print progress (true = activated / false = deactivated)
uint8_t NeopixelTempPrinterStatBrightness= 8; //Overall brightness of the Neopixel-LEDs
uint32_t NeoPixelPrinterStatColorIdle= ConvertColor(255,255,255); //RGB values for specified status
uint32_t NeoPixelPrinterStatColorPrinting= ConvertColor(64,255,64); //RGB values for specified status
uint32_t NeoPixelPrinterStatColorPrintingDone= ConvertColor(0,255,0); //RGB values for specified status
uint32_t NeoPixelPrinterStatColorStopped= ConvertColor(0,0,255); //RGB values for specified status
uint32_t NeoPixelPrinterStatColorConfiguring= ConvertColor(255,255,0); //RGB values for specified status
uint32_t NeoPixelPrinterStatColorPaused= ConvertColor(160,32,240); //RGB values for specified status
uint32_t NeoPixelPrinterStatColorBusy= ConvertColor(255,255,0); //RGB values for specified status
uint32_t NeoPixelPrinterStatColorPausing= ConvertColor(160,32,240); //RGB values for specified status
uint32_t NeoPixelPrinterStatColorResuming= ConvertColor(255,255,0); //RGB values for specified status
uint32_t NeoPixelPrinterStatColorFlashing= ConvertColor(255,255,0); //RGB values for specified status
uint32_t NeoPixelPrinterStatColorDefault= ConvertColor(255,255,255); //RGB values for specified status
uint32_t NeoPixelPrinterStatColorAnimation= ConvertColor(0,0,0); //RGB values for specified status

//Heatbed
bool NeoPixelTempHeatbedActive= true; //NeoPixel showing the heatbed temperature (true = activated / false = deactivated)
neoPixelType NeoPixelTempHeatbedType= NEO_GRB + NEO_KHZ800; //Neopixel type (do not change if using NeoPixel from the BOM)
uint16_t NeoPixelTempHeatbedCount= 16; //Count of NeoPixel-LEDs (do not change if using Neopixel from the BOM)
uint8_t NeoPixeTempHeatbedArduinoPin= 8; //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
int NeoPixelTempHeatbedPixelOffset= 0; //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
int NeoPixelTempHeatbedTempOffset= 0; //Minimum Temperature at which the first LED lights up
int NeoPixelTempHeatbedScale= 10; //Temperature steps at which the following LEDs light up
bool NeoPixelTempHeatbedAnimationActive= true; //Animation when the Heatbed heats up (true = activated / false = deactivated)
uint8_t NeopixelTempHeatbedBrightness= 8; //Overall brightness of the Neopixel-LEDs
uint32_t NeoPixelTempHeatbedColorIdle= ConvertColor(255,255,255); //RGB values for specified status
uint32_t NeoPixelTempHeatbedColorHeatUp= ConvertColor(255,64,64); //RGB values for specified status
uint32_t NeoPixelTempHeatbedColorHeatUpDone= ConvertColor(255,0,0); //RGB values for specified status
uint32_t NeoPixelTempHeatbedColorCoolDown= ConvertColor(0,0,255); //RGB values for specified status
uint32_t NeoPixelTempHeatbedColorAnimation= ConvertColor(0,0,0); //RGB values for specified status

// ********** User-Config End **********
// *************************************


// Initialize global variables
unsigned long SerialTimeout= 100;
unsigned long NeopixelRefreshSpeed= 200;
unsigned long NeoPixelTimerRefresh = millis();

String SerialMessage;
bool SerialMessageComplete = false;

int SetTempHotend=0;
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

NeoPatterns NeoPixelTempHotend(NeoPixelTempHotendCount, NeoPixeTempHotendArduinoPin, NeoPixelTempHotendType, &NeoPixelComplete);
NeoPatterns NeoPixelPrinterStat(NeoPixelPrinterStatCount, NeoPixePrinterStatArduinoPin, NeoPixelPrinterStatType, &NeoPixelComplete);
NeoPatterns NeoPixelTempHeatbed(NeoPixelTempHeatbedCount, NeoPixeTempHeatbedArduinoPin, NeoPixelTempHeatbedType, &NeoPixelComplete);

class NeoPixelAnimation {
  public:
  int Position;
  int Position_Memory;
  int RangeBegin;
  int RangeEnd;
  int Running;
};
NeoPixelAnimation NeoPixelTempHotendAnimation;
NeoPixelAnimation NeoPixelPrinterStatAnimation;
NeoPixelAnimation NeoPixelTempHeatbedAnimation;

class PanelDueMessage {
  public:
  char Status;
  float ActTempHeatbed;
  float ActTempHotend;
  float ActiveTempHeatbed;
  float ActiveTempHotend;
  float StandbyTempHeatbed;
  float StandbyTempHotend;
  int HeaterStatusHeatbed;
  int HeaterStatusHotend;
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
  if (JsonParseRoot(SerialMessage,"status",0) != ""){
	  Printer.Status = JsonParseRoot(SerialMessage,"status",0).charAt(0);
	  Printer.UpdatePending = true;
	}
  if (JsonParseRoot(SerialMessage,"heaters",1) != ""){
	  Printer.ActTempHeatbed = JsonParseRoot(SerialMessage,"heaters",1).toFloat();
	  Printer.UpdatePending = true;
	}
  if (JsonParseRoot(SerialMessage,"heaters",2) != ""){
    Printer.ActTempHotend = JsonParseRoot(SerialMessage,"heaters",2).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"active",1) != ""){
    Printer.ActiveTempHeatbed = JsonParseRoot(SerialMessage,"active",1).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"active",2) != ""){
    Printer.ActiveTempHotend = JsonParseRoot(SerialMessage,"active",2).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"standby",1) != ""){
    Printer.StandbyTempHeatbed = JsonParseRoot(SerialMessage,"standby",1).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"standby",2) != ""){
    Printer.StandbyTempHotend = JsonParseRoot(SerialMessage,"standby",2).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"hstat",1) != ""){
    Printer.HeaterStatusHeatbed = JsonParseRoot(SerialMessage,"hstat",1).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"hstat",2) != ""){
    Printer.HeaterStatusHotend = JsonParseRoot(SerialMessage,"hstat",2).toFloat();
    Printer.UpdatePending = true;
  }
  if (JsonParseRoot(SerialMessage,"fraction_printed",0) != ""){
	  Printer.FractionPrinted = JsonParseRoot(SerialMessage,"fraction_printed",0).toFloat();
	  Printer.UpdatePending = true;
	}
  #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL2_ACTIVE)
  	if (Printer.UpdatePending == true){
 		  Serial.println("StatusUpdate: Status= "+String(Printer.Status)+" / ActualTHb= "+Printer.ActTempHeatbed+" / ActualTHe= "+Printer.ActTempHotend+" / ActiveTHb= "+Printer.ActiveTempHeatbed+" / ActiveTHe= "+Printer.ActiveTempHotend+" / StandbyTHb= "+Printer.StandbyTempHeatbed+" / StandbyTHe= "+Printer.StandbyTempHotend+" / StatusHb= "+Printer.HeaterStatusHeatbed+" / StatusHe= "+Printer.HeaterStatusHotend+" / PrintProgress= "+Printer.FractionPrinted);
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
  NeoPixelTempHotendAnimation.Position = 0;
  NeoPixelTempHotendAnimation.Position_Memory = 0;
  NeoPixelTempHotendAnimation.RangeBegin = 0;
  NeoPixelTempHotendAnimation.RangeEnd = 0;
  NeoPixelTempHotendAnimation.Running = false;
  
  NeoPixelPrinterStatAnimation.Position = 0;
  NeoPixelPrinterStatAnimation.Position_Memory = 0;
  NeoPixelPrinterStatAnimation.RangeBegin = 0;
  NeoPixelPrinterStatAnimation.RangeEnd = 0;
  NeoPixelPrinterStatAnimation.Running = false;
  
  NeoPixelTempHeatbedAnimation.Position = 0;
  NeoPixelTempHeatbedAnimation.Position_Memory = 0;
  NeoPixelTempHeatbedAnimation.RangeBegin = 0;
  NeoPixelTempHeatbedAnimation.RangeEnd = 0;
  NeoPixelTempHeatbedAnimation.Running = false;

  Printer.Status = ' ';
  Printer.ActTempHeatbed = 0.0;
  Printer.ActTempHotend = 0.0;
  Printer.ActiveTempHeatbed = 0.0;
  Printer.ActiveTempHotend = 0.0;
  Printer.StandbyTempHeatbed = 0.0;
  Printer.StandbyTempHotend = 0.0;
  Printer.HeaterStatusHeatbed = 0.0;
  Printer.HeaterStatusHotend = 0.0;
  Printer.FractionPrinted = 0.0;
  Printer.UpdatePending = false;

  #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL1_ACTIVE)
    DebugPrinter.ActTempHeatbed = 0.0;
    DebugPrinter.ActTempHotend = 0.0;
    DebugPrinter.ActiveTempHeatbed = 0.0;
    DebugPrinter.ActiveTempHotend = 0.0;
    DebugPrinter.StandbyTempHeatbed = 0.0;
    DebugPrinter.StandbyTempHotend = 0.0;
    DebugPrinter.HeaterStatusHeatbed = 0.0;
    DebugPrinter.HeaterStatusHotend = 0.0;
    DebugPrinter.FractionPrinted = 0.0;
  #endif 

  // Initialize Neopixels
  if (NeoPixelTempHotendActive == true){
    NeoPixelTempHotend.begin();
    NeoPixelTempHotend.setBrightness(NeopixelTempHotendBrightness);
    NeoPixelTempHotend.fill(ConvertColor(0,0,0));
    NeoPixelTempHotend.show();
  }
  if (NeoPixelPrinterStatActive == true){
    NeoPixelPrinterStat.begin();
    NeoPixelPrinterStat.setBrightness(NeopixelTempPrinterStatBrightness);
    NeoPixelPrinterStat.fill(ConvertColor(0,0,0));
    NeoPixelPrinterStat.show();
  }
  if (NeoPixelTempHeatbedActive == true){
    NeoPixelTempHeatbed.begin();
    NeoPixelTempHeatbed.setBrightness(NeopixelTempHeatbedBrightness);
    NeoPixelTempHeatbed.fill(ConvertColor(0,0,0));
    NeoPixelTempHeatbed.show();
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
        if (((Printer.ActTempHotend > DebugPrinter.ActTempHotend) && (Printer.ActTempHotend / DebugPrinter.ActTempHotend) > 2) || ((Printer.ActTempHotend < DebugPrinter.ActTempHotend) && (DebugPrinter.ActTempHotend / Printer.ActTempHotend) > 2)){
           Serial.println("High Delta ActTempHotend: Act="+String(Printer.ActTempHotend) + " / Memory= "+String(DebugPrinter.ActTempHotend));
           Serial.println("SerialMessage= "+SerialMessage);
           Serial.println("");
        }
        if (((Printer.ActiveTempHeatbed > DebugPrinter.ActiveTempHeatbed) && (Printer.ActiveTempHeatbed / DebugPrinter.ActiveTempHeatbed) > 2) || ((Printer.ActiveTempHeatbed < DebugPrinter.ActiveTempHeatbed) && (DebugPrinter.ActiveTempHeatbed / Printer.ActiveTempHeatbed) > 2)){
          Serial.println("High Delta ActiveTempHeatbed: Act="+String(Printer.ActiveTempHeatbed) + " / Memory= "+String(DebugPrinter.ActiveTempHeatbed));
          Serial.println("SerialMessage= "+SerialMessage);
          Serial.println("");
        }
        if (((Printer.ActiveTempHotend > DebugPrinter.ActiveTempHotend) && (Printer.ActiveTempHotend / DebugPrinter.ActiveTempHotend) > 2) || ((Printer.ActiveTempHotend < DebugPrinter.ActiveTempHotend) && (DebugPrinter.ActiveTempHotend / Printer.ActiveTempHotend) > 2)){
          Serial.println("High Delta ActiveTempHotend: Act="+String(Printer.ActiveTempHotend) + " / Memory= "+String(DebugPrinter.ActiveTempHotend));
          Serial.println("SerialMessage= "+SerialMessage);
          Serial.println("");
        }
        if (((Printer.StandbyTempHeatbed > DebugPrinter.StandbyTempHeatbed) && (Printer.StandbyTempHeatbed / DebugPrinter.StandbyTempHeatbed) > 2) || ((Printer.StandbyTempHeatbed < DebugPrinter.StandbyTempHeatbed) && (DebugPrinter.StandbyTempHeatbed / Printer.StandbyTempHeatbed) > 2)){
          Serial.println("High Delta StandbyTempHeatbed: Act="+String(Printer.StandbyTempHeatbed) + " / Memory= "+String(DebugPrinter.StandbyTempHeatbed));
          Serial.println("SerialMessage= "+SerialMessage);
          Serial.println("");
        }
        if (((Printer.StandbyTempHotend > DebugPrinter.StandbyTempHotend) && (Printer.StandbyTempHotend / DebugPrinter.StandbyTempHotend) > 2) || ((Printer.StandbyTempHotend < DebugPrinter.StandbyTempHotend) && (DebugPrinter.StandbyTempHotend / Printer.StandbyTempHotend) > 2)){
          Serial.println("High Delta StandbyTempHotend: Act="+String(Printer.StandbyTempHotend) + " / Memory= "+String(DebugPrinter.StandbyTempHotend));
          Serial.println("SerialMessage= "+SerialMessage);
          Serial.println("");
        }
        if (((Printer.FractionPrinted > DebugPrinter.FractionPrinted) && (Printer.FractionPrinted / DebugPrinter.FractionPrinted) > 2) || ((Printer.FractionPrinted < DebugPrinter.FractionPrinted) && (DebugPrinter.FractionPrinted / Printer.FractionPrinted) > 2)){
          Serial.println("High Delta FractionPrinted: Act="+String(Printer.FractionPrinted) + " / Memory= "+String(DebugPrinter.FractionPrinted));
          Serial.println("SerialMessage= "+SerialMessage);
          Serial.println("");
        }
        DebugPrinter.ActTempHeatbed = Printer.ActTempHeatbed;
        DebugPrinter.ActTempHotend = Printer.ActTempHotend;
        DebugPrinter.ActiveTempHeatbed = Printer.ActiveTempHeatbed;
        DebugPrinter.ActiveTempHotend = Printer.ActiveTempHotend;
        DebugPrinter.StandbyTempHeatbed = Printer.StandbyTempHeatbed;
        DebugPrinter.StandbyTempHotend = Printer.StandbyTempHotend;
        DebugPrinter.FractionPrinted = Printer.FractionPrinted;
      #endif 
      
      //Update Neopixel Hotend
      if (NeoPixelTempHotendActive == true){
        //Initialize AnimationRange
        NeoPixelTempHotendAnimation.RangeBegin = 0;
        NeoPixelTempHotendAnimation.RangeEnd = 0;
  
        //NeoPixel: Bed-Temperature   
        SetTempHotend=0;
        if (Printer.HeaterStatusHotend == 2)
        {
          SetTempHotend=Printer.ActiveTempHotend;
        }
        else if (Printer.HeaterStatusHotend == 1){
          SetTempHotend=Printer.StandbyTempHotend;
        }
        for (int NeoPixelPosition = 1; NeoPixelPosition <= NeoPixelTempHotendCount; NeoPixelPosition++)
        {
          if((((Printer.ActTempHotend - NeoPixelTempHotendTempOffset) / NeoPixelTempHotendScale) < NeoPixelPosition) && (((SetTempHotend - NeoPixelTempHotendTempOffset) / NeoPixelTempHotendScale) >= NeoPixelPosition)){
            NeoPixelTempHotend.setPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHotendCount,NeoPixelTempHotendPixelOffset,NeoPixelPosition),NeoPixelTempHotendColorHeatUp);
            //Define Animation-Range
            if (NeoPixelTempHotendAnimation.RangeBegin == 0) {
              NeoPixelTempHotendAnimation.RangeBegin = NeoPixelPosition;
              NeoPixelTempHotendAnimation.RangeEnd = NeoPixelPosition;
            } else {
              NeoPixelTempHotendAnimation.RangeEnd++;
            }
          }
          else if((((Printer.ActTempHotend - NeoPixelTempHotendTempOffset) / NeoPixelTempHotendScale) >= NeoPixelPosition) && (((SetTempHotend - NeoPixelTempHotendTempOffset) / NeoPixelTempHotendScale) >= NeoPixelPosition)){
            NeoPixelTempHotend.setPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHotendCount,NeoPixelTempHotendPixelOffset,NeoPixelPosition),NeoPixelTempHotendColorHeatUpDone);
          }
          else if((((Printer.ActTempHotend - NeoPixelTempHotendTempOffset) / NeoPixelTempHotendScale) >= NeoPixelPosition) && (((SetTempHotend - NeoPixelTempHotendTempOffset) / NeoPixelTempHotendScale) < NeoPixelPosition)){
            NeoPixelTempHotend.setPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHotendCount,NeoPixelTempHotendPixelOffset,NeoPixelPosition),NeoPixelTempHotendColorCoolDown);
          }
          else{
            NeoPixelTempHotend.setPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHotendCount,NeoPixelTempHotendPixelOffset,NeoPixelPosition),NeoPixelTempHotendColorIdle);
          }
        }
      }
        
      //Update Neopixel PrinterStatus
      if (NeoPixelPrinterStatActive == true){
        //Initialize AnimationRange Hotend
        NeoPixelPrinterStatAnimation.RangeBegin = 0;
        NeoPixelPrinterStatAnimation.RangeEnd = 0;
  
        //NeoPixel: Printer-Status & Print-Progress
        if(Printer.Status == 'P'){ 
          //Display Print-Progress
          for (int NeoPixelPosition = 1; NeoPixelPosition <= NeoPixelPrinterStatCount; NeoPixelPosition++)
          {
            if(NeoPixelPosition < (Printer.FractionPrinted * NeoPixelPrinterStatCount)){
              NeoPixelPrinterStat.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatCount,NeoPixelPrinterStatPixelOffset,NeoPixelPosition),NeoPixelPrinterStatColorPrintingDone);
            }
            else{
              NeoPixelPrinterStat.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatCount,NeoPixelPrinterStatPixelOffset,NeoPixelPosition),NeoPixelPrinterStatColorPrinting);
              //Define Animation-Range
              if (NeoPixelPrinterStatAnimation.RangeBegin == 0) {
                NeoPixelPrinterStatAnimation.RangeBegin = NeoPixelPosition;
                NeoPixelPrinterStatAnimation.RangeEnd = NeoPixelPosition;
              } else {
                NeoPixelPrinterStatAnimation.RangeEnd++;
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
              NeoPixelPrinterStat.fill(NeoPixelPrinterStatColorIdle);
              break;
            case 'P':
              NeoPixelPrinterStat.fill(NeoPixelPrinterStatColorPrinting);
              break;
            case 'S':
              NeoPixelPrinterStat.fill(NeoPixelPrinterStatColorStopped);
              break;
            case 'C':
              NeoPixelPrinterStat.fill(NeoPixelPrinterStatColorConfiguring);
              break;
            case 'A':
              NeoPixelPrinterStat.fill(NeoPixelPrinterStatColorPaused);
              break;
            case 'D':
              NeoPixelPrinterStat.fill(NeoPixelPrinterStatColorBusy);
              break;
            case 'R':
              NeoPixelPrinterStat.fill(NeoPixelPrinterStatColorPausing);
              break;
            case 'B':
              NeoPixelPrinterStat.fill(NeoPixelPrinterStatColorResuming);
              break;
            case 'F':
              NeoPixelPrinterStat.fill(NeoPixelPrinterStatColorFlashing);
              break;
            default:
              NeoPixelPrinterStat.fill(NeoPixelPrinterStatColorDefault);
              break;
          }
        }
      }    
  
      //Update Neopixel Heatbed
      if (NeoPixelTempHeatbedActive == true){
        //Initialize AnimationRange
        NeoPixelTempHeatbedAnimation.RangeBegin = 0;
        NeoPixelTempHeatbedAnimation.RangeEnd = 0;
  
        //NeoPixel: Bed-Temperature   
        SetTempHeatbed=0;
        if (Printer.HeaterStatusHeatbed == 2)
        {
          SetTempHeatbed=Printer.ActiveTempHeatbed;
        }
        else if (Printer.HeaterStatusHeatbed == 1){
          SetTempHeatbed=Printer.StandbyTempHeatbed;
        }
        for (int NeoPixelPosition = 1; NeoPixelPosition <= NeoPixelTempHeatbedCount; NeoPixelPosition++)
        {
          if((((Printer.ActTempHeatbed - NeoPixelTempHeatbedTempOffset) / NeoPixelTempHeatbedScale) < NeoPixelPosition) && (((SetTempHeatbed - NeoPixelTempHeatbedTempOffset) / NeoPixelTempHeatbedScale) >= NeoPixelPosition)){
            NeoPixelTempHeatbed.setPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHeatbedCount,NeoPixelTempHeatbedPixelOffset,NeoPixelPosition),NeoPixelTempHeatbedColorHeatUp);
            //Define Animation-Range
            if (NeoPixelTempHeatbedAnimation.RangeBegin == 0) {
              NeoPixelTempHeatbedAnimation.RangeBegin = NeoPixelPosition;
              NeoPixelTempHeatbedAnimation.RangeEnd = NeoPixelPosition;
            } else {
              NeoPixelTempHeatbedAnimation.RangeEnd++;
            }
          }
          else if((((Printer.ActTempHeatbed - NeoPixelTempHeatbedTempOffset) / NeoPixelTempHeatbedScale) >= NeoPixelPosition) && (((SetTempHeatbed - NeoPixelTempHeatbedTempOffset) / NeoPixelTempHeatbedScale) >= NeoPixelPosition)){
            NeoPixelTempHeatbed.setPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHeatbedCount,NeoPixelTempHeatbedPixelOffset,NeoPixelPosition),NeoPixelTempHeatbedColorHeatUpDone);
          }
          else if((((Printer.ActTempHeatbed - NeoPixelTempHeatbedTempOffset) / NeoPixelTempHeatbedScale) >= NeoPixelPosition) && (((SetTempHeatbed - NeoPixelTempHeatbedTempOffset) / NeoPixelTempHeatbedScale) < NeoPixelPosition)){
            NeoPixelTempHeatbed.setPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHeatbedCount,NeoPixelTempHeatbedPixelOffset,NeoPixelPosition),NeoPixelTempHeatbedColorCoolDown);
          }
          else{
            NeoPixelTempHeatbed.setPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHeatbedCount,NeoPixelTempHeatbedPixelOffset,NeoPixelPosition),NeoPixelTempHeatbedColorIdle);
          }
        }
      }
    }  

    //Animation Hotend
    if (NeoPixelTempHotendAnimationActive == true){
      //AnimationRange exists?
      if (NeoPixelTempHotendAnimation.RangeBegin == 0){
        NeoPixelTempHotendAnimation.Running = false;
      }
      else{
        //Animation initialize?
        if (NeoPixelTempHotendAnimation.Running == false){
            NeoPixelTempHotendAnimation.Running = true;
            NeoPixelTempHotendAnimation.Position = NeoPixelTempHotendAnimation.RangeBegin;
            NeoPixelTempHotendAnimation.Position_Memory = 0;
        }
        //Restart animation at new position?
        if (NeoPixelTempHotendAnimation.Position < NeoPixelTempHotendAnimation.RangeBegin){
          NeoPixelTempHotendAnimation.Position = NeoPixelTempHotendAnimation.RangeBegin;
        }
        if (NeoPixelTempHotendAnimation.Position_Memory != NeoPixelTempHotendAnimation.Position && NeoPixelTempHotendAnimation.Position_Memory >= NeoPixelTempHotendAnimation.RangeBegin){
          NeoPixelTempHotend.setPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHotendCount,NeoPixelTempHotendPixelOffset,NeoPixelTempHotendAnimation.Position_Memory),NeoPixelTempHotendColorHeatUp);
        }
        if (NeoPixelTempHotend.getPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHotendCount,NeoPixelTempHotendPixelOffset,NeoPixelTempHotendAnimation.Position)) == NeoPixelTempHotendColorAnimation){
            NeoPixelTempHotend.setPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHotendCount,NeoPixelTempHotendPixelOffset,NeoPixelTempHotendAnimation.Position),NeoPixelTempHotendColorHeatUp);
        }
        else{
          NeoPixelTempHotendAnimation.Position_Memory = NeoPixelTempHotendAnimation.Position;
          NeoPixelTempHotend.setPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHotendCount,NeoPixelTempHotendPixelOffset,NeoPixelTempHotendAnimation.Position),NeoPixelTempHotendColorAnimation);
        }
        NeoPixelTempHotendAnimation.Position++;
        if (NeoPixelTempHotendAnimation.Position > NeoPixelTempHotendAnimation.RangeEnd){
          NeoPixelTempHotendAnimation.Position = NeoPixelTempHotendAnimation.RangeBegin;
        }
      }
    }

    //Animation PrinterStatus
    if (NeoPixelPrinterStatAnimationActive == true){
      //AnimationRange exists?
      if (NeoPixelPrinterStatAnimation.RangeBegin == 0){
        NeoPixelPrinterStatAnimation.Running = false;
      }
      else{
        //Animation initialize?
        if (NeoPixelPrinterStatAnimation.Running == false){
            NeoPixelPrinterStatAnimation.Running = true;
            NeoPixelPrinterStatAnimation.Position = NeoPixelPrinterStatAnimation.RangeBegin;
            NeoPixelPrinterStatAnimation.Position_Memory = 0;
        }
        //Restart animation at new position?
        if (NeoPixelPrinterStatAnimation.Position < NeoPixelPrinterStatAnimation.RangeBegin){
          NeoPixelPrinterStatAnimation.Position = NeoPixelPrinterStatAnimation.RangeBegin;
        }
        if (NeoPixelPrinterStatAnimation.Position_Memory != NeoPixelPrinterStatAnimation.Position && NeoPixelPrinterStatAnimation.Position_Memory >= NeoPixelPrinterStatAnimation.RangeBegin){
          NeoPixelPrinterStat.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatCount,NeoPixelPrinterStatPixelOffset,NeoPixelPrinterStatAnimation.Position_Memory),NeoPixelPrinterStatColorPrinting);
        }
        if (NeoPixelPrinterStat.getPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatCount,NeoPixelPrinterStatPixelOffset,NeoPixelPrinterStatAnimation.Position)) == NeoPixelPrinterStatColorAnimation){
            NeoPixelPrinterStat.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatCount,NeoPixelPrinterStatPixelOffset,NeoPixelPrinterStatAnimation.Position),NeoPixelPrinterStatColorPrinting);
        }
        else{
          NeoPixelPrinterStatAnimation.Position_Memory = NeoPixelPrinterStatAnimation.Position;
          NeoPixelPrinterStat.setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatCount,NeoPixelPrinterStatPixelOffset,NeoPixelPrinterStatAnimation.Position),NeoPixelPrinterStatColorAnimation);
        }
        NeoPixelPrinterStatAnimation.Position++;
        if (NeoPixelPrinterStatAnimation.Position > NeoPixelPrinterStatAnimation.RangeEnd){
          NeoPixelPrinterStatAnimation.Position = NeoPixelPrinterStatAnimation.RangeBegin;
        }
      }
    }
            
    //Animation Heatbed
    if (NeoPixelTempHeatbedAnimationActive == true){
      //AnimationRange exists?
      if (NeoPixelTempHeatbedAnimation.RangeBegin == 0){
        NeoPixelTempHeatbedAnimation.Running = false;
      }
      else{
        //Animation initialize?
        if (NeoPixelTempHeatbedAnimation.Running == false){
            NeoPixelTempHeatbedAnimation.Running = true;
            NeoPixelTempHeatbedAnimation.Position = NeoPixelTempHeatbedAnimation.RangeBegin;
            NeoPixelTempHeatbedAnimation.Position_Memory = 0;
        }
        //Restart animation at new position?
        if (NeoPixelTempHeatbedAnimation.Position < NeoPixelTempHeatbedAnimation.RangeBegin){
          NeoPixelTempHeatbedAnimation.Position = NeoPixelTempHeatbedAnimation.RangeBegin;
        }
        if (NeoPixelTempHeatbedAnimation.Position_Memory != NeoPixelTempHeatbedAnimation.Position && NeoPixelTempHeatbedAnimation.Position_Memory >= NeoPixelTempHeatbedAnimation.RangeBegin){
          NeoPixelTempHeatbed.setPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHeatbedCount,NeoPixelTempHeatbedPixelOffset,NeoPixelTempHeatbedAnimation.Position_Memory),NeoPixelTempHeatbedColorHeatUp);
        }
        if (NeoPixelTempHeatbed.getPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHeatbedCount,NeoPixelTempHeatbedPixelOffset,NeoPixelTempHeatbedAnimation.Position)) == NeoPixelTempHeatbedColorAnimation){
            NeoPixelTempHeatbed.setPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHeatbedCount,NeoPixelTempHeatbedPixelOffset,NeoPixelTempHeatbedAnimation.Position),NeoPixelTempHeatbedColorHeatUp);
        }
        else{
          NeoPixelTempHeatbedAnimation.Position_Memory = NeoPixelTempHeatbedAnimation.Position;
          NeoPixelTempHeatbed.setPixelColor(ConvertPosition2PixelIndex(NeoPixelTempHeatbedCount,NeoPixelTempHeatbedPixelOffset,NeoPixelTempHeatbedAnimation.Position),NeoPixelTempHeatbedColorAnimation);
        }
        NeoPixelTempHeatbedAnimation.Position++;
        if (NeoPixelTempHeatbedAnimation.Position > NeoPixelTempHeatbedAnimation.RangeEnd){
          NeoPixelTempHeatbedAnimation.Position = NeoPixelTempHeatbedAnimation.RangeBegin;
        }
      }
    }

    //Neopixel refresh
    if (NeoPixelTempHotendActive == true){
      NeoPixelTempHotend.show();
    }  
    if (NeoPixelPrinterStatActive == true){
      NeoPixelPrinterStat.show();   
    }   
    if (NeoPixelTempHeatbedActive == true){
      NeoPixelTempHeatbed.show();
    }  
  }
}
