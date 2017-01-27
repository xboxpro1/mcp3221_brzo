# MCP3221 BRZO

ESP8266 library for the I2C controlled MCP3221 A/D Converter.

This library uses the BRZO I2C library for the ESP8266.
[https://github.com/pasko-zh/brzo_i2c](https://github.com/pasko-zh/brzo_i2c)

###MCP3221 Info
- Power supply range of 2.7V to 5.5V.
- Resolution is 12 Bit.
- I2C Clock Frequency 100kHz standard mode and 400kHz fast mode.


###MCP3221 Addresses
  - A0	0x48
  - A1	0x49
  - A2	0x4A
  - A3	0x4B
  - A4	0x4C
  - A5	0x4D  Default
  - A6	0x4E
  - A7	0x4F
  
###Driver API
**MCP3221_BRZO adc(address, vinRef)**
Init the temperature sensor with the given address, and sets the Vin Ref to calculate the Analog Data to Millivolt.

**readADC(int16_t)**
Read the raw data as int16_t. Returns the brzo_i2c error code.
Brzo_i2c error codes see [README](https://github.com/pasko-zh/brzo_i2c/blob/master/README.md)

**calcMV(float)**
Calculate the Analog Data to Millivolt to the base Vin Ref in float. Returns the brzo_i2c error code.


Created for Arduino IDE and PlatformIO.


This library is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.
