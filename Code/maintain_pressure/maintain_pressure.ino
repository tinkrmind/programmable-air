
#include "HX711.h"
#include "programmable_air.h"

HX711 pressureSensor1;
//HX711 scale(DT, SCK);

float old_pressure;
float clean_pressure;
float temp_pressure;
float alpha = 0.7;

float setPressure = 1500;
float tolerence = 300;

#define INCREASING 1
#define DECREASING -1
#define UN_KNOWN 0

int state;

void setup() {
  Serial.begin(115200);
  pressureSensor1.begin(A5,  13, 32);

  pressureSensor1.set_scale(2280.f);
  pressureSensor1.tare();

  clean_pressure = pressureSensor1.get_units();
  old_pressure = pressureSensor1.get_units();

  initializePins();

  //  while(1);
  //  analogWrite(pump[0], 128);
  switchOnPump(1);
  //  switchOnPump(2);
}

void loop() {
  temp_pressure = pressureSensor1.get_units();
  clean_pressure = old_pressure * (1 - alpha) + temp_pressure * alpha;

  Serial.print(setPressure);
  Serial.print(",0,");
  Serial.println(clean_pressure);

  if (clean_pressure > setPressure + tolerence) {
    vent(2);
    state = DECREASING;
    //    suck(2);
  }
  else {
    if (clean_pressure < (setPressure - tolerence)) {
      blow(2);
      state = INCREASING;
    }
    else {
      if (state == UN_KNOWN)
      {
//        closeAll(2);
      }
    }
  }
  if (clean_pressure < setPressure && state == DECREASING) {
    state = UN_KNOWN;
  }
  if (clean_pressure > setPressure && state == INCREASING) {
    state = UN_KNOWN;
  }

  if (millis() % 30000 < 1000) {
    vent(1);
  }
  else {
    closeAll(1);
  }
}
