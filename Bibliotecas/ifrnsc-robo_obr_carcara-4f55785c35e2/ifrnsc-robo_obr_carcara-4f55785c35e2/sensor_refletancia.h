#ifndef SENSOR_REFLETANCIA_H
#define SENSOR_REFLETANCIA_H

#include "robo_hardware.h"
//#include "calibracao.h"

class SensorRefletancia{

public:
  SensorRefletancia(int sensor);
  SensorRefletancia(int sensor, int maiorValorConst, int menorValorConst);
  
  int getLuz();  
  boolean ehBranco();
  boolean ehPreto();
  void calibrar(int maiorValorCalibr, int menorValorCalibr);
  inline float getMedia(){return media;}
  inline void setMedia(float m){media = m;}
  inline Valores_cali_refletancia getCaliVal(){return cali_val;}
  
private:
  float facaMedia(int num1, int num2);
  int maiorValor = 1000;
  int menorValor = 1000;
  int pinoSensor;
  float media;
  
  Valores_cali_refletancia cali_val;
  

};


#endif

