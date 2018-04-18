// Programmable Air
// Author: tinkrmind
// github.com/tinkrmind/programmable-air
//
// Simple pick and place
// IO board 1 connected to channel 4
// Valve board 1 connected to SMD pick and place syringe
//

#include <Adafruit_NeoPixel.h>

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

#define neopixelPin 3
#define btn1 2
#define btn2 12

Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(1, neopixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  // Initiate with all valve and pumps off
  initializePins();

  //switch on pumps
  digitalWrite(pump[0], HIGH);
  digitalWrite(pump[1], HIGH);

  // Initialise IO board
  neopixel.begin();
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
}

void loop() {
  // If button 1 is pressed release the conponent
  if (!digitalRead(btn1)) {
    neopixel.setPixelColor(0, neopixel.Color(0, 25, 0));
    neopixel.show();
    setValve(0, CLOSE);
    setValve(1, OPEN);
  }
  // if button is not pressed suck air from syringe to pick up components
  else {
    neopixel.setPixelColor(0, neopixel.Color(0, 0, 0));
    neopixel.show();
    setValve(0, OPEN);
    setValve(1, CLOSE);
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

void initializePins(){
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

