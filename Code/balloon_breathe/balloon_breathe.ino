#include "programmable_air.h"

int state = UN_KNOWN;

void setup() {
  Serial.begin(115200);

  initializePins();

  switchOnPump(1, 50);
  switchOnPump(2, 50);
}

void loop() {
  float pressure = readPressure();
  Serial.println(pressure);
  if (!digitalRead(btn1)) {
    blow(0);
  }
  else {
    if (!digitalRead(btn2)) {
      suck(0);
    }
    else {
      switch (state) {
        case UN_KNOWN:
          if (pressure > 514) {
            suck();
            state = DECREASING;
          }
          else {
            blow();
            state = INCREASING;
          }
          break;

        case INCREASING:
          if (pressure > 520) {
            suck();
            state = DECREASING;
          } else {
            blow();
          }
          break;

        case DECREASING:
          if (pressure < 500) {
            blow();
            state = INCREASING;
          } else {
            suck();
          }
          break;
      }
    }
  }
  for (int i = 0; i < 20; i++) {
    pressure = readPressure();
    Serial.println(pressure);
    delay(200);
  }
}

