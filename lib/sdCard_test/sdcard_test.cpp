#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include "config.h"
#include "sdcard_test.h"

void sdInit() {
  Serial.println("Initializing SD...");

  if (!SD.begin(SD_CS)) {
    Serial.println("SD FAIL");
    return;
  }

  Serial.println("SD OK");
}

void sdWriteTest() {
  File file = SD.open("/test.txt", FILE_WRITE);

  if (!file) {
    Serial.println("Failed to open file for writing");
    return;
  }

  file.println("ESP32 SD test OK");
  file.close();

  Serial.println("File written");
}

void sdReadTest() {
  File file = SD.open("/test.txt");

  if (!file) {
    Serial.println("Failed to open file");
    return;
  }

  Serial.println("Reading file:");

  while (file.available()) {
    Serial.write(file.read());
  }

  file.close();
}