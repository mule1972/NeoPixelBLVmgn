#pragma once

#include <JsonHandler.h>

#define NumberHeaters 5

class StructPanelDueMessage {
  friend class StreamingHandler;
  public:
  char Status;
  uint8_t Heater_Status[NumberHeaters];
  float Heater_ActTemp[NumberHeaters];
  float Heater_ActiveTemp[NumberHeaters];
  float Heater_StandbyTemp[NumberHeaters];
  bool UpdatePending;
  // prevent divby0
  inline float FractionPrinted() { return printDuration / (float) max(1, printDuration + printRemaining); }
  bool complete = false;
  private:
  uint16_t printDuration = 0;
  uint16_t printRemaining = 0;
};

class StreamingHandler: public JsonHandler {

  private:
    StructPanelDueMessage* Printer = NULL;

  public:
    inline void startDocument() {};

    inline void startArray(ElementPath path) {};

    inline void startObject(ElementPath path) {};

    inline void endArray(ElementPath path) {};

    inline void endObject(ElementPath path) {};

    inline void endDocument() { Printer->complete = true; }

    virtual void value(ElementPath path, ElementValue value);
  
    inline void whitespace(char c) {};

    inline void setPrinter(StructPanelDueMessage* message) { Printer = message; }
};
