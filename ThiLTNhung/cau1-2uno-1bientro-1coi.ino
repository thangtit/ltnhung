//  Arduino 1
void setup() {
  Serial.begin(9600);
}

void loop() {
  int a = analogRead(A1);
  Serial.println(a); // G?i giá tr? bi?n tr?
  delay(100);
}

// Arduino 2
const int buzzerPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    int a = Serial.parseInt(); // ??c giá tr? t? thi?t b? A
    if (a < 512) {
      tone(buzzerPin, 10000); // Kêu v?i t?n s? 10000Hz
    } else {
      noTone(buzzerPin); // Ng?ng kêu
    }
  }
}