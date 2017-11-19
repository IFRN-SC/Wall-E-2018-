#include "sensor_refletancia.h"


SensorRefletancia::SensorRefletancia(int sensor){
  pinoSensor = sensor;
  media = facaMedia(menorValor,maiorValor); 

}
SensorRefletancia::SensorRefletancia(int sensor,int maiorValorConst, int menorValorConst){
  pinoSensor = sensor;
  media = facaMedia(maiorValorConst,menorValorConst);
}
  
boolean SensorRefletancia::ehBranco(){
  int valor = robo.lerSensorDeLinha(pinoSensor);
  if(valor < media){
    return true;
  }else{
    return false;
  }
}

boolean SensorRefletancia::ehPreto(){
int valor = robo.lerSensorDeLinha(pinoSensor);
  if(valor > media){
    return true;
  }else{
    return false;
  }
}

int SensorRefletancia::getLuz(){
  return robo.lerSensorDeLinha(pinoSensor);
}

float SensorRefletancia::facaMedia(int num1, int num2){
  return (num1 * 0.7) + (num2 * 0.3 );
}

void SensorRefletancia::calibrar(int maiorValorCalibr, int menorValorCalibr){
  media = facaMedia(maiorValorCalibr, menorValorCalibr);
  cali_val.preto_refletancia = maiorValorCalibr;
  cali_val.branco_refletancia = menorValorCalibr;
}
