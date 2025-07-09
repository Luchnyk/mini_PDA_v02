# Mini PVA v02 Project

This project demonstrates the interaction of the **NodeMCU v3 (ESP8266)** microcontroller with:

* A **rotary encoder** (with push button)
* A **0.96" OLED display** using the **I²C** interface

The firmware is written for the **Arduino IDE** and is ideal for IoT applications, menu navigation, or control interfaces.

---

## Components

| Component       | Model / Specification   |
| --------------- | ----------------------- |
| Microcontroller | NodeMCU v3 (ESP8266)    |
| Display         | OLED 0.96", 128x64, I²C |
| Rotary Encoder  | KY-040 or without board |
| IDE             | Arduino IDE             |

---

## Wiring Diagram

### OLED Display (I²C)

| OLED Pin | NodeMCU Pin |
| -------- | ----------- |
| VCC      | 3V3         |
| GND      | GND         |
| SCL      | D1 (GPIO5)  |
| SDA      | D2 (GPIO4)  |

### Rotary Encoder

| Encoder Pin | NodeMCU Pin |
| ----------- | ----------- |
| CLK         | D5 (GPIO14) |
| DT          | D6 (GPIO12) |
| SW (Button) | D7 (GPIO13) |
| +           | 3V3         |
| GND         | GND         |
> If the encoder is not soldered to the board, then there is no VCC(VDD) contact there.
> You can change pin assignments in the code if needed.

---

## Libraries (via Arduino Library Manager)

Before compiling, make sure the following libraries are installed:

* [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
* [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)

---

## Uploading Firmware

1. Open Arduino IDE.
2. Install ESP8266 board support (via Boards Manager).
3. Select board: `NodeMCU 1.0 (ESP-12E Module)`
4. Connect NodeMCU via USB.
5. Upload the firmware.

---

## Functionality

* Rotating the encoder changes values or navigates the menu.
* Pressing the button triggers an action (e.g. selection).
* Data is displayed on the OLED screen.
