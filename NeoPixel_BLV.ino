#include <JsonStreamingParser.h>

#include <Adafruit_NeoPixel.h>
#include <AltSoftSerial.h>

#include "StreamingHandler.h"
#include "Debugging.h"

#if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega32U4__) || defined(__SAM3X8E__))
#else
  #error Unsupported CPU-Architecture found!!
#endif  

// ************* V3.0 ***********
// ********** User-Config Begin **********

//Configure Serial Ports (Do not change if you do not know what you are doing!)
//SoftwareSerial SoftSerial(RX,TX);  //Uncomment this line if you whish to use a soft serial for communication with the duet mainboard. Set according Arduino pin numbers to use for Receive(RX) and Transmit(TX).

// if you use soft serial, you *MUST* decrease speed to 38400 for both ports, 
// the arduino will lack sufficient processing power to handle data any faster
#if defined(DEBUGLEVEL1_ACTIVE) || defined(DEBUGLEVEL2_ACTIVE)
// On most arduino, alt soft serial runs rx=9 tx=8
AltSoftSerial SoftSerialDebug;  //Uncomment this line if you wish to use a soft serial for debug purposes.
#endif
//#define SerialPort SoftSerial  //Per default the serial port for communication with the duet mainboard is being auto configured depending on the chipset being used. If you whish to customize it by your own, you have to uncomment this line and define the serial port to be used (e.g. Serial or Serial1 or SoftSerial etc.).

//General
#define NeoPixelStartupAnimationActive true  //Show Startup Animation for all Neopixels (true = activated / false = deactivated) !!Attention!! Animation will only be played if all NeoPixels have the same number of LEDs
#define DisplayPrinterObjectCylceFrequency 3  //Cycle frequency in seconds for displaying multiple PrinterObjects

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
#define NeoPixel1_StartupAnimationColor 0,0,255  //RGB values for StartupAnimation
#define NeoPixel1_DisplayPrinterObject 99  //PrinterObject(s) to be displayed by NeoPixel: 0= Heatbed / 1= Heater#1 / 2= Heater#2 / 3= Heater#3 / 4= Heater#4 / 99= PrinterStatus => Multiple PrinterObjects seperated by ,
#define NeoPixel1_DisplayPrinterObjectCycleByFrequency false  //If multiple PrinterObjects (Heater(s), PrinterStatus) should be displayed by a single Neopixel: false= Cycle PrinterObject depending on status of heaters / true= Cycle PrinterObject every x seconds as set by DisplayPrinterObjectCylceFrequency
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
#define NeoPixel2_StartupAnimationColor 255,0,0  //RGB values for StartupAnimation
#define NeoPixel2_DisplayPrinterObject 0  //PrinterObject(s) to be displayed by NeoPixel: 0= Heatbed / 1= Heater#1 / 2= Heater#2 / 3= Heater#3 / 4= Heater#4 / 99= PrinterStatus => Multiple PrinterObjects seperated by ,
#define NeoPixel2_DisplayPrinterObjectCycleByFrequency false  //If multiple PrinterObjects (Heater(s), PrinterStatus) should be displayed by a single Neopixel: false= Cycle PrinterObject depending on status of heaters / true= Cycle PrinterObject every x seconds as set by DisplayPrinterObjectCylceFrequency
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
#define NeoPixel3_StartupAnimationColor 0,255,0  //RGB values for StartupAnimation
#define NeoPixel3_DisplayPrinterObject 1  //PrinterObject(s) to be displayed by NeoPixel: 0= Heatbed / 1= Heater#1 / 2= Heater#2 / 3= Heater#3 / 4= Heater#4 / 99= PrinterStatus => Multiple PrinterObjects seperated by ,
#define NeoPixel3_DisplayPrinterObjectCycleByFrequency false  //If multiple PrinterObjects (Heater(s), PrinterStatus) should be displayed by a single Neopixel: false= Cycle PrinterObject depending on status of heaters / true= Cycle PrinterObject every x seconds as set by DisplayPrinterObjectCylceFrequency
#define NeoPixel3_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixel3_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
// moved to PIN 11 from 8 because of AltSoftSerial
#if defined(DEBUGLEVEL1_ACTIVE) || defined(DEBUGLEVEL2_ACTIVE)
#define NeoPixel3_ArduinoPin 11  //Arduino pin used to control the Neopixel (moved when using soft serial)
#else
#define NeoPixel3_ArduinoPin 8  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#endif
#define NeoPixel3_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixel3_TempOffset 0.0  //Minimum Temperature at which the first LED lights up
#define NeoPixel3_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixel3_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixel3_Brightness 8  //Overall brightness of the Neopixel-LEDs

