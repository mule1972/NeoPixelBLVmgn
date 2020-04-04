#include <Adafruit_NeoPixel.h>

//#define DEBUGLEVEL1_ACTIVE
//#define DEBUGLEVEL2_ACTIVE

// ***************************************
// ********** User-Config Begin **********

//General
#define NeoPixelStartupAnimationActive true  //Show Startup Animation for all Neopixels (true = activated / false = deactivated) !!Attention!! Animation will only be shown if all Neopixels have the same number of LEDs

//Heater-Scaling
#define Heater0_Scale 10  //Display scale factor for Heater 0 (Heatbed)
#define Heater1_Scale 20  //Display scale factor for Heater 1
#define Heater2_Scale 20  //Display scale factor for Heater 2
#define Heater3_Scale 20  //Display scale factor for Heater 3
#define Heater4_Scale 20  //Display scale factor for Heater 4

//NeoPixel#1 - Printer status
#define NeoPixelPrinterStatus_Active true  //NeoPixel#1 (true = activated / false = deactivated)
#define NeoPixelPrinterStatus_StartupAnimationType 2  //Startup animation type (1-3)
#define NeoPixelPrinterStatus_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixelPrinterStatus_LEDs 16  //Number of NeoPixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixelPrinterStatus_ArduinoPin 7  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixelPrinterStatus_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the startpoint clockwise (positive offset) or anti-clockwise (negative offset).
#define NeoPixelPrinterStatus_AnimationActive true  //Animation for print progress (true = activated / false = deactivated)
#define NeoPixelPrinterStatus_Reverse false  //Reverse Direction of Animation (false = default / true = reversed)
#define NeoPixelPrinterStatus_Brightness 8  //Overall brightness of the Neopixel-LEDs
#define NeoPixelPrinterStatus_ColorIdle ConvertColor(255,255,255)  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorPrinting ConvertColor(64,255,64)  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorPrintingDone ConvertColor(0,255,0)  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorStopped ConvertColor(0,0,255)  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorConfiguring ConvertColor(255,255,0)  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorPaused ConvertColor(160,32,240)  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorBusy ConvertColor(255,255,0)  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorPausing ConvertColor(160,32,240)  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorResuming ConvertColor(255,255,0)  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorFlashing ConvertColor(255,255,0)  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorDefault ConvertColor(255,255,255)  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorAnimation ConvertColor(0,0,0)  //RGB values for specified status

//NeoPixel#2 - Heater
#define NeoPixelHeater0_Active true  //NeoPixel#2 (true = activated / false = deactivated)
#define NeoPixelHeater0_StartupAnimationType 3  //Startup animation type (1-3)
#define NeoPixelHeater0_ShowHeaters "0"  //Show temp of Heater n (multiple Heaters seperated by & / 0= Heatbed)
#define NeoPixelHeater0_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixelHeater0_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixelHeater0_ArduinoPin 6  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixelHeater0_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixelHeater0_TempOffset 0  //Minimum Temperature at which the first LED lights up
#define NeoPixelHeater0_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixelHeater0_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixelHeater0_Brightness 8  //Overall brightness of the Neopixel-LEDs
#define NeoPixelHeater0_ColorIdle ConvertColor(255,255,255)  //RGB values for specified status
#define NeoPixelHeater0_ColorHeatUp ConvertColor(255,64,64)  //RGB values for specified status
#define NeoPixelHeater0_ColorHeatUpDone ConvertColor(255,0,0)  //RGB values for specified status
#define NeoPixelHeater0_ColorCoolDown ConvertColor(0,0,255)  //RGB values for specified status
#define NeoPixelHeater0_ColorAnimation ConvertColor(0,0,0)  //RGB values for specified status

//NeoPixel#3 - Heater
#define NeoPixelHeater1_Active true  //NeoPixel#3 (true = activated / false = deactivated)
#define NeoPixelHeater1_StartupAnimationType 1  //Startup animation type (1-3)
#define NeoPixelHeater1_ShowHeaters "1"  //Show temp of Heater n (multiple Heaters seperated by & / 0= Heatbed)
#define NeoPixelHeater1_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixelHeater1_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixelHeater1_ArduinoPin 8  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixelHeater1_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixelHeater1_TempOffset 0  //Minimum Temperature at which the first LED lights up
#define NeoPixelHeater1_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixelHeater1_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixelHeater1_Brightness 8  //Overall brightness of the Neopixel-LEDs
#define NeoPixelHeater1_ColorIdle ConvertColor(255,255,255)  //RGB values for specified status
#define NeoPixelHeater1_ColorHeatUp ConvertColor(255,64,64)  //RGB values for specified status
#define NeoPixelHeater1_ColorHeatUpDone ConvertColor(255,0,0)  //RGB values for specified status
#define NeoPixelHeater1_ColorCoolDown ConvertColor(0,0,255)  //RGB values for specified status
#define NeoPixelHeater1_ColorAnimation ConvertColor(0,0,0)  //RGB values for specified status

//NeoPixel#4 - Heater
#define NeoPixelHeater2_Active false  //NeoPixel#4 (true = activated / false = deactivated)
#define NeoPixelHeater2_StartupAnimationType 1  //Startup animation type (1-3)
#define NeoPixelHeater2_ShowHeaters "2"  //Show temp of Heater n (multiple Heaters seperated by & / 0= Heatbed)
#define NeoPixelHeater2_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixelHeater2_LEDs 16  //Numbner of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixelHeater2_ArduinoPin 0  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixelHeater2_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixelHeater2_TempOffset 0  //Minimum Temperature at which the first LED lights up
#define NeoPixelHeater2_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixelHeater2_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixelHeater2_Brightness 8  //Overall brightness of the Neopixel-LEDs
#define NeoPixelHeater2_ColorIdle ConvertColor(255,255,255)  //RGB values for specified status
#define NeoPixelHeater2_ColorHeatUp ConvertColor(255,64,64)  //RGB values for specified status
#define NeoPixelHeater2_ColorHeatUpDone ConvertColor(255,0,0)  //RGB values for specified status
#define NeoPixelHeater2_ColorCoolDown ConvertColor(0,0,255)  //RGB values for specified status
#define NeoPixelHeater2_ColorAnimation ConvertColor(0,0,0)  //RGB values for specified status

//NeoPixel#5 - Heater
#define NeoPixelHeater3_Active false  //NeoPixel#5 (true = activated / false = deactivated)
#define NeoPixelHeater3_StartupAnimationType 1  //Startup animation type (1-3)
#define NeoPixelHeater3_ShowHeaters "3"  //Show temp of Heater n (multiple Heaters seperated by & / 0= Heatbed)
#define NeoPixelHeater3_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixelHeater3_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixelHeater3_ArduinoPin 0  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixelHeater3_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixelHeater3_TempOffset 0  //Minimum Temperature at which the first LED lights up
#define NeoPixelHeater3_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixelHeater3_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixelHeater3_Brightness 8  //Overall brightness of the Neopixel-LEDs
#define NeoPixelHeater3_ColorIdle ConvertColor(255,255,255)  //RGB values for specified status
#define NeoPixelHeater3_ColorHeatUp ConvertColor(255,64,64)  //RGB values for specified status
#define NeoPixelHeater3_ColorHeatUpDone ConvertColor(255,0,0)  //RGB values for specified status
#define NeoPixelHeater3_ColorCoolDown ConvertColor(0,0,255)  //RGB values for specified status
#define NeoPixelHeater3_ColorAnimation ConvertColor(0,0,0)  //RGB values for specified status

