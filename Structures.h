#pragma once

#define NumberHeaters 5
#define NumberNeoPixels 6

struct StructNeoPixelConfig {
  bool Active;
  uint32_t StartupAnimationColor;
  int8_t DisplayPrinterObject[(NumberHeaters + 1)];
  bool DisplayPrinterObjectChangeByFrequency;
  neoPixelType Type;
  uint16_t LEDs;
  uint16_t ArduinoPin;
  int8_t PixelOffset;
  float TempOffset;
  bool AnimationActive;
  bool AnimationReverse;
  uint8_t Brightness;
  uint8_t DisplayPrinterObjectPosition;
  bool AnimationMemoryActive;
  bool AnimationMemoryRunning;
  uint8_t AnimationMemoryPosition;
  uint8_t AnimationMemoryPosition_Memory;
  uint8_t AnimationMemoryRangeBegin;
  uint8_t AnimationMemoryRangeEnd;
  int8_t AnimationMemoryDisplayPrinterObject;
  uint8_t AnimationMemoryAnimationColor;
};  

struct StructHeaterConfig {
  uint8_t Scale;
  uint32_t ColorIdle;
  uint32_t ColorHeatUp;
  uint32_t ColorHeatUpDone;
  uint32_t ColorCoolDown;
  uint32_t ColorAnimation;
};
