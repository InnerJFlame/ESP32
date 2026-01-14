#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class OledDisplay {
private:
    Adafruit_SSD1306& display;

public:
    // Конструктор приймає готовий об'єкт Adafruit_SSD1306
    OledDisplay(Adafruit_SSD1306& disp) : display(disp) {}

    void begin() {
        display.clearDisplay();
        display.display();
    }

    void clear() {
        display.clearDisplay();
    }

    void drawText(int x, int y, const String& text, int textSize = 1) {
        display.setTextSize(textSize);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(x, y);
        display.println(text);
    }

    // value від 0 до 100
    void drawProgressBar(int x, int y, int w, int h, int value) {
        display.drawRect(x, y, w, h, SSD1306_WHITE); // рамка
        int fillWidth = (value * w) / 100;
        if (fillWidth > 0) {
            display.fillRect(x + 1, y + 1, fillWidth - 2, h - 2, SSD1306_WHITE);
        }
    }

    void update() {
        display.display();
    }
};
