const int potPin = A0;    // Bi?n tr? ? A0
const int ledPin = 9;     // LED n?i chân PWM D9

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);               // ??c giá tr? bi?n tr? (0-1023)
  int brightness = map(potValue, 0, 1023, 0, 255);  // Chuy?n thành ?? sáng (0-255)

  analogWrite(ledPin, brightness);                  // ?i?u khi?n ?? sáng LED

  Serial.print("Gia tri bien tro: ");
  Serial.print(potValue);
  Serial.print(" - Do sang LED: ");
  Serial.println(brightness);

  delay(300);
}
