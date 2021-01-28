#include <JsonHandler.h>
#include "StreamingHandler.h"

#define IS_HEATER (strcmp(path.get(-2)->getKey(), "heaters") == 0)
#define STR(x, y) (strcmp(x, y) == 0)

void StreamingHandler::value(ElementPath path, ElementValue value) {
  const char* key = path.getKey();

  if (key[0] != '\0') {
    if (STR(key, "status") && STR(path.getParent()->getKey(), "state")) {
        char *status = value.getString();
        if (STR(status, "idle")) {
            Printer->Status = 'I';
        } else if (STR(status, "simulating")) {
            Printer->Status = 'P';
        } else if (STR(status, "processing")) {
            Printer->Status = 'P';
        } else if (STR(status, "resuming")) {
            Printer->Status = 'B';
        } else if (STR(status, "busy")) {
            Printer->Status = 'D';
        } else if (STR(status, "starting")) {
            Printer->Status = 'F';
        } else if (STR(status, "updating")) {
            Printer->Status = 'C';
        } else if (STR(status, "pausing")) {
            Printer->Status = 'R';
        } else if (STR(status, "paused")) {
            Printer->Status = 'A';
        } else if (STR(status, "halted")) {
            Printer->Status = 'S';
        } else if (STR(status, "off")) {
            Printer->Status = 'S';
        }
        Printer->UpdatePending = true;
    } else if (STR(key, "active") && IS_HEATER) {
        Printer->Heater_ActiveTemp[path.getIndex()] = value.getFloat();
        Printer->UpdatePending = true;
    } else if (STR(key, "standby") && IS_HEATER) {
        Printer->Heater_StandbyTemp[path.getIndex()] = value.getFloat();
        Printer->UpdatePending = true;
    } else if (STR(key, "current") && IS_HEATER) {
        Printer->Heater_ActTemp[path.getIndex()] = value.getFloat();
        Printer->UpdatePending = true;
    } else if (STR(key, "state") && IS_HEATER) {
        char *status = value.getString();
        if (STR(status, "off") || STR(status, "offline")) {
            Printer->Heater_Status[path.getIndex()] = 0;
        } else if (STR(status, "active")) {
            Printer->Heater_Status[path.getIndex()] = 2;
        } else if (STR(status, "standby")) {
            Printer->Heater_Status[path.getIndex()] = 0;
        } else if (STR(status, "fault")) {
            Printer->Heater_Status[path.getIndex()] = 3;
        } else if (STR(status, "tuning")) {
            Printer->Heater_Status[path.getIndex()] = 4;
        }

        Printer->UpdatePending = true;
    } else if (STR(key, "duration") && STR(path.getParent()->getKey(), "job")) {
        Printer->printDuration = value.getInt();
        Printer->UpdatePending = true;
    } else if (STR(key, "file") && STR(path.getParent()->getKey(), "timesLeft")) {
        Printer->printRemaining = value.getInt();
        Printer->UpdatePending = true;
    }
  } 
}
