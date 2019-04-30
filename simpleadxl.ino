#include <ADXL375.h>

ADXL345 adxl = ADXL345(SS);

void setup(){
  Serial.begin(115200);
  Serial.println("ADXL375");
  Serial.println();
  
  adxl.powerOn();
  adxl.setRangeSetting(16); //16g
}

void loop(){
  
  // Accelerometer Readings
  int x,y,z;   
  adxl.readAccel(&x, &y, &z);         // Read the accelerometer values and store them in variables declared above x,y,z

  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.println(z); 
  
}
