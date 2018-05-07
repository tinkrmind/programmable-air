#include <Adafruit_NeoPixel.h>
#include "HX711.h"

const int pump[2] = {10, 11};

#define OPEN 1
#define CLOSE 0
// vacuum, atmosphere, pressure
const int valve[9] = {  9, 8, 7,  \
                        5, 4, A4, \
                        A0, A1, A2
                     };

const int sense[3] = {6, A5, A3};

float readPressure(int num = 0, int times = 1);

HX711 pressureSensor1;
//HX711 scale(DT, SCK);

HX711 pressureSensor[3] = {
  HX711(sense[0],  SCK, 32),
  HX711(sense[1],  SCK, 32),
  HX711(sense[2],  SCK, 32)
};
//HX711 sensor(DT, SCK);

#define SCK 13

#define neopixelPin 12
#define btn1 2
#define btn2 3

Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(3, neopixelPin, NEO_GRB + NEO_KHZ800);

#define DEBUG 0

void initializePins() {
  for (int i = 0; i < 9; i++) {
    pinMode(valve[i], OUTPUT);
    digitalWrite(valve[i], LOW);
  }

  pinMode(SCK, OUTPUT);

  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);

  for (int i = 0; i < 2; i++) {
    pinMode(pump[i], OUTPUT);
    digitalWrite(pump[i], LOW);
  }

  neopixel.begin();
  for (int i = 0; i < 3; i++) {
    neopixel.setPixelColor(i, neopixel.Color(5, 0, 5));
  }
  neopixel.show();
  neopixel.show();

  pressureSensor1.begin(A5,  13, 32);

  pressureSensor1.set_scale(2280.f);
  pressureSensor1.tare();

  Serial.println("Pins initialised.");
}

void setValve(int number, int position) {
  if (number >= 0 && number < 9) {
    if (position == OPEN) {
      digitalWrite(valve[number], HIGH);
    }

    if (position == CLOSE) {
      digitalWrite(valve[number], LOW);
    }
  }
}

void setAllValves(int position) {
  if (position == OPEN) {
    for (int i = 0; i < 9; i++) {
      digitalWrite(valve[i], HIGH);
    }
  }

  if (position == CLOSE) {
    for (int i = 0; i < 9; i++) {
      digitalWrite(valve[i], LOW);
    }
  }
}

//0-blow, 1-vent, 2-suck

void blow(int i) {
  if (DEBUG) {
    Serial.print("Blow: ");
    Serial.println(i);
  }
  if (i >= 1 && i <= 3) {
    i = i - 1;
    setValve(i * 3 + 0, OPEN);
    setValve(i * 3 + 1, CLOSE);
    setValve(i * 3 + 2, CLOSE);
  }
}

void vent(int i) {
  if (DEBUG) {
    Serial.print("Vent: ");
    Serial.println(i);
  }
  if (i >= 1 && i <= 3) {
    i = i - 1;
    setValve(i * 3 + 0, CLOSE);
    setValve(i * 3 + 1, OPEN);
    setValve(i * 3 + 2, CLOSE);
  }
}

void ventQuick(int i) {
  if (DEBUG) {
    Serial.print("ventQuick: ");
    Serial.println(i);
  }
  if (i >= 1 && i <= 3) {
    i = i - 1;
    setValve(i * 3 + 0, CLOSE);
    setValve(i * 3 + 1, OPEN);
    setValve(i * 3 + 2, OPEN);
  }
}

void suck(int i) {
  if (DEBUG) {
    Serial.print("Suck: ");
    Serial.println(i);
  }
  if (i >= 1 && i <= 3) {
    i = i - 1;
    setValve(i * 3 + 0, CLOSE);
    setValve(i * 3 + 1, CLOSE);
    setValve(i * 3 + 2, OPEN);
  }
}

void closeAll(int i) {
  if (DEBUG) {
    Serial.print("Close all: ");
    Serial.println(i);
  }
  if (i >= 1 && i <= 3) {
    i = i - 1;
    setValve(i * 3 + 0, CLOSE);
    setValve(i * 3 + 1, CLOSE);
    setValve(i * 3 + 2, CLOSE);
  }
}

void switchOnPump(int num) {
  if (num == 1 || num == 2) {
    digitalWrite(pump[num - 1], HIGH);
  }
}

void switchOffPump(int num) {
  if (num == 1 || num == 2) {
    digitalWrite(pump[num - 1], LOW);
  }
}

float readPressure(int num = 0, int times = 1) {
  float pressure = pressureSensor1.get_units(times);
  return pressure;
}

