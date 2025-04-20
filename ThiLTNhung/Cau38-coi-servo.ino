#include <Servo.h>

Servo myServo;
int buzzerPin = 6;

void setup() {
  myServo.attach(5);       // G?n servo v�o ch�n 5
  pinMode(buzzerPin, OUTPUT);
  randomSeed(analogRead(0)); // T?o seed cho s? ng?u nhi�n
}

void loop() {
  int a = random(0, 181);   // T?o s? ng?u nhi�n t? 0 ??n 180
  myServo.write(a);         // ?i?u khi?n servo quay ??n g�c a
  tone(buzzerPin, a * 100); // Ph�t �m thanh v?i t?n s? a * 100 Hz
  delay(500);               // K�u trong 0.5s
  noTone(buzzerPin);        // T?t buzzer
  delay(4500);              // Ch? ??n h?t chu k? 5s
}