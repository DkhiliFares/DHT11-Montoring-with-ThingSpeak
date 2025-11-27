#include <WiFi.h>
#include "DHTesp.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>

#define DHT_PIN 4       // GPIO where DHT11 is connected
DHTesp dht;

// WiFi credentials
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// ThingSpeak Write API Key
const char* thingspeakApiKey = "Thingspeakwriteapikey";

void setup() {
  Serial.begin(115200);
  dht.setup(23, DHTesp::DHT22);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi!");
}

void loop() {
  float temperature = dht.getTemperature();
  float humidity = dht.getHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: "); Serial.println(temperature);
  Serial.print("Humidity: "); Serial.println(humidity);

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // ThingSpeak URL (HTTP GET)
    String url = "http://api.thingspeak.com/update?api_key=";
    url += thingspeakApiKey;
    url += "&field1=";
    url += String(temperature);
    url += "&field2=";
    url += String(humidity);

    http.begin(url);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.println("Data sent to ThingSpeak successfully!");
    } else {
      Serial.print("Error sending data. HTTP code: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }

  delay(20000); // ThingSpeak minimum interval: 15s
}


