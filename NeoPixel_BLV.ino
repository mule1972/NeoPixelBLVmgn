#include <Adafruit_NeoPixel.h>

//#define DEBUGLEVEL1_ACTIVE
//#define DEBUGLEVEL2_ACTIVE

// ************* V3.0 Beta 15  ***********
// ********** User-Config Begin **********

//General
#define NeoPixelStartupAnimationActive true  //Show Startup Animation for all Neopixels (true = activated / false = deactivated) !!Attention!! Animation will only be played if all NeoPixels have the same number of LEDs
#define DisplayPrinterObjectChangeFrequency 3  //Change frequency in seconds for displaying multiple PrinterObjects

//PrinterObject#0 - Heater0 (Heatbed)
#define Heater0_Scale 10  //Display scale factor for Heater 0 (Heatbed)
#define Heater0_ColorIdle 255,255,255  //RGB values for specified status
#define Heater0_ColorHeatUp 255,64,64  //RGB values for specified status
#define Heater0_ColorHeatUpDone 255,0,0  //RGB values for specified status
#define Heater0_ColorCoolDown 0,0,255  //RGB values for specified status
#define Heater0_ColorAnimation 0,0,0  //RGB values for specified status

//PrinterObject#1 - Heater1
#define Heater1_Scale 20  //Display scale factor for Heater 1
#define Heater1_ColorIdle 255,255,255  //RGB values for specified status
#define Heater1_ColorHeatUp 255,64,64  //RGB values for specified status
#define Heater1_ColorHeatUpDone 255,0,0  //RGB values for specified status
#define Heater1_ColorCoolDown 0,0,255  //RGB values for specified status
#define Heater1_ColorAnimation 0,0,0  //RGB values for specified status

//PrinterObject#2 - Heater2
#define Heater2_Scale 20  //Display scale factor for Heater 2
#define Heater2_ColorIdle 255,255,255  //RGB values for specified status
#define Heater2_ColorHeatUp 255,64,64  //RGB values for specified status
#define Heater2_ColorHeatUpDone 255,0,0  //RGB values for specified status
#define Heater2_ColorCoolDown 0,0,255  //RGB values for specified status
#define Heater2_ColorAnimation 0,0,0  //RGB values for specified status

//PrinterObject#3 - Heater3
#define Heater3_Scale 20  //Display scale factor for Heater 3
#define Heater3_ColorIdle 255,255,255  //RGB values for specified status
#define Heater3_ColorHeatUp 255,64,64  //RGB values for specified status
#define Heater3_ColorHeatUpDone 255,0,0  //RGB values for specified status
#define Heater3_ColorCoolDown 0,0,255  //RGB values for specified status
#define Heater3_ColorAnimation 0,0,0  //RGB values for specified status

//PrinterObject#4 - Heater4
#define Heater4_Scale 20  //Display scale factor for Heater 4
#define Heater4_ColorIdle 255,255,255  //RGB values for specified status
#define Heater4_ColorHeatUp 255,64,64  //RGB values for specified status
#define Heater4_ColorHeatUpDone 255,0,0  //RGB values for specified status
#define Heater4_ColorCoolDown 0,0,255  //RGB values for specified status
#define Heater4_ColorAnimation 0,0,0  //RGB values for specified status

//PrinterObject#5 - PrinterStatus
#define PrinterStatus_ColorIdle 255,255,255  //RGB values for specified status
#define PrinterStatus_ColorPrinting 64,255,64  //RGB values for specified status
#define PrinterStatus_ColorPrintingDone 0,255,0  //RGB values for specified status
#define PrinterStatus_ColorStopped 0,0,255  //RGB values for specified status
#define PrinterStatus_ColorConfiguring 255,255,0  //RGB values for specified status
#define PrinterStatus_ColorPaused 160,32,240  //RGB values for specified status
#define PrinterStatus_ColorBusy 255,255,0  //RGB values for specified status
#define PrinterStatus_ColorPausing 160,32,240  //RGB values for specified status
#define PrinterStatus_ColorResuming 255,255,0  //RGB values for specified status
#define PrinterStatus_ColorFlashing 255,255,0  //RGB values for specified status
#define PrinterStatus_ColorDefault 255,255,255  //RGB values for specified status
#define PrinterStatus_ColorAnimation 0,0,0  //RGB values for specified status

//NeoPixel#1
#define NeoPixel1_Active true  //NeoPixel#1 (true = activated / false = deactivated)
#define NeoPixel1_StartupAnimationType 3  //Startup animation type (1-3)
#define NeoPixel1_DisplayPrinterObject 99  //Show Object: 0= Heatbed / 1-4= Heater #1-4 / 99= PrinterStatus => Multiple PrinterObjects seperated by ,
#define NeoPixel1_DisplayPrinterObjectChangeByFrequency false  //If multiple PrinterObjects (Heater(s), PrinterStatus) should be displayed by a single Neopixel: false= change display depending on status of heaters / true= Change every x seconds as set by DisplayPrinterObjectChangeFrequency
#define NeoPixel1_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixel1_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixel1_ArduinoPin 7  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixel1_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixel1_TempOffset 0.0  //Minimum Temperature at which the first LED lights up
#define NeoPixel1_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixel1_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixel1_Brightness 8  //Overall brightness of the Neopixel-LEDs

//NeoPixel#2
#define NeoPixel2_Active true  //NeoPixel#2 (true = activated / false = deactivated)
#define NeoPixel2_StartupAnimationType 1  //Startup animation type (1-3)
#define NeoPixel2_DisplayPrinterObject 0  //Show Object: 0= Heatbed / 1-4= Heater #1-4 / 99= PrinterStatus => Multiple PrinterObjects seperated by ,
#define NeoPixel2_DisplayPrinterObjectChangeByFrequency false  //If multiple PrinterObjects (Heater(s), PrinterStatus) should be displayed by a single Neopixel: false= change display depending on status of heaters / true= Change every x seconds as set by DisplayPrinterObjectChangeFrequency
#define NeoPixel2_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixel2_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixel2_ArduinoPin 6  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixel2_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixel2_TempOffset 0.0  //Minimum Temperature at which the first LED lights up
#define NeoPixel2_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixel2_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixel2_Brightness 8  //Overall brightness of the Neopixel-LEDs

