const int buzzer = 2;
const int joystick = A1;
int period = 0;
int duty = 20;

void setup() {
  pinMode(A1, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(joystick));
  period = round(800-(analogRead(joystick) + 1));
  digitalWrite(buzzer, HIGH);
  delay(duty);
  digitalWrite(buzzer, LOW);
  delay(period);
  digitalWrite(buzzer, HIGH);
  delay(duty);
  digitalWrite(buzzer, LOW);
  delay(period);
}
