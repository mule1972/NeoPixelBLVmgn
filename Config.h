#pragma once

#include <Adafruit_Neopixel.h>
#include "Structures.h"

#define NeoPixelStartupAnimationActive true  //Show Startup Animation for all Neopixels (true = activated / false = deactivated) !!Attention!! Animation will only be played if all NeoPixels have the same number of LEDs
#define COLOR(r, g, b) (((uint32_t)r << 16) | ((uint32_t)g <<  8) | b)
#define DisplayPrinterObjectCycleFrequency 3  // Cycle frequency in seconds

/*
 * Configure your Neopixels here
 *
 * Active - true/false: enable/disable this neopixel
 * StartupAnimationColor - COLOR(red, green, blue), animates with color intensity 0-255
 * DisplayPrinterObject - [0, 1, 2, 3, 4, 99]: heater, extruder1-4, 99 = printer status
 *                        multiple may be selected, the last element must always be -1
 * DisplayPrinterObjectChangeByFrequency - true/false: true: switch DisplayPrinter object based on the value of
 *                                         DisplayPrinterObjectCycleFrequency, false: pick the first of 99,
 *                                         or heater active, standby, off
 * Type - neopixel library value, do not change from default unless they are not BOM neopixels
 * LEDs - N: number of LEDs in the neopixel
 * ArduinoPin - N: Arduino PIN number to attach this neopixel
 * PixelOffset - N: LED position for starting point, positive is clockwise, negative is counterclockwise
 * TempOffset - N.M: floating point minimum value at which the first LED lights up
 * AnimationActive - true/false: Animate while heating
 * AnimationReverse - true/false: Reverse the display direction
 * Brightness - N: 0-255 brightness level
 *
 */
StructNeoPixelConfig NeoPixelConfig[NumberNeoPixels] = {
  { // Neopixel 1
    Active                                : true,
    StartupAnimationColor                 : COLOR(0, 0, 255),
    DisplayPrinterObject                  : { 1, 99, -1 },
    DisplayPrinterObjectChangeByFrequency : true,
    Type                                  : NEO_GRB + NEO_KHZ800,
    LEDs                                  : 16,
    ArduinoPin                            : 7,
    PixelOffset                           : 2,
    TempOffset                            : 0,
    AnimationActive                       : true,
    AnimationReverse                      : false,
    Brightness                            : 8,
  },
  { // Neopixel 2
    Active                                : true,
    StartupAnimationColor                 : COLOR(255, 0, 0),
    DisplayPrinterObject                  : { 0, -1 },
    DisplayPrinterObjectChangeByFrequency : false,
    Type                                  : NEO_GRB + NEO_KHZ800,
    LEDs                                  : 16,
    ArduinoPin                            : 6,
    PixelOffset                           : 0,
    TempOffset                            : 0,
    AnimationActive                       : true,
    AnimationReverse                      : false,
    Brightness                            : 8,
  },
  { // Neopixel 3
    Active                                : true,
    StartupAnimationColor                 : COLOR(0, 255, 0),
    DisplayPrinterObject                  : { 1, -1 },
    DisplayPrinterObjectChangeByFrequency : false,
    Type                                  : NEO_GRB + NEO_KHZ800,
    LEDs                                  : 16,
#if defined(DEBUGLEVEL1_ACTIVE) || defined(DEBUGLEVEL2_ACTIVE)
    ArduinoPin                            : 8,
#else
    ArduinoPin                            : 11, // move this neopixel to pin 11 if debugging is enabled
#endif
    PixelOffset                           : 0,
    TempOffset                            : 0,
    AnimationActive                       : true,
    AnimationReverse                      : false,
    Brightness                            : 8,
  },
  { // Neopixel 4
    Active                                : false,
    StartupAnimationColor                 : COLOR(255, 255, 0),
    DisplayPrinterObject                  : { 2, -1 },
    DisplayPrinterObjectChangeByFrequency : false,
    Type                                  : NEO_GRB + NEO_KHZ800,
    LEDs                                  : 16,
    ArduinoPin                            : 5,
    PixelOffset                           : 0,
    TempOffset                            : 0,
    AnimationActive                       : true,
    AnimationReverse                      : false,
    Brightness                            : 8,
  },
  { // Neopixel 5
    Active                                : false,
    StartupAnimationColor                 : COLOR(0, 255, 255),
    DisplayPrinterObject                  : { 3, -1 },
    DisplayPrinterObjectChangeByFrequency : false,
    Type                                  : NEO_GRB + NEO_KHZ800,
    LEDs                                  : 16,
    ArduinoPin                            : 4,
    PixelOffset                           : 0,
    TempOffset                            : 0,
    AnimationActive                       : true,
    AnimationReverse                      : false,
    Brightness                            : 8,
  },
  { // Neopixel 6
    Active                                : false,
    StartupAnimationColor                 : COLOR(255, 0, 255),
    DisplayPrinterObject                  : { 4, -1 },
    DisplayPrinterObjectChangeByFrequency : false,
    Type                                  : NEO_GRB + NEO_KHZ800,
    LEDs                                  : 16,
    ArduinoPin                            : 3,
    PixelOffset                           : 0,
    TempOffset                            : 0,
    AnimationActive                       : true,
    AnimationReverse                      : false,
    Brightness                            : 8,
  },
};

/*
 * Scale - N: Temperature / N = number of LEDs to color in
 * ColorIdle, HeatUp, HeatUpDone, CoolDown, Animation: COLOR values for the specified state
 */
StructHeaterConfig HeaterConfig[NumberHeaters] = {
  { // heater0: bed
    Scale           : 6, // 0-96C range (over 96C = 16 LEDs), 6C steps
    ColorIdle       : COLOR(255, 255, 255),
    ColorHeatUp     : COLOR(255, 64, 64),
    ColorHeatUpDone : COLOR(255, 0, 0),
    ColorCoolDown   : COLOR(0, 0, 255),
    ColorAnimation  : COLOR(0, 0, 0)
  },
  { // heater1: extruder 1
    Scale           : 16, // 0-256C range (over 256C = 16 LEDs), 16C steps
    ColorIdle       : COLOR(255, 255, 255),
    ColorHeatUp     : COLOR(255, 64, 64),
    ColorHeatUpDone : COLOR(255, 0, 0),
    ColorCoolDown   : COLOR(0, 0, 255),
    ColorAnimation  : COLOR(0, 0, 0)
  },
  { // heater2: extruder 2
    Scale           : 20,
    ColorIdle       : COLOR(255, 255, 255),
    ColorHeatUp     : COLOR(255, 64, 64),
    ColorHeatUpDone : COLOR(255, 0, 0),
    ColorCoolDown   : COLOR(0, 0, 255),
    ColorAnimation  : COLOR(0, 0, 0)
  },
  { // heater3: extruder 3
    Scale           : 20,
    ColorIdle       : COLOR(255, 255, 255),
    ColorHeatUp     : COLOR(255, 64, 64),
    ColorHeatUpDone : COLOR(255, 0, 0),
    ColorCoolDown   : COLOR(0, 0, 255),
    ColorAnimation  : COLOR(0, 0, 0)
  },
  { // heater4: extruder 4
    Scale           : 20,
    ColorIdle       : COLOR(255, 255, 255),
    ColorHeatUp     : COLOR(255, 64, 64),
    ColorHeatUpDone : COLOR(255, 0, 0),
    ColorCoolDown   : COLOR(0, 0, 255),
    ColorAnimation  : COLOR(0, 0, 0)
  },
};

//PrinterObject#99 - PrinterStatus
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
