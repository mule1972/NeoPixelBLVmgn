#include <AltSoftSerial.h>
#pragma once

//#define DEBUGLEVEL1_ACTIVE
//#define DEBUGLEVEL2_ACTIVE

#if defined(DEBUGLEVEL1_ACTIVE) || defined(DEBUGLEVEL2_ACTIVE)
extern AltSoftSerial SoftSerialDebug;
#define SerialPortDebug SoftSerialDebug  //Per default the serial port for debugging purposes is being auto configured depending on the chipset being used. If you whish to customize it by your own, you have to uncomment this line and define the serial port to be used (e.g. "Serial" or "Serial1" or SoftSerialDebug etc).
#endif

//Setup Serial Interface (Debug)
#if (defined SerialPortDebug)
  #define SerialObjectDebug SerialPortDebug
#else
  //Arduino-Mega & Co.
  #if (defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__))
    #define SerialObjectDebug Serial
  #endif
  //Arduino-Pro & Co.
  #if (defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__))
    #define SerialObjectDebug Serial
  #endif
  //Arduino-Leonardo & Co.
  #if (defined(__AVR_ATmega32U4__))
    #define SerialObjectDebug Serial1
  #endif
  //Arduino-Due & Co.
  #if (defined(__SAM3X8E__))
    #define SerialObjectDebug Serial1
  #endif
#endif  

#ifdef DEBUGLEVEL1_ACTIVE
#define DEBUG1(x) SerialObjectDebug.println(x);
#define DEBUG1F(x) SerialObjectDebug.print(x);
#else
#define DEBUG1(x) ;
#define DEBUG1F(x) ;
#endif
