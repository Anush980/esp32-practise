## ESP32 + MPU6050 Wiring Guide (Working Setup)

---

## Overview

This setup uses ESP32 with MPU6050 (IMU sensor) using **I2C communication** for motion tracking (accelerometer + gyroscope).

This version uses **low-level register communication**, which is more reliable than some high-level libraries for clone modules.

---

## Wiring (MPU6050 → ESP32)

| MPU6050 Pin | ESP32 Pin |
|------------|----------|
| VCC        | 3.3V |
| GND        | GND |
| SDA        | GPIO 21 |
| SCL        | GPIO 22 |
| INT        | Not used (optional) |

---

## I2C Notes

- MPU6050 communicates using I2C protocol
- Only 2 data lines are needed:
  - SDA (data)
  - SCL (clock)
- Multiple I2C devices can share the same SDA/SCL pins

---

## Why Earlier Code Showed "0.00"

### 1. Library vs Register Access Issue

There are two ways to use MPU6050:

#### High-level library (Adafruit MPU6050)
- Easy to use
- Can fail silently on some modules
- Sometimes returns all zeros if initialization is incomplete

#### Low-level register method (THIS PROJECT)
- Direct communication with sensor registers
- More reliable for cheap or clone modules
- Used in production embedded systems

---

### 2. Fake / Clone MPU6050 Modules

Many low-cost MPU6050 modules are not fully original.

Common behavior of clones:
- Respond to I2C scan (0x68 shows correctly)
- But return incorrect or zero data if not properly initialized
- Require correct wake-up command:
  - `0x6B = 0x00` (very important)

---

### 3. Missing Wake-up Command (Critical)

MPU6050 starts in sleep mode by default.

If not properly initialized:

- Sensor stays inactive
- All readings become 0.00

Correct step used in this project:
- Write `0x00` to register `0x6B`

---

## Why This Setup Works

This implementation fixes previous issues by:

- Direct register control (no hidden library behavior)
- Explicit sensor wake-up
- Manual calibration handling
- Stable I2C configuration (100kHz)

---

## Key Learnings

- I2C scan showing `0x68` only means device is connected, NOT fully working
- Zero output usually means:
  - sensor not woken up
  - incorrect library usage
  - unstable clone module behavior
- Register-level control is more reliable for real embedded systems

---

## Final Rule

- If you want reliability → use register-level control
- If you want speed of development → use libraries (but expect issues with clones)

---

## Current Status

✔ MPU6050 detected  
✔ I2C communication working  
✔ Stable raw data access enabled  
✔ Calibration system implemented  