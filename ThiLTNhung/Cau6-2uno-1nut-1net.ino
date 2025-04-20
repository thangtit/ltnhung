#define BUTTON_PIN 7

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  Serial.println(buttonState); // 1 n?u b?m, 0 n?u không
  delay(100);
}



#define LED_PIN 6

unsigned long lastToggle = 0;
int ledState = LOW;
int interval = 2000;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    int state = Serial.parseInt();
    interval = (state == HIGH) ? 1000 : 2000; // ??i t?c ?? nh?p nháy
  }

  if (millis() - lastToggle >= interval) {
    lastToggle = millis();
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }
}