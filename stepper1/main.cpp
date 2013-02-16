/*
  Code to control a unipolar stepper motor using an Arduino.
  For connecting the motor, see:
      http://www.tigoe.net/pcomp/code/circuits/motors/stepper-motors/

  Later I want to implement the two-wire version from that site.
*/

#include "Arduino.h"

// This is the time in milliseconds between steps
// Roughly controls the speed
static const unsigned long interval = 30;

// Setup function to clear all of the pins that will be used
void setup() {
    for (auto i=2; i<=5; ++i) {
        pinMode(i, OUTPUT);
    }
}

// Writes the 4 pin values of a step to the digital output pins
void sendStep(const uint8_t vals[4]) {
    digitalWrite(2, vals[0]);
    digitalWrite(3, vals[1]);
    digitalWrite(4, vals[2]);
    digitalWrite(5, vals[3]);
}


void loop() {
    // Keep track of the current step
    static unsigned long curStep = 0;

    // Used for a simple delay loop
    static unsigned long previousMillis = 0;
    unsigned long currentMillis = millis();

    // The steps array contains the pin outputs for each step
    
    // // Full step 
    // static const uint8_t steps[][4] = {{HIGH, LOW, HIGH, LOW},
    //                                    {HIGH, LOW, LOW, HIGH},
    //                                    {LOW, HIGH, LOW, HIGH},
    //                                    {LOW, HIGH, HIGH, LOW},
    // };

    // Half step
    static const uint8_t steps[][4] = {{HIGH, LOW, HIGH, LOW},
                                       {HIGH, LOW, LOW, LOW},
                                       {HIGH, LOW, LOW, HIGH},
                                       {LOW, LOW, LOW, HIGH},
                                       {LOW, HIGH, LOW, HIGH},
                                       {LOW, HIGH, LOW, LOW},
                                       {LOW, HIGH, HIGH, LOW},
                                       {LOW, LOW, HIGH, LOW},
    };

    // Check if enough time has passed
    if (currentMillis - previousMillis > interval) {
        previousMillis = currentMillis;

        // Send the step
        sendStep(steps[curStep]);

        // Move to the next step
        curStep = (curStep+1)%(sizeof(steps)/sizeof(uint8_t[4]));
    }
}
