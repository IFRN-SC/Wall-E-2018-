#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#include "robo_hardware.h"


class movimento{
  

public:
  movimento();
  
  void no_eixo_para_esquerda();
  void no_eixo_para_direita();
  void andar_so_direita();
  void andar_so_esquerda();
  void andar_frente();
  void andar_tras();
  void enrolar_esquerda();
  void enrolar_direita();
  void parar();
  
};

#endif
