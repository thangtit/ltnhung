const int buttonPin = 2;    // N�t nh?n n?i ch�n D2
const int buzzerPin = 8;    // C�i n?i ch�n D8

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); // K�ch ho?t ?i?n tr? k�o l�n n?i b?
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {  // N�t nh?n ???c nh?n (v� pullup n�n LOW)
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Nut nhan dang duoc nhan, coi dang keu");
  } 
  else {                     // N�t th? ra
    digitalWrite(buzzerPin, LOW);
    Serial.println("Nut nhan khong duoc nhan, coi ngung keu");
  }

  delay(200);
}
