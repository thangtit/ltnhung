int leds[] = {7, 8, 9};
int buttons[] = {10, 11, 12};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
    pinMode(buttons[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    if (digitalRead(buttons[i]) == HIGH) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }
}