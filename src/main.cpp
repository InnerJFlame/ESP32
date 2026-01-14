#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "devices/Button.h"
#include "devices/Led.h"
#include "devices/OledDisplay.h"
#include "controller/DeviceController.h"

#define BUTTON_PIN 0
#define LED_PIN 2

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Button button(BUTTON_PIN);
Led led(LED_PIN);

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
OledDisplay display(oled);

DeviceController controller(button, led, display);

void setup() {
  Serial.begin(115200);
  if (!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("SSD1306 failed");
    for(;;);
  }
  display.begin();
}

void loop() {
  controller.update();
}
