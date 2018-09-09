# BikePixels

NeoMatrix with Arduino for a rear bicycle light with custom images and effects to ride safty by night.

## Components

To build your own Bike Pixel you should have all the elements listed bellow:

* Arduino UNO (or any other Ardiuno or compatible board);
* 1 x NeoPixel 8x8 matrix;
* 3 x touch switches;
* 3 x 10 kΩ resistence;
* 1 x 470 Ω resistence;
* 1 x 1000 uf/6.3V capacitator;
* 1 x 6 AAA battery holder (but you can try any other power source);
* 1 x on\off botton (optional if your battery holder have one built-in);
* wires and soldering stuff;
* the case.
    
If you have all the components you can assemble it following the next schema.

![BikePixel schema](./docs/electronics/sketch%20protoboard.png "BikePixel sketch")

## Software
All required application to edit and design Bike Pixel are open sourced. Bellow you can find all the used tools:

* [Arduino IDE](https://www.arduino.cc/en/Main/Software): to write, biuld and upload code to the Arduino board.
* [Fritzing](http://fritzing.org/download/): to design electronic schemas and the PCB.
* [Inkscape](https://inkscape.org/en/release/): to design custom parts for Fritzing (e.g. the board).
* [FreeCAD](https://www.freecadweb.org/wiki/Download): to design the case.

    
## Sketches
At the docs folder you can find the sketches and the draws with schemas and case model so you can send this data to any manufacturer to cut and print it by you or just DIY.

### Case
The case is designed to be made joining three layers of plexy. The base is made of 1 mm plexy black board, then the middle should have 5 or 6 mm and the final should be 1 mm of transparent plexy. The design and draws can be found at docs/case folder. The final result should look similar to:

![BikePixel case](./docs/case/case.png "BikePixel Case")


### PCB
The PCB encapsulates the buttons and manage connections from Arduino to the neopixel matrix. It desing is shown belllow:

![BikePixel schema](./docs/electronics/sketch%20pcb.png "BikePixel PCB")

Production files are available in SVG and Gerber 


## Setup
To compile the source you'll need some extra libraries:

* [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)
* [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel)
* [Adafruit NeoMatrix](https://github.com/adafruit/Adafruit_NeoMatrix)

Note that you can install these libraries directly from Arduino Studio (Sketch menu, > Include Library > Manage Libraries) or by placing it after download into the Arduino Library folder (usally in your home).

## Assembling
Bellow you can find step by step asseble Bike Pixel using the designed case and PCB. By now Arduino and batteries are kept apart from the main box with buttons and the neopixel matrix. The idea is to attach Bike Pixel to a back back. 

### Case
The case is designed to be plugable to the back pack by using 4 spring snaps but you can use any other method like a good double-sided adhesive tape or a hook and loop fastener.


## Additional info
Bellow you can find additional documentation and interesting stuff related with NeoPixel that I've found interesting and usefull during the construction of Bike Pixel:

* [All you always wanted to know about NeoPixel](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels) including [NeoPixel best practices](https://learn.adafruit.com/adafruit-neopixel-uberguide/best-practices)
* [Snowflake Sweater with Bluetooth Control example and tutorial](https://learn.adafruit.com/neopixel-matrix-snowflake-sweater/overview)
* [Creation of a custom PCB on Fritzing](http://fritzing.org/pcb-custom-shape/). Note that if you use Incskape you should edit the SVG file (Saved as plain SVG) manually in any text editor and change the layer names (e.g `<g id="L4123">` to `<g id="silkscreen 1">`).


