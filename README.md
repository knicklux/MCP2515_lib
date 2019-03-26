MCP2515 Library for Arduino
==============

The modifications in this repository are for the ESP32. the ESP32 hast two SPI modules: VSPI and HSPI. This modified implementation of the MCP2515 library allows selecting, which SPI module to use. The SPI module to use MUST be selected befor using this library, from then on, all SPI r/w operations will be delegated to the class providing the software interface to the selcted SPI module.

MCP2515 library v1.1
This library is compatible with any shield or CAN interface that uses the MCP2515 CAN protocol controller.
Baudrates 5k, 10k, 20k, 50k, 100k, 125k, 250k, 500k, & 1000k are confirmed to work using a Peak-System PCAN-USB dongle as a reference.

Installation
==============
Copy this into your "[...]/MySketches/libraries/" folder and restart the Arduino editor.

NOTE: If you have an older version of the library (CAN_BUS_Shield) be sure to remove
 it from the libraries folder or replace the files with those in this library to avoid conflicts.


*Happy Coding!*
