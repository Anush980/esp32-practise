#include <Arduino.h>
#include "config.h"
#include "led.h"

void setup() {
ledInit();
}

void loop() {
ledBlink(500);
}
