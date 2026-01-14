#pragma once
#include "../devices/Button.h"
#include "../devices/Led.h"
#include "../devices/OledDisplay.h"  // наш клас OledDisplay

class DeviceController {
    Button& _button;
    Led& _led;
    OledDisplay& _display;

    int _progress = 0;
    unsigned long _lastPressTime = 0;
    const unsigned long _debounce = 200; // антидребезг кнопки

public:
    DeviceController(Button& button, Led& led, OledDisplay& display)
        : _button(button), _led(led), _display(display) {}

    void update() {
        pressButton();
        drawDisplay();
    }

private:
    void pressButton() {
        // антидребезг
        if (_button.isPressed() && millis() - _lastPressTime > _debounce) {
            _led.toggle();       // включаємо/вимикаємо LED
            _progress += 10;     // прогрес росте на 10%
            if (_progress > 100) _progress = 0;
            _lastPressTime = millis();
        }
    }

    void drawDisplay() {
        _display.clear();
        _display.drawText(0, 0, "Device Controller", 1);
        _display.drawProgressBar(0, 50, 100, 10, _progress);
        _display.update();
    }
};
