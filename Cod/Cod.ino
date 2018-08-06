#include "Estrategia.h"
//#include "Botao.h"

Estrategia estrategia;


void setup(){
  Serial.begin(9600);
  robo.configurar(true);
  //estrategia.configurar();
  estrategia.calibrar();
}

void loop(){
  estrategia.executar();
}                                
                                                                                                               

//angelo.reset(obr2020, true);**-123 
