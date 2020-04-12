#include <Adafruit_NeoPixel.h>

//#define DEBUGLEVEL1_ACTIVE
//#define DEBUGLEVEL2_ACTIVE

// ***************************************
// ********** User-Config Begin **********

//General
#define NeoPixelStartupAnimationActive true  //Show Startup Animation for all Neopixels (true = activated / false = deactivated) !!Attention!! Animation will only be shown if all Neopixels have the same number of LEDs

//Heater-Config
#define Heater0_Scale 10  //Display scale factor for Heater 0 (Heatbed)
#define Heater0_ColorIdle 255,255,255  //RGB values for specified status
#define Heater0_ColorHeatUp 255,64,64  //RGB values for specified status
#define Heater0_ColorHeatUpDone 255,0,0  //RGB values for specified status
#define Heater0_ColorCoolDown 0,0,255  //RGB values for specified status
#define Heater0_ColorAnimation 0,0,0  //RGB values for specified status

#define Heater1_Scale 20  //Display scale factor for Heater 1
#define Heater1_ColorIdle 255,255,255  //RGB values for specified status
#define Heater1_ColorHeatUp 255,64,64  //RGB values for specified status
#define Heater1_ColorHeatUpDone 255,0,0  //RGB values for specified status
#define Heater1_ColorCoolDown 0,0,255  //RGB values for specified status
#define Heater1_ColorAnimation 0,0,0  //RGB values for specified status

#define Heater2_Scale 20  //Display scale factor for Heater 2
#define Heater2_ColorIdle 255,255,255  //RGB values for specified status
#define Heater2_ColorHeatUp 255,64,64  //RGB values for specified status
#define Heater2_ColorHeatUpDone 255,0,0  //RGB values for specified status
#define Heater2_ColorCoolDown 0,0,255  //RGB values for specified status
#define Heater2_ColorAnimation 0,0,0  //RGB values for specified status

#define Heater3_Scale 20  //Display scale factor for Heater 3
#define Heater3_ColorIdle 255,255,255  //RGB values for specified status
#define Heater3_ColorHeatUp 255,64,64  //RGB values for specified status
#define Heater3_ColorHeatUpDone 255,0,0  //RGB values for specified status
#define Heater3_ColorCoolDown 0,0,255  //RGB values for specified status
#define Heater3_ColorAnimation 0,0,0  //RGB values for specified status

#define Heater4_Scale 20  //Display scale factor for Heater 4
#define Heater4_ColorIdle 255,255,255  //RGB values for specified status
#define Heater4_ColorHeatUp 255,64,64  //RGB values for specified status
#define Heater4_ColorHeatUpDone 255,0,0  //RGB values for specified status
#define Heater4_ColorCoolDown 0,0,255  //RGB values for specified status
#define Heater4_ColorAnimation 0,0,0  //RGB values for specified status

//NeoPixel#1 - Printer status
#define NeoPixelPrinterStatus_Active true  //NeoPixel#1 (true = activated / false = deactivated)
#define NeoPixelPrinterStatus_StartupAnimationType 2  //Startup animation type (1-3)
#define NeoPixelPrinterStatus_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixelPrinterStatus_LEDs 16  //Number of NeoPixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixelPrinterStatus_ArduinoPin 7  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixelPrinterStatus_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the startpoint clockwise (positive offset) or anti-clockwise (negative offset).
#define NeoPixelPrinterStatus_AnimationActive false  //Animation for print progress (true = activated / false = deactivated)
#define NeoPixelPrinterStatus_Reverse false  //Reverse Direction of Animation (false = default / true = reversed)
#define NeoPixelPrinterStatus_Brightness 8  //Overall brightness of the Neopixel-LEDs
#define NeoPixelPrinterStatus_ColorIdle 255,255,255  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorPrinting 64,255,64  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorPrintingDone 0,255,0  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorStopped 0,0,255  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorConfiguring 255,255,0  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorPaused 160,32,240  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorBusy 255,255,0  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorPausing 160,32,240  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorResuming 255,255,0  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorFlashing 255,255,0  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorDefault 255,255,255  //RGB values for specified status
#define NeoPixelPrinterStatus_ColorAnimation 0,0,0  //RGB values for specified status

//NeoPixel#2 - Heater
#define NeoPixelHeater0_Active true  //NeoPixel#2 (true = activated / false = deactivated)
#define NeoPixelHeater0_StartupAnimationType 3  //Startup animation type (1-3)
#define NeoPixelHeater0_ShowHeaters 0  //Show temp of Heater n (multiple Heaters seperated by , / 0= Heatbed)
#define NeoPixelHeater0_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixelHeater0_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixelHeater0_ArduinoPin 6  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixelHeater0_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixelHeater0_TempOffset 0  //Minimum Temperature at which the first LED lights up
#define NeoPixelHeater0_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixelHeater0_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixelHeater0_Brightness 8  //Overall brightness of the Neopixel-LEDs

//NeoPixel#3 - Heater
#define NeoPixelHeater1_Active true  //NeoPixel#3 (true = activated / false = deactivated)
#define NeoPixelHeater1_StartupAnimationType 1  //Startup animation type (1-3)
#define NeoPixelHeater1_ShowHeaters 1  //Show temp of Heater n (multiple Heaters seperated by , / 0= Heatbed)
#define NeoPixelHeater1_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixelHeater1_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixelHeater1_ArduinoPin 8  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixelHeater1_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixelHeater1_TempOffset 0  //Minimum Temperature at which the first LED lights up
#define NeoPixelHeater1_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixelHeater1_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixelHeater1_Brightness 8  //Overall brightness of the Neopixel-LEDs

