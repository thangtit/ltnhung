const int buttonPin = 7;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  Serial.println(buttonState); // G?i tr?ng thái nút nh?n
  delay(100);
}

// Arduino 2

#include <Servo.h>

Servo myServo;
const int servoPin = 9;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int buttonState = Serial.parseInt();
    if (buttonState == LOW) {
      myServo.write(60); // Quay ??n góc 60°
    } else {
      myServo.write(0); // Quay v? góc 0°
    }
  }
}