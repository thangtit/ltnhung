const int LDR_PIN = A1;
const int LED_PIN = 9;
int lightValue = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(LDR_PIN);
  Serial.print("Giá tr? ánh sáng: ");
  Serial.print(lightValue);

  if (lightValue > 500) {
    digitalWrite(LED_PIN, LOW); // T?t ?èn
    Serial.println(" -> ?èn LED t?t");
  } else {
    digitalWrite(LED_PIN, HIGH); // B?t ?èn
    Serial.println(" -> ?èn LED sáng");
  }

  delay(500);
}