//NeoPixel#4 - Heater
#define NeoPixelHeater2_Active false  //NeoPixel#4 (true = activated / false = deactivated)
#define NeoPixelHeater2_StartupAnimationType 1  //Startup animation type (1-3)
#define NeoPixelHeater2_ShowHeaters 2  //Show temp of Heater n (multiple Heaters seperated by , / 0= Heatbed)
#define NeoPixelHeater2_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixelHeater2_LEDs 16  //Numbner of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixelHeater2_ArduinoPin 0  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixelHeater2_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixelHeater2_TempOffset 0  //Minimum Temperature at which the first LED lights up
#define NeoPixelHeater2_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixelHeater2_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixelHeater2_Brightness 8  //Overall brightness of the Neopixel-LEDs

//NeoPixel#5 - Heater
#define NeoPixelHeater3_Active false  //NeoPixel#5 (true = activated / false = deactivated)
#define NeoPixelHeater3_StartupAnimationType 1  //Startup animation type (1-3)
#define NeoPixelHeater3_ShowHeaters 3  //Show temp of Heater n (multiple Heaters seperated by , / 0= Heatbed)
#define NeoPixelHeater3_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixelHeater3_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixelHeater3_ArduinoPin 0  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixelHeater3_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixelHeater3_TempOffset 0  //Minimum Temperature at which the first LED lights up
#define NeoPixelHeater3_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixelHeater3_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixelHeater3_Brightness 8  //Overall brightness of the Neopixel-LEDs

//NeoPixel#6 - Heater
#define NeoPixelHeater4_Active false  //NeoPixel#6 (true = activated / false = deactivated)
#define NeoPixelHeater4_StartupAnimationType 1  //Startup animation type (1-3)
#define NeoPixelHeater4_ShowHeaters 4  //Show temp of Heater n (multiple Heaters seperated by , / 0= Heatbed)
#define NeoPixelHeater4_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixelHeater4_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixelHeater4_ArduinoPin 0  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixelHeater4_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixelHeater4_TempOffset 0  //Minimum Temperature at which the first LED lights up
#define NeoPixelHeater4_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixelHeater4_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixelHeater4_Brightness 8  //Overall brightness of the Neopixel-LEDs

// ********** User-Config End **********
// *************************************

#define SerialTimeout 150
#define NeopixelRefreshSpeed 200
#define SerialMessageBuffer 550
#define NumberHeatersUsed 5
#define NumberNeoPixelsUsedForHeaters 5

struct StructNeoPixelConfig {
  public:
  bool Active;
  int StartupAnimationType;
  int ShowHeaters[(NumberHeatersUsed + 1)];
  neoPixelType Type;
  uint16_t LEDs;
  uint16_t ArduinoPin;
  int PixelOffset;
  int TempOffset;
  bool AnimationActive;
  bool AnimationReverse;
  int Brightness;
};  
StructNeoPixelConfig NeoPixelHeaterConfig[NumberNeoPixelsUsedForHeaters];

struct StructNeoPixelAnimationMemory {
  public:
  bool Active;
  bool Reverse;
  bool Running;
  int Position;
  int Position_Memory;
  int RangeBegin;
  int RangeEnd;
  int ShowHeater;
  int AnimationColor;
};
StructNeoPixelAnimationMemory NeoPixelPrinterStatus_AnimationMemory;
StructNeoPixelAnimationMemory NeoPixelHeater_AnimationMemory[NumberNeoPixelsUsedForHeaters];

struct StructHeaterConfig {
  public:
  int Scale;
  uint32_t ColorIdle;
  uint32_t ColorHeatUp;
  uint32_t ColorHeatUpDone;
  uint32_t ColorCoolDown;
  uint32_t ColorAnimation;
};
StructHeaterConfig HeaterConfig[NumberHeatersUsed];

int ShowHeater;
int HeaterPos;
int HeaterID;
int TmpShowHeaters0[(NumberHeatersUsed + 1)] = {NeoPixelHeater0_ShowHeaters , -1};
int TmpShowHeaters1[(NumberHeatersUsed + 1)] = {NeoPixelHeater1_ShowHeaters , -1};
int TmpShowHeaters2[(NumberHeatersUsed + 1)] = {NeoPixelHeater2_ShowHeaters , -1};
int TmpShowHeaters3[(NumberHeatersUsed + 1)] = {NeoPixelHeater3_ShowHeaters , -1};
int TmpShowHeaters4[(NumberHeatersUsed + 1)] = {NeoPixelHeater4_ShowHeaters , -1};
int SetTempHeater;
int ActTempHeater;
unsigned long NeoPixelTimerRefresh = millis();
char SerialMessage[SerialMessageBuffer]; 

Adafruit_NeoPixel *NeoPixel_Printerstatus;
Adafruit_NeoPixel *NeoPixel_Heater[NumberNeoPixelsUsedForHeaters];

