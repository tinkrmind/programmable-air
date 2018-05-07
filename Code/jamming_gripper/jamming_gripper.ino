#include "programmable_air.h"

void setup() {
  Serial.begin(115200);

  initializePins();
  
  switchOnPump(1);
  switchOnPump(2);
}

void loop() {
  if(!digitalRead(btn2)){
    suck(2);
  }
  else{
    vent(2);
  }
  Serial.println(readPressure());
  delay(100);
}
