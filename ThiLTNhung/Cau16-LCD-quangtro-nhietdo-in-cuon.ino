#include <LiquidCrystal.h>

// RS = 12, E = 11, D4 = 4, D5 = 5, D6 = 6, D7 = 7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

const int LDR_PIN = A0;
int analogValue = 0;
int nhietDo = 0;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  analogValue = analogRead(LDR_PIN);
  nhietDo = map(analogValue, 0, 1023, 0, 100);

  // Nh?p nháy 3 l?n
  for (int i = 0; i < 3; i++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CHAO NGAY MOI");
    lcd.setCursor(0, 1);
    lcd.print("Nhiet do: ");
    lcd.print(nhietDo);
    lcd.print(" C");
    delay(500);
    lcd.clear();
    delay(500);
  }

  // Hi?n th? l?i và di chuy?n t? trái qua ph?i
  lcd.setCursor(0, 0);
  lcd.print("CHAO NGAY MOI");
  lcd.setCursor(0, 1);
  lcd.print("Nhiet do: ");
  lcd.print(nhietDo);
  lcd.print(" C");

  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayRight();
    delay(300);
  }

  delay(1000);
}