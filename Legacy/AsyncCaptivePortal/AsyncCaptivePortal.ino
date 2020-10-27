#include <WiFi.h>
#include <DNSServer.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 1, 1);
DNSServer dnsServer;

AsyncWebServer server(80);

void setup() {
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP("CaptivePortal 5");

  dnsServer.start(DNS_PORT, "*", apIP);

  if(!SPIFFS.begin()){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
  }

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false);
  });
  server.on("/sun", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/sun.png", "image/png");
  });
  server.on("/sun-cloud", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/sun-cloud.png", "image/png");
  });
  server.on("/cloud", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/cloud.png", "image/png");
  });
  server.on("/rain", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/rain.png", "image/png");
  });
  server.on("/storm", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/storm.png", "image/png");
  });
  server.on("/snow", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/snow.png", "image/png");
  });
  server.begin();
}

void loop() {
  dnsServer.processNextRequest();
}