//NeoPixel#3
#define NeoPixel3_Active true  //NeoPixel#3 (true = activated / false = deactivated)
#define NeoPixel3_StartupAnimationType 2  //Startup animation type (1-3)
#define NeoPixel3_DisplayPrinterObject 1  //Show Object: 0= Heatbed / 1-4= Heater #1-4 / 99= PrinterStatus => Multiple PrinterObjects seperated by ,
#define NeoPixel3_DisplayPrinterObjectChangeByFrequency false  //If multiple PrinterObjects (Heater(s), PrinterStatus) should be displayed by a single Neopixel: false= change display depending on status of heaters / true= Change every x seconds as set by DisplayPrinterObjectChangeFrequency
#define NeoPixel3_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixel3_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixel3_ArduinoPin 8  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixel3_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixel3_TempOffset 0.0  //Minimum Temperature at which the first LED lights up
#define NeoPixel3_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixel3_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixel3_Brightness 8  //Overall brightness of the Neopixel-LEDs

//NeoPixel#4
#define NeoPixel4_Active false  //NeoPixel#4 (true = activated / false = deactivated)
#define NeoPixel4_StartupAnimationType 1  //Startup animation type (1-3)
#define NeoPixel4_DisplayPrinterObject 2  //Show Object: 0= Heatbed / 1-4= Heater #1-4 / 99= PrinterStatus => Multiple PrinterObjects seperated by ,
#define NeoPixel4_DisplayPrinterObjectChangeByFrequency false  //If multiple PrinterObjects (Heater(s), PrinterStatus) should be displayed by a single Neopixel: false= change display depending on status of heaters / true= Change every x seconds as set by DisplayPrinterObjectChangeFrequency
#define NeoPixel4_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixel4_LEDs 16  //Numbner of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixel4_ArduinoPin 0  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixel4_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixel4_TempOffset 0.0  //Minimum Temperature at which the first LED lights up
#define NeoPixel4_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixel4_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixel4_Brightness 8  //Overall brightness of the Neopixel-LEDs

//NeoPixel#5
#define NeoPixel5_Active false  //NeoPixel#5 (true = activated / false = deactivated)
#define NeoPixel5_StartupAnimationType 1  //Startup animation type (1-3)
#define NeoPixel5_DisplayPrinterObject 3  //Show Object: 0= Heatbed / 1-4= Heater #1-4 / 99= PrinterStatus => Multiple PrinterObjects seperated by ,
#define NeoPixel5_DisplayPrinterObjectChangeByFrequency false  //If multiple PrinterObjects (Heater(s), PrinterStatus) should be displayed by a single Neopixel: false= change display depending on status of heaters / true= Change every x seconds as set by DisplayPrinterObjectChangeFrequency)
#define NeoPixel5_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixel5_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixel5_ArduinoPin 0  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixel5_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixel5_TempOffset 0.0  //Minimum Temperature at which the first LED lights up
#define NeoPixel5_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixel5_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixel5_Brightness 8  //Overall brightness of the Neopixel-LEDs

//NeoPixel#6
#define NeoPixel6_Active false  //NeoPixel#6 (true = activated / false = deactivated)
#define NeoPixel6_StartupAnimationType 1  //Startup animation type (1-3)
#define NeoPixel6_DisplayPrinterObject 4  //Show Object: 0= Heatbed / 1-4= Heater #1-4 / 99= PrinterStatus => Multiple PrinterObjects seperated by ,
#define NeoPixel6_DisplayPrinterObjectChangeByFrequency false  //If multiple PrinterObjects (Heater(s), PrinterStatus) should be displayed by a single Neopixel: false= change display depending on status of heaters / true= Change every x seconds as set by DisplayPrinterObjectChangeFrequency
#define NeoPixel6_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixel6_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixel6_ArduinoPin 0  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixel6_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixel6_TempOffset 0.0  //Minimum Temperature at which the first LED lights up
#define NeoPixel6_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixel6_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixel6_Brightness 8  //Overall brightness of the Neopixel-LEDs

// ********** User-Config End **********
// *************************************

#define SerialTimeout 150
#define NeopixelRefreshSpeed 200
#define SerialMessageBuffer 550
#define NumberHeaters 5
#define NumberNeoPixels 6

struct StructNeoPixelConfig {
  bool Active;
  uint8_t StartupAnimationType;
  int8_t DisplayPrinterObject[(NumberHeaters + 1)];
  bool DisplayPrinterObjectChangeByFrequency;
  uint8_t DisplayPrinterObjectPosition;
  neoPixelType Type;
  uint16_t LEDs;
  uint16_t ArduinoPin;
  int8_t PixelOffset;
  float TempOffset;
  bool AnimationActive;
  bool AnimationReverse;
  int8_t Brightness;
  bool AnimationMemoryActive;
  bool AnimationMemoryRunning;
  uint8_t AnimationMemoryPosition;
  uint8_t AnimationMemoryPosition_Memory;
  uint8_t AnimationMemoryRangeBegin;
  uint8_t AnimationMemoryRangeEnd;
  int8_t AnimationMemoryDisplayPrinterObject;
  uint8_t AnimationMemoryAnimationColor;
};  
StructNeoPixelConfig NeoPixelConfig[NumberNeoPixels];

struct StructHeaterConfig {
  uint8_t Scale;
  uint32_t ColorIdle;
  uint32_t ColorHeatUp;
  uint32_t ColorHeatUpDone;
  uint32_t ColorCoolDown;
  uint32_t ColorAnimation;
};
StructHeaterConfig HeaterConfig[NumberHeaters];

struct StructPanelDueMessage {
  public:
  char Status;
  uint8_t Heater_Status[NumberHeaters];
  float Heater_ActTemp[NumberHeaters];
  float Heater_ActiveTemp[NumberHeaters];
  float Heater_StandbyTemp[NumberHeaters];
  float FractionPrinted;
  bool UpdatePending;
};
StructPanelDueMessage Printer;

int8_t TmpDisplayPrinterObject1[(NumberHeaters + 2)] = {NeoPixel1_DisplayPrinterObject , -1};
int8_t TmpDisplayPrinterObject2[(NumberHeaters + 2)] = {NeoPixel2_DisplayPrinterObject , -1};
int8_t TmpDisplayPrinterObject3[(NumberHeaters + 2)] = {NeoPixel3_DisplayPrinterObject , -1};
int8_t TmpDisplayPrinterObject4[(NumberHeaters + 2)] = {NeoPixel4_DisplayPrinterObject , -1};
int8_t TmpDisplayPrinterObject5[(NumberHeaters + 2)] = {NeoPixel5_DisplayPrinterObject , -1};
int8_t TmpDisplayPrinterObject6[(NumberHeaters + 2)] = {NeoPixel6_DisplayPrinterObject , -1};

