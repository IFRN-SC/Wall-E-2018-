#ifndef SENSORES_H
#define SENSORES_H

#include "robo_hardware.h"
#include "sensor_refletancia.h"
#include "sensor_cor.h"

#define BRANCO 1
#define PRETO 2
#define VERDE 3



class sensores{//:public calibracao{

 SensorRefletancia sensorEsquerdo, sensorMaisEsquerdo, sensorDireito, sensorMaisDireito;
 SensorDeCor corDireito, corEsquerdo;
 
 calibracao_dados calibracao_val;
 
 
public:  

  HSV getHSVBrancoDireito(){return corDireito.getHSVBranco();}
  HSV getHSVPretoDireito(){return corDireito.getHSVPreto();}
  HSV getHSVVerdeDireito(){return corDireito.getHSVVerde();}
  HSV getHSVCinzaDireito(){return corDireito.getHSVCinza();}
  
  HSV getHSVBrancoEsquerdo(){return corDireito.getHSVBranco();}
  HSV getHSVPretoEsquerdo(){return corDireito.getHSVPreto();}
  HSV getHSVVerdeEsquerdo(){return corDireito.getHSVVerde();}
  HSV getHSVCinzaEsquerdo(){return corDireito.getHSVCinza();}
  
  
  char zona_resgate;
  
  sensores();
  boolean configura(boolean realizar_cali);
 
  boolean branco_branco_branco_branco();
  boolean preto_preto_preto_preto();
  
  boolean branco_preto_branco_branco();
  boolean branco_branco_preto_branco();
  boolean preto_branco_branco_branco();
  boolean branco_branco_branco_preto();
  
  boolean preto_preto_branco_branco();
  boolean branco_branco_preto_preto();
  boolean branco_preto_preto_branco();
  boolean preto_branco_branco_preto();
  boolean preto_branco_preto_branco();
  boolean branco_preto_branco_preto();
  
  boolean preto_preto_preto_branco();
  boolean branco_preto_preto_preto();
  boolean preto_preto_branco_preto();
  boolean preto_branco_preto_preto();
  

  void luz();  
  inline boolean eh_preto_esquerdo(){return (sensorEsquerdo.ehPreto());}//robo.getHSVEsquerdo()));}//return (sensorEsquerdo.ehPreto());}
  inline boolean eh_branco_esquerdo(){return (sensorEsquerdo.ehBranco());}//robo.getHSVEsquerdo()));}// return(determine_cor() == BRANCO);}
  
  inline boolean eh_preto_cor_esquerdo(){return (corEsquerdo.ehPreto(robo.getHSVEsquerdo()));}
  inline boolean eh_verde_esquerdo(){return (corEsquerdo.ehVerde(robo.getHSVEsquerdo()));}
  //inline boolean eh_cinza_esquerdo(){return (corEsquerdo.ehCinza(robo.getHSVEsquerdo()));}
  
  inline boolean eh_preto_direito(){return (sensorDireito.ehPreto());}//robo.getHSVDireito()));}//return() ;}
  inline boolean eh_branco_direito(){return (sensorDireito.ehBranco());}//robo.getHSVDireito()));}//return();}
  
  inline boolean eh_preto_cor_direito(){return (corDireito.ehPreto(robo.getHSVDireito()));}
  inline boolean eh_verde_direito(){return (corDireito.ehVerde(robo.getHSVDireito()));}
  //inline boolean eh_cinza_direito(){return (corDireito.ehCinza(robo.getHSVDireito()));}
  
  inline boolean eh_preto_mais_esquerdo(){return (sensorMaisEsquerdo.ehPreto());}
  inline boolean eh_branco_mais_esquerdo(){return (sensorMaisEsquerdo.ehBranco());}
  
  inline boolean eh_preto_mais_direito(){return (sensorMaisDireito.ehPreto());}
  inline boolean eh_branco_mais_direito(){return (sensorMaisDireito.ehBranco());}  
  //void calibrar();
  boolean fim_de_curso_apertado();

  int distancia_lado();
  int distancia_frente();

private:
  void calibrar();
  void espereCor();
  void lerCalibracao();
  
  HSV hsv_esquerdo;
  HSV hsv_direito;
  
  boolean expor_v_esquerdo = false;
  boolean expor_v_direito = false;
};


#endif
