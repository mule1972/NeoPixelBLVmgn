#include <JsonStreamingParser.h>

#include <Adafruit_NeoPixel.h>
#include <AltSoftSerial.h>

#include "Structures.h"
#include "Debugging.h"
#include "Config.h"
#include "StreamingHandler.h"

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

// ********** User-Config End **********
// *************************************

#define COLOR1(x) COLOR(x) // expand a single argument to 3 for COLOR

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

StructPanelDueMessage Printer;

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
  bool messageComplete = false;
  char inChar;
  JsonStreamingParser parser;
  StreamingHandler handler;
  handler.setPrinter(&Printer);
  parser.setListener(&handler);
  Printer.reset();
  uint16_t bytesRead = 0;

  while(!messageComplete && ((millis() - timer) <= SerialTimeout))
  {    

    while(!messageComplete && ((millis() - timer) <= SerialTimeout) && SerialObject.available() > 0) 
    {
      inChar = SerialObject.read();
      if (inChar == '\n') messageComplete = true;
      else bytesRead += 1;
      
      if (inChar=='{')
        SerialMessageBegin = true;

      if (SerialMessageBegin)
        parser.parse(inChar);
    }
  }  
  if ((millis() - timer) > SerialTimeout && !messageComplete && bytesRead > 0) {
    DEBUG1F(F("\nmsg timeout ")) DEBUG1(bytesRead)
    // turn LED on to indicate message failed to parse
    digitalWrite(LED_BUILTIN, HIGH);
  } else if (Printer.complete) {
    digitalWrite(LED_BUILTIN, LOW);
    if (Printer.UpdatePending) {
      DEBUG1F(F("\n")) DEBUG1F(bytesRead) DEBUG1F(F(" bytes read, job %: ")) DEBUG1(String(Printer.FractionPrinted(), 3))
    }
  }
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
              NeoPixel_Device[NeoPixelID]->fill(COLOR(0, 0, 0));
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


#define FIND_ACTIVE_OBJECT(cond) { \
  for (PrinterObjectPos = 0; DisplayPrinterObject == -1 && NeoPixelConfig[NeoPixelID].DisplayPrinterObject[PrinterObjectPos] != -1; PrinterObjectPos++) { \
    PrinterObject = NeoPixelConfig[NeoPixelID].DisplayPrinterObject[PrinterObjectPos]; \
    if (cond) {DisplayPrinterObject = PrinterObject;} \
  } \
}

