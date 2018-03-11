#include "cor.h"
#include <math.h>
SensorCor::SensorCor(int s2_dado, int s3_dado, int out_dado){
  s2 = s2_dado;
  s3 = s3_dado;
  out = out_dado;

  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);   
  	 
}

void SensorCor::atualizarRGB(){
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  rgb.vermelho = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  

  digitalWrite(s3, HIGH);  
  rgb.azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  


  digitalWrite(s2, HIGH);    
  rgb.verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 

}

RGB SensorCor::getRGB(){
  atualizarRGB();
  return rgb;
}

int SensorCor::calculeMaximo(int vermelho, int verde, int azul){
  int Maximo = 0; 
  if(verde >= vermelho && verde >= azul){
    Maximo = verde;
  }else if(vermelho >= verde && vermelho >= azul){
    Maximo = vermelho;
  }else if(azul >= verde && azul >= vermelho){
    Maximo = azul;
  }
  return Maximo;
}

int SensorCor::calculeMinimo(int vermelho, int verde, int azul){
  int Minimo = 0;
  if(verde <= vermelho && verde <= azul){
    Minimo = verde;
  }else if(vermelho <= verde && vermelho <= azul){
    Minimo = vermelho;
  }else if(azul <= verde && azul <= vermelho){
    Minimo = azul;
  }
  return Minimo;
}

HSV SensorCor::getHSVSemFiltro(){
  int cont = 0;
  float Maximo = 0;
  float Minimo = 0;
  
  float vermelho = 0 ;
  float azul = 0; 
  float verde = 0; 
  while(cont < NUMERO_FILTRAGEM){

    atualizarRGB();
    vermelho = vermelho + rgb.vermelho;
    azul = azul + rgb.azul;
    verde = verde + rgb.verde;
    
    cont++;
  }
  
  vermelho = vermelho/cont;
  azul = azul/cont;
  verde = verde/cont;  
  
  Minimo = calculeMinimo(vermelho,verde,azul);
  Maximo = calculeMaximo(vermelho,verde,azul);
  
  
  if( abs(Maximo - vermelho) < 0,1 && verde >= azul){
    hsv.h =  60 * (verde - azul)/ (Maximo - Minimo) ; 
  }else if( abs(Maximo - vermelho) < 0,1 && verde < azul){
    hsv.h =  60 * (verde - azul)/(Maximo - Minimo) + 360;
  }else if(abs(Maximo - verde) < 0,1){
    hsv.h =  60 * (azul - vermelho)/(Maximo - Minimo) + 120;
  }else if(abs(Maximo - azul)){
    hsv.h =  60 * (vermelho - verde)/(Maximo - Minimo) + 240;
  }else{
    hsv.h = 5;
  }
  
  hsv.s =  (Maximo - Minimo) / Maximo;
  hsv.v = Maximo;
  return hsv;
}

HSV SensorCor::getHSV(){
  for(int i = 0; i < NUMERO_FILTRAGEM_2; i++){
    hsv = getHSVSemFiltro();
    hsvFiltrado.h += hsv.h;  
    hsvFiltrado.s += hsv.s;
    hsvFiltrado.v += hsv.v;
    
  }
  hsvFiltrado.h = hsvFiltrado.h/NUMERO_FILTRAGEM_2;
  hsvFiltrado.s = hsvFiltrado.s/NUMERO_FILTRAGEM_2;
  hsvFiltrado.v = hsvFiltrado.v/NUMERO_FILTRAGEM_2;
  
  return hsvFiltrado;

}

int SensorCor::getVerde(){
  return rgb.verde;
}

int SensorCor::getVermelho(){
  return rgb.vermelho;
}

int SensorCor::getAzul(){
  return rgb.azul;
}
