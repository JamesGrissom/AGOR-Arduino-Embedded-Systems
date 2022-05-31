void setup() {
pinMode(A2, INPUT);
Serial.begin(9600);
}

void loop() {
Serial.println(analogRead(A2));
}
