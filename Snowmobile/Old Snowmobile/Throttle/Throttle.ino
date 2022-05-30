#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>
#include "settings.h"
#include "idle.h"

// Mode settings - These could easily be 4 jumpers connected to spare pins, checked at startup to determine mode
boolean managedThrottle = true;     // Managed mode looks after the digipot if fitted for volume, and adds some mass to the engine
boolean potThrottle = true;         // A pot connected to A1, 0-1023 sets speed
boolean pwmThrottle = false;        // Takes a standard servo signal on pin 2 (UNO)
boolean spiThrottle = false;        // SPI mode, is an SPI slave, expects 1-255 for throttle position, with 0 being engine off

//https://circuitdigest.com/microcontroller-projects/arduino-audio-music-player
int fsrAnalogPin = A4;    // FSR is connected to analog 4
//int buzzerPin = 10;      // connect Red LED to pin 11 (PWM pin)
int fsrReading;          // the analog reading from the FSR resistor divider
int buzzerTone;
int KEYpin = A1; 

#include "SD.h" //Lib to read SD card
#include "TMRpcm.h" //Lib to play auido
#include "SPI.h" //SPI lib for SD card


//#define SD_ChipSelectPin 4//Chip select is pin number 4
#define SD_ChipSelectPin 10
TMRpcm music; //Lib object is named "music"

int song_number=0;
boolean debounce1=true;
boolean debounce2=true;
boolean play_pause;
 
void setup() {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  //pinMode(buzzerPin, OUTPUT);
  //pinMode(11, INPUT);
  pinMode(9,OUTPUT);

  music.speakerPin = 9;
  if (!SD.begin(SD_ChipSelectPin)) {
  Serial.println("SD fail");
  return;
  }

  music.setVolume(7);    //   0 to 7. Set volume level
  music.quality(1);        //  Set 1 for 2x oversampling Set 0 for normal
//music.volume(0);        //   1(up) or 0(down) to control volume
//music.play("filename",30); plays a file starting at 30 seconds into the track 
}

void loop() {
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
  //Serial.println(digitalRead(KEYpin));
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  //buzzerTone = map(fsrReading, 0, 1023, 0, 255);
  // LED gets brighter the harder you press
  //analogWrite(buzzerPin, buzzerTone);
delay(100);

  if (analogRead(KEYpin) > 1000){
  Serial.println("HIGH");
  //music.play("SnowmobileSoundFile.wav");
  }
  else{
  Serial.println("LOW");
  }
  while (analogRead(KEYpin) > 1000)
  {
    music.play("SnowmobileSoundFile.wav");
    Serial.println(music.isPlaying());
    tone(9, 3136, 3);
  }
}
