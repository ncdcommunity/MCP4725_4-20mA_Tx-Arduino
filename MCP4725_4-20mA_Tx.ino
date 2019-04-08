#include <Wire.h>
byte address = 0x60;
void setup()
{
  Serial.begin (9600);
  Wire.begin();

 
}

int set_volt ( int raw_value)
{
  Wire.beginTransmission(address );
  Wire.write(64); 
  Wire.write(raw_value >> 4);        // 8 MSB
  Wire.write((raw_value & 15) << 4); //4 LSB
  Wire.endTransmission();
  Serial.print (raw_value, DEC);
  Serial.print("\n");
}
void loop()
{
/// at DAC vlaue 290 the current output will be around 4mA and 
///at DAC vlaue 1500 the current output will be around 20mA 
/// you can change these values to tune the 4-20mA output
 //for (int i=0; i <= 4096; i++)  ///////to use this code with 0-10V Hardware
  for (int i=290; i <= 1500; i++) ///////to use this code with 4-20mA Hardware
  {
  Wire.beginTransmission(address );
  Wire.write(64); 
 // Wire.write(64); 
  Wire.write(i >> 4);        // 8 MSB
  Wire.write((i & 15) << 4); //4 LSB
  delay(1000);
  Serial.print (i, DEC);
  Serial.print("\n");
  Wire.endTransmission();
  i = i + 100;
  }
//set_volt(4095);
}
