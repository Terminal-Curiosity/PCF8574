Arduino code to test a PCF8574 as featured on the following YouTube Video:
https://www.youtube.com/watch?v=4vDW4iMZMSo 

The PCF8574 chip is connected to an arduino uno on pins 12 and 13. The two devices communicate using I2C and the standard Wire library.
The device has 4 switches connected to pins 0-3, which switch to ground and have 4.7k pullups to 5V.
There are also 4 LEDs on pins 4-7 which are connected to 5V and include a 470R series resistor. When the chip outputs a low signal to pins 4-7, the LEDs turn on (current sinking).

The code in this repository provides a simple test program which reads the values on each switch and pushes that data straight to the LEDs. 
