#include "DHT.h"
#include <SoftwareSerial.h>

#define DHTPIN 7
#define DHTTYPE DHT11
#define PHOTO_PIN A2  // Analogue pin for light sensor

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial XBee(2, 3);  // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  XBee.begin(9600);
}

void loop() {
  // Read sensor values
  int temp = dht.readTemperature();
  int hum = dht.readHumidity();
  int lightRaw = analogRead(PHOTO_PIN);
  int light = map(lightRaw, 60, 10, 0, 100);

  // Clamp light value
  light = constrain(light, 0, 100);

  // Debug output
  Serial.print("Temp: "); Serial.print(temp); Serial.print(" C | ");
  Serial.print("Hum: "); Serial.print(hum); Serial.print(" % | ");
  Serial.print("Light: "); Serial.print(light); Serial.println(" %");

  // Check for valid readings
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Sensor read failed!");
    return;
  }

  // Format and send data: "temp,hum,light\n"
  String data = String(temp) + "," + String(hum) + "," + String(light) + "\n";
  XBee.print(data);

  delay(2000);  // Adjust as needed
}