// Programmable Air
// Author: tinkrmind
// github.com/tinkrmind/programmable-air
// v0.3

#define DEBUG 0

#include <Adafruit_NeoPixel.h>

#define INCREASING 1
#define DECREASING -1
#define UN_KNOWN 0

const int pump[2] = {10, 11};
const int pump_sense[2] = {A6, A7};

#define OPEN 1
#define CLOSE 0
// vacuum, atmosphere, pressure
const int valve[9] = {   5,  4,  6,  \
                         8,  7,  9,  \
                         A1, A4, A0
                     };

const int sense[3] = {A3, A2, A5};

int readPressure(int num = 0, int times = 1);

#define neopixelPin 12
const int btn[2] = { 2, 3 };
const int btn1 = 2;
const int btn2 = 3;

Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(3, neopixelPin, NEO_GRB + NEO_KHZ800);

void initializePins() {
  for (int i = 0; i < 9; i++) {
    pinMode(valve[i], OUTPUT);
    digitalWrite(valve[i], LOW);
  }

  pinMode(SCK, OUTPUT);

  pinMode(btn[0], INPUT_PULLUP);
  pinMode(btn[1], INPUT_PULLUP);

  for (int i = 0; i < 2; i++) {
    pinMode(pump[i], OUTPUT);
    digitalWrite(pump[i], LOW);
  }

  neopixel.begin();
  for (int i = 0; i < 3; i++) {
    neopixel.setPixelColor(i, neopixel.Color(1, 0, 1));
  }
  neopixel.show();
  if (DEBUG) {
    Serial.println("Pins initialised.");
  }
}

void setAllValves(int position) {
  if (position == OPEN) {
    for (int i = 0; i < 12; i++) {
      digitalWrite(valve[i], HIGH);
    }
  }

  if (position == CLOSE) {
    for (int i = 0; i < 12; i++) {
      digitalWrite(valve[i], LOW);
    }
  }
}

void setValve(int number, int position) {
  if (position == OPEN) {
    digitalWrite(valve[number], HIGH);
  }

  if (position == CLOSE) {
    digitalWrite(valve[number], LOW);
  }
}

//0-blow, 1-vent, 2-suck
void blow(int i=0) {
  if (DEBUG) {
    Serial.print("Blow: ");
    Serial.println(i);
  }
  if (i >= 0 && i <= 2) {
    setValve(i * 3 + 0, OPEN);
    setValve(i * 3 + 1, CLOSE);
    setValve(i * 3 + 2, CLOSE);
  }
}

void vent(int i=0) {
  if (DEBUG) {
    Serial.print("Vent: ");
    Serial.println(i);
  }
  if (i >= 0 && i <= 2) {
    setValve(i * 3 + 0, CLOSE);
    setValve(i * 3 + 1, OPEN);
    setValve(i * 3 + 2, CLOSE);
  }
}

void ventQuick(int i=0) {
  if (DEBUG) {
    Serial.print("ventQuick: ");
    Serial.println(i);
  }
  if (i >= 0 && i <= 2) {
    setValve(i * 3 + 0, CLOSE);
    setValve(i * 3 + 1, OPEN);
    setValve(i * 3 + 2, OPEN);
  }
}

void suck(int i=0) {
  if (DEBUG) {
    Serial.print("Suck: ");
    Serial.println(i);
  }
  if (i >= 0 && i <= 2) {
    setValve(i * 3 + 0, CLOSE);
    setValve(i * 3 + 1, CLOSE);
    setValve(i * 3 + 2, OPEN);
  }
}

void closeAll(int i=0) {
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

// Read pressure
int readPressure(int num = 0, int times = 1) {
  //  Serial.print("reading pressure sensor ");
  //  Serial.print(num);
  //  Serial.print(" Averaging ");
  //  Serial.print(times);
  //  Serial.println(" times.");

  long pressure = 0;

  for (int i = 0; i < times; i++) {
    pressure += analogRead(sense[num]);
  }
  pressure /= times;

  //  Serial.print("Pressure: ");
  //  Serial.println(pressure);
  return int(pressure);
}

void switchOnPump(int num,  int percentagePower = 100) {
  if (num == 1 || num == 2) {
    analogWrite(pump[num - 1], percentagePower * 255 / 100);
  }
}

void switchOffPump(int num, int percentagePower = 100) {
  if (num == 1 || num == 2) {
    analogWrite(pump[num - 1], percentagePower * 255 / 100);
  }
}
