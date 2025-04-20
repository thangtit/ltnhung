const int LDR_PIN = A0;
const int LED_PIN = 9;
int lightValue = 0;
int ledBrightness = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(LDR_PIN);
  ledBrightness = map(lightValue, 0, 1023, 0, 255);

  analogWrite(LED_PIN, ledBrightness);

  Serial.print("Giá tr? ánh sáng: ");
  Serial.print(lightValue);
  Serial.print(" -> ?? sáng LED: ");
  Serial.println(ledBrightness);

  delay(500);
}