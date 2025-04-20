#include <LiquidCrystal.h>

const char* TARGET = "VIETNAM";

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Hay nhap 7 ky tu:");
}

void loop() {
  // ??c xâu
  while (!Serial.available()) {}
  String input = Serial.readStringUntil('\n');
  input.trim();

  lcd.clear();
  if (input == TARGET) {
    lcd.setCursor(0, 0);
    lcd.print("DA NHAP DUNG:");
    lcd.setCursor(0, 1);
    lcd.print(TARGET);
    while (true) {}
  } else {
    lcd.setCursor(0, 0);
    lcd.print(input.substring(0, 16));
    lcd.setCursor(0, 1);
    lcd.print("HAY NHAP LAI");
    delay(1500);
    lcd.clear();
    lcd.print("Hay nhap 7 ky tu:");
  }
}