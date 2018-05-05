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
}

void loop() {
  temp_pressure = pressureSensor1.get_units();
  clean_pressure = old_pressure * (1 - alpha) + temp_pressure * alpha;

  if (temp_pressure > 5) {
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

  old_pressure = clean_pressure;

  Serial.print(clean_pressure);

  Serial.println();
  delay(50);
}
