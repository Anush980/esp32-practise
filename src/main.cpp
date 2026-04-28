#include <Arduino.h>
#include "config.h"
#include "display_test.h"
// #include "led.h"

void setup() {
// ledInit();
initDisplay();
}

void loop() {
// ledBlink(500);
runDisplayTest();
}
