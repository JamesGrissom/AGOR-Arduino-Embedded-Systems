const int buzzer = 2;         //connect the buzzer to digital pin 2
const int forceSensor = A1;   //connect the force sensor to analog pin 1
const int rhrMeter = 3;       //commect the R/hr meter to digital pin 3 - use a 50 to 1 voltsge divider
const int powerSwitch = 4;
int force = 0;
int period = 0;
int duty = 20;

void setup() {
  pinMode(forceSensor, INPUT);
  pinMode(powerSwitch, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(rhrMeter, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(powerSwitch) == HIGH) {
    force = analogRead(forceSensor);
    Serial.println(force);
    period = round(1000 - force);
    analogWrite(rhrMeter, round(force / 5));
    digitalWrite(buzzer, HIGH);
    delay(duty);
    digitalWrite(buzzer, LOW);
    delay(period);
  }
}
