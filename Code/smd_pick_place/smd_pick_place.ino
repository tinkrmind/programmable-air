#include "programmable_air.h"

void setup() {
  Serial.begin(115200);

  initializePins();
}

void loop() {
  float pressure = readPressure();
  Serial.println(pressure);
  if (pressure > 5) {
    for (int i = 0; i < 3; i++) {
      neopixel.setPixelColor(i, neopixel.Color(temp_pressure*10, 0, temp_pressure*10));
    }
    neopixel.show();
  }
  else{
    for (int i = 0; i < 3; i++) {
      neopixel.setPixelColor(i, neopixel.Color(0, 0, 0));
    }
    neopixel.show();
  }

  delay(100);
}
