const int LDR_PIN = A0;
const int BUZZER_PIN = 8;
int lightValue = 0;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(LDR_PIN);

  Serial.print("Giá tr? ánh sáng: ");
  Serial.print(lightValue);

  if (lightValue < 500) {
    digitalWrite(BUZZER_PIN, HIGH); // Còi kêu
    Serial.println(" -> Còi ?ang kêu");
  } else {
    digitalWrite(BUZZER_PIN, LOW); // Còi t?t
    Serial.println(" -> Còi ?ang t?t");
  }

  delay(500);
}