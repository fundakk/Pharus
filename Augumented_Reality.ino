#include <DNSServer.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"
#include "SD.h"
#include <Wire.h>

DNSServer dnsServer;
AsyncWebServer server(80);

class CaptiveRequestHandler : public AsyncWebHandler {
  public:
    CaptiveRequestHandler() {}
    virtual ~CaptiveRequestHandler() {}

    bool canHandle(AsyncWebServerRequest *request) {
      //request->addInterestingHeader("CAPTIVE");
      return true;
    }

    void handleRequest(AsyncWebServerRequest *request) {
      Serial.println("Requested index.html");
      request->send(SD, "/index.html", String(), false);
    }

};

void setup() {
  Serial.begin(115200);

  // initialize SD card
  Serial.println("::::SD::::");
  if (!SD.begin()) {
    Serial.println("Card Mount Failed");
    delay(3000);
    Serial.println("Restarting");
    ESP.restart();
  } else {
    Serial.println("Card Mounted");
  }
  uint8_t cardType = SD.cardType();
  Serial.print("Card type: ");
  Serial.println(cardType);

  listDir(SD, "/", 2);
  Serial.println("::::/SD::::");
  Serial.println("");

  WiFi.softAP("esp-captive");
  dnsServer.start(53, "*", WiFi.softAPIP());
  Serial.println(WiFi.softAPIP());

  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("Requested style.css");
    request->send(SD, "/style.css", "text/css");
  });
  server.on("/background.jpg", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("Requested background.jpg");
    request->send(SD, "/background.jpg", "image/jpg");
  });
  server.on("/image1.jpg", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("Requested image1.jpg");
    request->send(SD, "/image1.jpg", "image/jpg");
  });
  server.on("/image2.jpg", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("Requested image2.jpg");
    request->send(SD, "/image2.jpg", "image/jpg");
  });
  server.on("/image3.jpg", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("Requested image3.jpg");
    request->send(SD, "/image3.jpg", "image/jpg");
  });
  server.on("/image4.jpg", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("Requested image4.jpg");
    request->send(SD, "/image4.jpg", "image/jpg");
  });
  server.on("/sound.mp3", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("Requested sound.mp3");
    request->send(SD, "/sound.mp3", "sound/mp3");
  });
  server.on("/movie.mp4", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.println("Requested movie.mp4");
    request->send(SD, "/movie.mp4", "movie/mp4");
  });

  server.addHandler(new CaptiveRequestHandler());

  server.begin();
}

void loop() {
  dnsServer.processNextRequest();
}

void listDir(fs::FS &fs, const char * dirname, uint8_t levels) {
  Serial.printf("Listing directory: %s\n", dirname);

  File root = fs.open(dirname);
  if (!root) {
    Serial.println("Failed to open directory");
    return;
  }
  if (!root.isDirectory()) {
    Serial.println("Not a directory");
    return;
  }

  File file = root.openNextFile();
  while (file) {
    if (file.isDirectory()) {
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if (levels) {
        listDir(fs, file.name(), levels - 1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("  SIZE: ");
      Serial.println(file.size());
    }
    file = root.openNextFile();
  }
}
