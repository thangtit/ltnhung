void setup() {
  Serial.begin(9600);
}

void loop() {
  int b = analogRead(A4) / 10; // Gi?m ?? phân gi?i
  int a = (b + 1) * 10;
  Serial.println(a); // G?i t?n s? a
  delay(100);
}
//2
#define BUZZER_PIN 8

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    int freq = Serial.parseInt(); // Nh?n t?n s?
    tone(BUZZER_PIN, freq);       // Phát âm v?i t?n s? a
    delay(100);
    noTone(BUZZER_PIN);           // T?t t?m th?i ?? nghe rõ ti?ng
  }
}