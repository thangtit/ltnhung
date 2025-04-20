#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
const int sensorPin = A0;
const int ledPin    = 13;

void setup() {
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int raw  = analogRead(sensorPin);
  int temp = map(raw, 0, 1023, 0, 100);

  // Hi?n th? LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nhiet do:");
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("C");

  // ?i?u khi?n LED
  if (temp > 30) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}