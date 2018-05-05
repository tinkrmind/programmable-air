#include "HX711.h"

HX711 scale2;

void setup() {
  Serial.begin(115200);

  scale.begin(A5, 13, 32);
  scale2.begin(6, 13, 32);

  scale2.set_scale(2280.f);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale2.tare();                // reset the scale to 0
  
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
}

void loop() {
  Serial.print(scale2.get_units());

  Serial.print(",0, 700");
  Serial.println();
  delay(50);  
}
