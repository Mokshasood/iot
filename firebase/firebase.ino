#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
 
// Settings
#define FIREBASE_HOST "HOST_ADDRESS"
#define FIREBASE_AUTH "SECURITY_KEY"
#define WIFI_SSID "WIFI_SSID"
#define WIFI_PASSWORD "PASSWORD"

int num = 0;

void setup()
{
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
 
void loop()
{
  if(num++ > 50) num=0;
  Firebase.setInt("Variable/Value",num);
  String s = Firebase.getString("locations/test");
  Serial.println(s);
  delay(1000);            
}
