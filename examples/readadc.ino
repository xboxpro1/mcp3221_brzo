/*
readadc.ino
Example for Microchip MCP3221 A/D Converter using the MCP3221 BRZO library
The sketch reads the MCP3221 via BRZO I2C and outputs the data to the serial port
Created Jan 2017
By Martin S		https://github.com/xboxpro1/mcp3221_brzo
*/

#include <Arduino.h>	// need for PlatformIO
#include "mcp3221_brzo.h"

#define I2CSDA      4                           //brzo SDA Pin
#define I2CSCL      5                           //brzo SCL Pin
#define SCLSTRECH   200                        //brzo SCL Stretch timeout

MCP3221_BRZO adc(0x4C, 3300);             // set the MCP3221 address to 0x4C (default 0x4D) see datasheet and set vref in millivolt
                 
uint16_t adcdata;                         // define variable to hold the adc data in millivolt
uint8_t errorcode;
bool  initok = false;

void setup(){
   brzo_i2c_setup(I2CSDA, I2CSCL, SCLSTRECH);   // initialize the brzo_i2c library
   Serial.begin(115200);                        // initialize the serial port
   delay(1000);
   Serial.print ("Get MCP3221 ADC raw data.... ");	
   errorcode = adc.readADC(adcdata);              // read ADC raw data
   if(errorcode == 0){
     Serial.println (adcdata);
     Serial.println ("OK");
     initok = true;
   }
  else {
     Serial.println ("ERROR!!!");
     Serial.print ("Error Code: ");
     Serial.println (errorcode);
     Serial.println ("Please reset device!");
  }
 }


void loop(){
    if(initok){
      errorcode = adc.calcMV(adcdata);             // calculate millivolt base vref
      if(errorcode == 0){
        Serial.print ("ADC: ");
        Serial.print (adcdata);
        Serial.println (" mV");
      }
       else{
         Serial.println ("ERROR!!!");
         Serial.print ("Error Code: ");
         Serial.println (errorcode);
       }
       
      delay(2000);					// Wait 2 seconds
    }
}
