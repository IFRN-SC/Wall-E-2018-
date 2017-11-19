#include "sensor_cor.h"

#define AJUSTE_1 5
#define AJUSTE_2 16

SensorDeCor::SensorDeCor(){
/* hsv.h = 100;
 hsv.s = 100;
 hsv.v = 100;
*/
}

void SensorDeCor::calibrar(){
  vCinzaBranco = media(cinza.v,branco.v);
  vBrancoVerde = media(branco.v,verde.v) + AJUSTE_2;
  vVerdePreto = preto.v + 5;
  hVerdePreto = media(preto.h,verde.h) + 10 ;
}

void SensorDeCor::atualizarHSV(HSV hsvAt){
  hsv = hsvAt;
}
boolean SensorDeCor::ehBranco(){
  return (hsv.v > vCinzaBranco && hsv.v < vBrancoVerde);
}
boolean SensorDeCor::ehPreto(){
  return (hsv.v > vBrancoVerde && hsv.v < vVerdePreto);
}
boolean SensorDeCor::ehVerde(){
  return ( hsv.h < hVerdePreto);
}
boolean SensorDeCor::ehCinza(){
  return(hsv.v < vCinzaBranco);
}


boolean SensorDeCor::ehBranco(HSV hsvAt){
  atualizarHSV(hsvAt);
  return ehBranco();
}
boolean SensorDeCor::ehPreto(HSV hsvAt){
  atualizarHSV(hsvAt);
  return ehPreto();
}
boolean SensorDeCor::ehVerde(HSV hsvAt){
  atualizarHSV(hsvAt);
  return ehVerde();
}
boolean SensorDeCor::ehCinza(HSV hsvAt){
  atualizarHSV(hsvAt);
  return ehCinza();
}

// colocanco valores dos sensores de cor 

void SensorDeCor::setBranco(HSV brancoAt){
  branco = brancoAt;
  cali_val.branco = branco;

}
void SensorDeCor::setPreto(HSV pretoAt){ 
  preto = pretoAt; 
  cali_val.preto = preto;
}
void SensorDeCor::setVerde(HSV verdeAt){ 
  verde = verdeAt;
  cali_val.verde = verde;
}
void SensorDeCor::setCinza(HSV cinzaAt){
  cinza = cinzaAt;
  cali_val.cinza = cinza;
}


float SensorDeCor:: media(int num1, int num2){ return (num1 + num2)/2; }
/*
 float vCinzaBranco = 22;
 float vBrancoVerde = 68;
 float hVerdePreto = 32;
*/
