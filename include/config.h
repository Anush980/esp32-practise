#pragma once

// first_led config

#define LED_PIN 2
#define SECOND_LED_PIN 5
///////

//display_test config
#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  4
//default:
// scl(clock) --> gpio 18
// mosi sda(data out)  --> gpio 23
// miso(data in) --> not used, leave unconnected
////

//sdCard_test config
#define SD_CS 17


///mpu6050_test config
#define PIN_SDA 21
#define PIN_SCL 22
#define MPU_ADDR 0x68

#define CALIB_SAMPLES 200
#define LOOP_MS 200