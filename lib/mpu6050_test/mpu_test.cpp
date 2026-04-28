#include <Arduino.h>
#include <Wire.h>
#include "config.h"
#include "mpu_test.h"

// offsets
float ox=0, oy=0, oz=0;
float gx_off=0, gy_off=0, gz_off=0;

// low-level write
static void mpuWrite(byte reg, byte val) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}

// low-level read 16-bit
static int16_t mpuRead16(byte reg) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 2);

  return (Wire.read() << 8) | Wire.read();
}

void mpuInit() {
  Wire.begin(PIN_SDA, PIN_SCL);
  Wire.setClock(100000);

  Serial.println("Booting MPU...");

  mpuWrite(0x6B, 0x00); // wake up
  delay(100);

  mpuWrite(0x1B, 0x08); // gyro ±500
  mpuWrite(0x1C, 0x00); // accel ±2g
  mpuWrite(0x1A, 0x03); // filter

  Serial.println("MPU ready");
}

void mpuCalibrate() {
  Serial.println("Calibrating... keep still");

  float ax=0, ay=0, az=0;
  float gx=0, gy=0, gz=0;

  for (int i = 0; i < CALIB_SAMPLES; i++) {
    ax += mpuRead16(0x3B) / 16384.0f;
    ay += mpuRead16(0x3D) / 16384.0f;
    az += mpuRead16(0x3F) / 16384.0f;

    gx += mpuRead16(0x43) / 65.5f;
    gy += mpuRead16(0x45) / 65.5f;
    gz += mpuRead16(0x47) / 65.5f;

    delay(5);
  }

  ox = ax / CALIB_SAMPLES;
  oy = ay / CALIB_SAMPLES;
  oz = az / CALIB_SAMPLES;

  gx_off = gx / CALIB_SAMPLES;
  gy_off = gy / CALIB_SAMPLES;
  gz_off = gz / CALIB_SAMPLES;

  Serial.println("Calibration done");
}

void mpuRead(float &ax, float &ay, float &az,
             float &gx, float &gy, float &gz) {

  ax = (mpuRead16(0x3B) / 16384.0f) - ox;
  ay = (mpuRead16(0x3D) / 16384.0f) - oy;
  az = (mpuRead16(0x3F) / 16384.0f) - oz;

  gx = (mpuRead16(0x43) / 65.5f) - gx_off;
  gy = (mpuRead16(0x45) / 65.5f) - gy_off;
  gz = (mpuRead16(0x47) / 65.5f) - gz_off;
}