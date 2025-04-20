#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
String text; 

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Nhap chuoi:");
}

void loop() {
  // 1) ??c chu?i t? Serial
  if (Serial.available()) {
    text = Serial.readStringUntil('\n');
    text.trim();
    
    // 2) Hi?n th? chu?i lên LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(text);
    
    // 3) ??i 2s
    delay(2000);
    
    // 4) Nh?p nháy 3 l?n
    for (int i = 0; i < 3; i++) {
      lcd.clear();
      delay(300);
      lcd.setCursor(0, 0);
      lcd.print(text);
      delay(300);
    }
    
    // 5) Cu?n ch? t? ph?i sang trái
    //    In l?i ? v? trí ban ??u
    lcd.clear();
    lcd.setCursor(16 - min((int)text.length(), 16), 0);
    lcd.print(text);
    //    Cu?n
    int scrollCount = (int)text.length() + 16;
    for (int i = 0; i < scrollCount; i++) {
      lcd.scrollDisplayLeft();
      delay(300);
    }
    
    // Quay l?i yêu c?u nh?p m?i
    lcd.clear();
    lcd.print("Nhap chuoi:");
  }
}