#include "HX711.h"

  HX711 scale(2,  13, 32);    
//HX711 scale(DT, SCK);

void setup() {
  Serial.begin(115200);
}

void loop() {
  int64_t tempScaleReading =scale.read();
  
  if(tempScaleReading>pow(2, 16)){
    tempScaleReading = tempScaleReading - pow(2, 32);
  } 
  int32_t printableScaleReading=tempScaleReading;
  Serial.println(printableScaleReading);
  
  delay(50);  
}
