#include "Arduino.h"

const int ledPin = 13;

int ledState = LOW;
long previousMillis = 0;
unsigned long interval = 1500;

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis > interval) {
        previousMillis = currentMillis;
        if (ledState == LOW) {
            ledState = HIGH;
        } else {
            ledState = LOW;
        }
        digitalWrite(ledPin, ledState);
    }
}
