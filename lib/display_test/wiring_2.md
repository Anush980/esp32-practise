## ESP32 Wiring Diagram (TFT Display + Wire Input)


## Required libraries:

- Adafruit GFX Library (^1.12.5)
- Adafruit ILI9341 (^1.6.3)

## TFT Display (ILI9341 - SPI)

ESP32 → TFT Display

- 3.3V → VCC  
- GND → GND  

- GPIO 15 → CS  
- GPIO 2 → DC  
- GPIO 4 → RST  

- GPIO 18 → SCK (default SPI clock)  
- GPIO 23 → MOSI (default SPI data)  

- 3.3V → LED (Backlight)

---


## Notes

- GPIO 18 and 23 are SPI communication pins used by the display and should not be reused
- GPIO 15, 2, 4 are control pins for TFT display
- Backlight is directly connected to 3.3V (always ON)
- Avoid GPIO 6–11 (used internally for flash memory)
- Avoid GPIO 1 and 3 (used for serial communication and debugging)