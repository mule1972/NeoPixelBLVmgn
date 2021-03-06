# About
This is a NeoPixel sketch for the great 3D-Printer project from Ben Levi (https://www.thingiverse.com/thing:3382718)

With this sketch you can use up to six Neopixel groups (rings or strips) to show printer status (heater temperatures, print progress, and other things). Get nearly full control on the NeoPixels and their configuration and use totally different types of NeoPixels, change colors, switch animations on/off, change brightness, set offsets and so on.

### Hardware Requirements
- A Duet3D control board
- An attached Panel Due, or
- A 5V to 3V level-shifting circuit

### Software Requirements
- [Arduino IDE](https://www.arduino.cc/en/software)
- [Adafruit Neopixel Library](https://github.com/adafruit/Adafruit_NeoPixel) (minimum version 1.2.3)

# Wiring
This sketch communicates with the Duet board via the PanelDue port.

If you have a PanelDue connected, the PanelDue will ask the Duet for status updates and the Arduino running this sketch "overhears" what the Duet says. For this configuration, connect the RX pin of the Arduino to the UTXD0 pin on the Duet PanelDue port. (See the diagram below.)

If you don't have a PanelDue connected, this sketch can still work, but needs some extra parts so it can ask the Duet for a status update. Connect a wire between the Arduino's RX pin and the Duet's UTXD0 pin as described above. Then connect the Arduino's TX pin **through a level shifter** (such as a voltage divider) to the Duet's URXD0 pin. The problem here is that the Arduino uses a higher voltage than the Duet, so if the Arduino talks directly to the Duet, it screams too loudly and will fry the Duet, making it deaf! :) Please do not connect this second wire if you don't know what you are doing, but note that the NeoPixels won't work without it if you don't have a PanelDue.

![Wiring Diagram](https://forum.duet3d.com/assets/uploads/files/1596792970038-screenshot-2020-08-07-at-11.34.09.png)

For tech-nerds like me: The Duet runs on 3.3V and the Arduino runs on 5V. The Arduino can pick up the 3.3V serial line from the Duet, but do not connect the Arduino TX line to the Duet without a level-shifter. The URXD0 pin on the Duet is connected straight to the processor and *not* 5V tolerant. I made a voltage divider with two 3.3K resistors, but there may be a better way.

Still nerd-talk: This sketch brilliantly auto-selects a serial port to use based on the processor. (See NeoPixel_BLV.ino, near the top) On my Arduino Pro Mini, it uses the default Serial port on pins 0 and 1, as well as a baud rate of 57600 to match the PanelDue.

# Configuration
To configure the NeoPixels, edit the "Config.h" file according to the instructions below, then upload the sketch to your Arduino.

For each neopixel ring or strip, you have the following settings:
- Active (Enable or disable these NeoPixels)
- Startup Animation Color (By default the leds light up and spin when you first power them on. This is the color for that animation.)
- Display Printer Object (See explanation below. This is a list of which statuses you want the NeoPixel group to show.)
- Display Printer Object Change By Frequency (Set this to true to automatically scroll through the statuses above.)
- Type (The physical type of NeoPixel used--normally not changed.)
- LEDs (The number of LEDs in this group (strip, ring, etc.)
- Arduino Pin (The Arduino pin that the NeoPixels are connected to.)
- Pixel Offset (Changes where the animations and graphs start. For example, if you have a ring that's tilted, use this offset to make the graphs start at the bottom of the ring.
- Temp Offset (If you're displaying heater statuses, this is how hot it needs to be before lighting the first LED in the graph. Use this to make the graph compensate for room temperature.)
- Animation Active (Set to true to animate the graphs and statuses.)
- Animation Reverse (Reverses the direction the graphs are shown.)
- Brightness (Set between 0 and 255 to control the overall brightness of the LEDs from off to full power.)

### Understanding Colors
Each color is set using a system of red, green, and blue `COLOR(red, green, blue)`. Each color has a range of 0-255, with 0 being off, and 255 being full brightness. `COLOR(255, 0, 0)` is pure red, `Color(255, 0, 255)` is full-power red and blue, so a purple color, and `Color(0, 255, 100)` is green with a twinge of blue, etc.

### Printer Objects
Right now (maybe I will add some more in the future) you can display these six different types of statues (named PrinterObjects) on the Neopixels.
- 0 = Status of Heater 0 (Typically the Bed Heater)
- 1 = Status of Heater 1 (Typically the Main Hotend)
- 2 = Status of Heater 2
- 3 = Status of Heater 3
- 4 = Status of Heater 4
- 99 = Printer Status combined with Print Progress

To select which printer objects to show, put the number corresponding to the status in the `PrinterObject` setting for a NeoPixel group. You can show multiple objects with one group of NeoPixels by making a list. The last object in the list must always be `-1`. See the examples below:

Display only the temperature of Heater 0 (Typically the Bed):
```
DisplayPrinterObject : { 0, -1 },
```

Show the temperature of Heater 1 and the printer status:
```
DisplayPrinterObject : { 1, 99, -1 },
```

If you setup one NeoPixel group to show more than one PrinterObject, use the setting `DisplayPrinterObjectChangeByFrequency` to set how the NeoPixels show the printer objects.
- Set to True (This makes the Neopixels switch to the next object in the list every few seconds. The time can be set with the `DisplayPrinterObjectCycleFrequency` at the very top of the Config.h file.
- Set to False (This only works if only heaters are shown on a group of NeoPixels. It shows only the heater with the "Highest Priority." The first active heater in the list gets first priority, the first standby heater gets second priority, and the first off heater gets third.

### Changing Graph Colors
The bottom section of the Config.h file sets the colors for the various heaters. Each heater uses the following settings:
- Scale (This sets the range a heater graph shows. To calculate this number, subtract the temperature offset described above from the max temperature you want your graph to show. Then divide that number by how many LEDs are in your group. For example, to show a temperature range of 0-96C on 16 LEDs with no offset, `(96 - 0) / 16 = 6` you would use a scale number of 6.
- Color Idle (This is the color of the "empty space" in the graph. Think of it like a background.)
- Color Heat Up (When a heater is heating, this is the color that indicates the heater's setpoint - it's the goal for the heater to reach!)
- Color Heat Up Done (This shows the actual temperature of the heater - how close it is to the goal.)
- Color Cool Down (After a heater is turned off, the graph showing its temperature is switched to this color.)
- Color Animation (This is the color of the animation pixel, if enabled.)

At the very bottom of the file, there's a list of color settings for Printer Object 99 (the printer status). These names are fairly self-explanatory.

## Changes to your Duet Configuration
In order to enable the PanelDue serial port and turn off check-sums, which the Arduino doesn't generate, add this line somewhere in your Duet's config file:
`M575 P1 S0`

`M575` sets serial parameters, `P1` selects the auxillary serial port, and `S0` sets it to use PanelDue mode without checksums. [More details here.](https://duet3d.dozuki.com/Wiki/Gcode#Section_M575_Set_serial_comms_parameters)

# Support
If you have any questions about this sketch, just ask in [Ben Levi's Facebook group](https://www.facebook.com/groups/BenLevi/)
