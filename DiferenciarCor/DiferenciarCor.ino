#include "SensoresWallE.h"

Sensores sensor;

void setup() {
  Serial.begin(9600);
  robo.configurar(false);
  sensor.Menu_calibrar();

}

void loop() {

  if (sensor.corEsq_branco()) {
    Serial.print("BRANCO ESQ   ");
  }
  else if (sensor.corEsq_preto()) {
    Serial.print("PRETO ESQ   ");
  }
  else if (sensor.corEsq_verde()){
    Serial.print("VERDE ESQ   ");
  }
  else {
    Serial.print("NAOSEI ESQ   ");
  }

  HSV leituraSensorCor = robo.getHSV_Esquerdo();
  Serial.print(leituraSensorCor.h);
  Serial.print(", ");
  Serial.print(leituraSensorCor.s);
  Serial.print(", ");
  Serial.print(leituraSensorCor.v);
  
  
  Serial.println("    |    ");
/*
  if (sensor.corDir_branco()) {
    Serial.print("BRANCO DIR  ");
  }
  else if (sensor.corDir_preto()) {
    Serial.print("PRETO  DIR  ");
  }
  else if (sensor.corDir_verde()){
    Serial.print("VERDE DIR   ");
  }
  else {
    Serial.print("NAOSEI    ");
  }

  HSV leituraSensorCor2 = robo.getHSV_Direito();
  Serial.print(leituraSensorCor2.h);
  Serial.print(", ");
  Serial.print(leituraSensorCor2.s);
  Serial.print(", ");
  Serial.print(leituraSensorCor2.v);
  Serial.println();*/
}
