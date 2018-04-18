#include "Estrategia.h"
//#include "Botao.h"

Estrategia estrategia;


void setup(){
  Serial.begin(9600);
  robo.configurar(false);
  estrategia.configurar();
  estrategia.calibrar();
}

void loop(){
  estrategia.executar();
}                                
                                                                                                                

