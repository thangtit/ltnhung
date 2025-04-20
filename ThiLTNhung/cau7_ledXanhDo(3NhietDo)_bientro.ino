// Khai báo chân
const int potPin = A0;       // Chân analog ??c bi?n tr?
const int led1 = 8;          // LED 1
const int led2 = 9;          // LED 2

void setup() {
  Serial.begin(9600);        // B?t ??u giao ti?p Serial
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(potPin);    // ??c giá tr? t? bi?n tr?
  int temperature = map(sensorValue, 0, 1023, 0, 100);   // Chuy?n ??i thành nhi?t ??

  // In ra Serial Monitor
  Serial.print("Nhiet do: ");
  Serial.print(temperature);
  Serial.print(" °C - ");

  // X? lý  t?t ?èn theo nhi?t ??
  if (temperature <= 30) {
    digitalWrite(led1, LOW);
    digitalWrite(led2,LOW);
    Serial.println("Ca 2 den tat sang");
  } 
  else if (temperature > 30 && temperature <= 50) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    Serial.println("Chi den 1 sang");
  } 
  else if (temperature > 50 && temperature <= 80) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    Serial.println("Chi den 2 sang");
  } 
  else { // temperature > 80
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    Serial.println("Ca 2 den dang sang");
  }

  delay(500);  // ??i 0.5 giây tr??c l?n ??c ti?p theo
}