//NeoPixel#4
#define NeoPixel4_Active true  //NeoPixel#4 (true = activated / false = deactivated)
#define NeoPixel4_StartupAnimationColor 255,255,0  //RGB values for StartupAnimation
#define NeoPixel4_DisplayPrinterObject 99,1  //PrinterObject(s) to be displayed by NeoPixel: 0= Heatbed / 1= Heater#1 / 2= Heater#2 / 3= Heater#3 / 4= Heater#4 / 99= PrinterStatus => Multiple PrinterObjects seperated by ,
#define NeoPixel4_DisplayPrinterObjectCycleByFrequency false  //If multiple PrinterObjects (Heater(s), PrinterStatus) should be displayed by a single Neopixel: false= Cycle PrinterObject depending on status of heaters / true= Cycle PrinterObject every x seconds as set by DisplayPrinterObjectCylceFrequency
#define NeoPixel4_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixel4_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixel4_ArduinoPin 5  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixel4_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixel4_TempOffset 0.0  //Minimum Temperature at which the first LED lights up
#define NeoPixel4_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixel4_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixel4_Brightness 8  //Overall brightness of the Neopixel-LEDs

//NeoPixel#5
#define NeoPixel5_Active false  //NeoPixel#5 (true = activated / false = deactivated)
#define NeoPixel5_StartupAnimationColor 0,255,255  //RGB values for StartupAnimation
#define NeoPixel5_DisplayPrinterObject 3  //PrinterObject(s) to be displayed by NeoPixel: 0= Heatbed / 1= Heater#1 / 2= Heater#2 / 3= Heater#3 / 4= Heater#4 / 99= PrinterStatus => Multiple PrinterObjects seperated by ,
#define NeoPixel5_DisplayPrinterObjectCycleByFrequency false  //If multiple PrinterObjects (Heater(s), PrinterStatus) should be displayed by a single Neopixel: false= Cycle PrinterObject depending on status of heaters / true= Cycle PrinterObject every x seconds as set by DisplayPrinterObjectCylceFrequency
#define NeoPixel5_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixel5_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixel5_ArduinoPin 4  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixel5_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixel5_TempOffset 0.0  //Minimum Temperature at which the first LED lights up
#define NeoPixel5_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixel5_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixel5_Brightness 8  //Overall brightness of the Neopixel-LEDs

//NeoPixel#6
#define NeoPixel6_Active false  //NeoPixel#6 (true = activated / false = deactivated)
#define NeoPixel6_StartupAnimationColor 255,0,255  //RGB values for StartupAnimation
#define NeoPixel6_DisplayPrinterObject 4  //PrinterObject(s) to be displayed by NeoPixel: 0= Heatbed / 1= Heater#1 / 2= Heater#2 / 3= Heater#3 / 4= Heater#4 / 99= PrinterStatus => Multiple PrinterObjects seperated by ,
#define NeoPixel6_DisplayPrinterObjectCycleByFrequency false  //If multiple PrinterObjects (Heater(s), PrinterStatus) should be displayed by a single Neopixel: false= Cycle PrinterObject depending on status of heaters / true= Cycle PrinterObject every x seconds as set by DisplayPrinterObjectCylceFrequency
#define NeoPixel6_Type NEO_GRB + NEO_KHZ800  //Neopixel type (do not change if using NeoPixel from the BOM)
#define NeoPixel6_LEDs 16  //Number of Neopixel-LEDs (do not change if using Neopixel from the BOM)
#define NeoPixel6_ArduinoPin 3  //Arduino pin used to control the Neopixel (do not change if using the wiring diagram from Ben Levi)
#define NeoPixel6_PixelOffset 0  //Usually LED number one of the NeoPixel is being used as the start point. Using the offset you can move the start point clockwise (positive offset) or anti-clockwise (negative offset)
#define NeoPixel6_TempOffset 0.0  //Minimum Temperature at which the first LED lights up
#define NeoPixel6_AnimationActive true  //Animation when the Hotend heats up (true = activated / false = deactivated)
#define NeoPixel6_Reverse false  //Reverse display direction (false = default / true = reversed)
#define NeoPixel6_Brightness 8  //Overall brightness of the Neopixel-LEDs

