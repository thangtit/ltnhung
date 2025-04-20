const int potPin = A1;    // Bi?n tr? ? A1
const int buzzerPin = 10; // C�i n?i ch�n PWM D10

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);                // ??c gi� tr? bi?n tr? (0-1023)
  int buzzerVolume = map(potValue, 0, 1023, 0, 255); // Chuy?n th�nh �m l??ng (0-255)

  analogWrite(buzzerPin, buzzerVolume);             // ?i?u ch?nh ?? l?n c�i

  Serial.print("Gia tri dien ap (A1): ");
  Serial.print(potValue);
  Serial.print(" - Am luong coi: ");
  Serial.println(buzzerVolume);

  delay(300);
}
