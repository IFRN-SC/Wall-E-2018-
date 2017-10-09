#include <cor.h>
#include <pinagem.h>
#include <robo_hardware.h>
#include <Ultrasonic.h>

//#define ESQUERDO 1
//#define DIREITO 0

// ************* PINAGEM *******************//

// ************* REFLETÂNCIA *****************//
//      ESQUERDO : A0
//      ESQUERDO2 : A1
//      DIREITO : A2
//      DIREITO2 : A3    
//********************************************//


//************* MOTORES *********************//
//    MOTOR1: 
//    pino1 PWM_RODA_DIREITA   6
//    pino2 SENTIDO_RODA_DIREITA  7

//    MOTOR2:
//pino1 PWM_RODA_ESQUERDA   5
//pino2 SENTIDO_RODA_ESQUERDA 4
//*****************************************//


//*********** SONAR ***************//
//  SONAR_TRIGGER_FRONTAL  2
//  SONAR_ECHO_FRONTAL    3
//*********************************//

//***********************************************//
#include <cor.h>
#include <pinagem.h>
#include <robo_hardware.h>  
#include <Ultrasonic.h>

#define BRA_PRE_DIR 23
#define BRA_PRE_ESQ 25
#define BRA_PRE_ESQ2 18
#define BRA_PRE_DIR2 25



void setup(){
  robo.configurar(false);
}

void loop(){

  float RefletESQ = robo.lerSensorLinhaEsq();
  float RefletESQ2 = robo.lerSensorLinhaEsq2();
  float RefletDIR = robo.lerSensorLinhaDir();
  float RefletDIR2 = robo.lerSensorLinhaDir2();
  
  int cont;

  bool maisEsq_Branco = (RefletESQ2 > BRA_PRE_ESQ2); // Mais esquerdo branco
  bool maisEsq_Preto = (RefletESQ2 < BRA_PRE_ESQ2);  // Mais esquerdo preto
  bool Esq_Branco = (RefletESQ > BRA_PRE_ESQ);       // Esquerdo branco
  bool Esq_Preto = (RefletESQ < BRA_PRE_ESQ);        // Esquerdo preto
  bool Dir_Branco = (RefletDIR > BRA_PRE_DIR);       // Dreito branco
  bool Dir_Preto = (RefletDIR < BRA_PRE_DIR);        // Direito preto
  bool maisDir_Branco = (RefletDIR2 > BRA_PRE_DIR);  // Mais direito branco
  bool maisDir_Preto = (RefletDIR2 < BRA_PRE_DIR);   // Mais direito preto

/************************OBSTÁCULO**************************/
    float valor_sensor_frontal = robo.lerSensorSonarFrontal(); 
    float acm;
    
    for (int cont; cont < 10; cont++){
      float leitura = robo.lerSensorSonarFrontal();
      acm = acm + leitura;
    }

    valor_sensor_frontal = (acm/10);
    
    int velDir = 30; 
    int velEsq = 30;
    
    if(valor_sensor_frontal <= 6){
      robo.acionarMotores(-50, 50);
      delay(1000);

      while (maisEsq_Branco && Esq_Branco && Dir_Branco && maisDir_Branco){
        robo.acionarMotores(-30, -30);
      }

      robo.acionarMotores(40, 40);
      delay(1200);

      robo.acionarMotores(40, -40);
      delay(1000);

      robo.acionarMotores(40, 40);
      delay(1200);

      robo.acionarMotores(-40, 40);
      delay(1000);

      while (maisEsq_Branco && Esq_Branco && Dir_Branco && maisDir_Branco){
        robo.acionarMotores(30, 30);
      }

      robo.acionarMotores(30, 30);
      delay(400);

      while (Dir_Branco){
        robo.acionarMotores(-30, 30);
      }
    }

/************************OBSTÁCULO**************************/      


//****************SEGUIR LINHA******************//
  

//**********************************************//
  
  
  if(maisEsq_Branco && Esq_Branco && Dir_Branco && maisDir_Branco) { // Todos branco
      robo.acionarMotores(40, 40);
  }
                                                                                                                  
  else if(maisEsq_Preto && Esq_Preto && Dir_Preto && maisDir_Preto) { // Todos preto
      robo.acionarMotores(40, 40);
  }                                                                                                                
  
  else if(maisEsq_Branco && Esq_Branco && Dir_Preto && maisDir_Preto){
      robo.acionarMotores(50, -50);
      cont = 1;
  }
   
  else if(maisEsq_Preto && Esq_Preto && Dir_Branco && maisDir_Branco){
      robo.acionarMotores(-50, 50);
      cont = 0;
    }

  else if(maisEsq_Branco && Esq_Preto && Dir_Branco && maisDir_Branco){
      robo.acionarMotores(-50, 50);
      cont = 0;
   }

  else if(maisEsq_Branco && Esq_Branco && Dir_Preto && maisDir_Branco){
      robo.acionarMotores(50, -50);
      cont = 1;
    }
    
    else if(maisEsq_Branco && Esq_Preto && Dir_Preto && maisDir_Preto){
       if(cont = 0){
        robo.acionarMotores(-60, 40);
      }
      else if (cont = 1){
        robo.acionarMotores(40, -60);
      }
      
    }

    else if(maisEsq_Preto && Esq_Branco && Dir_Preto && maisDir_Branco){
      robo.acionarMotores(50, -50);
      if(cont = 0){
        robo.acionarMotores(-60, 40);
      }
      else if (cont = 1){
        robo.acionarMotores(40, -60);
      }
    }

    else if(maisEsq_Branco && Esq_Preto && Dir_Branco && maisDir_Preto){
      robo.acionarMotores(-50, 50);
      if(cont = 0){
        robo.acionarMotores(-60, 40);
      }
      else if (cont = 1){
        robo.acionarMotores(40, -60);
      }
    }
    
    else if(maisEsq_Preto && Esq_Preto && Dir_Preto && maisDir_Branco){
       if(cont = 0){
        robo.acionarMotores(-60, 40);
      }
      else if (cont = 1){
        robo.acionarMotores(40, -60);
      }
      
    }
    

  else if(maisEsq_Branco && Esq_Preto && Dir_Preto && maisDir_Branco){
      if(cont = 0){
        robo.acionarMotores(-40, 60);
      }
      else if (cont = 1){
        robo.acionarMotores(60, -40);
      }
      
    }
}                                
                                                                                                                

