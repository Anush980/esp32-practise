#include <Arduino.h>
#include "config.h"
// #include "display_test.h"
// #include "led.h"
// #include "sdcard_test.h"
#include "mpu_test.h"

void setup() {
  Serial.begin(115200);


// ledInit();
// initDisplay();


// digitalWrite(TFT_CS, HIGH);
//   digitalWrite(SD_CS, LOW);
//   sdInit();
//   sdWriteTest();
//   sdReadTest();
//   digitalWrite(SD_CS, HIGH);
//   digitalWrite(TFT_CS, LOW);


 delay(1000);
  mpuInit();
  delay(500);
  mpuCalibrate();

}

void loop() {
// ledBlink(500);
// runDisplayTest();

  float ax, ay, az;
  float gx, gy, gz;

  mpuRead(ax, ay, az, gx, gy, gz);

  Serial.print("AX: "); Serial.print(ax);
  Serial.print(" AY: "); Serial.print(ay);
  Serial.print(" AZ: "); Serial.print(az);

  Serial.print(" || GX: "); Serial.print(gx);
  Serial.print(" GY: "); Serial.print(gy);
  Serial.print(" GZ: "); Serial.println(gz);

  delay(LOOP_MS);
}
