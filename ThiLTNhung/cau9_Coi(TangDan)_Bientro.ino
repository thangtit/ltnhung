const int potPin = A1;    // Bi?n tr? ? A1
const int buzzerPin = 10; // Còi n?i chân PWM D10

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);                // ??c giá tr? bi?n tr? (0-1023)
  int buzzerVolume = map(potValue, 0, 1023, 0, 255); // Chuy?n thành âm l??ng (0-255)

  analogWrite(buzzerPin, buzzerVolume);             // ?i?u ch?nh ?? l?n còi

  Serial.print("Gia tri dien ap (A1): ");
  Serial.print(potValue);
  Serial.print(" - Am luong coi: ");
  Serial.println(buzzerVolume);

  delay(300);
}
