const int keyStart = 2;  // Turning the key connects the yellow and blue wires - starts the snowmobile
const int engineStart = 3; // Triggers the engine starting sound
const int engineRun  = 4; // Tiggers the engine running sound
const int headlight = 5;  // Turns on the headlight
const int taillight = 6;  // Turns on the taillight
const int throttle = A0;  // Signal from the green wire - range from around 340 to about 415 at 5v

void setup() {
  pinMode(key, INPUT);
  pinMode(throttle, INPUT);
  pinMode(engineStart, OUTPUT);
  pinMode(engineRun, OUTPUT);
  pinMode(headlight, OUTPUT);
  pinMode(taillight, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(throttle));
  if (keyStart == HIGH) {
    engineStart = LOW;
    delay(1000);
    engineStart = HIGH;
    engineRun = LOW;
    headlight = HIGH;
    tailLight = HIGH;
  }
  else if (keyStart == LOW) {
    engineStart = HIGH;
    engineRun = HIGH;
    headlight = LOW;
    taillight = LOW;
  }
}
