// Programmable Air
// Author: tinkrmind
// github.com/tinkrmind/programmable-air
//
// Simple pick and place
// IO board 1 connected to channel 4
// Valve board 1 connected to SMD pick and place syringe
//

#include <Adafruit_NeoPixel.h>

#define LDR A7

const int pump[2] = {A3, 7};

#define OPEN 1
#define CLOSE 0
// vacuum, atmosphere, pressure
const int valve[12] = {   4,  5,  6, \
                          9,  10, 11, \
                          A0, A1, A2,  \
                          12, 3,  2
                      };

const int sense[4] = {A7, 8, A6, A4};

#define SCK 13

#define neopixelPin 3
#define btn1 2
#define btn2 12

Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(1, neopixelPin, NEO_GRB + NEO_KHZ800);

int state = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);


  // Initiate with all valve and pumps off
  initializePins();
  pinMode(LDR, INPUT);

  //switch on pumps
  digitalWrite(pump[0], HIGH);
  digitalWrite(pump[1], HIGH);
}

void loop() {
  //  Serial.println(analogRead(LDR));

  blow();
  delay(7000);
  suck();
  vent();
  delay(5000);
  suck();
  delay(5000);
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

void initializePins() {
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
}

//0-blow, 1-vent, 2-suck 

void vent() {
  setValve(1, OPEN);
  setValve(2, OPEN);
  setValve(0, CLOSE);
}

void blow() {
  setValve(2, CLOSE);
  setValve(1, CLOSE);
  setValve(0, OPEN);
}

void suck() {
  setValve(2, OPEN);
  setValve(0, CLOSE);
  setValve(1, CLOSE);
}

