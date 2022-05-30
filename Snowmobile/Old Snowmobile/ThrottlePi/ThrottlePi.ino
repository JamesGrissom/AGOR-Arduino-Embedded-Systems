#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

//https://circuitdigest.com/microcontroller-projects/arduino-audio-music-player
int fsrAnalogPin = A4;    // FSR is connected to analog 4
//int buzzerPin = 10;      // connect Red LED to pin 11 (PWM pin)
int fsrReading;          // the analog reading from the FSR resistor divider
int buzzerTone;
int KEYpin = A1; 

void setup() {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(9,OUTPUT);
}


void loop() {
  fsrReading = analogRead(fsrAnalogPin);

  
delay(100);

  if (analogRead(KEYpin) > 1000){
  Serial.println(2000+fsrReading);
  }
  else{
  Serial.println(fsrReading);

  }
}
