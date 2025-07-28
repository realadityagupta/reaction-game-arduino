# Reaction Game using Arduino

This is a simple reaction time game using an Arduino Uno, LCD display, LED, and a push button. The game measures how quickly a player reacts to an LED turning on.

## Features
- Random delay (1–5 seconds) before LED turns on
- Displays reaction time on 16x2 I2C LCD
- Saves best score using EEPROM

## Components Used
- Arduino Uno
- 16x2 I2C LCD
- Push Button
- Green LED
- 220Ω Resistor
- Breadboard
- Jumper Wires

## Circuit Diagram
(Insert image in `images/circuit_diagram.png` if available)

## How to Use
1. Upload the `reaction_game.ino` to your Arduino Uno.
2. Open the Serial Monitor to see reaction feedback (optional).
3. Press the button as soon as the LED lights up.
4. Reaction time and best score are shown on the LCD.

## Simulation
Wokwi: [Click to simulate](https://wokwi.com/projects/436091803219969025)

---

## Author
Aditya Gupta
