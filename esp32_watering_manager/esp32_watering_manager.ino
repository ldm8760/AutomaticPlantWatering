#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "config.h"

const char * ssid = WIFI_SSID;
const char * password = WIFI_PASS;

const int soilSensorPin = 34;
const int waterPumpPin = 25;
const int dry = 3400; // value for dry sensor
const int wet = 1000; // value for wet sensor
// wet and dry need to be recalibrated

WebServer server(80);

void handleMeasure() {
    int moisture = readSoilSensor();
    char str[4];

    snprintf(str, sizeof(str), "%d", moisture);
    server.send(200, "text/plain", str);
}

void handleWater() {
    testPump();
    server.send(200, "text/plain", "Pumping water succesfully");
}

void setup()
{
    Serial.begin(115200);
    pinMode(waterPumpPin, OUTPUT);

    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    if (MDNS.begin("plantHandler")) {
        Serial.println("Access via: http://plantHandler.local");
    }

    server.on("/", handleRoot);
    server.on("/measure", handleMeasure);
    server.on("/water", handleWater);

    server.begin();
    Serial.println("HTTP server started");
}

void loop()
{
    server.handleClient();
}

// Capacitive Moisture Soil Sensor functionality
int readSoilSensor()
{
    int sensorValue = analogRead(soilSensorPin);
    int moisturePercentage = map(sensorValue, wet, dry, 100, 0);
    return moisturePercentage;
}
// Water Pump functionality
void testPump()
{
    digitalWrite(waterPumpPin, true);
    delay(1000);
    digitalWrite(waterPumpPin, false);
}

