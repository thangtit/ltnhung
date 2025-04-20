// Thi?t b? A
void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A3); // ??c giá tr? t? quang tr?
  int angle = constrain(sensorValue / 6, 0, 180); // Chuy?n v? góc 0-180
  Serial.println(angle); // G?i d? li?u qua Serial
  delay(100);
}

#include <Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(12); // G?n Servo vào chân 12
}

void loop() {
  if (Serial.available()) {
    int angle = Serial.parseInt(); // Nh?n d? li?u t? A
    myServo.write(angle); // ?i?u khi?n Servo
  }
}