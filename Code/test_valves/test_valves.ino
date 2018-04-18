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

#define neopixel 3
#define btn1 2
#define btn2 

void setup() {
  for (int i = 0; i < 12; i++) {
    pinMode(valve[i], OUTPUT);
    digitalWrite(valve[i], LOW);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(sense[i], INPUT);
  }
  pinMode(SCK, OUTPUT);

  for (int i = 0; i < 2; i++) {
    pinMode(pump[i], OUTPUT);
    digitalWrite(pump[i], LOW);
  }

  digitalWrite(pump[0], HIGH);
  digitalWrite(pump[1], HIGH);
}

void loop() {
  //  setAllValves(OPEN);
  //  delay(1000);
  //  setAllValves(CLOSE);
  //  delay(1000);

  //cycle through all valves
  for (int i = 2; i < 3; i++) {
    setAllValves(CLOSE);
    setValve(i, OPEN);
    delay(5000);
    //    while (1);
    setValve(i, CLOSE);
    delay(2500);
  }
}

void setAllValves(int position) {
  if (position == OPEN) {
    for (int i = 0; i < 12; i++) {
      digitalWrite(valve[i], HIGH);
    }
  }

  if (position == CLOSE) {
    for (int i = 0; i < 12; i++) {
      digitalWrite(valve[i], LOW);
    }
  }
}

void setValve(int number, int position) {
  if (position == OPEN) {
    digitalWrite(valve[number], HIGH);
  }

  if (position == CLOSE) {
    digitalWrite(valve[number], LOW);
  }
}