int8_t DisplayPrinterObject;
uint8_t HeaterPos;
uint8_t PrinterObject;
float SetTempHeater;
float ActTempHeater;
unsigned long NeoPixelTimerRefresh = millis();
unsigned long NeoPixelTimerChangeDisplayPrinterObject = millis();
char SerialMessage[SerialMessageBuffer]; 
uint8_t NeoPixelID;
uint8_t NeoPixelLEDID;
bool ChangeDisplayPrinterObject;
int HeaterID;
bool InitialSerialMessageSuccess;

Adafruit_NeoPixel *NeoPixel_Device[NumberNeoPixels];

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

  //Printer Status
  JsonResult = JsonParseRoot(JsonResultValue, SerialMessage, JsonObjstatus, 0);
  if (JsonResult == true) {Printer.Status = JsonResultValue[0]; Printer.UpdatePending = true;}

  for (HeaterID = 0; HeaterID < NumberHeaters; HeaterID++){
  //Heater Actual-Temp
    JsonResult = JsonParseRoot(JsonResultValue, SerialMessage, JsonObjheaters, (HeaterID + 1));
    if (JsonResult == true) {Printer.Heater_ActTemp[HeaterID] = atof(JsonResultValue); Printer.UpdatePending = true;}

  //Heater Active-Temp
    JsonResult = JsonParseRoot(JsonResultValue, SerialMessage, JsonObjactive, (HeaterID + 1));
    if (JsonResult == true) {Printer.Heater_ActiveTemp[HeaterID] = atof(JsonResultValue); Printer.UpdatePending = true;}

  //Heater Standby-Temp
    JsonResult = JsonParseRoot(JsonResultValue, SerialMessage, JsonObjstandby, (HeaterID + 1));
    if (JsonResult == true) {Printer.Heater_StandbyTemp[HeaterID] = atof(JsonResultValue); Printer.UpdatePending = true;}

  //HeaterStatus 0= Off / 1= Standby / 2= Active / 3= Fault / 4= Tuning
    JsonResult = JsonParseRoot(JsonResultValue, SerialMessage, JsonObjhstat, (HeaterID + 1));
    if (JsonResult == true) {Printer.Heater_Status[HeaterID] = atoi(JsonResultValue); Printer.UpdatePending = true;}
  }  
  
  //Print Progress  
  JsonResult = JsonParseRoot(JsonResultValue, SerialMessage, JsonObjfractionprinted, 0);
  if (JsonResult == true) {Printer.FractionPrinted = atof(JsonResultValue); Printer.UpdatePending = true;}
}


