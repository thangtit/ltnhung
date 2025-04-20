#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
int n;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Nhap 0..9:");
}

void loop() {
  if (Serial.available()) {
    n = Serial.parseInt();          // ??c s? nguyên
    n = constrain(n, 0, 9);         // Gi?i h?n 0?9
    
    // ??m ng??c
    for (int i = n; i >= 0; i--) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Count down:");
      lcd.setCursor(0, 1);
      lcd.print(i);
      delay(500);
    }
    
    // Sau khi v? 0, yêu c?u nh?p l?i
    lcd.clear();
    lcd.print("Nhap 0..9:");
    // Xóa buffer n?u c?n
    while (Serial.available()) Serial.read();
  }
}