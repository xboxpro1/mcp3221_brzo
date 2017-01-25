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

uint8_t scl_speed = 100; //MCP3221 SCL frequency 100kHz - Standard Mode

MCP3221_BRZO::MCP3221_BRZO(uint8_t mcp_Addr, uint16_t vin_Ref) {
  _mcpAddr = mcp_Addr;
  _vinRef = vin_Ref;
}

uint8_t MCP3221_BRZO::readADC(uint16_t *adc){
  uint8_t _ecode;
  uint8_t _buffer[2];
  
  brzo_i2c_start_transaction(_mcpAddr, scl_speed);
  brzo_i2c_read(_buffer, 2, false);
  _ecode = brzo_i2c_end_transaction();
  
  if(_ecode == 0){
    *adc = (buffer[0] << 8) | buffer[1];
  }
  else{
    *adc = 0;
  }
  return _ecode;
}

uint8_t MCP3221_BRZO::calcMV(float *mv);{
  uint16_t _adc;
  uint8_t _ecode;
  
  _ecode = readADC(_adc);
  
  if(_ecode == 0){
    *mv = ((_adc / 4095)*_vinRef);        //MCP3221 is 12bit a full range of 4095
  }
  else{
    *mv = 0;
  }
  return _ecode;
}

