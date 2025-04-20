const int LDR_PIN = A0;
const int BUZZER_PIN = 8;
int lightValue = 0;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(LDR_PIN);

  Serial.print("Gi� tr? �nh s�ng: ");
  Serial.print(lightValue);

  if (lightValue < 500) {
    digitalWrite(BUZZER_PIN, HIGH); // C�i k�u
    Serial.println(" -> C�i ?ang k�u");
  } else {
    digitalWrite(BUZZER_PIN, LOW); // C�i t?t
    Serial.println(" -> C�i ?ang t?t");
  }

  delay(500);
}