//NeoPixel#6 - Heater
#define NeoPixelHeater4_Active false  //NeoPixel#6 (true = activated / false = deactivated)
#define NeoPixelHeater4_StartupAnimationType 1  //Startup animation type (1-3)
#define NeoPixelHeater4_ShowHeaters "4"  //Show temp of Heater n (multiple Heaters seperated by & / 0= Heatbed)
#define NeoPixelHeater4_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixelHeater4_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixelHeater4_ArduinoPin 0  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixelHeater4_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixelHeater4_TempOffset 0  //Minimum Temperature at which the first LED lights up
#define NeoPixelHeater4_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixelHeater4_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixelHeater4_Brightness 8  //Overall brightness of the Neopixel-LEDs
#define NeoPixelHeater4_ColorIdle ConvertColor(255,255,255)  //RGB values for specified status
#define NeoPixelHeater4_ColorHeatUp ConvertColor(255,64,64)  //RGB values for specified status
#define NeoPixelHeater4_ColorHeatUpDone ConvertColor(255,0,0)  //RGB values for specified status
#define NeoPixelHeater4_ColorCoolDown ConvertColor(0,0,255)  //RGB values for specified status
#define NeoPixelHeater4_ColorAnimation ConvertColor(0,0,0)  //RGB values for specified status

// ********** User-Config End **********
// *************************************

#define SerialTimeout 150
#define NeopixelRefreshSpeed 200
#define SerialMessageBuffer 550
#define NumberHeatersUsed 5
#define NumberNeoPixelsUsedForHeaters 5

struct HeaterConfig {
  public:
  bool Active;
  int StartupAnimationType;
  String ShowHeaters;
  neoPixelType Type;
  uint16_t LEDs;
  uint16_t ArduinoPin;
  int PixelOffset;
  int TempOffset;
  bool AnimationActive;
  bool AnimationReverse;
  int Brightness;
  uint32_t ColorIdle;
  uint32_t ColorHeatUp;
  uint32_t ColorHeatUpDone;
  uint32_t ColorCoolDown;
  uint32_t ColorAnimation;
};  
HeaterConfig NeoPixelHeater[NumberNeoPixelsUsedForHeaters];

struct NeoPixelAnimationMemory {
  public:
  bool Active;
  bool Reverse;
  bool Running;
  int Position;
  int Position_Memory;
  int RangeBegin;
  int RangeEnd;
  int ShowHeater_Memory;
  int AnimationColor = 0;
};
NeoPixelAnimationMemory NeoPixelPrinterStatus_AnimationMemory;
NeoPixelAnimationMemory NeoPixelHeater_AnimationMemory[NumberNeoPixelsUsedForHeaters];

int ShowHeater;
int StringPos;
int HeaterDelimiterPos;
int HeaterID;
int SetTempHeater;
int ActTempHeater;
unsigned long NeoPixelTimerRefresh = millis();
char SerialMessage[SerialMessageBuffer]; 
int HeaterScale[NumberHeatersUsed];

Adafruit_NeoPixel *NeoPixel_Printerstatus;
Adafruit_NeoPixel *NeoPixel_Heater[NumberNeoPixelsUsedForHeaters];

struct PanelDueMessage {
  public:
  char Status;
  int Heater_Status[NumberHeatersUsed];
  float Heater_ActTemp[NumberHeatersUsed];
  float Heater_ActiveTemp[NumberHeatersUsed];
  float Heater_StandbyTemp[NumberHeatersUsed];
  float FractionPrinted;
  bool UpdatePending;
  int Tool;
};
PanelDueMessage Printer;

#if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL1_ACTIVE)
  PanelDueMessage DebugPrinter;
#endif

static uint32_t  ConvertColor(uint8_t red, uint8_t green, uint8_t blue) {
  return ((uint32_t)red << 16) | ((uint32_t)green <<  8) | blue;
}

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

void AnalyzeSerialMessage() {
  Printer.UpdatePending = false;
  char JsonResultValue[100];
  bool JsonResult;
  char JsonObjstatus[] = "status";
  char JsonObjheaters[] = "heaters";
  char JsonObjactive[] = "active";
  char JsonObjstandby[] = "standby";
  char JsonObjhstat[] = "hstat";
  char JsonObjfractionprinted[] = "fraction_printed";
  char JsonObjtool[] = "tool";
  
  //Printer Status
  JsonResult = JsonParseRoot(JsonResultValue, SerialMessage, JsonObjstatus, 0);
  if (JsonResult == true) {Printer.Status = JsonResultValue[0]; Printer.UpdatePending = true;}

  //Heater Actual-Temp
  for (int i = 0; i < NumberHeatersUsed; i++){
    JsonResult = JsonParseRoot(JsonResultValue, SerialMessage, JsonObjheaters, (i + 1));
    if (JsonResult == true) {Printer.Heater_ActTemp[i] = atof(JsonResultValue); Printer.UpdatePending = true;}
  }  

  //Heater Active-Temp
  for (int i = 0; i < NumberHeatersUsed; i++){
    JsonResult = JsonParseRoot(JsonResultValue, SerialMessage, JsonObjactive, (i + 1));
    if (JsonResult == true) {Printer.Heater_ActiveTemp[i] = atof(JsonResultValue); Printer.UpdatePending = true;}
  }

  // HeaterStatus 0= Off / 1= Standby / 2= Active / 3= Fault / 4= Tuning
  for (int i = 0; i < NumberHeatersUsed; i++){
    JsonResult = JsonParseRoot(JsonResultValue, SerialMessage, JsonObjhstat, (i + 1));
    if (JsonResult == true) {Printer.Heater_Status[i] = atoi(JsonResultValue); Printer.UpdatePending = true;}
  }
  
  JsonResult = JsonParseRoot(JsonResultValue, SerialMessage, JsonObjfractionprinted, 0);
  if (JsonResult == true) {Printer.FractionPrinted = atof(JsonResultValue); Printer.UpdatePending = true;}

  JsonResult = JsonParseRoot(JsonResultValue, SerialMessage, JsonObjtool, 0);
  if (JsonResult == true) {Printer.Tool = atoi(JsonResultValue); Printer.UpdatePending = true;}
}


