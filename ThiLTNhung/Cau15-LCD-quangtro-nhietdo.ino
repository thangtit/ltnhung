#include <LiquidCrystal.h>

// RS = 12, E = 11, D4 = 4, D5 = 5, D6 = 6, D7 = 7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

const int P2_PIN = A0;
int analogValue = 0;
int nhietDo = 0;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  analogValue = analogRead(P2_PIN);
  nhietDo = map(analogValue, 0, 1023, 0, 100);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gia tri ADC: ");
  lcd.print(analogValue);

  lcd.setCursor(0, 1);
  lcd.print("Nhiet do: ");
  lcd.print(nhietDo);
  lcd.print(" C");

  delay(1000);
}