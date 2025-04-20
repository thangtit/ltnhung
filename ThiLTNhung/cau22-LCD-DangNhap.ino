#include <LiquidCrystal.h>

const char* USERNAME = "admin";
const char* PASSWORD = "123";

// Kh?i t?o LCD v?i chân RS=12, E=11, D4=4, D5=5, D6=6, D7=7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Nhap tai khoan:");
  Serial.println("Nhap tai khoan:");
}

void loop() {
  // ??c username
  while (!Serial.available()) {}
  String user = Serial.readStringUntil('\n');
  user.trim();

  if (user != USERNAME) {
    lcd.clear();
    lcd.print("Nhap sai, nhap lai");
    delay(1000);
    lcd.clear();
    lcd.print("Nhap tai khoan:");
    return;
  }

  // ?úng username ? h?i m?t kh?u
  lcd.clear();
  lcd.print("Nhap mat khau:");
  Serial.println("Nhap mat khau:");

  while (!Serial.available()) {}
  String pass = Serial.readStringUntil('\n');
  pass.trim();

  if (pass != PASSWORD) {
    lcd.clear();
    lcd.print("Nhap sai MK");
    delay(1000);
    lcd.clear();
    lcd.print("Nhap tai khoan:");
    return;
  }

  // ??ng nh?p thành công
  lcd.clear();
  lcd.print("Dang nhap TC");
  while (true) {}
}