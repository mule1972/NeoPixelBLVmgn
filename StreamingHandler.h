#pragma once

#include "src/json/JsonListener.h"

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
  inline float FractionPrinted() { return (printDuration - printWarmUpDuration) / (float) max(1, ((printDuration - printWarmUpDuration) + printRemaining)); }
  inline void reset() { UpdatePending = false; complete = false; }
  bool complete = false;
  private:
  inline void resetPrinting() { printDuration = 0; printRemaining = 0; printWarmUpDuration = 0;}
  uint16_t printDuration = 0;
  uint16_t printRemaining = 0;
  uint16_t printWarmUpDuration = 0;
};

const String EMPTY("");

class StreamingHandler: public JsonListener {

  private:
    StructPanelDueMessage* Printer = NULL;
    String stack[3] = { EMPTY, EMPTY, EMPTY };
    String current = EMPTY;
    uint8_t index = -1;
    bool shouldCount = true;
    uint8_t aryDepth = 0;
    bool inArray = false;
    uint8_t values = 0;

  public:
    inline void startDocument() { }

    inline void startArray() {
        index = -1;
        inArray = true;
        aryDepth = 0;

        push();
    }

    inline void startObject() {
        if (aryDepth == 0 && inArray) index++;

        push();

        aryDepth++;
    }

    inline void endArray() {
        pop();
        current = EMPTY;
        inArray = false;
    }

    inline void endObject() {
        pop();
        current = EMPTY;
        aryDepth--;
    }

    inline void endDocument() { Printer->complete = true; }

    inline void key(String k) {
        current = String(k);
        values = 0;
    }

    inline void value(String value) {
        values++;

        if (aryDepth == 0 && inArray) index++;
        handleValue(value);
    }

    void handleValue(String value);
  
    inline void whitespace(char c) { }

    inline void setPrinter(StructPanelDueMessage* message) { Printer = message; }

    void push() {
        stack[2] = stack[1];
        stack[1] = stack[0];
        if (values == 0 && current != EMPTY) {
            stack[0] = current;
        }
    }

    void pop() {
        stack[0] = stack[1];
        stack[1] = stack[2];
    }
};
