#include <WiFi.h>
#define BATTERY_PIN 32
#define SOLAR_PIN 35

//
int voltage_battery = 0;
int voltage_solar = 0;

// Replace with your SSID and Password
const char* ssid     = "SSID";
const char* password = "PASSWORD";

// Replace with your unique IFTTT URL resource
const char* resource = "/trigger/bme280_readings/with/key/nAZjOphL3d-ZO4N3k64-1A7gTlNSrxMJdmqy3";

// How your resource variable should look like, but with your own API KEY (that API KEY below is just an example):
//const char* resource = "/trigger/bme280_readings/with/key/nAZjOphL3d-ZO4N3k64-1A7gTlNSrxMJdmqy3";

// Maker Webhooks IFTTT
const char* server = "maker.ifttt.com";

void setup() {
  pinMode(BATTERY_PIN, INPUT);
  pinMode(SOLAR_PIN, INPUT);
  delay(500);

  Serial.begin(115200);
  Serial.println("START");
  delay(1000);
  Serial.println(analogRead(BATTERY_PIN));
  Serial.println(analogRead(SOLAR_PIN));
  delay(1000);
  initWifi();
}

void loop() {
  makeIFTTTRequest();
  delay(60000);
}

void initWifi() {
  Serial.print("Connecting to: ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);

  int timeout = 10 * 4; // 10 seconds
  while (WiFi.status() != WL_CONNECTED  && (timeout-- > 0)) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect");
  }

  Serial.print("WiFi connected in: ");
  Serial.print(millis());
  Serial.print(", IP address: ");
  Serial.println(WiFi.localIP());
}

void makeIFTTTRequest() {
  Serial.println(":::STARTING CONNECTION:::");

  //Read voltage
  voltage_battery = analogRead(BATTERY_PIN);
  voltage_solar = analogRead(SOLAR_PIN);
  delay(100);
  Serial.print("Battery voltage: ");
  Serial.println(voltage_battery);
  Serial.println("");
  Serial.print("Solar voltage: ");
  Serial.println(voltage_solar);
  Serial.println("");
  delay(100);

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
  } else {
    Serial.println("Not connected to WiFi");
    delay(500);
    initWifi();
    delay(2000);
  }

  Serial.print("Connecting to ");
  Serial.print(server);

  WiFiClient client;
  int retries = 5;
  while (!!!client.connect(server, 80) && (retries-- > 0)) {
    Serial.print(".");
  }
  Serial.println();
  if (!!!client.connected()) {
    Serial.println("Failed to connect...");
  }

  Serial.print("Request resource: ");
  Serial.println(resource);

  //  Battery status
  String jsonObject = String("{\"value1\":\"") + voltage_battery + "\",\"value2\":\"" + voltage_solar + "\"}";

  client.println(String("POST ") + resource + " HTTP/1.1");
  client.println(String("Host: ") + server);
  client.println("Connection: close\r\nContent-Type: application/json");
  client.print("Content-Length: ");
  client.println(jsonObject.length());
  client.println();
  client.println(jsonObject);

  int timeout = 5 * 10; // 5 seconds
  while (!!!client.available() && (timeout-- > 0)) {
    delay(100);
  }
  if (!!!client.available()) {
    Serial.println("No response...");
  }
  while (client.available()) {
    Serial.write(client.read());
  }
  Serial.println("");
  Serial.println(":::CLOSING CONNECTION:::");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  client.stop();
}
