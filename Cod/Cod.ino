#include "Estrategia.h"
//#include "Botao.h"

Estrategia estrategia;

void setup(){
  Serial.begin(9600);
  robo.configurar(true);
  robo.habilitaTCS34();
  estrategia.calibrar();
}

void loop(){
  estrategia.executar();
}                                
                                                                                                               

//angelo.reset(obr2020, true);**-123

 
