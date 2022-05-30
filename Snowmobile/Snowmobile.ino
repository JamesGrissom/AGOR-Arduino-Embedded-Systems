const int keyStart = 2;  // Turning the key connects the yellow and blue wires - starts the snowmobile
const int engineStart = 3; // Triggers the engine starting sound
const int engineRun  = 4; // Tiggers the engine running sound
const int headlight = 5;  // Turns on the headlight
const int taillight = 6;  // Turns on the taillight
const int volumeUp = 7;   // Turns up the engine volume
const int volumeDown = 8; // Turns down the engine volume
const int throttle = A0;  // Signal from the green wire - range from around 340 to about 415 at 5v
int volumeCount = 0

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
    while((analogRead(throttle) >= 375)) & (volumeCount < 5)) {
      volumeUp = LOW;
      volumeUp = HIGH;
      volt
    }
  }
  else if (keyStart == LOW) {
    engineStart = HIGH;
    engineRun = HIGH;
    volumeUp = HIGH;
    volumeDown = HIGH;
    headlight = LOW;
    taillight = LOW;
  }
}
