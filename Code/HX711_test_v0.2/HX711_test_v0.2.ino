// Programmable Air
// Author: tinkrmind
// github.com/tinkrmind/programmable-air
//
// Simple pick and place
// IO board 1 connected to channel 4
// Valve board 1 connected to SMD pick and place syringe
//
// PCB v0.2
//

#include "programmable_air.h"

int i = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  // Initiate with all valve and pumps off
  initializePins();

  //switch on pumps
    digitalWrite(pump[0], HIGH);
    digitalWrite(pump[1], HIGH);
}

void loop() {
  blow(i%3);
  delay(100);
  suck(i%3);
  delay(100);
  vent(i%3);
  delay(100);
  i++;
//  Serial.print(readPressure(0, 4));
//  Serial.print(',');
//  delay(5);
//  Serial.print(readPressure(1, 4));
////  Serial.print(',');
////  Serial.print(readPressure(2, 20));
//  Serial.println();
//  delay(5);
}