// Example-Json-Message: {"status":"I","heaters":[31.5,28.1],"active":[0.0,0.0],"standby":[0.0,0.0],"hstat":[0,0],"pos":[0.000,0.000,0.000],"machine":[0.000,0.000,0.000],"sfactor":100.00,"efactor":[100.00],"babystep":0.000,"Heater":-1,"probe":"0","fanPercent":[0.0,0.0,100.0,100.0,0.0,0.0,0.0,0.0,0.0,0.0],"fanRPM":0,"homed":[0,0,0],"msgBox.mode":-1,"geometry":"coreXY","axes":3,"totalAxes":3,"axisNames":"XYZ","volumes":2,"numHeaters":1,"myName":"BLV mgn Cube","firmwareName":"RepRapFirmware for Duet 2 WiFi/Ethernet"}
bool JsonParseRoot(char* Result, char* JsonMessagePtr, char* JsonRootObjectPtr, int JsonObjectIndex) {
  char* PositionBeginPtr;
  char* PositionEndPtr;
  int JsonValueIndex = 0;
  char JsonValue[100] = "";
  
  Result[0] = '\0';

  #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL1_ACTIVE)
    Serial.println(JsonMessagePtr);
    Serial.println(JsonRootObjectPtr);
    Serial.println(String(JsonObjectIndex));
  #endif 

  PositionBeginPtr = strstr(JsonMessagePtr, JsonRootObjectPtr);

  if (PositionBeginPtr == NULL) {
    return false;
  }
  else {  
    PositionBeginPtr = PositionBeginPtr + strlen(JsonRootObjectPtr) + 1;
    if (JsonMessagePtr[(PositionBeginPtr - JsonMessagePtr)] == '[') { 
      PositionEndPtr = strstr(PositionBeginPtr, "]");
      if (PositionEndPtr == NULL) {
        return false;
      }  
      else {
        strncat(JsonValue, (PositionBeginPtr + 1), (PositionEndPtr - (PositionBeginPtr + 1)));
        if (JsonObjectIndex == 0){
          if (strstr(JsonValue,",") == NULL) {
            strcpy(Result,JsonValue);
            return true;
          }
          else {
            //SingleValue expected, but MultiValue found 
            return false;
          }
        }
        else {
          if (strstr(JsonValue,",") == NULL) {
            //MultiValue expected, but Singlevalue found
            return false;
          }
          else {
            PositionBeginPtr = JsonValue;
            for (int JsonValueIndex = 1; JsonValueIndex < JsonObjectIndex; JsonValueIndex++){
              if (strstr(PositionBeginPtr,",") == NULL) {
                //Fewer Values found than expected
                return false;
              }
              else {
                PositionBeginPtr = strstr(JsonValue,",") + 1;
              }
            }
            if (strstr(PositionBeginPtr, ",") != NULL) {
              strncat(Result, PositionBeginPtr, (strstr(PositionBeginPtr, ",") - PositionBeginPtr));
              return true;
            }
            else {
              strcpy(Result,PositionBeginPtr);
              return true;
            }
          }
        }
      }
    }    
    else {
      if (JsonObjectIndex != 0){
        //Multivalue expected but not found
        return false;
      }
      else{
        if (strstr(PositionBeginPtr,",") != NULL) {
          strncat(Result, PositionBeginPtr, (strstr(PositionBeginPtr, ",") - PositionBeginPtr));
          return true;
        }
        else if (strstr(PositionBeginPtr,"}") != NULL) {
          strncat(Result, PositionBeginPtr, (strstr(PositionBeginPtr, "}") - PositionBeginPtr));
          return true;
        }
        else{
          //No EndPoint ( , or } ) for SingleValue found
          return false;          
        }
      }  
    } 
  }  
}


