#pragma once
#include <Arduino.h>

class Led {
    uint8_t pin;
public:
    Led(uint8_t p) : pin(p) {
        pinMode(pin, OUTPUT);
    }
    void on()  {
        digitalWrite(pin, HIGH);
    }
    void off() {
        digitalWrite(pin, LOW);
    }
    void toggle() {
        digitalWrite(pin, !digitalRead(pin));
    }
};