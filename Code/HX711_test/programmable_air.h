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

long readPressure(int num=0, int times=1);

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
    neopixel.setPixelColor(i, neopixel.Color(1, 0, 1));
  }
  neopixel.show();
  Serial.println("Pins initialised.");
}

//0-blow, 1-vent, 2-suck

void blow(int i) {
  Serial.print("Blow: ");
  Serial.println(i);
  if (i >= 0 && i <= 2) {
    setValve(i * 3 + 0, OPEN);
    setValve(i * 3 + 1, CLOSE);
    setValve(i * 3 + 2, CLOSE);
  }
}

void vent(int i) {
  Serial.print("Vent: ");
  Serial.println(i);
  if (i >= 0 && i <= 2) {
    setValve(i * 3 + 0, CLOSE);
    setValve(i * 3 + 1, OPEN);
    setValve(i * 3 + 2, CLOSE);
  }
}

void ventQuick(int i) {
  Serial.print("ventQuick: ");
  Serial.println(i);
  if (i >= 0 && i <= 2) {
    setValve(i * 3 + 0, CLOSE);
    setValve(i * 3 + 1, OPEN);
    setValve(i * 3 + 2, OPEN);
  }
}

void suck(int i) {
  Serial.print("Suck: ");
  Serial.println(i);
  if (i >= 0 && i <= 2) {
    setValve(i * 3 + 0, CLOSE);
    setValve(i * 3 + 1, CLOSE);
    setValve(i * 3 + 2, OPEN);
  }
}

void switchOnPump(int num){
  if(num == 1 || num == 2){
    digitalWrite(pump[i-1], HIGH);
  }
}

void switchOffPump(int num){
  if(num == 1 || num == 2){
    digitalWrite(pump[i-1], LOW);
  }
}

// Read pressure
long readPressure(int num=0, int times=1){
//  Serial.print("reading pressure sensor ");
//  Serial.print(num);
//  Serial.print(" Averaging ");
//  Serial.print(times);
//  Serial.println(" times.");

  int64_t tempScaleReading = pressureSensor[num].read_average(times);
  
  if(tempScaleReading>pow(2, 16)){
    tempScaleReading = tempScaleReading - pow(2, 32);
  } 
  long printableScaleReading=tempScaleReading;
  return printableScaleReading;
}
