#include <SPI.h>
#include <WiFi.h>
String readString1;

const char* ssid = "";
const char* pass = "";
byte server[] = {172, 217, 9, 132}; // server ip
//tracert www.google.com

WiFiClient client;

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

 if (client.connect(server, 80)) { //google
   Serial.println("connected");
   client.println("GET /search?q=arduino HTTP/1.0");
   client.println();
 } else {
   Serial.println("connection failed");
 }
}

void loop()
{
 if (client.available()) {
   char c = client.read();
   Serial.print(c);
   //readString += c;
 }
       
 if (!client.connected()) {
    client.stop();
   
   //Serial.print(readString);
   Serial.println();
   Serial.println();

   Serial.println("done");
   for(;;);
   
   }
}
