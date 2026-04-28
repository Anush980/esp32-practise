
#include <Arduino.h>
#include "led.h"
#include "config.h"

void ledInit() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(SECOND_LED_PIN, OUTPUT);
}

void ledBlink(int delayMs) {
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(SECOND_LED_PIN, LOW);
  delay(delayMs);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(SECOND_LED_PIN, HIGH);
  delay(delayMs);
}