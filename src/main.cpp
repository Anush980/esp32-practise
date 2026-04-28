#include <Arduino.h>
#include "config.h"
// #include "display_test.h"
// #include "led.h"
#include "sdcard_test.h"

void setup() {
  Serial.begin(115200);
// ledInit();
// initDisplay();

digitalWrite(TFT_CS, HIGH);
  digitalWrite(SD_CS, LOW);

  sdInit();
  sdWriteTest();
  sdReadTest();


  digitalWrite(SD_CS, HIGH);
  digitalWrite(TFT_CS, LOW);
}

void loop() {
// ledBlink(500);
// runDisplayTest();
}
