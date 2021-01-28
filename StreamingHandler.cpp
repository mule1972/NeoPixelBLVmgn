#include <JsonListener.h>
#include "StreamingHandler.h"

#define parent stack[0]
#define IS_HEATER (parent == "heaters")
#define EQ(x, y) (x == y)

void StreamingHandler::handleValue(String value) {

    if (EQ(current, "duration") || EQ(current, "active") || EQ(current, "file") || EQ(current, "status") || EQ(current, "standby") || EQ(current, "state") || EQ(current, "current")) {
      SoftSerialDebug.println(stack[2] + " -> " + stack[1] + " -> " + stack[0] + " -> " + current + " = " + value);
    }

    if (EQ(current, "status") && EQ(parent, "state")) {
        if (EQ(value, "idle")) {
            Printer->Status = 'I';
        } else if (EQ(value, "simulating")) {
            Printer->Status = 'P';
        } else if (EQ(value, "processing")) {
            Printer->Status = 'P';
        } else if (EQ(value, "resuming")) {
            Printer->Status = 'B';
        } else if (EQ(value, "busy")) {
            Printer->Status = 'D';
        } else if (EQ(value, "starting")) {
            Printer->Status = 'F';
        } else if (EQ(value, "updating")) {
            Printer->Status = 'C';
        } else if (EQ(value, "pausing")) {
            Printer->Status = 'R';
        } else if (EQ(value, "paused")) {
            Printer->Status = 'A';
        } else if (EQ(value, "halted")) {
            Printer->Status = 'S';
        } else if (EQ(value, "off")) {
            Printer->Status = 'S';
        }
        SoftSerialDebug.println(String("Got Status: ") + Printer->Status);
        Printer->UpdatePending = true;
    } else if (EQ(current, "active") && IS_HEATER) {
        Printer->Heater_ActiveTemp[index] = value.toFloat();
        SoftSerialDebug.println(String("Got Active Temp: ") + index + " " + value.toFloat());
        Printer->UpdatePending = true;
    } else if (EQ(current, "standby") && IS_HEATER) {
        Printer->Heater_StandbyTemp[index] = value.toFloat();
        Printer->UpdatePending = true;
    } else if (EQ(current, "current") && IS_HEATER) {
        Printer->Heater_ActTemp[index] = value.toFloat();
        SoftSerialDebug.println(String("Got Current Temp: ") + index + " " + value.toFloat());
        Printer->UpdatePending = true;
    } else if (EQ(current, "state") && IS_HEATER) {
        if (EQ(value, "off") || EQ(value, "offline")) {
            Printer->Heater_Status[index] = 0;
        } else if (EQ(value, "active")) {
            Printer->Heater_Status[index] = 2;
        } else if (EQ(value, "standby")) {
            Printer->Heater_Status[index] = 0;
        } else if (EQ(value, "fault")) {
            Printer->Heater_Status[index] = 3;
        } else if (EQ(value, "tuning")) {
            Printer->Heater_Status[index] = 4;
        }

        Printer->UpdatePending = true;
    } else if (EQ(current, "duration") && EQ(parent, "job")) {
        Printer->printDuration = value.toInt();
        SoftSerialDebug.println("Duration: " + value);
        Printer->UpdatePending = true;
    } else if (EQ(current, "file") && EQ(parent, "timesLeft")) {
        SoftSerialDebug.println("Time Left: " + value);
        Printer->printRemaining = value.toInt();
        Printer->UpdatePending = true;
    }
}
