#include <LiquidCrystal.h>

// Kh?i t?o LCD: RS=12, E=11, D4=4, D5=5, D6=6, D7=7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

const int sensorPin = A1;
const int ledPin    = 8;

void setup() {
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int raw = analogRead(sensorPin);  
  // Map th?ng raw [0..1023] ? temp [0..100]
  int temp = map(raw, 0, 1023, 0, 100);

  // Hi?n th? lên LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nhiet do: ");
  lcd.print(temp);
  lcd.print((char)223); // ký t? ??
  lcd.print("C");

  // ?i?u khi?n LED
  if (temp >= 35) {
    // Nh?p nháy 3 l?n
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
    }
  }
  else if (temp >= 30) {
    // Sáng liên t?c
    digitalWrite(ledPin, HIGH);
  }
  else {
    // T?t
    digitalWrite(ledPin, LOW);
  }

  delay(1000); // ??c m?i 1s
}