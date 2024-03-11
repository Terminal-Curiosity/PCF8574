#include <Wire.h>

#define device_address 0x20

void setup() {

  Serial.begin(9600);                     //initialise the serial terminal
  Wire.begin();                           //initialise the I2C communications
  Wire.beginTransmission(device_address); //start comms with the PCF8574
  Wire.write(0xFF);                       //initialise the chip to all-on  
  Wire.endTransmission(device_address);   //send data to the slave device from output buffer
}

void loop() {
  byte readValue = 0xFF;
  
  while(1)
  {
    Wire.requestFrom(device_address, 1);  //request 1 byte of data from the slave device at specified address 
    if (Wire.available())                 //check for data available in the I2C buffer
    { 
      readValue = Wire.read();                //if data available, read it and save in readValue variable
      Serial.println(readValue,BIN);          //print this to terminal for debugging purposes
      Wire.beginTransmission(device_address); //start comms with the PCF8574
      Wire.write((readValue << 4) + 0b1111);  //queue switch bits data (0-3) to LED bits (4-7)
      Wire.endTransmission(device_address);   //send from output buffer
    }
    delay(100);
  }
}
