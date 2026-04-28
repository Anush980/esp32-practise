### GPIO pins and D labeled pins are the same

## ESP32 Pin & Wiring Guide

### GPIO vs D Pins

| Label | GPIO |
|------|------|
| D2   | GPIO 2 |
| D5   | GPIO 5 |

In this project:
- LED 1 → GPIO 2 (D2)
- LED 2 → GPIO 5 (D5)

---

### LED Polarity

- Long leg = Anode (+) → connects to GPIO (through resistor)
- Short leg = Cathode (-) → connects to GND

---

### Wiring

- GPIO 5 (D5) ── 220Ω resistor ── LED 1 (+)
- GPIO 2 (D2) ── 220Ω resistor ── LED 2 (+)

- LED (-) cathode → GND

---

### Key Points

- Always use a 220Ω resistor with LEDs
- GPIO HIGH (3.3V) turns LED ON
- GPIO LOW turns LED OFF