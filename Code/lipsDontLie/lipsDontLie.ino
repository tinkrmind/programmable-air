#include "programmable_air.h"

int state;
unsigned long stateChangeTime = 0;

float temp_data = 0;
float cur_data = 0;
float old_data = 0;
float alpha = 0.8;
float sensorDistance() ;

void setup() {
  Serial.begin(115200);

  initializePins();
  vent(2);
  delay(500);
  pressureSensor1.tare();

  pinMode(A0, INPUT);

  //  while(1);
  //  analogWrite(pump[0], 128);
  switchOnPump(1);
  switchOnPump(2);

  cur_data = sensor_distance();
  old_data = sensor_distance();
}

void loop() {
  temp_data = sensor_distance();
  cur_data = old_data * alpha + temp_data * (1 - alpha);
  old_data = cur_data;
  
//  Serial.print("0, 5,");
//  Serial.println(cur_data);

  Serial.println(readPressure());

  if (cur_data > 0.6) {
    blow(2);
  }
  if (cur_data < 0.6) {
    ventQuick(2);
  }
}

// returns voltage. Read datasheet of GP2Y02YK to get distance
float sensor_distance() {
  float dist = analogRead(A0) * 5.0 / 1024;
  return dist;
}

