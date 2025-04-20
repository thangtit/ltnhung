#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

const int sensorPin = A0;
const int ledPin    = 8;
const int buzzerPin = 9;

void setup() {
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int raw = analogRead(sensorPin);
  int temp = map(raw, 0, 1023, 0, 100);

  // Hi?n th? LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nhiet do: ");
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("C");

  // ?i?u ki?n ?i?u khi?n LED & Buzzer
  if (temp > 40) {
    // Buzzer kêu liên t?c, LED t?t
    digitalWrite(ledPin, LOW);
    tone(buzzerPin, 1000); // ng?u ch?n 1?kHz
  }
  else if (temp >= 30) {
    // LED sáng, buzzer t?t
    digitalWrite(ledPin, HIGH);
    noTone(buzzerPin);
  }
  else {
    // D??i 30°C: t?t c?
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  delay(1000);
}