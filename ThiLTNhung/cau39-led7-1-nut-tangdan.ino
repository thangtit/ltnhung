int led[] = {2, 3, 4, 9, 6, 8, 7}; // LED 7 ?o?n: A, B, C, D, E, F, G

int mtso[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

const int nutNhan = 5; 
int so = 0;

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(led[i], OUTPUT);
  }

  pinMode(nutNhan, INPUT); 

  HienThiSo(so); 
}

void loop() {
  
  if (digitalRead(nutNhan) == HIGH) {
    delay(50); 
    so++;
    if (so > 9) so = 0;
    HienThiSo(so);

    
    while (digitalRead(nutNhan) == HIGH) {
      delay(10);
    }
  }
}


void HienThiSo(int so) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(led[i], mtso[so][i]);
  }
}