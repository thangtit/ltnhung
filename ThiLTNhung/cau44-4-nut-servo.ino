#include <Servo.h>

Servo myServo;
int buttons[] = {3, 4, 5, 6};
int angles[] = {45, 90, 135, 180};
int buttonState[4];

void setup() {
  myServo.attach(7);
  myServo.write(0); 

  for (int i = 0; i < 4; i++) {
    pinMode(buttons[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    if (digitalRead(buttons[i]) == HIGH) {
      myServo.write(angles[i]);
      delay(3000);
      myServo.write(0);
    }
  }
}