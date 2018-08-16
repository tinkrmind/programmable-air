#include "programmable_air.h"

void setup() {
  Serial.begin(115200);

  initializePins();
  pinMode(A5, INPUT_PULLUP);
  switchOnPump(1);
  switchOnPump(2);
}

void loop() {
  if (!digitalRead(btn2) || !digitalRead(A5)) {
    suck(0);
  }
  else {
    vent(0);
  }
  Serial.println(readPressure());
  delay(100);
}
