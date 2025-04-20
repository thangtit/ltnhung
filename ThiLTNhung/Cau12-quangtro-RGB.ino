const int LDR_PIN = A1;
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
int lightValue = 0;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(LDR_PIN);
  Serial.print("Gi� tr? �nh s�ng: ");
  Serial.print(lightValue);

  if (lightValue <= 200) {
    setColor(255, 0, 0); // ??
    Serial.println(" -> ?�n RGB s�ng m�u: ??");
  } else if (lightValue <= 400) {
    setColor(0, 255, 0); // xanh l�
    Serial.println(" -> ?�n RGB s�ng m�u: xanh l�");
  } else if (lightValue <= 500) {
    setColor(0, 0, 255); // xanh d??ng
    Serial.println(" -> ?�n RGB s�ng m�u: xanh d??ng");
  } else {
    setColor(255, 255, 255); // tr?ng (s�ng c? 3 m�u)
    Serial.println(" -> ?�n RGB s�ng m�u: tr?ng");
  }

  delay(500);
}

void setColor(int redVal, int greenVal, int blueVal) {
  analogWrite(RED_PIN, redVal);
  analogWrite(GREEN_PIN, greenVal);
  analogWrite(BLUE_PIN, blueVal);
}