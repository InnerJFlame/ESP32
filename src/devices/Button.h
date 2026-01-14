#pragma once
#include <Arduino.h>

class Button {
    uint8_t pin;
public:
    Button(uint8_t p) : pin(p) {
        pinMode(pin, INPUT_PULLUP);
    }
    bool isPressed() {
        return digitalRead(pin) == LOW;
    }
};
