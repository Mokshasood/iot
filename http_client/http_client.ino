#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>

#define wifiSSID "WIFI_SSID"
#define wifiPSWD "PASSWORD"

HTTPClient http;

void setup() {
  Serial.begin(9600);
  WiFi.begin(wifiSSID, wifiPSWD); 
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  http.begin("http://worldclockapi.com/api/json/utc/now");
  int httpCode = http.GET();
  if(httpCode == HTTP_CODE_OK) {
    Serial.println(http.getString());
  }
}

void loop() {
}
