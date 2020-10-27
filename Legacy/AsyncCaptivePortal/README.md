### Asynchronous Web Server with captive portal and data stored in SPIFFS

This code acts as asynchronous webserver, with http redirection (Captive Portal).

HTML page and images are stored in ESP32 flash memory as SPIFFS files.

#### Code

Required libraries

    #include <WiFi.h>
    #include <DNSServer.h>
    #include <ESPAsyncWebServer.h>
    #include <SPIFFS.h>

Setting up DNS server

    const byte DNS_PORT = 53;
    IPAddress apIP(192, 168, 1, 1);
    DNSServer dnsServer;

Starting asynchronous web server on port 80

    AsyncWebServer server(80);

Starting Wifi as access point, with IP and name

    void setup() {
      WiFi.mode(WIFI_AP);
      WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
      WiFi.softAP("CaptivePortal 5");

Starting dns server. "*" will redirect all http trafic to local server

      dnsServer.start(DNS_PORT, "*", apIP);

Starting SPIFFS

      if(!SPIFFS.begin()){
            Serial.println("An Error has occurred while mounting SPIFFS");
            return;
      }

Redirecting all requests of asynchronous server to SPIFFS memory.

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

Handling clients

    void loop() {
      dnsServer.processNextRequest();
    }
