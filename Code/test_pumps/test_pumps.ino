// Programmable Air
// Author: tinkrmind
// github.com/tinkrmind/programmable-air
// 
// Controls the onboard pump of master board to switch then on anf off alternatively.
//

#define pumpA A3
#define pumpB 7

void setup() {                
  pinMode(pumpA, OUTPUT);     
  pinMode(pumpB, OUTPUT);     
}

void loop() {
  digitalWrite(pumpA, HIGH);   
  digitalWrite(pumpB, LOW);   
  delay(1000);               
  digitalWrite(pumpA, LOW);    
  digitalWrite(pumpB, HIGH);  
  delay(1000);               
}
