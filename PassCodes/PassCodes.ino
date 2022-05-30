const int passwordLength = 4;
const int b0 = 0;
const int b1 = 1;
const int b2 = 2;
const int b3 = 3;
const int b4 = 4;
const int b5 = 5;
const int b6 = 6;
const int b7 = 7;
const int b8 = 8;
const int b9 = 9;
bool passwordCheck = 1;
int password[passwordLength];
int passwordGuess[passwordLength];

void setup() {
  pinMode(b0, INPUT);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
  pinMode(b5, INPUT);
  pinMode(b6, INPUT);
  pinMode(b7, INPUT);
  pinMode(b8, INPUT);
  pinMode(b9, INPUT);
}

void loop() {
  for (int i = 0; i < passwordLength; i++) {
    if (digitalRead(b0) == HIGH) {
      passwordGuess[i] = 0;
    }
    if (digitalRead(b1) == HIGH) {
      passwordGuess[i] = 1;
    }
    if (digitalRead(b2) == HIGH) {
      passwordGuess[i] = 2;
    }
    if (digitalRead(b3) == HIGH) {
      passwordGuess[i] = 3;
    }
    if (digitalRead(b4) == HIGH) {
      passwordGuess[i] = 4;
    }
    if (digitalRead(b5) == HIGH) {
      passwordGuess[i] = 5;
    }
    if (digitalRead(b6) == HIGH) {
      passwordGuess[i] = 6;
    }
    if (digitalRead(b7) == HIGH) {
      passwordGuess[i] = 7;
    }
    if (digitalRead(b8) == HIGH) {
      passwordGuess[i] = 8;
    }
    if (digitalRead(b9) == HIGH) {
      passwordGuess[i] = 9;
    }
    delay(250);
  }
  for (int i = 0; i < passwordLength; i++) {
    if (password[i] != passwordGuess[i]) {
      passwordCheck = 0;
    }
  }
}
