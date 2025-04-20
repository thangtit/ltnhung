int led[] = {2, 3, 4, 7, 8, 9, 10}; // LED 7 ?o?n: A, B, C, D, E, F, G
int L1 = 5;
int L2 = 6;

int mtso[11][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(led[i], OUTPUT);
  }
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);

  randomSeed(analogRead(0)); 
}

void loop() {
  int a = random(0, 6); 
  int b = random(0, 6);
  int tong = a + b;

  HienThiSo(tong);

  if (a > 3) {
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
  } else {
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
  }

  delay(3000); 
}


void HienThiSo(int so) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(led[i], mtso[so][i]);
  }
}