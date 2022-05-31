const int soundout = 10;            

int time;

void setup() {
  pinMode(soundout, OUTPUT);
  digitalWrite(soundout, LOW);
}

void loop() {
  //time should only update once time actually changes
  //no point in constantly updating if we're just gonna get
  //the same number over and over again
  if(time != millis() / 1000 / 60){
      time = millis() / 1000 / 60;
      //divide current time by 15 and check if remainder is 0
      //to compensate for absolute time
      if(time % 15 == 0){
        bellTrigger(3000);
      }
  }
}

void bellTrigger(int time){
  digitalWrite(soundout, HIGH);
  delay(time);
  digitalWrite(soundout, LOW);
}
