const int LDR_PIN = A1;
const int LED_PIN = 9;
int lightValue = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(LDR_PIN);
  Serial.print("Gi� tr? �nh s�ng: ");
  Serial.print(lightValue);

  if (lightValue > 500) {
    digitalWrite(LED_PIN, LOW); // T?t ?�n
    Serial.println(" -> ?�n LED t?t");
  } else {
    digitalWrite(LED_PIN, HIGH); // B?t ?�n
    Serial.println(" -> ?�n LED s�ng");
  }

  delay(500);
}