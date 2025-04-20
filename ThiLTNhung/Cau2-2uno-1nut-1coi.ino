//  Arduino 1
const int buttonPin = 7;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  Serial.println(buttonState); // G?i tr?ng thái nút nh?n
  delay(100);
}

//  Arduino 1
const int buzzerPin = 3;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int buttonState = Serial.parseInt();
    if (buttonState == LOW) {
      tone(buzzerPin, 10000);
    } else {
      noTone(buzzerPin);
    }
  }
}