// Example-Json-Message: {"status":"I","heaters":[31.5,28.1],"active":[0.0,0.0],"standby":[0.0,0.0],"hstat":[0,0],"pos":[0.000,0.000,0.000],"machine":[0.000,0.000,0.000],"sfactor":100.00,"efactor":[100.00],"babystep":0.000,"Heater":-1,"probe":"0","fanPercent":[0.0,0.0,100.0,100.0,0.0,0.0,0.0,0.0,0.0,0.0],"fanRPM":0,"homed":[0,0,0],"msgBox.mode":-1,"geometry":"coreXY","axes":3,"totalAxes":3,"axisNames":"XYZ","volumes":2,"numHeaters":1,"myName":"BLV mgn Cube","firmwareName":"RepRapFirmware for Duet 2 WiFi/Ethernet"}
bool JsonParseRoot(char* Result, char* JsonMessagePtr, char* JsonRootObjectPtr, int JsonObjectIndex) {
  char* PositionBeginPtr;
  char* PositionEndPtr;
  uint8_t JsonValueIndex = 0;
  char JsonValue[100] = "";
  
  Result[0] = '\0';

  #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL1_ACTIVE)
    Serial.print("JsonObject= ");
    Serial.print(JsonRootObjectPtr);
    Serial.print(" / JsonObjectIndex= ");
    Serial.print(JsonObjectIndex);
    Serial.print(" => JsonMessage= ");
    Serial.print(JsonMessagePtr);
    Serial.println("");
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
            for (JsonValueIndex = 1; JsonValueIndex < JsonObjectIndex; JsonValueIndex++){
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


void GetSerialMessage() {
  unsigned long timer = millis();
  int SerialMessagePosition = 0;
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
  uint32_t AnimationColor = ConvertColor(255, 0, 0);
  int16_t BrightnessID = 0;

  NeoPixelConfig[0].Active = NeoPixel1_Active;
  NeoPixelConfig[0].StartupAnimationType = NeoPixel1_StartupAnimationType;
  NeoPixelConfig[0].DisplayPrinterObjectChangeByFrequency = NeoPixel1_DisplayPrinterObjectChangeByFrequency;
  NeoPixelConfig[0].DisplayPrinterObjectPosition = 0;
  NeoPixelConfig[0].Type = NeoPixel1_Type;
  NeoPixelConfig[0].LEDs = NeoPixel1_LEDs;
  NeoPixelConfig[0].ArduinoPin = NeoPixel1_ArduinoPin;
  NeoPixelConfig[0].PixelOffset = NeoPixel1_PixelOffset;
  NeoPixelConfig[0].TempOffset = NeoPixel1_TempOffset;
  NeoPixelConfig[0].AnimationActive = NeoPixel1_AnimationActive;
  NeoPixelConfig[0].AnimationReverse = NeoPixel1_Reverse;
  NeoPixelConfig[0].Brightness = NeoPixel1_Brightness;
  NeoPixelConfig[1].Active = NeoPixel2_Active;
  NeoPixelConfig[1].StartupAnimationType = NeoPixel2_StartupAnimationType;
  NeoPixelConfig[1].DisplayPrinterObjectChangeByFrequency = NeoPixel2_DisplayPrinterObjectChangeByFrequency;
  NeoPixelConfig[1].DisplayPrinterObjectPosition = 0;
  NeoPixelConfig[1].Type = NeoPixel2_Type;
  NeoPixelConfig[1].LEDs = NeoPixel2_LEDs;
  NeoPixelConfig[1].ArduinoPin = NeoPixel2_ArduinoPin;
  NeoPixelConfig[1].PixelOffset = NeoPixel2_PixelOffset;
  NeoPixelConfig[1].TempOffset = NeoPixel2_TempOffset;
  NeoPixelConfig[1].AnimationActive = NeoPixel2_AnimationActive;
  NeoPixelConfig[1].AnimationReverse = NeoPixel2_Reverse;
  NeoPixelConfig[1].Brightness = NeoPixel2_Brightness;
  NeoPixelConfig[2].Active = NeoPixel3_Active;
  NeoPixelConfig[2].StartupAnimationType = NeoPixel3_StartupAnimationType;
  NeoPixelConfig[2].DisplayPrinterObjectChangeByFrequency = NeoPixel3_DisplayPrinterObjectChangeByFrequency;
  NeoPixelConfig[2].DisplayPrinterObjectPosition = 0;
  NeoPixelConfig[2].Type = NeoPixel3_Type;
  NeoPixelConfig[2].LEDs = NeoPixel3_LEDs;
  NeoPixelConfig[2].ArduinoPin = NeoPixel3_ArduinoPin;
  NeoPixelConfig[2].PixelOffset = NeoPixel3_PixelOffset;
  NeoPixelConfig[2].TempOffset = NeoPixel3_TempOffset;
  NeoPixelConfig[2].AnimationActive = NeoPixel3_AnimationActive;
  NeoPixelConfig[2].AnimationReverse = NeoPixel3_Reverse;
  NeoPixelConfig[2].Brightness = NeoPixel3_Brightness;
  NeoPixelConfig[3].Active = NeoPixel4_Active;
  NeoPixelConfig[3].StartupAnimationType = NeoPixel4_StartupAnimationType;
  NeoPixelConfig[3].DisplayPrinterObjectChangeByFrequency = NeoPixel4_DisplayPrinterObjectChangeByFrequency;
  NeoPixelConfig[3].DisplayPrinterObjectPosition = 0;
  NeoPixelConfig[3].Type = NeoPixel4_Type;
  NeoPixelConfig[3].LEDs = NeoPixel4_LEDs;
  NeoPixelConfig[3].ArduinoPin = NeoPixel4_ArduinoPin;
  NeoPixelConfig[3].PixelOffset = NeoPixel4_PixelOffset;
  NeoPixelConfig[3].TempOffset = NeoPixel4_TempOffset;
  NeoPixelConfig[3].AnimationActive = NeoPixel4_AnimationActive;
  NeoPixelConfig[3].AnimationReverse = NeoPixel4_Reverse;
  NeoPixelConfig[3].Brightness = NeoPixel4_Brightness;
  NeoPixelConfig[4].Active = NeoPixel5_Active;
  NeoPixelConfig[4].StartupAnimationType = NeoPixel5_StartupAnimationType;
  NeoPixelConfig[4].DisplayPrinterObjectChangeByFrequency = NeoPixel5_DisplayPrinterObjectChangeByFrequency;
  NeoPixelConfig[4].DisplayPrinterObjectPosition = 0;
  NeoPixelConfig[4].Type = NeoPixel5_Type;
  NeoPixelConfig[4].LEDs = NeoPixel5_LEDs;
  NeoPixelConfig[4].ArduinoPin = NeoPixel5_ArduinoPin;
  NeoPixelConfig[4].PixelOffset = NeoPixel5_PixelOffset;
  NeoPixelConfig[4].TempOffset = NeoPixel5_TempOffset;
  NeoPixelConfig[4].AnimationActive = NeoPixel5_AnimationActive;
  NeoPixelConfig[4].AnimationReverse = NeoPixel5_Reverse;
  NeoPixelConfig[4].Brightness = NeoPixel5_Brightness;
  NeoPixelConfig[5].Active = NeoPixel6_Active;
  NeoPixelConfig[5].StartupAnimationType = NeoPixel6_StartupAnimationType;
  NeoPixelConfig[5].DisplayPrinterObjectChangeByFrequency = NeoPixel6_DisplayPrinterObjectChangeByFrequency;
  NeoPixelConfig[5].DisplayPrinterObjectPosition = 0;
  NeoPixelConfig[5].Type = NeoPixel6_Type;
  NeoPixelConfig[5].LEDs = NeoPixel6_LEDs;
  NeoPixelConfig[5].ArduinoPin = NeoPixel6_ArduinoPin;
  NeoPixelConfig[5].PixelOffset = NeoPixel6_PixelOffset;
  NeoPixelConfig[5].TempOffset = NeoPixel6_TempOffset;
  NeoPixelConfig[5].AnimationActive = NeoPixel6_AnimationActive;
  NeoPixelConfig[5].AnimationReverse = NeoPixel6_Reverse;
  NeoPixelConfig[5].Brightness = NeoPixel6_Brightness;
  
  for (NeoPixelID = 0; TmpDisplayPrinterObject1[NeoPixelID] != -1; NeoPixelID++) {NeoPixelConfig[0].DisplayPrinterObject[NeoPixelID] = TmpDisplayPrinterObject1[NeoPixelID];} NeoPixelConfig[0].DisplayPrinterObject[NeoPixelID] = -1;
  for (NeoPixelID = 0; TmpDisplayPrinterObject2[NeoPixelID] != -1; NeoPixelID++) {NeoPixelConfig[1].DisplayPrinterObject[NeoPixelID] = TmpDisplayPrinterObject2[NeoPixelID];} NeoPixelConfig[1].DisplayPrinterObject[NeoPixelID] = -1;
  for (NeoPixelID = 0; TmpDisplayPrinterObject3[NeoPixelID] != -1; NeoPixelID++) {NeoPixelConfig[2].DisplayPrinterObject[NeoPixelID] = TmpDisplayPrinterObject3[NeoPixelID];} NeoPixelConfig[2].DisplayPrinterObject[NeoPixelID] = -1;
  for (NeoPixelID = 0; TmpDisplayPrinterObject4[NeoPixelID] != -1; NeoPixelID++) {NeoPixelConfig[3].DisplayPrinterObject[NeoPixelID] = TmpDisplayPrinterObject4[NeoPixelID];} NeoPixelConfig[3].DisplayPrinterObject[NeoPixelID] = -1;
  for (NeoPixelID = 0; TmpDisplayPrinterObject5[NeoPixelID] != -1; NeoPixelID++) {NeoPixelConfig[4].DisplayPrinterObject[NeoPixelID] = TmpDisplayPrinterObject5[NeoPixelID];} NeoPixelConfig[4].DisplayPrinterObject[NeoPixelID] = -1;
  for (NeoPixelID = 0; TmpDisplayPrinterObject6[NeoPixelID] != -1; NeoPixelID++) {NeoPixelConfig[5].DisplayPrinterObject[NeoPixelID] = TmpDisplayPrinterObject6[NeoPixelID];} NeoPixelConfig[5].DisplayPrinterObject[NeoPixelID] = -1;

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
  
  for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
    NeoPixel_Device[NeoPixelID] = new Adafruit_NeoPixel(NeoPixelConfig[NeoPixelID].LEDs, NeoPixelConfig[NeoPixelID].ArduinoPin, NeoPixelConfig[NeoPixelID].Type);
  }  

  // Initialize Neopixels
  for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
    if (NeoPixelConfig[NeoPixelID].Active == true) {NeoPixel_Device[NeoPixelID]->begin(); NeoPixel_Device[NeoPixelID]->show();}
  }  

  //Set start values
  for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
    NeoPixelConfig[NeoPixelID].AnimationMemoryPosition = 0;
    NeoPixelConfig[NeoPixelID].AnimationMemoryPosition_Memory = 0;
    NeoPixelConfig[NeoPixelID].AnimationMemoryRangeBegin = 0;
    NeoPixelConfig[NeoPixelID].AnimationMemoryRangeEnd = 0;
    NeoPixelConfig[NeoPixelID].AnimationMemoryRunning = false;
    NeoPixelConfig[NeoPixelID].AnimationMemoryAnimationColor = 0;
  }
  for (HeaterID = 0; HeaterID < NumberHeaters; HeaterID++){
    Printer.Heater_Status[HeaterID] = 0;
    Printer.Heater_ActTemp[HeaterID] = 0.0;
    Printer.Heater_ActiveTemp[HeaterID] = 0.0;
    Printer.Heater_StandbyTemp[HeaterID] = 0.0;
  }  
  Printer.Status = ' ';
  Printer.FractionPrinted = 0.0;
  Printer.UpdatePending = false;

  InitialSerialMessageSuccess = false;

  //Setup Serial Interface
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
  
  // Startup-Animation
  int NeoPixelCount = 0;
  bool NeoPixelStartupAnimationActive_Consistency = true;
  if (NeoPixelStartupAnimationActive == true)
  {
    // Animation Consistency-Check
    for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
      if (NeoPixelConfig[NeoPixelID].Active == true) {
        if (NeoPixelCount == 0) {
          NeoPixelCount = NeoPixelConfig[NeoPixelID].LEDs;
        }  
        else {
          if (NeoPixelConfig[NeoPixelID].LEDs != NeoPixelCount) {
            NeoPixelStartupAnimationActive_Consistency = false;
          }
        }
      }
    } 
    //Activate startup sequence & Co. if all activated NeoPixels have the same number of LEDs
  	if (NeoPixelCount > 0 && NeoPixelStartupAnimationActive_Consistency == true) {

      //Initialize Neopixels
      for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
        if (NeoPixelConfig[NeoPixelID].Active == true) {NeoPixel_Device[NeoPixelID]->setBrightness(255);}
      }
      //Startup Animation #1a
      for (NeoPixelLEDID = 0; NeoPixelLEDID < NeoPixelCount; NeoPixelLEDID++) {
        for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
          if (NeoPixelConfig[NeoPixelID].Active == true) {NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 0, 0)); switch (NeoPixelConfig[NeoPixelID].StartupAnimationType) {case 1: AnimationColor = ConvertColor(255, 0, 0); break; case 2: AnimationColor = ConvertColor(0, 255, 0); break; case 3: AnimationColor = ConvertColor(0, 0, 255); break;} NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,(NeoPixelLEDID + 1),NeoPixelConfig[NeoPixelID].AnimationReverse), AnimationColor); NeoPixel_Device[NeoPixelID]->show();}
        }
        delay(30);
      }
      //Startup Animation #1b
      for (NeoPixelLEDID = 0; NeoPixelLEDID < NeoPixelCount; NeoPixelLEDID++) {
        for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
          if (NeoPixelConfig[NeoPixelID].Active == true) {NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 0, 0)); switch (NeoPixelConfig[NeoPixelID].StartupAnimationType) {case 1: AnimationColor = ConvertColor(0, 255, 0); break; case 2: AnimationColor = ConvertColor(0, 0, 255); break; case 3: AnimationColor = ConvertColor(255, 0, 0); break;} NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,(NeoPixelLEDID + 1),NeoPixelConfig[NeoPixelID].AnimationReverse), AnimationColor); NeoPixel_Device[NeoPixelID]->show();}
        }
        delay(30);
      }
      //Startup Animation #1c
      for (NeoPixelLEDID = 0; NeoPixelLEDID < NeoPixelCount; NeoPixelLEDID++) {
        for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
          if (NeoPixelConfig[NeoPixelID].Active == true) {NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 0, 0)); switch (NeoPixelConfig[NeoPixelID].StartupAnimationType) {case 1: AnimationColor = ConvertColor(0, 0, 255); break; case 2: AnimationColor = ConvertColor(255, 0, 0); break; case 3: AnimationColor = ConvertColor(0, 255, 0); break;} NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,(NeoPixelLEDID + 1),NeoPixelConfig[NeoPixelID].AnimationReverse), AnimationColor); NeoPixel_Device[NeoPixelID]->show();}
        }
        delay(30);
      }

      //Startup Animation #2a1
      for(BrightnessID = 0; BrightnessID < 255; BrightnessID++)
      {
        for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
          if (NeoPixelConfig[NeoPixelID].Active == true) {NeoPixel_Device[NeoPixelID]->setBrightness(BrightnessID); switch (NeoPixelConfig[NeoPixelID].StartupAnimationType) {case 1: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(255, 0, 0)); break; case 2: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 255, 0)); break; case 3: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 0, 255)); break;} NeoPixel_Device[NeoPixelID]->show();}
        }
        delay(1);
      }
      //Startup Animation #2a2
      for(BrightnessID = 255; BrightnessID >= 0; BrightnessID--)
      {
        for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
          if (NeoPixelConfig[NeoPixelID].Active == true) {NeoPixel_Device[NeoPixelID]->setBrightness(BrightnessID); switch (NeoPixelConfig[NeoPixelID].StartupAnimationType) {case 1: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(255, 0, 0)); break; case 2: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 255, 0)); break; case 3: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 0, 255)); break;} NeoPixel_Device[NeoPixelID]->show();}
        }
        delay(1);
      }
      //Startup Animation #2b1
      for(BrightnessID = 0; BrightnessID < 255; BrightnessID++)
      {
        for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
          if (NeoPixelConfig[NeoPixelID].Active == true) {NeoPixel_Device[NeoPixelID]->setBrightness(BrightnessID); switch (NeoPixelConfig[NeoPixelID].StartupAnimationType) {case 1: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 255, 0)); break; case 2: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 0, 255)); break; case 3: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(255, 0, 0)); break;} NeoPixel_Device[NeoPixelID]->show();}
        }
        delay(1);
      }
      //Startup Animation #2b2
      for(BrightnessID = 255; BrightnessID >= 0; BrightnessID--)
      {
        for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
          if (NeoPixelConfig[NeoPixelID].Active == true) {NeoPixel_Device[NeoPixelID]->setBrightness(BrightnessID); switch (NeoPixelConfig[NeoPixelID].StartupAnimationType) {case 1: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 255, 0)); break; case 2: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 0, 255)); break; case 3: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(255, 0, 0)); break;} NeoPixel_Device[NeoPixelID]->show();}
        }
        delay(1);
      }
      //Startup Animation #2c1
      for(BrightnessID = 0; BrightnessID < 255; BrightnessID++)
      {
        for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
          if (NeoPixelConfig[NeoPixelID].Active == true) {NeoPixel_Device[NeoPixelID]->setBrightness(BrightnessID); switch (NeoPixelConfig[NeoPixelID].StartupAnimationType) {case 1: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 0, 255)); break; case 2: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(255, 0, 0)); break; case 3: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 255, 0)); break;} NeoPixel_Device[NeoPixelID]->show();}
        }
        delay(1);
      }
      //Startup Animation #2c2
      for(BrightnessID = 255; BrightnessID >= 0; BrightnessID--)
      {
        for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
          if (NeoPixelConfig[NeoPixelID].Active == true) {NeoPixel_Device[NeoPixelID]->setBrightness(BrightnessID); switch (NeoPixelConfig[NeoPixelID].StartupAnimationType) {case 1: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 0, 255)); break; case 2: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(255, 0, 0)); break; case 3: NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 255, 0)); break;} NeoPixel_Device[NeoPixelID]->show();}
        }
        delay(1);
      }
  	}	
  }  
  
  //Initial Neopixel for Loop
  for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
    if (NeoPixelConfig[NeoPixelID].Active == true) {
      NeoPixel_Device[NeoPixelID]->clear(); 
      NeoPixel_Device[NeoPixelID]->setBrightness(NeoPixelConfig[NeoPixelID].Brightness); 
      NeoPixel_Device[NeoPixelID]->show();
    }
  }
}