// ********** User-Config End **********
// *************************************

//Setup Serial Interface
#if (defined SerialPort)
  #define SerialObject SerialPort
#else
  //Arduino-Mega & Co.
  #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__))
    #define SerialObject Serial2
  #endif 
  //Arduino-Pro & Co.
  #if (defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__))
    #define SerialObject Serial
  #endif 
  //Arduino-Leonardo & Co.
  #if (defined(__AVR_ATmega32U4__))
    #define SerialObject Serial1
  #endif 
  //Arduino-Due & Co.
  #if (defined(__SAM3X8E__))
    #define SerialObject Serial3
  #endif 
#endif

#define SerialTimeout 1500 // need enough time to finish receiving and processing all the data
#define NeopixelRefreshSpeed 200
#define NumberHeaters 5
#define NumberNeoPixels 6

struct StructNeoPixelConfig {
  bool Active;
  uint32_t StartupAnimationColor;
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
  uint8_t Brightness;
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

StructPanelDueMessage Printer;

#define TMP_DISPLAY_PRINTER_OBJECT(x) \
int8_t TmpDisplayPrinterObject##x[(NumberHeaters + 2)] = {NeoPixel ## x ## _DisplayPrinterObject , -1};

TMP_DISPLAY_PRINTER_OBJECT(1)
TMP_DISPLAY_PRINTER_OBJECT(2)
TMP_DISPLAY_PRINTER_OBJECT(3)
TMP_DISPLAY_PRINTER_OBJECT(4)
TMP_DISPLAY_PRINTER_OBJECT(5)
TMP_DISPLAY_PRINTER_OBJECT(6)

int8_t DisplayPrinterObject;
uint8_t PrinterObjectPos;
uint8_t PrinterObject;
float SetTempHeater;
float ActTempHeater;
unsigned long NeoPixelTimerRefresh = millis();
unsigned long NeoPixelTimerToggleDisplayPrinterObject = millis();
uint8_t NeoPixelID;
uint8_t NeoPixelLEDID;
bool ToggleDisplayPrinterObject;
uint8_t HeaterID;
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

void GetSerialMessage() {
  unsigned long timer = millis();
  bool SerialMessageBegin = false;
  char inChar;
  JsonStreamingParser parser;
  StreamingHandler handler;
  handler.setPrinter(&Printer);
  parser.setListener(&handler);
  Printer.reset();
  uint16_t bytesRead = 0;

  while(!Printer.complete && ((millis() - timer) <= SerialTimeout))
  {    

    while(!Printer.complete && ((millis() - timer) <= SerialTimeout) && SerialObject.available() > 0) 
    {
      inChar = SerialObject.read();
      if (inChar == '\n') Printer.complete = true;
      bytesRead += 1;
      
      if (inChar=='{')
        SerialMessageBegin = true;

      if (SerialMessageBegin)
        parser.parse(inChar);
    }
  }  
  if ((millis() - timer) > SerialTimeout && !Printer.complete) {
    if (bytesRead > 0) {
      DEBUG1F(F("\nmsg timeout ")) DEBUG1(bytesRead)
      // turn LED on to indicate message failed to parse
      digitalWrite(LED_BUILTIN, HIGH);
    }
  } else if (Printer.complete && bytesRead > 1) {
    digitalWrite(LED_BUILTIN, LOW);
    if (Printer.UpdatePending) {
      DEBUG1F(F("\n")) DEBUG1F(bytesRead) DEBUG1F(F(" bytes read, job %: ")) DEBUG1(String(Printer.FractionPrinted(), 3))
    }
  }
}

#define SETUP_NEOPIXEL_CONFIG(x) { \
  NeoPixelConfig[x - 1].Active = NeoPixel ## x ## _Active; \
  NeoPixelConfig[x - 1].StartupAnimationColor = ConvertColor(NeoPixel ## x ## _StartupAnimationColor); \
  NeoPixelConfig[x - 1].DisplayPrinterObjectChangeByFrequency = NeoPixel ## x ## _DisplayPrinterObjectCycleByFrequency; \
  NeoPixelConfig[x - 1].DisplayPrinterObjectPosition = 0; \
  NeoPixelConfig[x - 1].Type = NeoPixel ## x ## _Type; \
  NeoPixelConfig[x - 1].LEDs = NeoPixel ## x ## _LEDs; \
  NeoPixelConfig[x - 1].ArduinoPin = NeoPixel ## x ## _ArduinoPin; \
  NeoPixelConfig[x - 1].PixelOffset = NeoPixel ## x ## _PixelOffset; \
  NeoPixelConfig[x - 1].TempOffset = NeoPixel ## x ## _TempOffset; \
  NeoPixelConfig[x - 1].AnimationActive = NeoPixel ## x ## _AnimationActive; \
  NeoPixelConfig[x - 1].AnimationReverse = NeoPixel ## x ## _Reverse; \
  NeoPixelConfig[x - 1].Brightness = NeoPixel ## x ## _Brightness; \
}

#define SETUP_HEATER_CONFIG(x) { \
  HeaterConfig[x].Scale = Heater ## x ## _Scale; \
  HeaterConfig[x].ColorIdle = ConvertColor(Heater ## x ## _ColorIdle); \
  HeaterConfig[x].ColorHeatUp = ConvertColor(Heater ## x ## _ColorHeatUp); \
  HeaterConfig[x].ColorHeatUpDone = ConvertColor(Heater ## x ## _ColorHeatUpDone); \
  HeaterConfig[x].ColorCoolDown = ConvertColor(Heater ## x ## _ColorCoolDown); \
  HeaterConfig[x].ColorAnimation = ConvertColor(Heater ## x ## _ColorAnimation); \
}

#define SETUP_NEOPIXEL_DISPLAY(x) { \
  for (NeoPixelID = 0; TmpDisplayPrinterObject ## x [NeoPixelID] != -1; NeoPixelID++) { \
    NeoPixelConfig[x - 1].DisplayPrinterObject[NeoPixelID] = TmpDisplayPrinterObject ## x [NeoPixelID]; \
  } \
  NeoPixelConfig[x - 1].DisplayPrinterObject[NeoPixelID] = -1; \
}

// Initialize everything and prepare to start
void setup()
{   
  pinMode(LED_BUILTIN, OUTPUT);
  // Initialize Variables
  int16_t BrightnessID = 0;
  uint8_t NeoPixelAnimationStep;
  uint8_t NeoPixelAnimationCount;
  uint8_t NeoPixelAnimationID;
  uint32_t AnimiationColor[NumberNeoPixels];

  SETUP_NEOPIXEL_CONFIG(1)
  SETUP_NEOPIXEL_CONFIG(2)
  SETUP_NEOPIXEL_CONFIG(3)
  SETUP_NEOPIXEL_CONFIG(4)
  SETUP_NEOPIXEL_CONFIG(5)
  SETUP_NEOPIXEL_CONFIG(6)
  
  SETUP_NEOPIXEL_DISPLAY(1)
  SETUP_NEOPIXEL_DISPLAY(2)
  SETUP_NEOPIXEL_DISPLAY(3)
  SETUP_NEOPIXEL_DISPLAY(4)
  SETUP_NEOPIXEL_DISPLAY(5)
  SETUP_NEOPIXEL_DISPLAY(6)

  SETUP_HEATER_CONFIG(0)
  SETUP_HEATER_CONFIG(1)
  SETUP_HEATER_CONFIG(2)
  SETUP_HEATER_CONFIG(3)
  SETUP_HEATER_CONFIG(4)
  
//  for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
//    NeoPixel_Device[NeoPixelID] = new Adafruit_NeoPixel(NeoPixelConfig[NeoPixelID].LEDs, NeoPixelConfig[NeoPixelID].ArduinoPin, NeoPixelConfig[NeoPixelID].Type);
//  }  

  // Initialize Neopixels
  for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
    if (NeoPixelConfig[NeoPixelID].Active == true) {
      NeoPixel_Device[NeoPixelID] = new Adafruit_NeoPixel(NeoPixelConfig[NeoPixelID].LEDs, NeoPixelConfig[NeoPixelID].ArduinoPin, NeoPixelConfig[NeoPixelID].Type);      
      NeoPixel_Device[NeoPixelID]->begin(); 
      NeoPixel_Device[NeoPixelID]->show();
    }
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
  Printer.UpdatePending = false;

  InitialSerialMessageSuccess = false;

  //Setup Serial Interface(s)
  SerialObject.begin(57600);
  while (!SerialObject);

  #if (defined(DEBUGLEVEL1_ACTIVE) || defined(DEBUGLEVEL2_ACTIVE))
    // my cpp isn't letting me compare SerialObject and SerialObjectDebug directly?
    if ((void*) &SerialObject != (void*) &SerialObjectDebug) {
        SerialObjectDebug.begin(38400);
    }
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

      //Initialize Neopixels && Build AnimationColor-Array
      NeoPixelAnimationCount = 0;
      for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++){
        if (NeoPixelConfig[NeoPixelID].Active == true) { 
          NeoPixel_Device[NeoPixelID]->setBrightness(255);
          AnimiationColor[NeoPixelAnimationCount] = NeoPixelConfig[NeoPixelID].StartupAnimationColor;
          NeoPixelAnimationCount++;
        }  
      }

      //Startup Animation Phase #1
      for (NeoPixelAnimationStep = 0; NeoPixelAnimationStep < NeoPixelAnimationCount; NeoPixelAnimationStep++) {
        for (NeoPixelLEDID = 0; NeoPixelLEDID < NeoPixelCount; NeoPixelLEDID++) {
          NeoPixelAnimationID = NeoPixelAnimationStep;
          for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++) {
            if (NeoPixelConfig[NeoPixelID].Active == true) {
              NeoPixel_Device[NeoPixelID]->fill(ConvertColor(0, 0, 0));
              NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,(NeoPixelLEDID + 1), NeoPixelConfig[NeoPixelID].AnimationReverse), AnimiationColor[NeoPixelAnimationID]); 
              NeoPixel_Device[NeoPixelID]->show();
            }  
            NeoPixelAnimationID++;
            if (NeoPixelAnimationID >= NeoPixelAnimationCount) {
              NeoPixelAnimationID = 0;
            }  
          }
          delay(30);
        }
      }  

