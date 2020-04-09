#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

TinyGPSPlus gps;  // The TinyGPS++ object

SoftwareSerial ss(4, 5); // The serial connection to the GPS device

const char* ssid = "Qwerty";
const char* password = "qwerty123";

float latitude , longitude;
String lat_str , lng_str;
int pm;

WiFiServer server(80);
void setup()
{
  Serial.begin(115200);
  ss.begin(9600);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());

}
void loop()
{}
  // Check if a client has connected
  WiFiClient client = server.available();

  // Prepare the response
  String s ;
  
    s += "<html><body><p align=center><a style=""color:RED;font-size:125%;"" href=""http://maps.google.com/maps?&z=15&mrt=yp&t=k&q=";
    s += "12.969950";
    s += "+";
    s += "79.155712";
    s += """ target=""_top"">Click here!</a> To check the location in Google maps.</p>";
    s += "</body> </html> \n";

  client.print(s);
  delay(100);

}
