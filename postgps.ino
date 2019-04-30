#include <SPI.h>
#include <WiFi.h>
#include <SparkFun_I2C_GPS_Arduino_Library.h>
#include <TinyGPS++.h> //https://github.com/mikalhart/TinyGPSPlus

String Lat;
String Lng;

const char* ssid = "Michealle's iPhone";
const char* pass = "misia123";
byte server[] = {172, 20, 10, 12}; // server ip

WiFiClient client;
I2CGPS myI2CGPS; //original gps
TinyGPSPlus gps; //parsed gps object

void setup()
{
 Serial.begin(115200);
 Serial.print("Connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, pass);
 Serial.println(WiFi.macAddress());

 while (WiFi.status() != WL_CONNECTED) {
  delay(800);
  Serial.print(".");
 }

 Serial.println("WiFi connected");
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
 Serial.println("This beetle says hello after connection.");
 
 if (myI2CGPS.begin() == false) {
  Serial.println("Module failed to respond. Please check wiring.");
  while (1); //Freeze!
 }
 Serial.println("GPS module found!");
}



void loop()
{
 while (myI2CGPS.available()) //available() returns the number of new bytes available from the GPS module
  {
    gps.encode(myI2CGPS.read()); //Feed the GPS parser
  }
 if (gps.time.isUpdated()) //Check to see if new GPS info is available
  {
    displayInfo();
  }

 if(client.connected()) {
  client.stop();
 }
}

void displayInfo() 
{
 if (client.connect(server, 80)) { //apache
  Serial.println("send");
  if (gps.location.isValid()) {
   client.print(F("GET /add4.php?Lat="));
   client.print(gps.location.lat(), 6);
   client.print(F("&Lng="));
   client.print(gps.location.lng(), 6);
   client.println(F(" HTTP/1.0"));
   client.println();
  } else {
   Serial.println(F("Location not yet valid"));
  }
 } else {
  Serial.println("connection failed");
 }  
}
