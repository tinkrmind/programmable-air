// Programmable Air
// Author: tinkrmind
// github.com/tinkrmind/programmable-air
// 
// Controls the valves of all attached slave boards.
//

const int pump[2] = {A3, 7};

#define OPEN 1
#define CLOSE 0

const int valve[12] = {   4,  5,  6, \
                          9,  10, 11, \
                          A0, A1, A2,  \
                          12, 3,  2
                      };

const int sense[4] = {A7, 8, A6, A4};                      

#define SCK 13

void setup() {
  for(int i=0; i<12; i++){
    pinMode(valve[i], OUTPUT);
    digitalWrite(valve[i], LOW);
  }
  for(int i=0; i<4; i++){
    pinMode(sense[i], INPUT);
  }
  pinMode(SCK, OUTPUT);
  
  for(int i=0; i<2; i++){
    pinMode(pump[i], OUTPUT);
    digitalWrite(pump[i], LOW);
  }
}

void loop() {
//  setAllValves(OPEN);
//  delay(1000);
//  setAllValves(CLOSE);
//  delay(1000);

  //cycle through all valves
  for(int i=0; i<12; i++){
    setAllValves(CLOSE);
    digitalWrite(valve[i], HIGH);    
    delay(1000);
  }
}

void setAllValves(int position){
  if(position == OPEN){
    for(int i=0; i<12; i++){
      digitalWrite(valve[i], HIGH);
    }
  }

  if(position == CLOSE){
    for(int i=0; i<12; i++){
      digitalWrite(valve[i], LOW);
    }
  }
}
