#include "programmable_air.h"

int state = UN_KNOWN;

void setup() {
  Serial.begin(115200);

  initializePins();

  switchOnPump(1, 50);
  switchOnPump(2, 50);
}

void loop() {
  suck();
  delay(4000);
  blow();
  delay(4000);
}

