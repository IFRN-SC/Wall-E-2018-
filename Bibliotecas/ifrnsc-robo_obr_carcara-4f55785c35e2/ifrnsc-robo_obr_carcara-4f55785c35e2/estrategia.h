#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include "sensores.h"
#include "movimento.h"
#include "menu.h"

#define DISTANCIA_OBSTACULO 6

class estrategia{
private:
  
  
  
  #define ESQUERDA 'z'
  #define DIREITA 'x'

  movimento mover;
  sensores sensor;
  menu  m;
  
  boolean lado_linha = false;
  boolean rampa = false;


public:

  
  HSV getHSVBrancoDireito(){return sensor.getHSVBrancoDireito();}
  HSV getHSVPretoDireito(){return sensor.getHSVPretoDireito();}
  HSV getHSVVerdeDireito(){return sensor.getHSVVerdeDireito();}
  HSV getHSVCinzaDireito(){return sensor.getHSVCinzaDireito();}
  
  HSV getHSVBrancoEsquerdo(){return sensor.getHSVBrancoEsquerdo();}
  HSV getHSVPretoEsquerdo(){return sensor.getHSVPretoEsquerdo();}
  HSV getHSVVerdeEsquerdo(){return sensor.getHSVVerdeEsquerdo();}
  HSV getHSVCinzaEsquerdo(){return sensor.getHSVCinzaEsquerdo();}
  
  estrategia();
  
  void configura();
  
  void siga_linha();
  void procure_linha();
  void passe_encruzilhada_esquerda();
  void passe_encruzilhada_direita();
  
  boolean vejo_obstaculo(int distancia_dada, int distancia_obstaculo);
  boolean vejo_rampa();
  void suba_rampa();
  
  void passe_obstaculo();
  void alinhe();
  
  void run(); 
  
 
 // inline void iniciar_menu(){m.executar(); sensor = m.get_sensores();}  
};

#endif