// Main loop
void loop()
{
  //Read serial
  GetSerialMessage();

  //Wait for first complete SerialMessage before starting to display anything
  if (InitialSerialMessageSuccess == false && Printer.UpdatePending == true) {
    InitialSerialMessageSuccess = true;
  }

  //NeopixelRefresh?
  if ((millis() - NeoPixelTimerRefresh) >= NeopixelRefreshSpeed && InitialSerialMessageSuccess == true){
    NeoPixelTimerRefresh = millis();

    //Change PrinterObject?
    if ((millis() - NeoPixelTimerChangeDisplayPrinterObject) >= (DisplayPrinterObjectChangeFrequency * 1000)) {
      NeoPixelTimerChangeDisplayPrinterObject = millis();
      ChangeDisplayPrinterObject = true;
    }  
    else {
      ChangeDisplayPrinterObject = false;
    }  
      
    //Update Neopixels
    for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++) {
      if (NeoPixelConfig[NeoPixelID].Active == true && NeoPixelConfig[NeoPixelID].DisplayPrinterObject[0] != -1) {
        //Determine PrinterObject to show
        DisplayPrinterObject = -1;
        if (NeoPixelConfig[NeoPixelID].DisplayPrinterObject[1] == -1) {
          //Single PrinterObject
          DisplayPrinterObject = NeoPixelConfig[NeoPixelID].DisplayPrinterObject[0];
        }
        else {
          if (NeoPixelConfig[NeoPixelID].DisplayPrinterObjectChangeByFrequency == false) {
            //Multiple PrinterObjects: Change PrinterObject by HeaterStatus
            //Check for Printerobject = 99 (PrinterStatus)
            for (HeaterPos = 0; DisplayPrinterObject == -1 && NeoPixelConfig[NeoPixelID].DisplayPrinterObject[HeaterPos] != -1; HeaterPos++) {
              PrinterObject = NeoPixelConfig[NeoPixelID].DisplayPrinterObject[HeaterPos];
              if (PrinterObject == 99) {DisplayPrinterObject = PrinterObject;}
            }
            //Determine first "active" heater
            for (HeaterPos = 0; DisplayPrinterObject == -1 && NeoPixelConfig[NeoPixelID].DisplayPrinterObject[HeaterPos] != -1; HeaterPos++) {
              PrinterObject = NeoPixelConfig[NeoPixelID].DisplayPrinterObject[HeaterPos];
              if (Printer.Heater_Status[PrinterObject] == 2) {DisplayPrinterObject = PrinterObject;}
            }
            //Determine first "standby" heater
            for (HeaterPos = 0; DisplayPrinterObject == -1 && NeoPixelConfig[NeoPixelID].DisplayPrinterObject[HeaterPos] != -1; HeaterPos++) {
              PrinterObject = NeoPixelConfig[NeoPixelID].DisplayPrinterObject[HeaterPos];
              if (Printer.Heater_Status[PrinterObject] == 1) {DisplayPrinterObject = PrinterObject;}
            }
            //Determine first "off" heater
            for (HeaterPos = 0; DisplayPrinterObject == -1 && NeoPixelConfig[NeoPixelID].DisplayPrinterObject[HeaterPos] != -1; HeaterPos++) {
              PrinterObject = NeoPixelConfig[NeoPixelID].DisplayPrinterObject[HeaterPos];
              if (Printer.Heater_Status[PrinterObject] == 0) {DisplayPrinterObject = PrinterObject;}
            }
          }
          else {
            //Multiple PrinterObjects: Change PrinterObjects by Frequency
            if (ChangeDisplayPrinterObject == true) {
              if (NeoPixelConfig[NeoPixelID].DisplayPrinterObject[(NeoPixelConfig[NeoPixelID].DisplayPrinterObjectPosition + 1)] == -1) {
                NeoPixelConfig[NeoPixelID].DisplayPrinterObjectPosition = 0;
              }  
              else {  
                NeoPixelConfig[NeoPixelID].DisplayPrinterObjectPosition++;
              } 
            }  
            DisplayPrinterObject = NeoPixelConfig[NeoPixelID].DisplayPrinterObject[NeoPixelConfig[NeoPixelID].DisplayPrinterObjectPosition];
          }
        }  

        #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)) && defined(DEBUGLEVEL2_ACTIVE)
          Serial.print("NeoPixelID["); Serial.print(i); Serial.print("]= "); Serial.print(DisplayPrinterObject); Serial.print(" / SetTemp= "); Serial.print(SetTempHeater); Serial.print(" / ActTemp= "); Serial.print(ActTempHeater); Serial.println("");
          Serial.print("0= "); Serial.print(NeoPixelConfig[NeoPixelID].DisplayPrinterObject[0]); Serial.print(" / 1= "); Serial.print(NeoPixelConfig[NeoPixelID].DisplayPrinterObject[1]); Serial.print(" / 2= "); Serial.print(NeoPixelConfig[NeoPixelID].DisplayPrinterObject[2]); Serial.print(" / 3= "); Serial.print(NeoPixelConfig[NeoPixelID].DisplayPrinterObject[3]); Serial.print(" / 4= "); Serial.print(NeoPixelConfig[NeoPixelID].DisplayPrinterObject[4]); Serial.print(" / 5= "); Serial.print(NeoPixelConfig[NeoPixelID].DisplayPrinterObject[5]); Serial.println(""); Serial.println("");
        #endif 

        //Update Neopixel?
        if (DisplayPrinterObject >= 0 && (DisplayPrinterObject != NeoPixelConfig[NeoPixelID].AnimationMemoryDisplayPrinterObject || Printer.UpdatePending == true)) {
          NeoPixelConfig[NeoPixelID].AnimationMemoryRangeBegin = 0;
          NeoPixelConfig[NeoPixelID].AnimationMemoryRangeEnd = 0;
          //PrinterObject has changed? => Reset AnimationMemory
          if (DisplayPrinterObject != NeoPixelConfig[NeoPixelID].AnimationMemoryDisplayPrinterObject) {
            NeoPixelConfig[NeoPixelID].AnimationMemoryDisplayPrinterObject = DisplayPrinterObject;
            NeoPixelConfig[NeoPixelID].AnimationMemoryPosition = 0;
            NeoPixelConfig[NeoPixelID].AnimationMemoryPosition_Memory = 0;
            NeoPixelConfig[NeoPixelID].AnimationMemoryRunning = false;
            NeoPixelConfig[NeoPixelID].AnimationMemoryAnimationColor = 0;
          }
          if (DisplayPrinterObject >= 0 && DisplayPrinterObject < NumberHeaters) {
            //Display HeaterStatus
            SetTempHeater = 0.0;
            ActTempHeater= Printer.Heater_ActTemp[DisplayPrinterObject];
            if (Printer.Heater_Status[DisplayPrinterObject] == 2){
              SetTempHeater = Printer.Heater_ActiveTemp[DisplayPrinterObject];
            }
            else if (Printer.Heater_Status[DisplayPrinterObject] == 1) {
              SetTempHeater = Printer.Heater_StandbyTemp[DisplayPrinterObject];
            }
            for (NeoPixelLEDID = 1; NeoPixelLEDID <= NeoPixelConfig[NeoPixelID].LEDs; NeoPixelLEDID++)
            {
              if((((ActTempHeater - NeoPixelConfig[NeoPixelID].TempOffset) / HeaterConfig[DisplayPrinterObject].Scale) < NeoPixelLEDID) && (((SetTempHeater - NeoPixelConfig[NeoPixelID].TempOffset) / HeaterConfig[DisplayPrinterObject].Scale) >= NeoPixelLEDID)) {
                NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelLEDID,NeoPixelConfig[NeoPixelID].AnimationReverse),HeaterConfig[DisplayPrinterObject].ColorHeatUp);
                //Define Animation-Range
                if (NeoPixelConfig[NeoPixelID].AnimationMemoryRangeBegin == 0) {
                  NeoPixelConfig[NeoPixelID].AnimationMemoryRangeBegin = NeoPixelLEDID;
                  NeoPixelConfig[NeoPixelID].AnimationMemoryRangeEnd = NeoPixelLEDID;
                } else {
                  NeoPixelConfig[NeoPixelID].AnimationMemoryRangeEnd++;
                }
              }
              else if((((ActTempHeater - NeoPixelConfig[NeoPixelID].TempOffset) / HeaterConfig[DisplayPrinterObject].Scale) >= NeoPixelLEDID) && (((SetTempHeater - NeoPixelConfig[NeoPixelID].TempOffset) / HeaterConfig[DisplayPrinterObject].Scale) >= NeoPixelLEDID)) {
                NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelLEDID,NeoPixelConfig[NeoPixelID].AnimationReverse),HeaterConfig[DisplayPrinterObject].ColorHeatUpDone);
              }
              else if((((ActTempHeater - NeoPixelConfig[NeoPixelID].TempOffset) / HeaterConfig[DisplayPrinterObject].Scale) >= NeoPixelLEDID) && (((SetTempHeater - NeoPixelConfig[NeoPixelID].TempOffset) / HeaterConfig[DisplayPrinterObject].Scale) < NeoPixelLEDID)) {
                NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelLEDID,NeoPixelConfig[NeoPixelID].AnimationReverse),HeaterConfig[DisplayPrinterObject].ColorCoolDown);
              }
              else{
                NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelLEDID,NeoPixelConfig[NeoPixelID].AnimationReverse),HeaterConfig[DisplayPrinterObject].ColorIdle);
              }
            }
          }
          else if (DisplayPrinterObject == 99) {
            //Display PrinterStatus & PrintProgress
            if(Printer.Status == 'P') { 
              //Display PrintProgress
              for (NeoPixelLEDID = 1; NeoPixelLEDID <= NeoPixelConfig[NeoPixelID].LEDs; NeoPixelLEDID++)
              {
                if(NeoPixelLEDID < (Printer.FractionPrinted * NeoPixelConfig[NeoPixelID].LEDs)) {
                  NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelLEDID,NeoPixelConfig[NeoPixelID].AnimationReverse),ConvertColor(PrinterStatus_ColorPrintingDone));
                }
                else {
                  NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelLEDID,NeoPixelConfig[NeoPixelID].AnimationReverse),ConvertColor(PrinterStatus_ColorPrinting));
                  //Define Animation-Range
                  if (NeoPixelConfig[NeoPixelID].AnimationMemoryRangeBegin == 0) {
                    NeoPixelConfig[NeoPixelID].AnimationMemoryRangeBegin = NeoPixelLEDID;
                    NeoPixelConfig[NeoPixelID].AnimationMemoryRangeEnd = NeoPixelLEDID;
                  } else {
                    NeoPixelConfig[NeoPixelID].AnimationMemoryRangeEnd++;
                  }
                }
              }
            }
            else {
              // Display PrinterStatus:
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
                  NeoPixel_Device[NeoPixelID]->fill(ConvertColor(PrinterStatus_ColorIdle));
                  break;
                case 'P':
                  NeoPixel_Device[NeoPixelID]->fill(ConvertColor(PrinterStatus_ColorPrinting));
                  break;
                case 'S':
                  NeoPixel_Device[NeoPixelID]->fill(ConvertColor(PrinterStatus_ColorStopped));
                  break;
                case 'C':
                  NeoPixel_Device[NeoPixelID]->fill(ConvertColor(PrinterStatus_ColorConfiguring));
                  break;
                case 'A':
                  NeoPixel_Device[NeoPixelID]->fill(ConvertColor(PrinterStatus_ColorPaused));
                  break;
                case 'D':
                  NeoPixel_Device[NeoPixelID]->fill(ConvertColor(PrinterStatus_ColorBusy));
                  break;
                case 'R':
                  NeoPixel_Device[NeoPixelID]->fill(ConvertColor(PrinterStatus_ColorPausing));
                  break;
                case 'B':
                  NeoPixel_Device[NeoPixelID]->fill(ConvertColor(PrinterStatus_ColorResuming));
                  break;
                case 'F':
                  NeoPixel_Device[NeoPixelID]->fill(ConvertColor(PrinterStatus_ColorFlashing));
                  break;
                default:
                  NeoPixel_Device[NeoPixelID]->fill(ConvertColor(PrinterStatus_ColorDefault));
                  break;
              }    
            }
          }
        }  
      }
    }  
    Printer.UpdatePending = false;

    //Animation Neopixels
    for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++) {
      if (NeoPixelConfig[NeoPixelID].Active == true && NeoPixelConfig[NeoPixelID].AnimationActive == true) {
        //AnimationRange exists?
        if (NeoPixelConfig[NeoPixelID].AnimationMemoryRangeBegin == 0) {
          NeoPixelConfig[NeoPixelID].AnimationMemoryRunning = false;
        }
        else {
          //Animation initialize?
          if (NeoPixelConfig[NeoPixelID].AnimationMemoryRunning == false) {
              NeoPixelConfig[NeoPixelID].AnimationMemoryRunning = true;
              NeoPixelConfig[NeoPixelID].AnimationMemoryPosition = NeoPixelConfig[NeoPixelID].AnimationMemoryRangeBegin;
              NeoPixelConfig[NeoPixelID].AnimationMemoryPosition_Memory = 0;
              NeoPixelConfig[NeoPixelID].AnimationMemoryAnimationColor = 0;
          }
          //Restart animation at new position (next heatup step reached)?
          if (NeoPixelConfig[NeoPixelID].AnimationMemoryPosition < NeoPixelConfig[NeoPixelID].AnimationMemoryRangeBegin) {
            NeoPixelConfig[NeoPixelID].AnimationMemoryPosition = NeoPixelConfig[NeoPixelID].AnimationMemoryRangeBegin;
          }
          //Animation one step further
          if (NeoPixelConfig[NeoPixelID].AnimationMemoryPosition_Memory != NeoPixelConfig[NeoPixelID].AnimationMemoryPosition && NeoPixelConfig[NeoPixelID].AnimationMemoryPosition_Memory >= NeoPixelConfig[NeoPixelID].AnimationMemoryRangeBegin) {
            if (NeoPixelConfig[NeoPixelID].AnimationMemoryDisplayPrinterObject != 99) {
              NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelConfig[NeoPixelID].AnimationMemoryPosition_Memory,NeoPixelConfig[NeoPixelID].AnimationReverse),HeaterConfig[NeoPixelConfig[NeoPixelID].AnimationMemoryDisplayPrinterObject].ColorHeatUp);
              NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelConfig[NeoPixelID].AnimationMemoryPosition,NeoPixelConfig[NeoPixelID].AnimationReverse),HeaterConfig[NeoPixelConfig[NeoPixelID].AnimationMemoryDisplayPrinterObject].ColorAnimation);
            }
            else {  
              NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelConfig[NeoPixelID].AnimationMemoryPosition_Memory,NeoPixelConfig[NeoPixelID].AnimationReverse),ConvertColor(PrinterStatus_ColorPrinting));
              NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelConfig[NeoPixelID].AnimationMemoryPosition,NeoPixelConfig[NeoPixelID].AnimationReverse),ConvertColor(PrinterStatus_ColorAnimation));
            }
            NeoPixelConfig[NeoPixelID].AnimationMemoryAnimationColor = 1;
          }
          else {
            //Animation phase1
            if (NeoPixelConfig[NeoPixelID].AnimationMemoryAnimationColor == 0) {
              if (NeoPixelConfig[NeoPixelID].AnimationMemoryDisplayPrinterObject != 99) {
                NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelConfig[NeoPixelID].AnimationMemoryPosition,NeoPixelConfig[NeoPixelID].AnimationReverse),HeaterConfig[NeoPixelConfig[NeoPixelID].AnimationMemoryDisplayPrinterObject].ColorAnimation);
              }
              else {
                NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelConfig[NeoPixelID].AnimationMemoryPosition,NeoPixelConfig[NeoPixelID].AnimationReverse),ConvertColor(PrinterStatus_ColorAnimation));
              }
              NeoPixelConfig[NeoPixelID].AnimationMemoryAnimationColor = 1;
            }
            else {
              //Animation phase2
              if (NeoPixelConfig[NeoPixelID].AnimationMemoryDisplayPrinterObject != 99) {
                NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelConfig[NeoPixelID].AnimationMemoryPosition,NeoPixelConfig[NeoPixelID].AnimationReverse),HeaterConfig[NeoPixelConfig[NeoPixelID].AnimationMemoryDisplayPrinterObject].ColorHeatUp);
              }  
              else {
                NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelConfig[NeoPixelID].AnimationMemoryPosition,NeoPixelConfig[NeoPixelID].AnimationReverse),ConvertColor(PrinterStatus_ColorPrinting));
              }
              NeoPixelConfig[NeoPixelID].AnimationMemoryAnimationColor = 0;
            }
          }
          NeoPixelConfig[NeoPixelID].AnimationMemoryPosition_Memory = NeoPixelConfig[NeoPixelID].AnimationMemoryPosition;
          NeoPixelConfig[NeoPixelID].AnimationMemoryPosition++;
          //Restart animation at begin position?
          if (NeoPixelConfig[NeoPixelID].AnimationMemoryPosition > NeoPixelConfig[NeoPixelID].AnimationMemoryRangeEnd) {
            NeoPixelConfig[NeoPixelID].AnimationMemoryPosition = NeoPixelConfig[NeoPixelID].AnimationMemoryRangeBegin;
          }
        }
      }
    }
    //Neopixel refresh
    for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
      if (NeoPixelConfig[NeoPixelID].Active == true) {NeoPixel_Device[NeoPixelID]->show();}
    }  
  }
}
