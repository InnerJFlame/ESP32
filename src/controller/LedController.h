#pragma once
#include "../devices/Button.h"
#include "../devices/Led.h"

class LedController {
    Button& _button;
    Led& _led;
    public:
        LedController(Button& button, Led& led) : _button(button), _led(led) {}
        void update() {
            if (_button.isPressed()) {
                _led.toggle();
                delay(500);
            }
        }
};