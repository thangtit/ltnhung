const int redPin = 7;
const int greenPin = 8;
const int bluePin = 9;

const int buttonR = 10;
const int buttonG = 11;
const int buttonB = 12;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(buttonR, INPUT_PULLUP);
  pinMode(buttonG, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);
}

void loop() {
  digitalWrite(redPin, digitalRead(buttonR) == LOW ? HIGH : LOW);
  digitalWrite(greenPin, digitalRead(buttonG) == LOW ? HIGH : LOW);
  digitalWrite(bluePin, digitalRead(buttonB) == LOW ? HIGH : LOW);
}