
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

  pinMode(A0, INPUT);
  
  //  while(1);
  //  analogWrite(pump[0], 128);
  switchOnPump(1);
  switchOnPump(2);
}

void loop() {
  if(sensorDistance() > 0.5){
    
  }
  
  blow(2);
  delay(7000);
  ventQuick(2);
  delay(3000);
  suck(2);
  delay(5000);
}

// returns voltage. Read datasheet of GP2Y02YK to get distance
int sensorDistance(){
  int dist = analogRead(A0)*5/1024;
}

