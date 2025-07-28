#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int ledPin = 6;
const int buttonPin = 2;
unsigned long startTime, reactionTime, bestTime;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();

  bestTime = EEPROM.read(0) * 256 + EEPROM.read(1);
  if (bestTime == 0xFFFF) bestTime = 9999;
  welcomeMessage();
}

void welcomeMessage() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Reaction Game!");
  lcd.setCursor(0, 1);
  lcd.print("Press to Start");
  while (digitalRead(buttonPin) == HIGH);
  delay(200);
  playGame();
}

void playGame() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wait for LED...");
  delay(random(1000, 5000));
  digitalWrite(ledPin, HIGH);
  startTime = millis();
  while (digitalRead(buttonPin) == HIGH);
  reactionTime = millis() - startTime;
  digitalWrite(ledPin, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(reactionTime);
  lcd.print(" ms");

  if (reactionTime < bestTime) {
    bestTime = reactionTime;
    EEPROM.write(0, bestTime / 256);
    EEPROM.write(1, bestTime % 256);
    lcd.setCursor(0, 1);
    lcd.print("New Best Time!");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Best: ");
    lcd.print(bestTime);
    lcd.print(" ms");
  }

  delay(4000);
  welcomeMessage();
}

void loop() {
  // controlled via functions
}
