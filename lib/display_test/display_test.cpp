#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include "display_test.h"
#include "config.h"


static Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);

void drawCenteredText(const char* text, uint16_t color) {
  tft.setTextColor(color);
  tft.setTextSize(3);

  int16_t x1, y1;
  uint16_t w, h;

  tft.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);

  int x = (tft.width() - w) / 2;
  int y = (tft.height() - h) / 2;

  tft.setCursor(x, y);
  tft.println(text);
}

void initDisplay() {
  tft.begin();
  tft.setRotation(1);
}

void runDisplayTest() {
  static int state = 0;

  if (state == 0) {
    tft.fillScreen(ILI9341_RED);
    drawCenteredText("RED", ILI9341_WHITE);
  }
  else if (state == 1) {
    tft.fillScreen(ILI9341_GREEN);
    drawCenteredText("GREEN", ILI9341_WHITE);
  }
  else if (state == 2) {
    tft.fillScreen(ILI9341_BLUE);
    drawCenteredText("BLUE", ILI9341_WHITE);
  }
  else if (state == 3) {
    tft.fillScreen(ILI9341_WHITE);
    drawCenteredText("WHITE", ILI9341_BLACK);
  }

  state = (state + 1) % 4;

  delay(1000);
}