# BikePixels

NeoMatrix with Arduino for a back pack light to ride safty by night.

## Components

To build your own Bike Pixel you should have all the elements listed bellow:

* Arduino UNO (or any other Ardiuno or compatible board);
* 1 x NeoPixel 8x8 matrix;
* 3 x touch switches (6x6x8mm);
* 3 x 10 kΩ resistance;
* 1 x 470 Ω resistance;
* 1 x 1000 uf/6.3V capacitator;
* Wires and soldering stuff;
* The plexi case;
* 1 x 6 AAA battery holder (optional);
* 1 x on\off botton (optional if your battery holder have one built-in);
* 1 x Power bank 10000 mAh or more (optional).

For the power supply you can use a Powerbank connected directly to the Arduino Nano board or a battery holder, also you can try any other power sources. Then if you have all the components you can assemble it following the next schema.

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
The case is designed to be made joining three layers of plexy. The base is made of 1 mm plexy black board, then the middle should have 4 o 5 mm and the final should be 1 mm of transparent plexy. The design and draws can be found at docs/case folder. The final result should look similar to:

![BikePixel case](./docs/case/case.png "BikePixel Case")


### PCB
The PCB encapsulates the buttons and manage connections from Arduino to the neopixel matrix. It desing is shown belllow:

![BikePixel schema](./docs/electronics/sketch%20pcb.png "BikePixel PCB")

Production files are available in SVG and Gerber 


## Setup
To compile the source you'll need some extra libraries:

## Assembling
Bellow you can find step by step asseble Bike Pixel using the designed case and PCB. By now Arduino and batteries are kept apart from the main box with buttons and the neopixel matrix. The idea is to attach Bike Pixel to a back back. 

### Case
The case is designed to be plugable to the back pack by using 4 spring snaps but you can use any other method like a good double-sided adhesive tape or a hook and loop fastener.


## Additional info
Bellow you can find additional documentation and interesting stuff related with NeoPixel that I've found interesting and usefull during the construction of Bike Pixel:

* [All you always wanted to know about NeoPixel](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels) including [NeoPixel best practices](https://learn.adafruit.com/adafruit-neopixel-uberguide/best-practices)
* [Snowflake Sweater with Bluetooth Control example and tutorial](https://learn.adafruit.com/neopixel-matrix-snowflake-sweater/overview)
* [Creation of a custom PCB on Fritzing](http://fritzing.org/pcb-custom-shape/). Note that if you use Incskape you should edit the SVG file (Saved as plain SVG) manually in any text editor and change the layer names (e.g `<g id="L4123">` to `<g id="silkscreen 1">`).

## License

As the project is compond by software, hardware and documentation each of these parts are licensed under the terms of specific license.

### Software License

Copyright © 2019 by BikePixels.com and contributors:

* Krzysztof Stopa ([kstopa](https://github.com/kstopa/)).

Bike Pixels contains free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or any later version.

Bike Pixels is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with CAMS tools. If not, see http://www.gnu.org/licenses/.

### Hardware License

Copyright © 2019 by BikePixels.com and contributors:

* Krzysztof Stopa ([kstopa](https://github.com/kstopa/)).

Hardware elements is licensed under the CERN OHL v. 1.2.

You may redistribute and modify this documentation under the terms of the CERN OHL v.1.2. (http://ohwr.org/cernohl). This documentation is distributed WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF MERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A PARTICULAR PURPOSE. Please see the CERN OHL v.1.2 for applicable conditions.

### Documentation and images License

Copyright © 2019 by BikePixels.com and contributors:

* Krzysztof Stopa ([kstopa](https://github.com/kstopa/)).

Documentation and image files are distributed under the Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0) lisence. The full text of the license can be found at the [CC BY-NC-SA 4.0 page](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode).