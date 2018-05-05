// Programmable Air
// Author: tinkrmind
// github.com/tinkrmind/programmable-air
//
// Switch on all valves one by one quickly, indefinitely
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
  switchOnPump(1);
  switchOnPump(2);
}

void loop() {
  blow(i % 3);
  delay(100);
  suck(i % 3);
  delay(100);
  vent(i % 3);
  delay(100);
  i++;
}