struct StructPanelDueMessage {
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
StructPanelDueMessage Printer;

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
    while(SerialMessageComplete == false  && ((millis() - timer) <= SerialTimeout) && Serial2.available() > 0) 
    {
      inChar = Serial2.read();
    #endif 
    
    //Arduino-Pro & Co.
    #if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
    while(SerialMessageComplete == false  && ((millis() - timer) <= SerialTimeout) && Serial.available() > 0) 
    {
      inChar = Serial.read();
    #endif 
    
    //Arduino-Leonardo & Co.
    #if defined(__AVR_ATmega32U4__)
    while(SerialMessageComplete == false  && ((millis() - timer) <= SerialTimeout) && Serial1.available() > 0) 
    {
      inChar = Serial1.read();
    #endif 
    
    //Arduino-Due
    #if defined(__SAM3X8E__)
    while(SerialMessageComplete == false  && ((millis() - timer) <= SerialTimeout) && Serial3.available() > 0) 
    {
      inChar = Serial3.read();
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
  
  NeoPixelHeaterConfig[0].Active = NeoPixelHeater0_Active;
  NeoPixelHeaterConfig[0].StartupAnimationType = NeoPixelHeater0_StartupAnimationType;
  NeoPixelHeaterConfig[0].Type = NeoPixelHeater0_Type;
  NeoPixelHeaterConfig[0].LEDs = NeoPixelHeater0_LEDs;
  NeoPixelHeaterConfig[0].ArduinoPin = NeoPixelHeater0_ArduinoPin;
  NeoPixelHeaterConfig[0].PixelOffset = NeoPixelHeater0_PixelOffset;
  NeoPixelHeaterConfig[0].TempOffset = NeoPixelHeater0_TempOffset;
  NeoPixelHeaterConfig[0].AnimationActive = NeoPixelHeater0_AnimationActive;
  NeoPixelHeaterConfig[0].AnimationReverse = NeoPixelHeater0_Reverse;
  NeoPixelHeaterConfig[0].Brightness = NeoPixelHeater0_Brightness;
  NeoPixelHeaterConfig[1].Active = NeoPixelHeater1_Active;
  NeoPixelHeaterConfig[1].StartupAnimationType = NeoPixelHeater1_StartupAnimationType;
  NeoPixelHeaterConfig[1].Type = NeoPixelHeater1_Type;
  NeoPixelHeaterConfig[1].LEDs = NeoPixelHeater1_LEDs;
  NeoPixelHeaterConfig[1].ArduinoPin = NeoPixelHeater1_ArduinoPin;
  NeoPixelHeaterConfig[1].PixelOffset = NeoPixelHeater1_PixelOffset;
  NeoPixelHeaterConfig[1].TempOffset = NeoPixelHeater1_TempOffset;
  NeoPixelHeaterConfig[1].AnimationActive = NeoPixelHeater1_AnimationActive;
  NeoPixelHeaterConfig[1].AnimationReverse = NeoPixelHeater1_Reverse;
  NeoPixelHeaterConfig[1].Brightness = NeoPixelHeater1_Brightness;
  NeoPixelHeaterConfig[2].Active = NeoPixelHeater2_Active;
  NeoPixelHeaterConfig[2].StartupAnimationType = NeoPixelHeater2_StartupAnimationType;
  NeoPixelHeaterConfig[2].Type = NeoPixelHeater2_Type;
  NeoPixelHeaterConfig[2].LEDs = NeoPixelHeater2_LEDs;
  NeoPixelHeaterConfig[2].ArduinoPin = NeoPixelHeater2_ArduinoPin;
  NeoPixelHeaterConfig[2].PixelOffset = NeoPixelHeater2_PixelOffset;
  NeoPixelHeaterConfig[2].TempOffset = NeoPixelHeater2_TempOffset;
  NeoPixelHeaterConfig[2].AnimationActive = NeoPixelHeater2_AnimationActive;
  NeoPixelHeaterConfig[2].AnimationReverse = NeoPixelHeater2_Reverse;
  NeoPixelHeaterConfig[2].Brightness = NeoPixelHeater2_Brightness;
  NeoPixelHeaterConfig[3].Active = NeoPixelHeater3_Active;
  NeoPixelHeaterConfig[3].StartupAnimationType = NeoPixelHeater3_StartupAnimationType;
  NeoPixelHeaterConfig[3].Type = NeoPixelHeater3_Type;
  NeoPixelHeaterConfig[3].LEDs = NeoPixelHeater3_LEDs;
  NeoPixelHeaterConfig[3].ArduinoPin = NeoPixelHeater3_ArduinoPin;
  NeoPixelHeaterConfig[3].PixelOffset = NeoPixelHeater3_PixelOffset;
  NeoPixelHeaterConfig[3].TempOffset = NeoPixelHeater3_TempOffset;
  NeoPixelHeaterConfig[3].AnimationActive = NeoPixelHeater3_AnimationActive;
  NeoPixelHeaterConfig[3].AnimationReverse = NeoPixelHeater3_Reverse;
  NeoPixelHeaterConfig[3].Brightness = NeoPixelHeater3_Brightness;
  NeoPixelHeaterConfig[4].Active = NeoPixelHeater4_Active;
  NeoPixelHeaterConfig[4].StartupAnimationType = NeoPixelHeater4_StartupAnimationType;
  NeoPixelHeaterConfig[4].Type = NeoPixelHeater4_Type;
  NeoPixelHeaterConfig[4].LEDs = NeoPixelHeater4_LEDs;
  NeoPixelHeaterConfig[4].ArduinoPin = NeoPixelHeater4_ArduinoPin;
  NeoPixelHeaterConfig[4].PixelOffset = NeoPixelHeater4_PixelOffset;
  NeoPixelHeaterConfig[4].TempOffset = NeoPixelHeater4_TempOffset;
  NeoPixelHeaterConfig[4].AnimationActive = NeoPixelHeater4_AnimationActive;
  NeoPixelHeaterConfig[4].AnimationReverse = NeoPixelHeater4_Reverse;
  NeoPixelHeaterConfig[4].Brightness = NeoPixelHeater4_Brightness;

  int i;
  for (i = 0; TmpShowHeaters0[i] != -1; i++) {NeoPixelHeaterConfig[0].ShowHeaters[i] = TmpShowHeaters0[i];} NeoPixelHeaterConfig[0].ShowHeaters[i] = -1;
  for (i = 0; TmpShowHeaters1[i] != -1; i++) {NeoPixelHeaterConfig[1].ShowHeaters[i] = TmpShowHeaters1[i];} NeoPixelHeaterConfig[1].ShowHeaters[i] = -1;
  for (i = 0; TmpShowHeaters2[i] != -1; i++) {NeoPixelHeaterConfig[2].ShowHeaters[i] = TmpShowHeaters2[i];} NeoPixelHeaterConfig[2].ShowHeaters[i] = -1;
  for (i = 0; TmpShowHeaters3[i] != -1; i++) {NeoPixelHeaterConfig[3].ShowHeaters[i] = TmpShowHeaters3[i];} NeoPixelHeaterConfig[3].ShowHeaters[i] = -1;
  for (i = 0; TmpShowHeaters4[i] != -1; i++) {NeoPixelHeaterConfig[4].ShowHeaters[i] = TmpShowHeaters4[i];} NeoPixelHeaterConfig[4].ShowHeaters[i] = -1;

  HeaterConfig[0].Scale = Heater0_Scale;
  HeaterConfig[0].ColorIdle = ConvertColor(Heater0_ColorIdle);
  HeaterConfig[0].ColorHeatUp = ConvertColor(Heater0_ColorHeatUp);
  HeaterConfig[0].ColorHeatUpDone = ConvertColor(Heater0_ColorHeatUpDone);
  HeaterConfig[0].ColorCoolDown = ConvertColor(Heater0_ColorCoolDown);
  HeaterConfig[0].ColorAnimation = ConvertColor(Heater0_ColorAnimation);
  HeaterConfig[1].Scale = Heater1_Scale;
  HeaterConfig[1].ColorIdle = ConvertColor(Heater1_ColorIdle);
  HeaterConfig[1].ColorHeatUp = ConvertColor(Heater1_ColorHeatUp);
  HeaterConfig[1].ColorHeatUpDone = ConvertColor(Heater1_ColorHeatUpDone);
  HeaterConfig[1].ColorCoolDown = ConvertColor(Heater1_ColorCoolDown);
  HeaterConfig[1].ColorAnimation = ConvertColor(Heater1_ColorAnimation);
  HeaterConfig[2].Scale = Heater2_Scale;
  HeaterConfig[2].ColorIdle = ConvertColor(Heater2_ColorIdle);
  HeaterConfig[2].ColorHeatUp = ConvertColor(Heater2_ColorHeatUp);
  HeaterConfig[2].ColorHeatUpDone = ConvertColor(Heater2_ColorHeatUpDone);
  HeaterConfig[2].ColorCoolDown = ConvertColor(Heater2_ColorCoolDown);
  HeaterConfig[2].ColorAnimation = ConvertColor(Heater2_ColorAnimation);
  HeaterConfig[3].Scale = Heater3_Scale;
  HeaterConfig[3].ColorIdle = ConvertColor(Heater3_ColorIdle);
  HeaterConfig[3].ColorHeatUp = ConvertColor(Heater3_ColorHeatUp);
  HeaterConfig[3].ColorHeatUpDone = ConvertColor(Heater3_ColorHeatUpDone);
  HeaterConfig[3].ColorCoolDown = ConvertColor(Heater3_ColorCoolDown);
  HeaterConfig[3].ColorAnimation = ConvertColor(Heater3_ColorAnimation);
  HeaterConfig[4].Scale = Heater4_Scale;
  HeaterConfig[4].ColorIdle = ConvertColor(Heater4_ColorIdle);
  HeaterConfig[4].ColorHeatUp = ConvertColor(Heater4_ColorHeatUp);
  HeaterConfig[4].ColorHeatUpDone = ConvertColor(Heater4_ColorHeatUpDone);
  HeaterConfig[4].ColorCoolDown = ConvertColor(Heater4_ColorCoolDown);
  HeaterConfig[4].ColorAnimation = ConvertColor(Heater4_ColorAnimation);
  
  NeoPixel_Printerstatus = new Adafruit_NeoPixel(NeoPixelPrinterStatus_LEDs, NeoPixelPrinterStatus_ArduinoPin, NeoPixelPrinterStatus_Type);
  for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
    NeoPixel_Heater[i] = new Adafruit_NeoPixel(NeoPixelHeaterConfig[i].LEDs, NeoPixelHeaterConfig[i].ArduinoPin, NeoPixelHeaterConfig[i].Type);
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
  //Arduino-Due
  #if defined(__SAM3X8E__)
    Serial3.begin(57600);
    while(!Serial3)
    {;}
  #endif 

  // Initialize Neopixels
  if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->begin(); NeoPixel_Printerstatus->show();}
  for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
    if (NeoPixelHeaterConfig[i].Active == true) {NeoPixel_Heater[i]->begin(); NeoPixel_Heater[i]->show();}
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
      if (NeoPixelHeaterConfig[i].Active == true) {
        if (NeoPixelCount == 0) {
          NeoPixelCount = NeoPixelHeaterConfig[i].LEDs;
        }  
        else {
          if (NeoPixelHeaterConfig[i].LEDs != NeoPixelCount) {
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
        if (NeoPixelHeaterConfig[i].Active == true) {NeoPixel_Heater[i]->setBrightness(255);}
      }

      //Startup Animation #1a
  		for (int j = 0; j < NeoPixelCount; j++) {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: AnimationColor = ConvertColor(255, 0, 0); break; case 2: AnimationColor = ConvertColor(0, 255, 0); break; case 3: AnimationColor = ConvertColor(0, 0, 255); break;} NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,(j+1),NeoPixelPrinterStatus_Reverse), AnimationColor); NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeaterConfig[i].Active == true) {NeoPixel_Heater[i]->clear(); switch (NeoPixelHeaterConfig[i].StartupAnimationType) {case 1: AnimationColor = ConvertColor(255, 0, 0); break; case 2: AnimationColor = ConvertColor(0, 255, 0); break; case 3: AnimationColor = ConvertColor(0, 0, 255); break;} NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeaterConfig[i].LEDs,NeoPixelHeaterConfig[i].PixelOffset,(j+1),NeoPixelHeaterConfig[i].AnimationReverse), AnimationColor); NeoPixel_Heater[i]->show();}
        }
        delay(30);
      }
      //Startup Animation #1b
      for (int j = 0; j < NeoPixelCount; j++) {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: AnimationColor = ConvertColor(0, 255, 0); break; case 2: AnimationColor = ConvertColor(0, 0, 255); break; case 3: AnimationColor = ConvertColor(255, 0, 0); break;} NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,(j+1),NeoPixelPrinterStatus_Reverse), AnimationColor); NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeaterConfig[i].Active == true) {NeoPixel_Heater[i]->clear(); switch (NeoPixelHeaterConfig[i].StartupAnimationType) {case 1: AnimationColor = ConvertColor(0, 255, 0); break; case 2: AnimationColor = ConvertColor(0, 0, 255); break; case 3: AnimationColor = ConvertColor(255, 0, 0); break;} NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeaterConfig[i].LEDs,NeoPixelHeaterConfig[i].PixelOffset,(j+1),NeoPixelHeaterConfig[i].AnimationReverse), AnimationColor); NeoPixel_Heater[i]->show();}
        }
        delay(30);
      }
      //Startup Animation #1c
      for (int j = 0; j < NeoPixelCount; j++) {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: AnimationColor = ConvertColor(0, 0, 255); break; case 2: AnimationColor = ConvertColor(255, 0, 0); break; case 3: AnimationColor = ConvertColor(0, 255, 0); break;} NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,(j+1),NeoPixelPrinterStatus_Reverse), AnimationColor); NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeaterConfig[i].Active == true) {NeoPixel_Heater[i]->clear(); switch (NeoPixelHeaterConfig[i].StartupAnimationType) {case 1: AnimationColor = ConvertColor(0, 0, 255); break; case 2: AnimationColor = ConvertColor(255, 0, 0); break; case 3: AnimationColor = ConvertColor(0, 255, 0); break;} NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeaterConfig[i].LEDs,NeoPixelHeaterConfig[i].PixelOffset,(j+1),NeoPixelHeaterConfig[i].AnimationReverse), AnimationColor); NeoPixel_Heater[i]->show();}
        }
        delay(30);
      }

      //Startup Animation #2a1
  		for(int j = 0; j < 255; j++)
  		{
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); NeoPixel_Printerstatus->setBrightness(j); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: NeoPixel_Printerstatus->fill(ConvertColor(255, 0, 0)); break; case 2: NeoPixel_Printerstatus->fill(ConvertColor(0, 255, 0)); break; case 3: NeoPixel_Printerstatus->fill(ConvertColor(0, 0, 255)); break;} NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeaterConfig[i].Active == true) {NeoPixel_Heater[i]->clear(); NeoPixel_Heater[i]->setBrightness(j); switch (NeoPixelHeaterConfig[i].StartupAnimationType) {case 1: NeoPixel_Heater[i]->fill(ConvertColor(255, 0, 0)); break; case 2: NeoPixel_Heater[i]->fill(ConvertColor(0, 255, 0)); break; case 3: NeoPixel_Heater[i]->fill(ConvertColor(0, 0, 255)); break;} NeoPixel_Heater[i]->show();}
        }
        delay(1);
  		}
      //Startup Animation #2a2
      for(int j = 255; j >= 0; j--)
      {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); NeoPixel_Printerstatus->setBrightness(j); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: NeoPixel_Printerstatus->fill(ConvertColor(255, 0, 0)); break; case 2: NeoPixel_Printerstatus->fill(ConvertColor(0, 255, 0)); break; case 3: NeoPixel_Printerstatus->fill(ConvertColor(0, 0, 255)); break;} NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeaterConfig[i].Active == true) {NeoPixel_Heater[i]->clear(); NeoPixel_Heater[i]->setBrightness(j); switch (NeoPixelHeaterConfig[i].StartupAnimationType) {case 1: NeoPixel_Heater[i]->fill(ConvertColor(255, 0, 0)); break; case 2: NeoPixel_Heater[i]->fill(ConvertColor(0, 255, 0)); break; case 3: NeoPixel_Heater[i]->fill(ConvertColor(0, 0, 255)); break;} NeoPixel_Heater[i]->show();}
        }
        delay(1);
      }
      //Startup Animation #2b1
      for(int j = 0; j < 255; j++)
      {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); NeoPixel_Printerstatus->setBrightness(j); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: NeoPixel_Printerstatus->fill(ConvertColor(0, 255, 0)); break; case 2: NeoPixel_Printerstatus->fill(ConvertColor(0, 0, 255)); break; case 3: NeoPixel_Printerstatus->fill(ConvertColor(255, 0, 0)); break;} NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeaterConfig[i].Active == true) {NeoPixel_Heater[i]->clear(); NeoPixel_Heater[i]->setBrightness(j); switch (NeoPixelHeaterConfig[i].StartupAnimationType) {case 1: NeoPixel_Heater[i]->fill(ConvertColor(0, 255, 0)); break; case 2: NeoPixel_Heater[i]->fill(ConvertColor(0, 0, 255)); break; case 3: NeoPixel_Heater[i]->fill(ConvertColor(255, 0, 0)); break;} NeoPixel_Heater[i]->show();}
        }
        delay(1);
      }
      //Startup Animation #2b2
      for(int j = 255; j >= 0; j--)
      {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); NeoPixel_Printerstatus->setBrightness(j); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: NeoPixel_Printerstatus->fill(ConvertColor(0, 255, 0)); break; case 2: NeoPixel_Printerstatus->fill(ConvertColor(0, 0, 255)); break; case 3: NeoPixel_Printerstatus->fill(ConvertColor(255, 0, 0)); break;} NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeaterConfig[i].Active == true) {NeoPixel_Heater[i]->clear(); NeoPixel_Heater[i]->setBrightness(j); switch (NeoPixelHeaterConfig[i].StartupAnimationType) {case 1: NeoPixel_Heater[i]->fill(ConvertColor(0, 255, 0)); break; case 2: NeoPixel_Heater[i]->fill(ConvertColor(0, 0, 255)); break; case 3: NeoPixel_Heater[i]->fill(ConvertColor(255, 0, 0)); break;} NeoPixel_Heater[i]->show();}
        }
        delay(1);
      }
      //Startup Animation #2c1
      for(int j = 0; j < 255; j++)
      {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); NeoPixel_Printerstatus->setBrightness(j); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: NeoPixel_Printerstatus->fill(ConvertColor(0, 0, 255)); break; case 2: NeoPixel_Printerstatus->fill(ConvertColor(255, 0, 0)); break; case 3: NeoPixel_Printerstatus->fill(ConvertColor(0, 255, 0)); break;} NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeaterConfig[i].Active == true) {NeoPixel_Heater[i]->clear(); NeoPixel_Heater[i]->setBrightness(j); switch (NeoPixelHeaterConfig[i].StartupAnimationType) {case 1: NeoPixel_Heater[i]->fill(ConvertColor(0, 0, 255)); break; case 2: NeoPixel_Heater[i]->fill(ConvertColor(255, 0, 0)); break; case 3: NeoPixel_Heater[i]->fill(ConvertColor(0, 255, 0)); break;} NeoPixel_Heater[i]->show();}
        }
        delay(1);
      }
      //Startup Animation #2c2
      for(int j = 255; j >= 0; j--)
      {
        if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); NeoPixel_Printerstatus->setBrightness(j); switch (NeoPixelPrinterStatus_StartupAnimationType) {case 1: NeoPixel_Printerstatus->fill(ConvertColor(0, 0, 255)); break; case 2: NeoPixel_Printerstatus->fill(ConvertColor(255, 0, 0)); break; case 3: NeoPixel_Printerstatus->fill(ConvertColor(0, 255, 0)); break;} NeoPixel_Printerstatus->show();}
        for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
          if (NeoPixelHeaterConfig[i].Active == true) {NeoPixel_Heater[i]->clear(); NeoPixel_Heater[i]->setBrightness(j); switch (NeoPixelHeaterConfig[i].StartupAnimationType) {case 1: NeoPixel_Heater[i]->fill(ConvertColor(0, 0, 255)); break; case 2: NeoPixel_Heater[i]->fill(ConvertColor(255, 0, 0)); break; case 3: NeoPixel_Heater[i]->fill(ConvertColor(0, 255, 0)); break;} NeoPixel_Heater[i]->show();}
        }
        delay(1);
      }
  	}	
  }  
  
  //Initial Neopixel for Loop
  if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->clear(); NeoPixel_Printerstatus->setBrightness(NeoPixelPrinterStatus_Brightness); NeoPixel_Printerstatus->show();}
  for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
    if (NeoPixelHeaterConfig[i].Active == true) {NeoPixel_Heater[i]->clear(); NeoPixel_Heater[i]->setBrightness(NeoPixelHeaterConfig[i].Brightness); NeoPixel_Heater[i]->show();}
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
      Printer.UpdatePending = false;

      //Update Neopixels - Heater
      for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
        if (NeoPixelHeaterConfig[i].Active == true && NeoPixelHeaterConfig[i].ShowHeaters[0] != -1) {
          NeoPixelHeater_AnimationMemory[i].RangeBegin = 0;
          NeoPixelHeater_AnimationMemory[i].RangeEnd = 0;

          //Find heater to show
          ShowHeater = -1;
          HeaterID= 0;
          // Find first "active" heater
          HeaterPos = 0;
          while (ShowHeater == -1 && NeoPixelHeaterConfig[i].ShowHeaters[HeaterPos] != -1) {
            HeaterID = NeoPixelHeaterConfig[i].ShowHeaters[HeaterPos];
            HeaterPos++;
            if (Printer.Heater_Status[HeaterID] == 2) {ShowHeater= HeaterID;}
          }
          //Find first "standby" heater
          HeaterPos = 0;
          while (ShowHeater == -1 && NeoPixelHeaterConfig[i].ShowHeaters[HeaterPos] != -1) {
            HeaterID = NeoPixelHeaterConfig[i].ShowHeaters[HeaterPos];
            HeaterPos++;
            if (Printer.Heater_Status[HeaterID] == 1) {ShowHeater= HeaterID;}
          }
          //Find first "off" heater
          HeaterPos = 0;
          while (ShowHeater == -1 && NeoPixelHeaterConfig[i].ShowHeaters[HeaterPos] != -1) {
            HeaterID = NeoPixelHeaterConfig[i].ShowHeaters[HeaterPos];
            HeaterPos++;
            if (Printer.Heater_Status[HeaterID] == 0) {ShowHeater= HeaterID;}
          }

          //Display heater status
          if (ShowHeater >= 0) {
            //If HeaterID has changed, reset AnimationMemory
            if (ShowHeater != NeoPixelHeater_AnimationMemory[i].ShowHeater) {
              NeoPixelHeater_AnimationMemory[i].ShowHeater = ShowHeater;
              NeoPixelHeater_AnimationMemory[i].Position = 0;
              NeoPixelHeater_AnimationMemory[i].Position_Memory = 0;
              NeoPixelHeater_AnimationMemory[i].RangeBegin = 0;
              NeoPixelHeater_AnimationMemory[i].RangeEnd = 0;
              NeoPixelHeater_AnimationMemory[i].Running = false;
              NeoPixelHeater_AnimationMemory[i].AnimationColor = 0;
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

            #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL2_ACTIVE)
              Serial.print("NeoPixelID["); Serial.print(i); Serial.print("]= "); Serial.print(ShowHeater); Serial.print(" / SetTemp= "); Serial.print(SetTempHeater); Serial.print(" / ActTemp= "); Serial.print(ActTempHeater); Serial.println("");
              Serial.print("0= "); Serial.print(NeoPixelHeaterConfig[i].ShowHeaters[0]); Serial.print(" / 1= "); Serial.print(NeoPixelHeaterConfig[i].ShowHeaters[1]); Serial.print(" / 2= "); Serial.print(NeoPixelHeaterConfig[i].ShowHeaters[2]); Serial.print(" / 3= "); Serial.print(NeoPixelHeaterConfig[i].ShowHeaters[3]); Serial.print(" / 4= "); Serial.print(NeoPixelHeaterConfig[i].ShowHeaters[4]); Serial.print(" / 5= "); Serial.print(NeoPixelHeaterConfig[i].ShowHeaters[5]); Serial.println(""); Serial.println("");
            #endif 

            for (int NeoPixelPosition = 1; NeoPixelPosition <= NeoPixelHeaterConfig[i].LEDs; NeoPixelPosition++)
            {
              if((((ActTempHeater - NeoPixelHeaterConfig[i].TempOffset) / HeaterConfig[ShowHeater].Scale) < NeoPixelPosition) && (((SetTempHeater - NeoPixelHeaterConfig[i].TempOffset) / HeaterConfig[ShowHeater].Scale) >= NeoPixelPosition)) {
                NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeaterConfig[i].LEDs,NeoPixelHeaterConfig[i].PixelOffset,NeoPixelPosition,NeoPixelHeaterConfig[i].AnimationReverse),HeaterConfig[ShowHeater].ColorHeatUp);
                //Define Animation-Range
                if (NeoPixelHeater_AnimationMemory[i].RangeBegin == 0) {
                  NeoPixelHeater_AnimationMemory[i].RangeBegin = NeoPixelPosition;
                  NeoPixelHeater_AnimationMemory[i].RangeEnd = NeoPixelPosition;
                } else {
                  NeoPixelHeater_AnimationMemory[i].RangeEnd++;
                }
              }
              else if((((ActTempHeater - NeoPixelHeaterConfig[i].TempOffset) / HeaterConfig[ShowHeater].Scale) >= NeoPixelPosition) && (((SetTempHeater - NeoPixelHeaterConfig[i].TempOffset) / HeaterConfig[ShowHeater].Scale) >= NeoPixelPosition)) {
                NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeaterConfig[i].LEDs,NeoPixelHeaterConfig[i].PixelOffset,NeoPixelPosition,NeoPixelHeaterConfig[i].AnimationReverse),HeaterConfig[ShowHeater].ColorHeatUpDone);
              }
              else if((((ActTempHeater - NeoPixelHeaterConfig[i].TempOffset) / HeaterConfig[ShowHeater].Scale) >= NeoPixelPosition) && (((SetTempHeater - NeoPixelHeaterConfig[i].TempOffset) / HeaterConfig[ShowHeater].Scale) < NeoPixelPosition)) {
                NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeaterConfig[i].LEDs,NeoPixelHeaterConfig[i].PixelOffset,NeoPixelPosition,NeoPixelHeaterConfig[i].AnimationReverse),HeaterConfig[ShowHeater].ColorCoolDown);
              }
              else{
                NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeaterConfig[i].LEDs,NeoPixelHeaterConfig[i].PixelOffset,NeoPixelPosition,NeoPixelHeaterConfig[i].AnimationReverse),HeaterConfig[ShowHeater].ColorIdle);
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
              NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,NeoPixelPosition,NeoPixelPrinterStatus_Reverse),ConvertColor(NeoPixelPrinterStatus_ColorPrintingDone));
            }
            else {
              NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,NeoPixelPosition,NeoPixelPrinterStatus_Reverse),ConvertColor(NeoPixelPrinterStatus_ColorPrinting));
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
              NeoPixel_Printerstatus->fill(ConvertColor(NeoPixelPrinterStatus_ColorIdle));
              break;
            case 'P':
              NeoPixel_Printerstatus->fill(ConvertColor(NeoPixelPrinterStatus_ColorPrinting));
              break;
            case 'S':
              NeoPixel_Printerstatus->fill(ConvertColor(NeoPixelPrinterStatus_ColorStopped));
              break;
            case 'C':
              NeoPixel_Printerstatus->fill(ConvertColor(NeoPixelPrinterStatus_ColorConfiguring));
              break;
            case 'A':
              NeoPixel_Printerstatus->fill(ConvertColor(NeoPixelPrinterStatus_ColorPaused));
              break;
            case 'D':
              NeoPixel_Printerstatus->fill(ConvertColor(NeoPixelPrinterStatus_ColorBusy));
              break;
            case 'R':
              NeoPixel_Printerstatus->fill(ConvertColor(NeoPixelPrinterStatus_ColorPausing));
              break;
            case 'B':
              NeoPixel_Printerstatus->fill(ConvertColor(NeoPixelPrinterStatus_ColorResuming));
              break;
            case 'F':
              NeoPixel_Printerstatus->fill(ConvertColor(NeoPixelPrinterStatus_ColorFlashing));
              break;
            default:
              NeoPixel_Printerstatus->fill(ConvertColor(NeoPixelPrinterStatus_ColorDefault));
              break;
          }
        }
      }
    }

    //Animation Neopixel - Heater
    for (int i = 0; i < NumberNeoPixelsUsedForHeaters; i++){
      if (NeoPixelHeaterConfig[i].Active == true && NeoPixelHeaterConfig[i].AnimationActive == true) {
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
            NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeaterConfig[i].LEDs,NeoPixelHeaterConfig[i].PixelOffset,NeoPixelHeater_AnimationMemory[i].Position_Memory,NeoPixelHeaterConfig[i].AnimationReverse),HeaterConfig[NeoPixelHeater_AnimationMemory[i].ShowHeater].ColorHeatUp);
            NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeaterConfig[i].LEDs,NeoPixelHeaterConfig[i].PixelOffset,NeoPixelHeater_AnimationMemory[i].Position,NeoPixelHeaterConfig[i].AnimationReverse),HeaterConfig[NeoPixelHeater_AnimationMemory[i].ShowHeater].ColorAnimation);
            NeoPixelHeater_AnimationMemory[i].AnimationColor = 1;
          }
          else {
            //Animation phase1
            if (NeoPixelHeater_AnimationMemory[i].AnimationColor == 0) {
              NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeaterConfig[i].LEDs,NeoPixelHeaterConfig[i].PixelOffset,NeoPixelHeater_AnimationMemory[i].Position,NeoPixelHeaterConfig[i].AnimationReverse),HeaterConfig[NeoPixelHeater_AnimationMemory[i].ShowHeater].ColorAnimation);
              NeoPixelHeater_AnimationMemory[i].AnimationColor = 1;
            }
            else {
              //Animation phase2
              NeoPixel_Heater[i]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelHeaterConfig[i].LEDs,NeoPixelHeaterConfig[i].PixelOffset,NeoPixelHeater_AnimationMemory[i].Position,NeoPixelHeaterConfig[i].AnimationReverse),HeaterConfig[NeoPixelHeater_AnimationMemory[i].ShowHeater].ColorHeatUp);
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
          NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,NeoPixelPrinterStatus_AnimationMemory.Position_Memory,NeoPixelPrinterStatus_Reverse),ConvertColor(NeoPixelPrinterStatus_ColorPrinting));
          NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,NeoPixelPrinterStatus_AnimationMemory.Position,NeoPixelPrinterStatus_Reverse),ConvertColor(NeoPixelPrinterStatus_ColorAnimation));
          NeoPixelPrinterStatus_AnimationMemory.AnimationColor = 1;
        }
        else {
          //Animation phase1
          if (NeoPixelPrinterStatus_AnimationMemory.AnimationColor == 0) {
            NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,NeoPixelPrinterStatus_AnimationMemory.Position,NeoPixelPrinterStatus_Reverse),ConvertColor(NeoPixelPrinterStatus_ColorAnimation));
            NeoPixelPrinterStatus_AnimationMemory.AnimationColor = 1;
          }
          else{
            //Animation phase2
            NeoPixel_Printerstatus->setPixelColor(ConvertPosition2PixelIndex(NeoPixelPrinterStatus_LEDs,NeoPixelPrinterStatus_PixelOffset,NeoPixelPrinterStatus_AnimationMemory.Position,NeoPixelPrinterStatus_Reverse),ConvertColor(NeoPixelPrinterStatus_ColorPrinting));
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
      if (NeoPixelHeaterConfig[i].Active == true) {NeoPixel_Heater[i]->show();}
    }  
    if (NeoPixelPrinterStatus_Active == true) {NeoPixel_Printerstatus->show();}
  }
}
