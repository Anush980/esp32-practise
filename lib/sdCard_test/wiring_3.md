## ESP32 SD Card Module Setup (SPI Only)


## Overview

This project tests an SD card module with ESP32 using SPI communication.  
It supports:
- SD card initialization
- Writing a test file (`test.txt`)
- Reading file content via Serial Monitor

---

## Wiring (SD Card → ESP32)

| SD Pin | ESP32 Pin |
|--------|----------|
| VCC    | 3.3V |
| GND    | GND |
| CS     | GPIO 17 |
| SCK    | GPIO 18 |
| MOSI   | GPIO 23 |
| MISO   | GPIO 19 |

---

## Important Rules

- SD card MUST be powered (VCC + GND required)
- Use FAT32 formatted SD card
- SPI pins must match code (18, 23, 19)
- CS pin must be unique and set to GPIO 5
- Do not leave MISO unconnected

---

## Example Code Behavior

### What happens on boot:

1. ESP32 initializes SPI bus
2. SD card is mounted
3. `test.txt` is created (or updated)
4. Data is written to file
5. File content is read and printed

---

## Expected Serial Output
```
Initializing SD...
SD OK
File written
Reading file:
ESP32 SD test OK
```
## Run Commmand
- pio run --target upload
- pio device monitor -b 115200