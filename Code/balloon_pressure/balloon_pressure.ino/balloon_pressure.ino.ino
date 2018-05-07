#include "programmable_air.h"

void setup() {
  Serial.begin(115200);

  initializePins();

  switchOnPump(1, 100);
  switchOnPump(2, 100);
}

void loop() {
  float pressure = readPressure();
  Serial.println(pressure);

  if (!digitalRead(btn1)) {
  blow(2);
  }
  else {
    if (!digitalRead(btn2)) {
    suck(2);
   }
   else{
    vent(2);
   }
  }

  delay(10);
}
