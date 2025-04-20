int leds[] = {3, 4, 5};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW); // Kh?i t?o t?t
  }

  randomSeed(analogRead(0)); // T?o s? ng?u nhiên
}

void loop() {
  int a = random(1, 4); // 1 ??n 3

  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], (a == i + 1) ? HIGH : LOW);
  }

  delay(1000);
}