#include <SPI.h>
#include <WiFi.h>
String readString1;

const char* ssid = "";
const char* pass = "";
byte server[] = {192, 168, 1, 21}; // server ip

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

 if (client.connect(server, 80)) { //apache
   Serial.println("connected");
   client.println("GET /add3.php?name1=Gabe&num1=19 HTTP/1.0");
   client.println();
 } else {
   Serial.println("connection failed");
 }

 if(client.connected()) {
  client.stop();
 }
}



void loop()
{
}
