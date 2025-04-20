#include <Servo.h>

Servo myServo;
int bienTro = A0;

void setup() {
  myServo.attach(5);
}

void loop() {
  int a = analogRead(bienTro);
  int goc = map(a, 0, 1023, 0, 180);
  myServo.write(goc);
  delay(15); // ??i servo quay
}