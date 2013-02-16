#include "Arduino.h"

const int ledPin = 13;

int ledState = LOW;
long previousMillis = 0;
unsigned long interval = 333;

inline void myWrite(uint8_t pin, uint8_t val) {
    digitalWrite(pin+2, val);
}

void setup() {
    pinMode(ledPin, OUTPUT);
    for (auto i=0;i<8;++i) {
        pinMode(i, OUTPUT);
    }
}

unsigned long mcount = 0;

void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis > interval) {
        previousMillis = currentMillis;

        int prev = mcount-1;
        myWrite(prev%8, LOW);
        myWrite(mcount%8 , HIGH);
        // for (int i=0;i<8;++i) {
        //     if ((i+mcount)%2 == 1) {
        //         digitalWrite(i, LOW);
        //     } else {
        //         digitalWrite(i, HIGH);
        //     }
        // }
        ++mcount;
    }
}
