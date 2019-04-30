#include <SPI.h>

void setup() {
  delay(5000);
  Serial.begin(115200);
  Serial.println(MOSI);
  Serial.println(MISO);
  Serial.println(SCK);
  Serial.println(SS);
}

void loop() {
  // put your main code here, to run repeatedly:

}