#define IS_HOT (Printer.Heater_ActTemp[PrinterObject] >= 50)
#define IS_PRINTERSTATUS (PrinterObject == 99)
#define UPDATE_THRESHOLD 5000
#define ACTIVE_UPDATE_THRESHOLD 1000
// Main loop
void loop()
{
  // Request update from duet board
  static unsigned long lastUpdate = 0;
  unsigned long loopStart = millis();

  // supports duet3, enable uart on port 2 (io1): M575 P2 S1 B57600
  // additionally, this can enable duet2 neopixels without paneldue, connect arduino tx to duet rx through a level shifter
  // do not connect tx to rx on duet 2 without a level shifter, you will fry your duet. do not connect tx to rx if a paneldue is connected
  if (loopStart - lastUpdate > (Printer.Status != 'I' ? ACTIVE_UPDATE_THRESHOLD : UPDATE_THRESHOLD)) {
    Serial.println("M409 F\"d99f\"");
    lastUpdate = loopStart;
  }

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
    if ((millis() - NeoPixelTimerToggleDisplayPrinterObject) >= (DisplayPrinterObjectCycleFrequency * 1000)) {
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
            // find a heater that is heating up still
            FIND_ACTIVE_OBJECT(!IS_PRINTERSTATUS && Printer.Heater_Status[PrinterObject] == 2 && Printer.Heater_ActTemp[PrinterObject] < Printer.Heater_ActiveTemp[PrinterObject] - HeaterConfig[PrinterObject].Scale)
            //Check for Printerobject = 99 (PrinterStatus) and printing, busy, paused/ing, resuming
            FIND_ACTIVE_OBJECT(IS_PRINTERSTATUS && strchr_P(PSTR("PDRBA"), Printer.Status) != NULL)
            //Determine first "active" heater
            FIND_ACTIVE_OBJECT(!IS_PRINTERSTATUS && Printer.Heater_Status[PrinterObject] == 2)
            //Determine first "standby" heater && >50C
            FIND_ACTIVE_OBJECT(!IS_PRINTERSTATUS && Printer.Heater_Status[PrinterObject] == 1 && IS_HOT)
            //Determine first "off" heater && >50C
            FIND_ACTIVE_OBJECT(!IS_PRINTERSTATUS && Printer.Heater_Status[PrinterObject] == 0 && IS_HOT)

            // otherwise show printer status if set, fall back to standby and off heaters
            FIND_ACTIVE_OBJECT(IS_PRINTERSTATUS)
            FIND_ACTIVE_OBJECT(Printer.Heater_Status[PrinterObject] == 1)
            FIND_ACTIVE_OBJECT(Printer.Heater_Status[PrinterObject] == 0)
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
                  NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelLEDID,NeoPixelConfig[NeoPixelID].AnimationReverse),COLOR1(PrinterStatus_ColorPrintingDone));
                }
                else {
                  NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelLEDID,NeoPixelConfig[NeoPixelID].AnimationReverse),COLOR1(PrinterStatus_ColorPrinting));
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
                  NeoPixel_Device[NeoPixelID]->fill(COLOR1(PrinterStatus_ColorIdle));
                  break;
                case 'P':
                  NeoPixel_Device[NeoPixelID]->fill(COLOR1(PrinterStatus_ColorPrinting));
                  break;
                case 'S':
                  NeoPixel_Device[NeoPixelID]->fill(COLOR1(PrinterStatus_ColorStopped));
                  break;
                case 'C':
                  NeoPixel_Device[NeoPixelID]->fill(COLOR1(PrinterStatus_ColorConfiguring));
                  break;
                case 'A':
                  NeoPixel_Device[NeoPixelID]->fill(COLOR1(PrinterStatus_ColorPaused));
                  break;
                case 'D':
                  NeoPixel_Device[NeoPixelID]->fill(COLOR1(PrinterStatus_ColorBusy));
                  break;
                case 'R':
                  NeoPixel_Device[NeoPixelID]->fill(COLOR1(PrinterStatus_ColorPausing));
                  break;
                case 'B':
                  NeoPixel_Device[NeoPixelID]->fill(COLOR1(PrinterStatus_ColorResuming));
                  break;
                case 'F':
                  NeoPixel_Device[NeoPixelID]->fill(COLOR1(PrinterStatus_ColorFlashing));
                  break;
                default:
                  NeoPixel_Device[NeoPixelID]->fill(COLOR1(PrinterStatus_ColorDefault));
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
              NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelConfig[NeoPixelID].AnimationMemoryPosition_Memory,NeoPixelConfig[NeoPixelID].AnimationReverse),COLOR1(PrinterStatus_ColorPrinting));
              NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelConfig[NeoPixelID].AnimationMemoryPosition,NeoPixelConfig[NeoPixelID].AnimationReverse),COLOR1(PrinterStatus_ColorAnimation));
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
                NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelConfig[NeoPixelID].AnimationMemoryPosition,NeoPixelConfig[NeoPixelID].AnimationReverse),COLOR1(PrinterStatus_ColorAnimation));
              }
              NeoPixelConfig[NeoPixelID].AnimationMemoryAnimationColor = 1;
            }
            else {
              //Animation phase2
              if (NeoPixelConfig[NeoPixelID].AnimationMemoryDisplayPrinterObject != 99) {
                NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelConfig[NeoPixelID].AnimationMemoryPosition,NeoPixelConfig[NeoPixelID].AnimationReverse),HeaterConfig[NeoPixelConfig[NeoPixelID].AnimationMemoryDisplayPrinterObject].ColorHeatUp);
              }  
              else {
                NeoPixel_Device[NeoPixelID]->setPixelColor(ConvertPosition2PixelIndex(NeoPixelConfig[NeoPixelID].LEDs,NeoPixelConfig[NeoPixelID].PixelOffset,NeoPixelConfig[NeoPixelID].AnimationMemoryPosition,NeoPixelConfig[NeoPixelID].AnimationReverse),COLOR1(PrinterStatus_ColorPrinting));
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