void GetSerialMessage(){
  unsigned long timer = millis();
  int SerialMessagePosition;
  bool SerialMessageComplete = false;
  bool SerialMessageBegin = false;
  char inChar;
  while(SerialMessageComplete == false && ((millis() - timer) <= SerialTimeout))
  {    

    //Arduino-Mega & Co.
    #if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    while(SerialMessageComplete == false && Serial2.available() > 0) 
    {
      inChar = Serial2.read();
    #endif 
    
    //Arduino-Pro & Co.
    #if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
    while(SerialMessageComplete == false && Serial.available() > 0) 
    {
      inChar = Serial.read();
    #endif 
    
    //Arduino-Leonardo & Co.
    #if defined(__AVR_ATmega32U4__)
    while(SerialMessageComplete == false && Serial1.available() > 0) 
    {
      inChar = Serial1.read();
    #endif 
    
      if(inChar=='{') {
        SerialMessageBegin = true;
        SerialMessagePosition = 0;
        SerialMessage[SerialMessagePosition] = inChar;
        SerialMessagePosition++;
      }
      else if (SerialMessageBegin == true && SerialMessagePosition < (SerialMessageBuffer - 3)) {
        if (inChar=='}') {
          SerialMessage[SerialMessagePosition] = inChar;
          SerialMessage[(SerialMessagePosition + 1)] = '\0';
          SerialMessageComplete=true;
          AnalyzeSerialMessage();
        }
        else {
          if (inChar != '\"') {
            SerialMessage[SerialMessagePosition] = inChar;
            SerialMessagePosition++;
          }  
        }  
      }
    }
  }  
}

// Initialize everything and prepare to start
void setup()
{   
  // Initialize Variables
  uint32_t AnimationColor;
  
  NeoPixelHeater[0].Active = NeoPixelHeater0_Active;
  NeoPixelHeater[0].StartupAnimationType = NeoPixelHeater0_StartupAnimationType;
  NeoPixelHeater[0].ShowHeaters = NeoPixelHeater0_ShowHeaters;
  NeoPixelHeater[0].Type = NeoPixelHeater0_Type;
  NeoPixelHeater[0].LEDs = NeoPixelHeater0_LEDs;
  NeoPixelHeater[0].ArduinoPin = NeoPixelHeater0_ArduinoPin;
  NeoPixelHeater[0].PixelOffset = NeoPixelHeater0_PixelOffset;
  NeoPixelHeater[0].TempOffset = NeoPixelHeater0_TempOffset;
  NeoPixelHeater[0].AnimationActive = NeoPixelHeater0_AnimationActive;
  NeoPixelHeater[0].AnimationReverse = NeoPixelHeater0_Reverse;
  NeoPixelHeater[0].Brightness = NeoPixelHeater0_Brightness;
  NeoPixelHeater[0].ColorIdle = NeoPixelHeater0_ColorIdle;
  NeoPixelHeater[0].ColorHeatUp = NeoPixelHeater0_ColorHeatUp;
  NeoPixelHeater[0].ColorHeatUpDone = NeoPixelHeater0_ColorHeatUpDone;
  NeoPixelHeater[0].ColorCoolDown = NeoPixelHeater0_ColorCoolDown;
  NeoPixelHeater[0].ColorAnimation = NeoPixelHeater0_ColorAnimation;
  NeoPixelHeater[1].Active = NeoPixelHeater1_Active;
  NeoPixelHeater[1].StartupAnimationType = NeoPixelHeater1_StartupAnimationType;
  NeoPixelHeater[1].ShowHeaters = NeoPixelHeater1_ShowHeaters;
  NeoPixelHeater[1].Type = NeoPixelHeater1_Type;
  NeoPixelHeater[1].LEDs = NeoPixelHeater1_LEDs;
  NeoPixelHeater[1].ArduinoPin = NeoPixelHeater1_ArduinoPin;
  NeoPixelHeater[1].PixelOffset = NeoPixelHeater1_PixelOffset;
  NeoPixelHeater[1].TempOffset = NeoPixelHeater1_TempOffset;
  NeoPixelHeater[1].AnimationActive = NeoPixelHeater1_AnimationActive;
  NeoPixelHeater[1].AnimationReverse = NeoPixelHeater1_Reverse;
  NeoPixelHeater[1].Brightness = NeoPixelHeater1_Brightness;
  NeoPixelHeater[1].ColorIdle = NeoPixelHeater1_ColorIdle;
  NeoPixelHeater[1].ColorHeatUp = NeoPixelHeater1_ColorHeatUp;
  NeoPixelHeater[1].ColorHeatUpDone = NeoPixelHeater1_ColorHeatUpDone;
  NeoPixelHeater[1].ColorCoolDown = NeoPixelHeater1_ColorCoolDown;
  NeoPixelHeater[1].ColorAnimation = NeoPixelHeater1_ColorAnimation;
  NeoPixelHeater[2].Active = NeoPixelHeater2_Active;
  NeoPixelHeater[2].StartupAnimationType = NeoPixelHeater2_StartupAnimationType;
  NeoPixelHeater[2].ShowHeaters = NeoPixelHeater2_ShowHeaters;
  NeoPixelHeater[2].Type = NeoPixelHeater2_Type;
  NeoPixelHeater[2].LEDs = NeoPixelHeater2_LEDs;
  NeoPixelHeater[2].ArduinoPin = NeoPixelHeater2_ArduinoPin;
  NeoPixelHeater[2].PixelOffset = NeoPixelHeater2_PixelOffset;
  NeoPixelHeater[2].TempOffset = NeoPixelHeater2_TempOffset;
  NeoPixelHeater[2].AnimationActive = NeoPixelHeater2_AnimationActive;
  NeoPixelHeater[2].AnimationReverse = NeoPixelHeater2_Reverse;
  NeoPixelHeater[2].Brightness = NeoPixelHeater2_Brightness;
  NeoPixelHeater[2].ColorIdle = NeoPixelHeater2_ColorIdle;
  NeoPixelHeater[2].ColorHeatUp = NeoPixelHeater2_ColorHeatUp;
  NeoPixelHeater[2].ColorHeatUpDone = NeoPixelHeater2_ColorHeatUpDone;
  NeoPixelHeater[2].ColorCoolDown = NeoPixelHeater2_ColorCoolDown;
  NeoPixelHeater[2].ColorAnimation = NeoPixelHeater2_ColorAnimation;
  NeoPixelHeater[3].Active = NeoPixelHeater3_Active;
  NeoPixelHeater[3].StartupAnimationType = NeoPixelHeater3_StartupAnimationType;
  NeoPixelHeater[3].ShowHeaters = NeoPixelHeater3_ShowHeaters;
  NeoPixelHeater[3].Type = NeoPixelHeater3_Type;
  NeoPixelHeater[3].LEDs = NeoPixelHeater3_LEDs;
  NeoPixelHeater[3].ArduinoPin = NeoPixelHeater3_ArduinoPin;
  NeoPixelHeater[3].PixelOffset = NeoPixelHeater3_PixelOffset;
  NeoPixelHeater[3].TempOffset = NeoPixelHeater3_TempOffset;
  NeoPixelHeater[3].AnimationActive = NeoPixelHeater3_AnimationActive;
  NeoPixelHeater[3].AnimationReverse = NeoPixelHeater3_Reverse;
  NeoPixelHeater[3].Brightness = NeoPixelHeater3_Brightness;
  NeoPixelHeater[3].ColorIdle = NeoPixelHeater3_ColorIdle;
  NeoPixelHeater[3].ColorHeatUp = NeoPixelHeater3_ColorHeatUp;
  NeoPixelHeater[3].ColorHeatUpDone = NeoPixelHeater3_ColorHeatUpDone;
  NeoPixelHeater[3].ColorCoolDown = NeoPixelHeater3_ColorCoolDown;
  NeoPixelHeater[3].ColorAnimation = NeoPixelHeater3_ColorAnimation;
  NeoPixelHeater[4].Active = NeoPixelHeater4_Active;
  NeoPixelHeater[4].StartupAnimationType = NeoPixelHeater4_StartupAnimationType;
  NeoPixelHeater[4].ShowHeaters = NeoPixelHeater4_ShowHeaters;
  NeoPixelHeater[4].Type = NeoPixelHeater4_Type;
  NeoPixelHeater[4].LEDs = NeoPixelHeater4_LEDs;
  NeoPixelHeater[4].ArduinoPin = NeoPixelHeater4_ArduinoPin;
  NeoPixelHeater[4].PixelOffset = NeoPixelHeater4_PixelOffset;
  NeoPixelHeater[4].TempOffset = NeoPixelHeater4_TempOffset;
  NeoPixelHeater[4].AnimationActive = NeoPixelHeater4_AnimationActive;
  NeoPixelHeater[4].AnimationReverse = NeoPixelHeater4_Reverse;
  NeoPixelHeater[4].Brightness = NeoPixelHeater4_Brightness;
  NeoPixelHeater[4].ColorIdle = NeoPixelHeater4_ColorIdle;
  NeoPixelHeater[4].ColorHeatUp = NeoPixelHeater4_ColorHeatUp;
  NeoPixelHeater[4].ColorHeatUpDone = NeoPixelHeater4_ColorHeatUpDone;
  NeoPixelHeater[4].ColorCoolDown = NeoPixelHeater4_ColorCoolDown;
  NeoPixelHeater[4].ColorAnimation = NeoPixelHeater4_ColorAnimation;
        
  HeaterScale[0] = Heater0_Scale;
  HeaterScale[1] = Heater1_Scale;
  HeaterScale[2] = Heater2_Scale;
  HeaterScale[3] = Heater3_Scale;
  HeaterScale[4] = Heater4_Scale;
  
  NeoPixel_Printerstatus = new Adafruit_NeoPixel(NeoPixelPrinterStatus_LEDs, NeoPixelPrinterStatus_ArduinoPin, NeoPixelPrinterStatus_Type);
  for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
    NeoPixel_Heater[i] = new Adafruit_NeoPixel(NeoPixelHeater[i].LEDs, NeoPixelHeater[i].ArduinoPin, NeoPixelHeater[i].Type);
  }  

  //Set start values
  NeoPixelPrinterStatus_AnimationMemory.Position = 0;
  NeoPixelPrinterStatus_AnimationMemory.Position_Memory = 0;
  NeoPixelPrinterStatus_AnimationMemory.RangeBegin = 0;
  NeoPixelPrinterStatus_AnimationMemory.RangeEnd = 0;
  NeoPixelPrinterStatus_AnimationMemory.Running = false;
  NeoPixelPrinterStatus_AnimationMemory.AnimationColor = 0;
  for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
    NeoPixelHeater_AnimationMemory[i].Position = 0;
    NeoPixelHeater_AnimationMemory[i].Position_Memory = 0;
    NeoPixelHeater_AnimationMemory[i].RangeBegin = 0;
    NeoPixelHeater_AnimationMemory[i].RangeEnd = 0;
    NeoPixelHeater_AnimationMemory[i].Running = false;
    NeoPixelHeater_AnimationMemory[i].AnimationColor = 0;
  }
  for (int i = 0; i < NumberHeatersUsed; i++){
    Printer.Heater_Status[i] = 0;
    Printer.Heater_ActTemp[i] = 0.0;
    Printer.Heater_ActiveTemp[i] = 0.0;
    Printer.Heater_StandbyTemp[i] = 0.0;
  }  
  Printer.Status = ' ';
  Printer.FractionPrinted = 0.0;

  //Arduino-Mega & Co.
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
  
  //Arduino-Pro & Co.
  #if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
    Serial.begin(57600);
    while(!Serial)
    {;}
  #endif 
  
  //Arduino-Leonardo & Co.
  #if defined(__AVR_ATmega32U4__)
    Serial1.begin(57600);
    while(!Serial1)
    {;}
  #endif 

  //Initialize Debug
  #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL1_ACTIVE)
    for (int i = 0; i < NumberHeatersUsed; i++){
      DebugPrinter.Heater_Status[i] = 0;
      DebugPrinter.Heater_ActTemp[i] = 0.0;
      DebugPrinter.Heater_ActiveTemp[i] = 0.0;
      DebugPrinter.Heater_StandbyTemp[i] = 0.0;
    }  
    DebugPrinter.Status = ' ';
    DebugPrinter.FractionPrinted = 0.0;
    DebugPrinter.UpdatePending = false;
  #endif 

  // Initialize Neopixels
  if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->begin(); NeoPixel_Printerstatus->show();}
  for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
    if (NeoPixelHeater[i].Active == true) {NeoPixel_Heater[i]->begin(); NeoPixel_Heater[i]->show();}
  }  

  // Startup-Animation
  int NeoPixelCount = 0;
  bool NeoPixelStartupAnimationActive_Consistency = true;
  if (NeoPixelStartupAnimationActive == true)
  {
    // Animation Consistency-Check
    if (NeoPixelPrinterStatus_Active == true) {
      if (NeoPixelCount == 0) {
        NeoPixelCount = NeoPixelPrinterStatus_LEDs;
      }  
      else {
        if (NeoPixelPrinterStatus_LEDs != NeoPixelCount) {
          NeoPixelStartupAnimationActive_Consistency = false;
        }
      }
    }
    for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
      if (NeoPixelHeater[i].Active == true) {
        if (NeoPixelCount == 0) {
          NeoPixelCount = NeoPixelHeater[i].LEDs;
        }  
        else {
          if (NeoPixelHeater[i].LEDs != NeoPixelCount) {
            NeoPixelStartupAnimationActive_Consistency = false;
          }
        }
      }
    }  
  	
    //Activate startup sequence & Co. if all activated NeoPixels have the same number of LEDs
  	if (NeoPixelCount > 0 && NeoPixelStartupAnimationActive_Consistency == true) {

      //Initialize Neopixels
      if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->setBrightness(255);}
      for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
        if (NeoPixelHeater[i].Active == true) {NeoPixel_Heater[i]->setBrightness(255);}
      }

      //Startup Animation #1a
  		for (int j = 0; j < NeoPixelCount; j++) {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: AnimationColor = ConvertColor(255, 0, 0); break; case 2: AnimationColor = ConvertColor(0, 255, 0); break; case 3: AnimationColor = ConvertColor(0, 0, 255); break;} NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,(j+1),NeoPixelPrinterStatus_Reverse), AnimationColor); NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeater[i].Active == true) {NeoPixel_Heater[i]->clear(); switch (NeoPixelHeater[i].StartupAnimationType) {case 1: AnimationColor = ConvertColor(255, 0, 0); break; case 2: AnimationColor = ConvertColor(0, 255, 0); break; case 3: AnimationColor = ConvertColor(0, 0, 255); break;} NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater[i].LEDs,NeoPixelHeater[i].PixelOffset,(j+1),NeoPixelHeater[i].AnimationReverse), AnimationColor); NeoPixel_Heater[i]->show();}
        }
        delay(30);
      }
      //Startup Animation #1b
      for (int j = 0; j < NeoPixelCount; j++) {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: AnimationColor = ConvertColor(0, 255, 0); break; case 2: AnimationColor = ConvertColor(0, 0, 255); break; case 3: AnimationColor = ConvertColor(255, 0, 0); break;} NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,(j+1),NeoPixelPrinterStatus_Reverse), AnimationColor); NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeater[i].Active == true) {NeoPixel_Heater[i]->clear(); switch (NeoPixelHeater[i].StartupAnimationType) {case 1: AnimationColor = ConvertColor(0, 255, 0); break; case 2: AnimationColor = ConvertColor(0, 0, 255); break; case 3: AnimationColor = ConvertColor(255, 0, 0); break;} NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater[i].LEDs,NeoPixelHeater[i].PixelOffset,(j+1),NeoPixelHeater[i].AnimationReverse), AnimationColor); NeoPixel_Heater[i]->show();}
        }
        delay(30);
      }
      //Startup Animation #1c
      for (int j = 0; j < NeoPixelCount; j++) {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: AnimationColor = ConvertColor(0, 0, 255); break; case 2: AnimationColor = ConvertColor(255, 0, 0); break; case 3: AnimationColor = ConvertColor(0, 255, 0); break;} NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,(j+1),NeoPixelPrinterStatus_Reverse), AnimationColor); NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeater[i].Active == true) {NeoPixel_Heater[i]->clear(); switch (NeoPixelHeater[i].StartupAnimationType) {case 1: AnimationColor = ConvertColor(0, 0, 255); break; case 2: AnimationColor = ConvertColor(255, 0, 0); break; case 3: AnimationColor = ConvertColor(0, 255, 0); break;} NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater[i].LEDs,NeoPixelHeater[i].PixelOffset,(j+1),NeoPixelHeater[i].AnimationReverse), AnimationColor); NeoPixel_Heater[i]->show();}
        }
        delay(30);
      }

      //Startup Animation #2a1
  		for(int j = 0; j < 255; j++)
  		{
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); NeoPixel_Printerstatus->setBrightness(j); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: NeoPixel_Printerstatus->fill(ConvertColor(255, 0, 0)); break; case 2: NeoPixel_Printerstatus->fill(ConvertColor(0, 255, 0)); break; case 3: NeoPixel_Printerstatus->fill(ConvertColor(0, 0, 255)); break;} NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeater[i].Active == true) {NeoPixel_Heater[i]->clear(); NeoPixel_Heater[i]->setBrightness(j); switch (NeoPixelHeater[i].StartupAnimationType) {case 1: NeoPixel_Heater[i]->fill(ConvertColor(255, 0, 0)); break; case 2: NeoPixel_Heater[i]->fill(ConvertColor(0, 255, 0)); break; case 3: NeoPixel_Heater[i]->fill(ConvertColor(0, 0, 255)); break;} NeoPixel_Heater[i]->show();}
        }
        delay(1);
  		}
      //Startup Animation #2a2
      for(int j = 255; j >= 0; j--)
      {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); NeoPixel_Printerstatus->setBrightness(j); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: NeoPixel_Printerstatus->fill(ConvertColor(255, 0, 0)); break; case 2: NeoPixel_Printerstatus->fill(ConvertColor(0, 255, 0)); break; case 3: NeoPixel_Printerstatus->fill(ConvertColor(0, 0, 255)); break;} NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeater[i].Active == true) {NeoPixel_Heater[i]->clear(); NeoPixel_Heater[i]->setBrightness(j); switch (NeoPixelHeater[i].StartupAnimationType) {case 1: NeoPixel_Heater[i]->fill(ConvertColor(255, 0, 0)); break; case 2: NeoPixel_Heater[i]->fill(ConvertColor(0, 255, 0)); break; case 3: NeoPixel_Heater[i]->fill(ConvertColor(0, 0, 255)); break;} NeoPixel_Heater[i]->show();}
        }
        delay(1);
      }
      //Startup Animation #2b1
      for(int j = 0; j < 255; j++)
      {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); NeoPixel_Printerstatus->setBrightness(j); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: NeoPixel_Printerstatus->fill(ConvertColor(0, 255, 0)); break; case 2: NeoPixel_Printerstatus->fill(ConvertColor(0, 0, 255)); break; case 3: NeoPixel_Printerstatus->fill(ConvertColor(255, 0, 0)); break;} NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeater[i].Active == true) {NeoPixel_Heater[i]->clear(); NeoPixel_Heater[i]->setBrightness(j); switch (NeoPixelHeater[i].StartupAnimationType) {case 1: NeoPixel_Heater[i]->fill(ConvertColor(0, 255, 0)); break; case 2: NeoPixel_Heater[i]->fill(ConvertColor(0, 0, 255)); break; case 3: NeoPixel_Heater[i]->fill(ConvertColor(255, 0, 0)); break;} NeoPixel_Heater[i]->show();}
        }
        delay(1);
      }
      //Startup Animation #2b2
      for(int j = 255; j >= 0; j--)
      {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); NeoPixel_Printerstatus->setBrightness(j); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: NeoPixel_Printerstatus->fill(ConvertColor(0, 255, 0)); break; case 2: NeoPixel_Printerstatus->fill(ConvertColor(0, 0, 255)); break; case 3: NeoPixel_Printerstatus->fill(ConvertColor(255, 0, 0)); break;} NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeater[i].Active == true) {NeoPixel_Heater[i]->clear(); NeoPixel_Heater[i]->setBrightness(j); switch (NeoPixelHeater[i].StartupAnimationType) {case 1: NeoPixel_Heater[i]->fill(ConvertColor(0, 255, 0)); break; case 2: NeoPixel_Heater[i]->fill(ConvertColor(0, 0, 255)); break; case 3: NeoPixel_Heater[i]->fill(ConvertColor(255, 0, 0)); break;} NeoPixel_Heater[i]->show();}
        }
        delay(1);
      }
      //Startup Animation #2c1
      for(int j = 0; j < 255; j++)
      {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); NeoPixel_Printerstatus->setBrightness(j); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: NeoPixel_Printerstatus->fill(ConvertColor(0, 0, 255)); break; case 2: NeoPixel_Printerstatus->fill(ConvertColor(255, 0, 0)); break; case 3: NeoPixel_Printerstatus->fill(ConvertColor(0, 255, 0)); break;} NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeater[i].Active == true) {NeoPixel_Heater[i]->clear(); NeoPixel_Heater[i]->setBrightness(j); switch (NeoPixelHeater[i].StartupAnimationType) {case 1: NeoPixel_Heater[i]->fill(ConvertColor(0, 0, 255)); break; case 2: NeoPixel_Heater[i]->fill(ConvertColor(255, 0, 0)); break; case 3: NeoPixel_Heater[i]->fill(ConvertColor(0, 255, 0)); break;} NeoPixel_Heater[i]->show();}
        }
        delay(1);
      }
      //Startup Animation #2c2
      for(int j = 255; j >= 0; j--)
      {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); NeoPixel_Printerstatus->setBrightness(j); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: NeoPixel_Printerstatus->fill(ConvertColor(0, 0, 255)); break; case 2: NeoPixel_Printerstatus->fill(ConvertColor(255, 0, 0)); break; case 3: NeoPixel_Printerstatus->fill(ConvertColor(0, 255, 0)); break;} NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeater[i].Active == true) {NeoPixel_Heater[i]->clear(); NeoPixel_Heater[i]->setBrightness(j); switch (NeoPixelHeater[i].StartupAnimationType) {case 1: NeoPixel_Heater[i]->fill(ConvertColor(0, 0, 255)); break; case 2: NeoPixel_Heater[i]->fill(ConvertColor(255, 0, 0)); break; case 3: NeoPixel_Heater[i]->fill(ConvertColor(0, 255, 0)); break;} NeoPixel_Heater[i]->show();}
        }
        delay(1);
      }
  	}	
  }  
  
  //Initial Neopixel for Loop
  if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); NeoPixel_Printerstatus->setBrightness(NeoPixelPrinterStatus_Brightness); NeoPixel_Printerstatus->show();}
  for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
    if (NeoPixelHeater[i].Active == true) {NeoPixel_Heater[i]->clear(); NeoPixel_Heater[i]->setBrightness(NeoPixelHeater[i].Brightness); NeoPixel_Heater[i]->show();}
  }
}


