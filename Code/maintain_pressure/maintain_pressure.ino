#include "HX711.h"
#include "programmable_air.h"

HX711 pressureSensor1;
//HX711 scale(DT, SCK);

float old_pressure;
float clean_pressure;
float temp_pressure;
float alpha = 0.7;

void setup() {
  Serial.begin(115200);
  pressureSensor1.begin(A5,  13, 32);

  pressureSensor1.set_scale(2280.f);
  pressureSensor1.tare();

  clean_pressure = pressureSensor1.get_units();
  old_pressure = pressureSensor1.get_units();

  initializePins();

  //  analogWrite(pump[0], 128);
  switchOnPump(1);
  //  switchOnPump(2);
}

void loop() {
  temp_pressure = pressureSensor1.get_units();
  clean_pressure = old_pressure * (1 - alpha) + temp_pressure * alpha;

  Serial.print("0,");
  Serial.println(clean_pressure);

  if (clean_pressure > 2000) {
    vent(2);
    //    suck(2);
  }
  else {
    blow(2);
  }
  if(millis() % 30000 < 1000){
    vent(1);
  }  
  else{
    closeAll(1);
  }
}
