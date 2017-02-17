/*
  mcp3221_brzo.h - ESP8266 I2C library for the MCP3221 A/D Converter.  
  This library uses the BRZO_I2C library for the ESP8266.
  
  Created Jan 2017
  By Martin Stahl	https://github.com/xboxpro1/mcp3221_brzo
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.
  You should have received a copy of the GNU General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  
  MCP3221 Address
  A0	0x48
  A1	0x49
  A2	0x4A
  A3	0x4B
  A4	0x4C
  A5	0x4D
  A6	0x4E
  A7	0x4F
  
  MCP3221 SCL frequency 100kHz Standard Mode, 400kHz Fast Mode
*/

#ifndef mcp3221_brzo_h
#define mcp3221_brzo_h

#include <stdint.h>
#include "brzo_i2c.h"

class MCP3221_BRZO {
	
public:
  MCP3221_BRZO(uint8_t mcp_Addr, uint16_t vin_Ref);
  
  uint8_t readADC(uint16_t &adc);
  uint8_t calcMV(uint16_t &mv);	
  uint8_t calcAVG(uint16_t &av);
	
private:
  uint8_t _mcpAddr;
  uint16_t _vinRef;          //Vin of the MCP3221 in Millivolts
};

#endif
