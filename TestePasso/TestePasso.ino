#include "MotorPasso.h"

MotorPasso mp(64,64);

void setup() {
  Serial.begin(9600);
}

void loop() {

 
  mp.acionarMotorPasso(5, -5);
 //mp.acionarMotoresEmGraus(80, 180);
  
 //while(1){mp.acionarAngDir(0, 0);}

}
