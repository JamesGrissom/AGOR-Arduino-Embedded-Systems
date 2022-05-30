
#include <Volume.h>

// documentation for volume.h found here:
// https://github.com/connornishijima/arduino-volume1

int fsrAnalogPin = A0; // FSR is connected to analog 0
int LEDpin = 11;      // connect Red LED to pin 11 (PWM pin)
int fsrReading;       // the analog reading from the FSR resistor divider
int handleReading;
int KEYpin = 10;      //connect blue Key wire to pin 10

Volume vol;

void setup(void) {
  Serial.begin(9600);
  vol.begin();
  vol.setMasterVolume(.2);
  pinMode(LEDpin, OUTPUT);
  pinMode(KEYpin, INPUT);
}
 
void loop(void) {

  fsrReading = analogRead(fsrAnalogPin);
  handleReading = map(fsrReading, 0, 850, 0, 255); // maps fsr reading into something vol can use
  Serial.print("Mapped reading = ");
  Serial.println(handleReading);
  if (digitalRead(KEYpin) == HIGH){ // if key is turned, allow sound
    analogWrite(LEDpin, handleReading);
    if (handleReading > 1) { // play sound based on how far the handle is turned
      vol.tone(100, handleReading);
      vol.delay(1);
    } else {
      vol.noTone(); // turn off sound
    }
  }
  else {
    digitalWrite(LEDpin, LOW);
    vol.fadeOut(20);
    vol.delay(20);
    vol.noTone();
  }
  
  delay(10000);
}