// Main loop
void loop()
{
  //Read serial
  GetSerialMessage();

  //NeopixelRefresh?
  if ((millis() - NeoPixelTimerRefresh) >= NeopixelRefreshSpeed){
    NeoPixelTimerRefresh = millis();

    //New PrinterStatusUpdate?
    if (Printer.UpdatePending == true){

      #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL2_ACTIVE)
        for(int i = 0; i < NumberHeatersUsed; i++) {
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
        for (int i = 0; i < NumberHeatersUsed; i++){
          DebugPrinter.Heater_Status[i] = Printer.Heater_Status[i]
          DebugPrinter.Heater_ActTemp[i] = Printer.Heater_ActTemp[i];
          DebugPrinter.Heater_ActiveTemp[i] = Printer.Heater_ActiveTemp[i];
          DebugPrinter.Heater_StandbyTemp[i] = Printer.Heater_StandbyTemp[i];
        }  
        DebugPrinter.Status = Printer.Status;
        DebugPrinter.FractionPrinted = Printer.FractionPrinted;
        DebugPrinter.UpdatePending = DebugPrinter.UpdatePending;
      #endif 

      //Update Neopixels - Heater
      for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
        if (NeoPixelHeater[i].Active == true && NeoPixelHeater[i].ShowHeaters.length() > 0) {
          NeoPixelHeater_AnimationMemory[i].RangeBegin = 0;
          NeoPixelHeater_AnimationMemory[i].RangeEnd = 0;
          //Find heater to show
          ShowHeater = -1;
          StringPos= 0;
          HeaterDelimiterPos= 0;
          HeaterID= 0;
          // Find first "active" heater
          while (ShowHeater == -1 && StringPos < NeoPixelHeater[i].ShowHeaters.length()) {
            HeaterDelimiterPos= NeoPixelHeater[i].ShowHeaters.indexOf('&', StringPos);
            if (HeaterDelimiterPos == -1) {
              HeaterID= NeoPixelHeater[i].ShowHeaters.substring(StringPos, NeoPixelHeater[i].ShowHeaters.length()).toInt();
              StringPos++;
              if (Printer.Heater_Status[HeaterID] == 2) {ShowHeater= HeaterID;}
            }
            else {
              HeaterID= (NeoPixelHeater[i].ShowHeaters.substring(StringPos, HeaterDelimiterPos)).toInt();
              StringPos = HeaterDelimiterPos + 1;
              if (Printer.Heater_Status[HeaterID] == 2) {ShowHeater= HeaterID;}
            }
          }
          //Find first "standby" heater
          StringPos= 0;
          HeaterDelimiterPos= 0;
          HeaterID= 0;
          while (ShowHeater == -1 && StringPos <= NeoPixelHeater[i].ShowHeaters.length()) {
            HeaterDelimiterPos= NeoPixelHeater[i].ShowHeaters.indexOf('&', StringPos);
            if (HeaterDelimiterPos == -1) {
              HeaterID=NeoPixelHeater[i].ShowHeaters.substring(StringPos, NeoPixelHeater[i].ShowHeaters.length()).toInt();
              StringPos++;
              if (Printer.Heater_Status[HeaterID] == 1) {ShowHeater= HeaterID;}
            }
            else {
              HeaterID= (NeoPixelHeater[i].ShowHeaters.substring(StringPos, HeaterDelimiterPos)).toInt();
              StringPos = HeaterDelimiterPos + 1;
              if (Printer.Heater_Status[HeaterID] == 1) {ShowHeater= HeaterID;}
            }
          }
          //Find first "off" heater
          StringPos= 0;
          HeaterDelimiterPos= 0;
          HeaterID= 0;
          while (ShowHeater == -1 && StringPos <= NeoPixelHeater[i].ShowHeaters.length()) {
            HeaterDelimiterPos= NeoPixelHeater[i].ShowHeaters.indexOf('&', StringPos);
            if (HeaterDelimiterPos == -1) {
              HeaterID= NeoPixelHeater[i].ShowHeaters.substring(StringPos, NeoPixelHeater[i].ShowHeaters.length()).toInt();
              StringPos++;
              if (Printer.Heater_Status[HeaterID] == 0) {ShowHeater= HeaterID;}
            }
            else {
              HeaterID= (NeoPixelHeater[i].ShowHeaters.substring(StringPos, HeaterDelimiterPos)).toInt();
              StringPos = HeaterDelimiterPos + 1;
              if (Printer.Heater_Status[HeaterID] == 0) {ShowHeater= HeaterID;}
            }
          }
          
          #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL2_ACTIVE)
            Serial.println("=> ShowHeater: NeoPixelHeater[i] / FoundShowHeater= "+String(ShowHeater));
          #endif
          
          //Display heater status
          if (ShowHeater >= 0) {
            //If HeaterID has changed, reset AnimationMemory
            if (ShowHeater != NeoPixelHeater_AnimationMemory[i].ShowHeater_Memory) {
              NeoPixelHeater_AnimationMemory[i].ShowHeater_Memory = ShowHeater;
              NeoPixelHeater_AnimationMemory[i].Position = 0;
              NeoPixelHeater_AnimationMemory[i].Position_Memory = 0;
              NeoPixelHeater_AnimationMemory[i].RangeBegin = 0;
              NeoPixelHeater_AnimationMemory[i].RangeEnd = 0;
              NeoPixelHeater_AnimationMemory[i].Running = false;
              NeoPixel_Heater[i]->clear();
            }  
    
            SetTempHeater=0;
            ActTempHeater=Printer.Heater_ActTemp[ShowHeater];
            if (Printer.Heater_Status[ShowHeater] == 2){
              SetTempHeater=Printer.Heater_ActiveTemp[ShowHeater];
            }
            else if (Printer.Heater_Status[ShowHeater] == 1) {
              SetTempHeater=Printer.Heater_StandbyTemp[ShowHeater];
            }
            for (int NeoPixelPosition = 1; NeoPixelPosition <= NeoPixelHeater[i].LEDs; NeoPixelPosition++)
            {
              if((((ActTempHeater - NeoPixelHeater[i].TempOffset) / HeaterScale[ShowHeater]) < NeoPixelPosition) && (((SetTempHeater - NeoPixelHeater[i].TempOffset) / HeaterScale[ShowHeater]) >= NeoPixelPosition)) {
                NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater[i].LEDs,NeoPixelHeater[i].PixelOffset,NeoPixelPosition,NeoPixelHeater[i].AnimationReverse),NeoPixelHeater[i].ColorHeatUp);
                //Define Animation-Range
                if (NeoPixelHeater_AnimationMemory[i].RangeBegin == 0) {
                  NeoPixelHeater_AnimationMemory[i].RangeBegin = NeoPixelPosition;
                  NeoPixelHeater_AnimationMemory[i].RangeEnd = NeoPixelPosition;
                } else {
                  NeoPixelHeater_AnimationMemory[i].RangeEnd++;
                }
              }
              else if((((ActTempHeater - NeoPixelHeater[i].TempOffset) / HeaterScale[ShowHeater]) >= NeoPixelPosition) && (((SetTempHeater - NeoPixelHeater[i].TempOffset) / HeaterScale[ShowHeater]) >= NeoPixelPosition)) {
                NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater[i].LEDs,NeoPixelHeater[i].PixelOffset,NeoPixelPosition,NeoPixelHeater[i].AnimationReverse),NeoPixelHeater[i].ColorHeatUpDone);
              }
              else if((((ActTempHeater - NeoPixelHeater[i].TempOffset) / HeaterScale[ShowHeater]) >= NeoPixelPosition) && (((SetTempHeater - NeoPixelHeater[i].TempOffset) / HeaterScale[ShowHeater]) < NeoPixelPosition)) {
                NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater[i].LEDs,NeoPixelHeater[i].PixelOffset,NeoPixelPosition,NeoPixelHeater[i].AnimationReverse),NeoPixelHeater[i].ColorCoolDown);
              }
              else{
                NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater[i].LEDs,NeoPixelHeater[i].PixelOffset,NeoPixelPosition,NeoPixelHeater[i].AnimationReverse),NeoPixelHeater[i].ColorIdle);
              }
            }
          }
        }  
      }

      //Update Neopixel - PrinterStatus
      if (NeoPixelPrinterStatus_Active == true) {
        //Initialize AnimationRange
        NeoPixelPrinterStatus_AnimationMemory.RangeBegin = 0;
        NeoPixelPrinterStatus_AnimationMemory.RangeEnd = 0;
  
        //NeoPixel: Printer-Status & Print-Progress
        if(Printer.Status == 'P') { 
          //Display Print-Progress
          for (int NeoPixelPosition = 1; NeoPixelPosition <= NeoPixelPrinterStatus_LEDs; NeoPixelPosition++)
          {
            if(NeoPixelPosition < (Printer.FractionPrinted * NeoPixelPrinterStatus_LEDs)) {
              NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,NeoPixelPosition,NeoPixelPrinterStatus_Reverse),NeoPixelPrinterStatus_ColorPrintingDone);
            }
            else {
              NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,NeoPixelPosition,NeoPixelPrinterStatus_Reverse),NeoPixelPrinterStatus_ColorPrinting);
              //Define Animation-Range
              if (NeoPixelPrinterStatus_AnimationMemory.RangeBegin == 0) {
                NeoPixelPrinterStatus_AnimationMemory.RangeBegin = NeoPixelPosition;
                NeoPixelPrinterStatus_AnimationMemory.RangeEnd = NeoPixelPosition;
              } else {
                NeoPixelPrinterStatus_AnimationMemory.RangeEnd++;
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
              NeoPixel_Printerstatus->fill(NeoPixelPrinterStatus_ColorIdle);
              break;
            case 'P':
              NeoPixel_Printerstatus->fill(NeoPixelPrinterStatus_ColorPrinting);
              break;
            case 'S':
              NeoPixel_Printerstatus->fill(NeoPixelPrinterStatus_ColorStopped);
              break;
            case 'C':
              NeoPixel_Printerstatus->fill(NeoPixelPrinterStatus_ColorConfiguring);
              break;
            case 'A':
              NeoPixel_Printerstatus->fill(NeoPixelPrinterStatus_ColorPaused);
              break;
            case 'D':
              NeoPixel_Printerstatus->fill(NeoPixelPrinterStatus_ColorBusy);
              break;
            case 'R':
              NeoPixel_Printerstatus->fill(NeoPixelPrinterStatus_ColorPausing);
              break;
            case 'B':
              NeoPixel_Printerstatus->fill(NeoPixelPrinterStatus_ColorResuming);
              break;
            case 'F':
              NeoPixel_Printerstatus->fill(NeoPixelPrinterStatus_ColorFlashing);
              break;
            default:
              NeoPixel_Printerstatus->fill(NeoPixelPrinterStatus_ColorDefault);
              break;
          }
        }
      }
    }

    //Animation Neopixel - Heater
    for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
      if (NeoPixelHeater[i].Active == true && NeoPixelHeater[i].AnimationActive == true) {
        //AnimationRange exists?
        if (NeoPixelHeater_AnimationMemory[i].RangeBegin == 0) {
          NeoPixelHeater_AnimationMemory[i].Running = false;
        }
        else {
          //Animation initialize?
          if (NeoPixelHeater_AnimationMemory[i].Running == false) {
              NeoPixelHeater_AnimationMemory[i].Running = true;
              NeoPixelHeater_AnimationMemory[i].Position = NeoPixelHeater_AnimationMemory[i].RangeBegin;
              NeoPixelHeater_AnimationMemory[i].Position_Memory = 0;
              NeoPixelHeater_AnimationMemory[i].AnimationColor = 0;
          }
          //Restart animation at new position (next heatup step reached)?
          if (NeoPixelHeater_AnimationMemory[i].Position < NeoPixelHeater_AnimationMemory[i].RangeBegin) {
            NeoPixelHeater_AnimationMemory[i].Position = NeoPixelHeater_AnimationMemory[i].RangeBegin;
          }
          //Animation one step further
          if (NeoPixelHeater_AnimationMemory[i].Position_Memory != NeoPixelHeater_AnimationMemory[i].Position && NeoPixelHeater_AnimationMemory[i].Position_Memory >= NeoPixelHeater_AnimationMemory[i].RangeBegin) {
            NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater[i].LEDs,NeoPixelHeater[i].PixelOffset,NeoPixelHeater_AnimationMemory[i].Position_Memory,NeoPixelHeater[i].AnimationReverse),NeoPixelHeater[i].ColorHeatUp);
            NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater[i].LEDs,NeoPixelHeater[i].PixelOffset,NeoPixelHeater_AnimationMemory[i].Position,NeoPixelHeater[i].AnimationReverse),NeoPixelHeater[i].ColorAnimation);
            NeoPixelHeater_AnimationMemory[i].AnimationColor = 1;
          }
          else {
            //Animation phase1
            if (NeoPixelHeater_AnimationMemory[i].AnimationColor == 0) {
              NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater[i].LEDs,NeoPixelHeater[i].PixelOffset,NeoPixelHeater_AnimationMemory[i].Position,NeoPixelHeater[i].AnimationReverse),NeoPixelHeater[i].ColorAnimation);
              NeoPixelHeater_AnimationMemory[i].AnimationColor = 1;
            }
            else {
              //Animation phase2
              NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeater[i].LEDs,NeoPixelHeater[i].PixelOffset,NeoPixelHeater_AnimationMemory[i].Position,NeoPixelHeater[i].AnimationReverse),NeoPixelHeater[i].ColorHeatUp);
              NeoPixelHeater_AnimationMemory[i].AnimationColor = 0;
            }
          }
          NeoPixelHeater_AnimationMemory[i].Position_Memory = NeoPixelHeater_AnimationMemory[i].Position;
          NeoPixelHeater_AnimationMemory[i].Position++;
          //Restart animation at begin position?
          if (NeoPixelHeater_AnimationMemory[i].Position > NeoPixelHeater_AnimationMemory[i].RangeEnd) {
            NeoPixelHeater_AnimationMemory[i].Position = NeoPixelHeater_AnimationMemory[i].RangeBegin;
          }
        }
      }
    }  
    
    //Animation PrinterStatus
    if (NeoPixelPrinterStatus_Active == true && NeoPixelPrinterStatus_AnimationActive == true) {
      //AnimationRange exists?
      if (NeoPixelPrinterStatus_AnimationMemory.RangeBegin == 0) {
        NeoPixelPrinterStatus_AnimationMemory.Running = false;
      }
      else{
        //Animation initialize?
        if (NeoPixelPrinterStatus_AnimationMemory.Running == false) {
            NeoPixelPrinterStatus_AnimationMemory.Running = true;
            NeoPixelPrinterStatus_AnimationMemory.Position = NeoPixelPrinterStatus_AnimationMemory.RangeBegin;
            NeoPixelPrinterStatus_AnimationMemory.Position_Memory = 0;
            NeoPixelPrinterStatus_AnimationMemory.AnimationColor = 0;
        }
        //Restart animation at new position?
        if (NeoPixelPrinterStatus_AnimationMemory.Position < NeoPixelPrinterStatus_AnimationMemory.RangeBegin) {
          NeoPixelPrinterStatus_AnimationMemory.Position = NeoPixelPrinterStatus_AnimationMemory.RangeBegin;
        }

        //Animation one step further
        if (NeoPixelPrinterStatus_AnimationMemory.Position_Memory != NeoPixelPrinterStatus_AnimationMemory.Position && NeoPixelPrinterStatus_AnimationMemory.Position_Memory >= NeoPixelPrinterStatus_AnimationMemory.RangeBegin) {
          NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,NeoPixelPrinterStatus_AnimationMemory.Position_Memory,NeoPixelPrinterStatus_Reverse),NeoPixelPrinterStatus_ColorPrinting);
          NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,NeoPixelPrinterStatus_AnimationMemory.Position,NeoPixelPrinterStatus_Reverse),NeoPixelPrinterStatus_ColorAnimation);
          NeoPixelPrinterStatus_AnimationMemory.AnimationColor = 1;
        }
        else {
          //Animation phase1
          if (NeoPixelPrinterStatus_AnimationMemory.AnimationColor == 0) {
            NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,NeoPixelPrinterStatus_AnimationMemory.Position,NeoPixelPrinterStatus_Reverse),NeoPixelPrinterStatus_ColorAnimation);
            NeoPixelPrinterStatus_AnimationMemory.AnimationColor = 1;
          }
          else{
            //Animation phase2
            NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,NeoPixelPrinterStatus_AnimationMemory.Position,NeoPixelPrinterStatus_Reverse),NeoPixelPrinterStatus_ColorPrinting);
            NeoPixelPrinterStatus_AnimationMemory.AnimationColor = 0;
          }
        }  
        
        NeoPixelPrinterStatus_AnimationMemory.Position_Memory = NeoPixelPrinterStatus_AnimationMemory.Position;
        NeoPixelPrinterStatus_AnimationMemory.Position++;
        if (NeoPixelPrinterStatus_AnimationMemory.Position > NeoPixelPrinterStatus_AnimationMemory.RangeEnd) {
          NeoPixelPrinterStatus_AnimationMemory.Position = NeoPixelPrinterStatus_AnimationMemory.RangeBegin;
        }
      }
    }  
    //Neopixel refresh
    for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
      if (NeoPixelHeater[i].Active == true) {NeoPixel_Heater[i]->show();}
    }  
    if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->show();}
  }
}
