#include "Debugging.h"
#include "StreamingHandler.h"

#define EQ(x, y) (strcmp_P(x.c_str(), PSTR(y)) == 0)

#define D(x) DEBUG1F(x)
#define DLN(x) DEBUG1(x)
void StreamingHandler::handleValue(String value) {

    if (EQ(current, "status") && EQ(stack[0], "state")) {
        if (EQ(value, "idle")) {
            Printer->resetPrinting();
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
            Printer->resetPrinting();
            Printer->Status = 'F';
        } else if (EQ(value, "updating")) {
            Printer->resetPrinting();
            Printer->Status = 'C';
        } else if (EQ(value, "pausing")) {
            Printer->Status = 'R';
        } else if (EQ(value, "paused")) {
            Printer->Status = 'A';
        } else if (EQ(value, "halted")) {
            Printer->resetPrinting();
            Printer->Status = 'S';
        } else if (EQ(value, "off")) {
            Printer->resetPrinting();
            Printer->Status = 'S';
        }
        D(F("Status: ")) DLN(Printer->Status);
        Printer->UpdatePending = true;
    } else if (EQ(current, "active") && EQ(stack[0], "heaters")) {
        Printer->Heater_ActiveTemp[index] = value.toFloat();
        D(F("Active Temp: ")) D(index) D(" ") DLN(value)
        Printer->UpdatePending = true;
    } else if (EQ(current, "standby") && EQ(stack[0], "heaters")) {
        D(F("Standby Temp: ")) D(index) D(" ") DLN(value)
        Printer->Heater_StandbyTemp[index] = value.toFloat();
        Printer->UpdatePending = true;
    } else if (EQ(current, "current") && EQ(stack[0], "heaters")) {
        D(F("Current Temp: ")) D(index) D(" ") DLN(value)
        Printer->Heater_ActTemp[index] = value.toFloat();
        Printer->UpdatePending = true;
    } else if (EQ(current, "state") && EQ(stack[0], "heaters")) {
        if (EQ(value, "off") || EQ(value, "offline")) {
            Printer->Heater_Status[index] = 0;
        } else if (EQ(value, "active")) {
            Printer->Heater_Status[index] = 2;
        } else if (EQ(value, "standby")) {
            Printer->Heater_Status[index] = 1;
        } else if (EQ(value, "fault")) {
            Printer->Heater_Status[index] = 3;
        } else if (EQ(value, "tuning")) {
            Printer->Heater_Status[index] = 4;
        }
        D(F("Heater State: ")) D(index) D(" ") DLN(value)
        Printer->UpdatePending = true;
    } else if (EQ(current, "slicer") && EQ(stack[0], "timesLeft")) {
        D(F("Time Left: ")) DLN(value);
        Printer->printRemaining = value.toInt();
        Printer->UpdatePending = true;
    } else if (EQ(current, "duration") && EQ(stack[0], "job") && Printer->printRemaining > 0) {
        Printer->printDuration = value.toInt();
        D(F("Duration: ")) DLN(value);
        Printer->UpdatePending = true;
    } else if (EQ(current, "warmUpDuration") && EQ(stack[0], "job") && Printer->printRemaining > 0) {
        Printer->printWarmUpDuration = value.toInt();
        D(F("WarmUpDuration: ")) DLN(value);
        Printer->UpdatePending = true;
    }
}
