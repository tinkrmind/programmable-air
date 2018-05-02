// Programmable Air
// Author: tinkrmind
// github.com/tinkrmind/programmable-air
//
// Simple pick and place
// IO board 1 connected to channel 4
// Valve board 1 connected to SMD pick and place syringe
//

#include <Adafruit_NeoPixel.h>

const int pump[2] = {10, 11};

#define OPEN 1
#define CLOSE 0
// vacuum, atmosphere, pressure
const int valve[9] = {  9, 8, 7,  \
                        5, 4, A4, \
                        A0, A1, A2
                     };

const int sense[3] = {6, A5, A3};

#define SCK 13

#define neopixelPin 12
#define btn1 2
#define btn2 3

Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(3, neopixelPin, NEO_GRB + NEO_KHZ800);

int state = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  // Initiate with all valve and pumps off
  initializePins();

  //switch on pumps
  //  digitalWrite(pump[0], HIGH);
  //  digitalWrite(pump[1], HIGH);
}

void loop() {
  //  Serial.println(analogRead(LDR));
  digitalWrite(6, HIGH);
  while(1);
//  blow(1);
//  delay(7000);
//  ventQuick(1);
//  delay(3000);
//  suck(1);
//  delay(3000);
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

  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);

  for (int i = 0; i < 2; i++) {
    pinMode(pump[i], OUTPUT);
    digitalWrite(pump[i], LOW);
  }

  neopixel.begin();
  for (int i = 0; i < 3; i++) {
    neopixel.setPixelColor(i, neopixel.Color(5, 0, 5));
  }
  neopixel.show();
  Serial.println("Pins initialised.");
}

//0-blow, 1-vent, 2-suck

void blow(int i) {
  Serial.print("Blow: ");
  Serial.println(i);
  if (i < 0 || i > 2) {
    setValve(i * 3 + 0, OPEN);
    setValve(i * 3 + 1, CLOSE);
    setValve(i * 3 + 2, CLOSE);
  }
}

void vent(int i) {
  Serial.print("Vent: ");
  Serial.println(i);
  if (i > 0 && i < 2) {
    setValve(i * 3 + 0, CLOSE);
    setValve(i * 3 + 1, OPEN);
    setValve(i * 3 + 2, CLOSE);
  }
}

void ventQuick(int i) {
  Serial.print("ventQuick: ");
  Serial.println(i);
  if (i > 0 && i < 2) {
    setValve(i * 3 + 0, CLOSE);
    setValve(i * 3 + 1, OPEN);
    setValve(i * 3 + 2, OPEN);
  }
}


void suck(int i) {
  Serial.print("Suck: ");
  Serial.println(i);
  if (i > 0 && i < 2) {
    setValve(i * 3 + 0, CLOSE);
    setValve(i * 3 + 1, CLOSE);
    setValve(i * 3 + 2, OPEN);
  }
}
