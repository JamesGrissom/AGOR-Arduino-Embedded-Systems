#include <Stepper.h>

#define STEPS_PER_REV 800

Stepper motor(STEPS_PER_REV,6,7); // using the stepper module makes everything simpler!
int pos = 0;
int x = 0;
int randomNum;
const int switchPin = 2;

/*
const int pulPin = 6;
const int dirPin = 7;
const int enPin = 8;
*/

void setup() {
  /*
  pinMode(pulPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);
  */
  Serial.begin(9600);
  randomSeed(analogRead(0));
  motor.setSpeed(60);
  pinMode(switchPin, INPUT);
}

void loop() {

  /* This code turns in random directions 5 times and then resets back into position
   * This is done by keeping track of the random position using pos
   * To reset, we move the motor by -pos
   */
   if (digitalRead(switchPin) == HIGH && x < 5) {
      randomNum = random(-8,8) * 100;
      Serial.print("turning by: ");
      Serial.println(randomNum);
      Serial.print("we are on iteration number " );
      Serial.println(x);
      motor.step(randomNum);
      pos += randomNum;
      x++;
      delay(500);
   } else {
      Serial.print("resetting by: ");
      Serial.println(-pos);
      motor.step(-pos);
      pos = 0;
      x = 0;
      delay(2000);
   }

  
  
/*
  Serial.print("starting");
  // Make the stepper motor spin 360 in one direction
  digitalWrite(dirPin, HIGH);
  for (int x = 0; x < 200; x++) {
    digitalWrite(pulPin, HIGH);
    Serial.print("turning");
    delayMicroseconds(500);
    digitalWrite(pulPin, LOW);
    delayMicroseconds(500);
  }
  delay(1000);
  // Make the motor spin in the other direction
  digitalWrite(dirPin, LOW);
  for (int x = 0; x < 200; x++) {
    digitalWrite(pulPin, HIGH);
    Serial.print("turning other way");
    delayMicroseconds(500);
    digitalWrite(pulPin, LOW);
    delayMicroseconds(500);
  }
  delay(1000); */
}
