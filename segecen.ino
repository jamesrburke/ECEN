#include <SPI.h>

char tempString[10];

void setup()
{
  Serial.begin(115200);
  pinMode(SS, OUTPUT);  // Set the Slave Select pin as output
  digitalWrite(SS, HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV64);  // Slow down SPI clock

  clearDisplay();

  s7sSend("ECEN");
  setDecimals(0b111111);  // Turn on all decimals, colon, apos

  setBrightness(0);  // Lowest brightness
  delay(1500);
  setBrightness(255);  // High brightness
  delay(1500);

  setDecimals(0b000000);  // Turn off all decimals, colon, apos
    
  clearDisplay();  
}

void loop()
{
  s7sSend("ECEN");
  delay(1000);  //1Hz
  s7sSend("-403");
  delay(1000);
  s7sSend("--IS");
  delay(1000);
  s7sSend("HARD");
  delay(1000);
}

void s7sSend(String Send)
{
  digitalWrite(SS, LOW);
  for (int i=0; i<4; i++)
  {
    SPI.transfer(Send[i]);
  }
  digitalWrite(SS, HIGH);
}

//sends clear display command (0x76)
void clearDisplay()
{
  digitalWrite(SS, LOW);
  SPI.transfer(0x76);
  digitalWrite(SS, HIGH);
}

//brightness value is dimmest 0 to 255 brightest
void setBrightness(byte value)
{
  digitalWrite(SS, LOW);
  SPI.transfer(0x7A);  // sends brightness command (0x7A)
  SPI.transfer(value);  // brightness
  digitalWrite(SS, HIGH);
}

//decimals format [MSB] (X)(X)(Apos)(Colon)(Digit 4)(Digit 3)(Digit2)(Digit1)
void setDecimals(byte decimals)
{
  digitalWrite(SS, LOW);
  SPI.transfer(0x77); // sends decimal set command (0x77)
  SPI.transfer(decimals);
  digitalWrite(SS, HIGH);
}
