int fsrAnalogPin = A4;    // FSR is connected to analog 0
int buzzerPin = 11;      // connect Red LED to pin 11 (PWM pin)
int fsrReading;          // the analog reading from the FSR resistor divider
int buzzerTone;
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(buzzerPin, OUTPUT);
}

void loop(void) {
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  buzzerTone = map(fsrReading, 0, 1023, 0, 255);
  // LED gets brighter the harder you press
  analogWrite(buzzerPin, buzzerTone);
 
  delay(100);



  
}