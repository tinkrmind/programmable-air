#include "programmable_air.h"

float setPressure = 2000;
float tolerence = 300;

int state;

void setup() {
  Serial.begin(115200);

  initializePins();

  switchOnPump(1);
  switchOnPump(2);
}

void loop() {
  float pressure = readPressure();

  Serial.print(setPressure);
  Serial.print(",0,");
  Serial.println(pressure);

  if (pressure > setPressure + tolerence) {
  vent(2);
    state = DECREASING;
    //    suck(2);
  }
  else {
    if (pressure < (setPressure - tolerence)) {
      blow(2);
      state = INCREASING;
    }
    else {
      if (state == UN_KNOWN)
      {
        closeAll(2);
      }
    }
  }
  if (pressure < setPressure && state == DECREASING) {
  state = UN_KNOWN;
}
if (pressure > setPressure && state == INCREASING) {
  state = UN_KNOWN;
}
}
