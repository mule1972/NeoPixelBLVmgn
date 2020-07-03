NeoPixel sketch for the great 3D-Printer project from Ben Levi (https://www.thingiverse.com/thing:3382718)

With this sketch you can use up to 6 Neopixels to show e.g. the hotend- and heatbed-temperature and the printer status including print progress.
Get nearly full control on the NeoPixels and their configuration and use even totally different types of NeoPixels, change colors, switch animations on/off, change brightness, set offsets and so on.

Requirements:
- Adafruit.NeopixelLibrary (minimum version 1.2.3) (https://github.com/adafruit/Adafruit_NeoPixel)
- PanelDue connected to the Duet mainboard

How to configure the sketch to your personal needs? 
Just change the parameters in the marked "User-Config" part in the sketch file before compiling and uploading it to your Arduino. Some more explanation:

Until now (maybe I will add some more in the future) you can display 6 different type of things (named PrinterObjects) via the Neopixels using the sketch:
0 = Temperature of Bed-Heater
1 = Temperature of Hotend1-Heater
2 = Temperature of Hotend2-Heater
3 = Temperature of Hotend3-Heater
4 = Temperature of Hotend4-Heater
99 = Printer Status combined with Print Progress

In order to define which NeoPixel displays which PrinterObject(s) you have to use the setup parameter "DisplayPrinterObject" for the proper NeoPixel. Some examples:
A) Display only the "Temperature of the Heatbed" on "Neopixel1":
NeoPixel1_DisplayPrinterObject = 0
B) Display only the "Printer Status combined with Print Progress" on "Neopixel3":
NeoPixel3_DisplayPrinterObject = 99
C) Display the "Temperature of the Heatbed" AND the "Temperature of Heater 1" on "Neopixel1":
NeoPixel1_DisplayPrinterObject = 0,1
D) Display the "Temperature of Heater 1" AND the "Temperature of Heater 2" AND the "Temperature of Heater 3" on "Neopixel2":
NeoPixel2_DisplayPrinterObject = 1,2,3
E) Display the "Temperature of the Heatbed" AND the "Temperature of Heater 1" AND the "Printer Status combined with Print Progress" on "Neopixel2":
NeoPixel3_DisplayPrinterObject = 0,1,99

If you setup one Neopixel to show more than one PrinterObject you can decide how the corresponding Neopixel cycles through the defined PrinterObjects by using the setup parameter "DisplayPrinterObjectChangeByFrequency":
true = the corresponding Neopixel cycles between the PrinterObjects in a fixed frequency (the frequency in seconds can be configured by using the setup parameter "DisplayPrinterObjectChangeFrequency")
false = the corresponding Neopixel displays only the heater with the "highest priority": Priority 1 = first active heater of the defined ones / Priority 2 = First standby heater of the defined ones / Priority 3 = First off heater of the defined ones
Attention: false can only be used if you setup the corresponding Neopixel to display heaters only.

If you have any question just ask in the facebook group of Ben Levi: https://www.facebook.com/groups/BenLevi/ 
