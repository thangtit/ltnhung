const int buttonPin = 2;    // Nút nh?n n?i chân D2
const int buzzerPin = 8;    // Còi n?i chân D8

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); // Kích ho?t ?i?n tr? kéo lên n?i b?
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {  // Nút nh?n ???c nh?n (vì pullup nên LOW)
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Nut nhan dang duoc nhan, coi dang keu");
  } 
  else {                     // Nút th? ra
    digitalWrite(buzzerPin, LOW);
    Serial.println("Nut nhan khong duoc nhan, coi ngung keu");
  }

  delay(200);
}