      //Startup Animation Phase #2
      for (NeoPixelAnimationStep = 0; NeoPixelAnimationStep < NeoPixelAnimationCount; NeoPixelAnimationStep++) {
        //Part A
        for(BrightnessID = 0; BrightnessID < 255; BrightnessID++) {
          NeoPixelAnimationID = NeoPixelAnimationStep;
          for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++) {
            if (NeoPixelConfig[NeoPixelID].Active == true) {
              NeoPixel_Device[NeoPixelID]->setBrightness(BrightnessID); 
              NeoPixel_Device[NeoPixelID]->fill(AnimiationColor[NeoPixelAnimationID]);
              NeoPixel_Device[NeoPixelID]->show();
            }
            NeoPixelAnimationID++;
            if (NeoPixelAnimationID >= NeoPixelAnimationCount) {
              NeoPixelAnimationID = 0;
            }
          }
          delay(1);
        }  
        //Part B
        for(BrightnessID = 255; BrightnessID >= 0; BrightnessID--) {
          NeoPixelAnimationID = NeoPixelAnimationStep;
          for (NeoPixelID = 0; NeoPixelID < NumberNeoPixels; NeoPixelID++) {
            if (NeoPixelConfig[NeoPixelID].Active == true) {
              NeoPixel_Device[NeoPixelID]->setBrightness(BrightnessID); 
              NeoPixel_Device[NeoPixelID]->fill(AnimiationColor[NeoPixelAnimationID]);
              NeoPixel_Device[NeoPixelID]->show();
            }
            NeoPixelAnimationID++;
            if (NeoPixelAnimationID >= NeoPixelAnimationCount) {
              NeoPixelAnimationID = 0;
            }
          }
          delay(1);
        }  
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
    if ((millis() - NeoPixelTimerToggleDisplayPrinterObject) >= (DisplayPrinterObjectCylceFrequency * 1000)) {
      NeoPixelTimerToggleDisplayPrinterObject = millis();
      ToggleDisplayPrinterObject = true;
    }  
    else {
      ToggleDisplayPrinterObject = false;
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
            for (PrinterObjectPos = 0; DisplayPrinterObject == -1 && NeoPixelConfig[NeoPixelID].DisplayPrinterObject[PrinterObjectPos] != -1; PrinterObjectPos++) {
              PrinterObject = NeoPixelConfig[NeoPixelID].DisplayPrinterObject[PrinterObjectPos];
              if (PrinterObject == 99) {DisplayPrinterObject = PrinterObject;}
            }
            //Determine first "active" heater
            for (PrinterObjectPos = 0; DisplayPrinterObject == -1 && NeoPixelConfig[NeoPixelID].DisplayPrinterObject[PrinterObjectPos] != -1; PrinterObjectPos++) {
              PrinterObject = NeoPixelConfig[NeoPixelID].DisplayPrinterObject[PrinterObjectPos];
              if (Printer.Heater_Status[PrinterObject] == 2) {DisplayPrinterObject = PrinterObject;}
            }
            //Determine first "standby" heater
            for (PrinterObjectPos = 0; DisplayPrinterObject == -1 && NeoPixelConfig[NeoPixelID].DisplayPrinterObject[PrinterObjectPos] != -1; PrinterObjectPos++) {
              PrinterObject = NeoPixelConfig[NeoPixelID].DisplayPrinterObject[PrinterObjectPos];
              if (Printer.Heater_Status[PrinterObject] == 1) {DisplayPrinterObject = PrinterObject;}
            }
            //Determine first "off" heater
            for (PrinterObjectPos = 0; DisplayPrinterObject == -1 && NeoPixelConfig[NeoPixelID].DisplayPrinterObject[PrinterObjectPos] != -1; PrinterObjectPos++) {
              PrinterObject = NeoPixelConfig[NeoPixelID].DisplayPrinterObject[PrinterObjectPos];
              if (Printer.Heater_Status[PrinterObject] == 0) {DisplayPrinterObject = PrinterObject;}
            }
          }
          else {
            //Multiple PrinterObjects: Change PrinterObjects by Frequency
            if (ToggleDisplayPrinterObject == true) {
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

        #if (defined(DEBUGLEVEL2_ACTIVE))
          SerialObjectDebug.print(F("=> Determine PrinterObject / NeoPixelID[")); SerialObjectDebug.print(NeoPixelID); SerialObjectDebug.print(F("]= ")); SerialObjectDebug.print(DisplayPrinterObject); SerialObjectDebug.println(F(""));
          SerialObjectDebug.print(F("0= ")); SerialObjectDebug.print(NeoPixelConfig[NeoPixelID].DisplayPrinterObject[0]); SerialObjectDebug.print(F(" / 1= ")); SerialObjectDebug.print(NeoPixelConfig[NeoPixelID].DisplayPrinterObject[1]); SerialObjectDebug.print(F(" / 2= ")); SerialObjectDebug.print(NeoPixelConfig[NeoPixelID].DisplayPrinterObject[2]); SerialObjectDebug.print(F(" / 3= ")); SerialObjectDebug.print(NeoPixelConfig[NeoPixelID].DisplayPrinterObject[3]); SerialObjectDebug.print(F(" / 4= ")); SerialObjectDebug.print(NeoPixelConfig[NeoPixelID].DisplayPrinterObject[4]); SerialObjectDebug.print(F(" / 5= ")); SerialObjectDebug.print(NeoPixelConfig[NeoPixelID].DisplayPrinterObject[5]); SerialObjectDebug.println(F(""));
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
            #if (defined(DEBUGLEVEL2_ACTIVE))
              SerialObjectDebug.print(F("=> Read Temperatures NeoPixelID[")); SerialObjectDebug.print(NeoPixelID); SerialObjectDebug.print(F("]= ")); SerialObjectDebug.print(DisplayPrinterObject); SerialObjectDebug.print(F(" / SetTemp= ")); SerialObjectDebug.print(SetTempHeater); SerialObjectDebug.print(F(" / ActTemp= ")); SerialObjectDebug.print(ActTempHeater); SerialObjectDebug.println(F(""));
            #endif 

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
                if(NeoPixelLEDID < (Printer.FractionPrinted() * NeoPixelConfig[NeoPixelID].LEDs)) {
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
