int buttons[] = {3, 4, 5, 6};
int tones[] = {10, 500, 1000, 6000};
int buzzer = 7;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(buttons[i], INPUT);
  }
  pinMode(buzzer, OUTPUT);
}

void loop() {
  for (int i = 0; i < 4; i++) {
    if (digitalRead(buttons[i]) == HIGH) {
      delay(50); // Ch?ng d?i
      tone(buzzer, tones[i]); // Ph�t �m thanh
      delay(1000);
      noTone(buzzer); // T?t c�i

      // ??i ng??i d�ng nh? n�t
      while (digitalRead(buttons[i]) == HIGH) {
        delay(10);
      }
    }
  }
}