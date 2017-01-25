/*
  mcp3221_brzo.cpp - ESP8266 I2C library for the MCP3221 A/D Converter.  
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

#include <stdint.h>
#include "brzo_i2c.h"
#include "mcp3221_brzo.h"

MCP3221_BRZO::MCP3221_BRZO(uint8_t mcp_Addr, int vin_Ref) {
  _mcpAddr = mcp_Addr;
  _vinRef = vin_Ref;
}

