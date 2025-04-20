// Khai báo chân
const int potPin = A0;      // Chân analog ??c bi?n tr?
const int ledGreen = 8;     // LED xanh
const int ledRed = 9;       // LED ??

void setup() {
  Serial.begin(9600);       // Kh?i ??ng Serial Monitor
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(potPin);  // ??c giá tr? analog (0-1023)
  
  // Chuy?n ??i giá tr? analog thành nhi?t ?? (0-100°C)
  int temperature = map(sensorValue, 0, 1023, 0, 100);

  // Hi?n th? nhi?t ??
  Serial.print("Nhiet do: ");
  Serial.print(temperature);
  Serial.print(" °C - ");

  // ?i?u khi?n LED
  if (temperature < 30) {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    Serial.println("LED xanh dang sang");
  }
  else if (temperature > 70) {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    Serial.println("LED do dang sang");
  }
  else {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, LOW);
    Serial.println("Khong co LED nao sang");
  }

  delay(500);  // ??c l?i sau 0.5 giây
}
