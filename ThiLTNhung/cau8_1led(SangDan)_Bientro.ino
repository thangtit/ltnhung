const int potPin = A0;    // Bi?n tr? ? A0
const int ledPin = 9;     // LED n?i ch�n PWM D9

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);               // ??c gi� tr? bi?n tr? (0-1023)
  int brightness = map(potValue, 0, 1023, 0, 255);  // Chuy?n th�nh ?? s�ng (0-255)

  analogWrite(ledPin, brightness);                  // ?i?u khi?n ?? s�ng LED

  Serial.print("Gia tri bien tro: ");
  Serial.print(potValue);
  Serial.print(" - Do sang LED: ");
  Serial.println(brightness);

  delay(300);
}
