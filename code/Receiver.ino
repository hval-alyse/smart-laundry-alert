#include <SoftwareSerial.h>

const int ledPin = 13;
SoftwareSerial XBee(2,3);
char serialInput = '1';     // Default to '1' (LED on)
unsigned long previousMillis = 0;
const long blinkInterval = 500;
bool ledBlinkState = false;

void setup() {
  // put your setup code here, to run once:
  pinMode (ledPin, OUTPUT);
  Serial.begin(9600);
  XBee.begin(9600);
}

void loop() {
  // Read serial input from XBee if available
  if (XBee.available() > 0) {
    char received = XBee.read();
    if (received == '0' || received == '1') {
      serialInput = received;
      Serial.print("Input changed to: ");
      Serial.println(serialInput);
    }
  }

  // Act on input
  if (serialInput == '1') {
    digitalWrite(ledPin, HIGH);  // LED stays on
  } else if (serialInput == '0') {
    // Non-blocking blink
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= blinkInterval) {
      previousMillis = currentMillis;
      ledBlinkState = !ledBlinkState;
      digitalWrite(ledPin, ledBlinkState ? HIGH : LOW);
    }
  }
}
