#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

ESP8266WebServer server(3000);

const String ssid = "WIFI_SSID";
const String password = "PASSWORD";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.write('.');
  }
  Serial.println("Connected");
  Serial.println(WiFi.localIP());
  server.on("/", HTTP_GET, onDefault);
  server.on("/set", HTTP_GET, setValue);
  server.onNotFound(notFound);
  server.begin();
}

void loop() {
  server.handleClient();
}

void setValue() {
  String data = server.arg("val");
  server.send(200, "text/html", data);
}

void onDefault() {
  server.send(200, "text/html", "hi");
}

void notFound() {
  server.send(404, "text/html", "<h1>404: Page Not Found</h1>");
}
