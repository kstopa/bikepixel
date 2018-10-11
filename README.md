# BikePixels

NeoMatrix with Arduino for a rear bicycle light with custom images and effects to ride safty by night.

## Components

To build your own Bike Pixel you should have all the elements listed bellow:

* Arduino Nano (or any other Ardiuno or compatible board);
* 1 x NeoPixel 8x8 matrix (flexible version recommended);
* 3 x touch switches;
* 3 x 10 kΩ resistence;
* 1 x 470 Ω resistence;
* 1 x 1000 uf/6.3V capacitator;
* 1 x 6 AAA battery holder (but you can try any other power source like a smartphone external battery);
* 1 x on\off botton (optional if your battery holder have one built-in);
* wires and soldering stuff;
* the case,
* 9 x 1.6M screws with a length of 10 or 12 mm and nuts.
* 4 x 1.6M screws with a length of 4 mm and nuts.
    
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

The case is designed to be made by joining three (or four optionally) layers of 
plexy. There are 2 possible configurations in both the base is made of 1 mm plexy 
black board and the top should be made of an 1 mm transparent plexy. The middle 
layers can be done with one 7-8 mm black board or two 5-6 mm + 2-3 mm boards. Bellow
you can find a case parts list: 

|      Piece      |            Thickness [mm]            |      Material     |                              CAD file                              |
|:---------------:|:------------------------------------:|:-----------------:|:------------------------------------------------------------------:|
|      Bottom     |                 1 or 2               |    Black plexi    | [case bottom.FCStd](docs/case/case%20bottom.FCStd)                   |
|      Middle     |  7 or 8   (5 or 6 if optional layer) |    Black plexi    | [case middle.FCStd](docs/case/case%20middle.FCStd)                   |
| Middle optional |                2 or 3                |    Black plexi    | [case middle optional.FCStd](docs/case/case%20middle%20optional.FCStd) |
|       Top       |                1 or 2                | Transparent plexi | [case top.FCStd](docs/case/case%20top.FCStd)                         |

To join the pices you'll need 1.6M screws and nuts with a length of 10 or 12 mm. 
All the CAD files has been created using FreeCAD and can be found at 
(docs/case)[docs/case] folder. Normally you will have to convert it to some other 
format (DXF, PDF, SVG) to send it to production. The final result should look similar to:

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


