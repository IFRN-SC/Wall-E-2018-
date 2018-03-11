
#ifndef SENSOR_COR_H
#define SENSOR_COR_H

#include "robo_hardware.h"
#include "cor.h"

class SensorDeCor{
                 
public:

  void setBranco(HSV brancoAt);
  void setPreto(HSV pretoAt);
  void setVerde(HSV verdeAt);
  void setCinza(HSV cinzaAt);
  
  HSV getHSVBranco(){return branco;} 
  HSV getHSVPreto(){return preto;}  
  HSV getHSVVerde(){return verde;}  
  HSV getHSVCinza(){return cinza;}  
  
 
  SensorDeCor();
  void atualizarHSV(HSV hsvAt);
  void calibrar();
  boolean ehBranco();
  boolean ehPreto();
  boolean ehVerde();
  boolean ehCinza();
  boolean ehBranco(HSV hsvAt);
  boolean ehPreto(HSV hsvAt);
  boolean ehVerde(HSV hsvAt);
  boolean ehCinza(HSV hsvAt);
  
  inline Valores_cali_cor getCaliVal(){return cali_val; }

private:
 Valores_cali_cor cali_val;
 float media(int num1, int num2);

 HSV hsv, branco, preto, verde, cinza;
 
 float vCinzaBranco = 0;
 float vBrancoVerde = 0;
 float vVerdePreto = 0;
 float hVerdePreto = 0;
 
};
#endif
