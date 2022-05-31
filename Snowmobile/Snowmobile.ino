const int keyStart = 2;   // Turning the key connects the yellow and blue wires - starts the snowmobile
const int headlight = 3;  // Turns on the headlight
const int taillight = 4;  // Turns on the taillight
const int FX1 = 5;        // Engine starting sound
const int FX2 = 6;        // Engine idling sound
const int FX3 = 7;        // Engine runnin - slow sound
const int FX4 = 8;        // Engine runnin - medium sound
const int FX5 = 9;        // Engine runnin - fast sound
const int FX6 = 10;       // Engine runnin - really fast sound
const int throttle = A0;  // Signal from the green wire - range from around 340 to about 415 at 5v

int throttleValue = 0;

void setup() {
  pinMode(keyStart, INPUT);
  pinMode(throttle, INPUT);
  pinMode(headlight, OUTPUT);
  pinMode(taillight, OUTPUT);

  pinMode(FX1, OUTPUT);
  pinMode(FX2, OUTPUT);
  pinMode(FX3, OUTPUT);
  pinMode(FX4, OUTPUT);
  pinMode(FX5, OUTPUT);
  pinMode(FX6, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (keyStart == HIGH) {
    FX1 = LOW;
    FX2 = HIGH;
    FX3 = HIGH;
    FX4 = HIGH;
    FX5 = HIGH;
    FX6 = HIGH;
    headlight = HIGH;
    taillight = HIGH;
    delay(1000);

    for (int i; i < 5; i++) {
      throttleValue = throttleValue + analogRead(throttle);
    }
    throttleValue = round(throttleValue / 5);

    if (340 < throttleValue < 360) {
      FX2 = LOW;
    }
    else if (340 < throttleValue < 360) {
      FX2 = LOW;
    }
    else if (340 < throttleValue < 360) {
      FX3 = LOW;
    }
    else if (340 < throttleValue < 360) {
      FX4 = LOW;
    }
    else if (340 < throttleValue < 360) {
      FX5 = LOW;
    }
    else if (340 < throttleValue < 360) {
      FX6 = LOW;
    }
  }
  else if (keyStart == LOW) {
    headlight = LOW;
    taillight = LOW;
  }
}
