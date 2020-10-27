#include <DNSServer.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"
#include <SPIFFS.h>

DNSServer dnsServer;
AsyncWebServer server(80);

class CaptiveRequestHandler : public AsyncWebHandler {
  public:
    CaptiveRequestHandler() {}
    virtual ~CaptiveRequestHandler() {}

    bool canHandle(AsyncWebServerRequest *request) {
      //request->addInterestingHeader("ANY");
      return true;
    }

    void handleRequest(AsyncWebServerRequest *request) {
      AsyncResponseStream *response = request->beginResponseStream("text/html");
      response->print("<!DOCTYPE html><html><head><title>Captive Portal</title></head><body>");
      response->print("<p>This is out captive portal front page.</p>");
      response->print("<img src=""frog"">");
      response->print("</body></html>");
      request->send(response);
    }
};

void setup() {
  //your other setup stuff...
  WiFi.softAP("esp-captive5");
  dnsServer.start(53, "*", WiFi.softAPIP());
  server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);//only when requested from AP
  //more handlers...

  server.on("frog", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/frog.jpg", "image/jpg");
  });

  server.begin();
}

void loop() {
  dnsServer.processNextRequest();
}
