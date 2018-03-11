#include "movimento.h"


movimento::movimento(){ 
}

void movimento::no_eixo_para_esquerda(){robo.acionarMotores(-50,50);}
void movimento::no_eixo_para_direita(){robo.acionarMotores(50,-50);}
void movimento::andar_so_esquerda(){robo.acionarMotores(50,0);}
void movimento::andar_so_direita(){robo.acionarMotores(0,50);}


void movimento::andar_frente(){
  robo.acionarMotores(35,40);
}
void movimento::andar_tras(){
  robo.acionarMotores(-50,-50);
}
void movimento::enrolar_esquerda(){
  robo.acionarMotores(-45,55);
}
void movimento::enrolar_direita(){
  robo.acionarMotores(55,-45);
}
void movimento::parar(){
  robo.acionarMotores(0,0);
}



