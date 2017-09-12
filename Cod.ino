#include <cor.h>
#include <pinagem.h>
#include <robo_hardware.h>
#include <Ultrasonic.h>

// *************PI PI PI PINAGEM *******************//

// *************RE RE REFLETÂNCIA *****************//
//      ESQUERDO : A0
//      ESQUERDO2 : A1
//      DIREITO : A2
//      DIREITO2 : A3    
//********************************************//


//************* MO MO MO MOTORES *********************//
//    MOTOR1: 
//    pino1 PWM_RODA_DIREITA   6
//    pino2 SENTIDO_RODA_DIREITA  7

//    MOTOR2:
//pino1 PWM_RODA_ESQUERDA   5
//pino2 SENTIDO_RODA_ESQUERDA 4
//*****************************************//


//***********SO SO SO SONAR ***************//
//  SONAR_TRIGGER_FRONTAL  2
//  SONAR_ECHO_FRONTAL    3
//*********************************//

//***********************************************//
#include <cor.h>
#include <pinagem.h>
#include <robo_hardware.h>  
#include <Ultrasonic.h>

#define BRA_PRE_DIR 27
#define BRA_PRE_ESQ 25
#define BRA_PRE_ESQ2 30
#define BRA_PRE_DIR2 30



void setup(){
  robo.configurar(false);
}

void loop(){

/************************OBSTÁCULO**************************/
//    float valor_sensor_frontal = robo.lerSensorSonarFrontal(); 
//    int velDir = 30; 
//    int velEsq = 30;
    
//    if(valor_sensor_frontal <= 5){

//      robo.acionarMotores(0, 0);
//      delay(300);

//      robo.acionarMotores(-velDir, -velEsq);  
//      delay(300);

//      robo.acionarMotores(velDir, -velEsq);
//      delay(900);

//      robo.acionarMotores(velDir, velEsq);
//      delay(720);

//      robo.acionarMotores(-velDir, velEsq);
//      delay(720);

//      robo.acionarMotores(velDir, velEsq);
//      delay(1510);

//      robo.acionarMotores(-velDir, velEsq);
//      delay(900);

//      robo.acionarMotores(velDir, velEsq);
//      delay(720);

//      robo.acionarMotores(velDir, -velEsq);
//      delay(400);
//    }

/************************OBSTÁCULO**************************/      


//****************SEGUIR LINHA******************//
  

//**********************************************//

  float RefletESQ = robo.lerSensorLinhaEsq();
  float RefletESQ2 = robo.lerSensorLinhaEsq2();
  float RefletDIR = robo.lerSensorLinhaDir();
  float RefletDIR2 = robo.lerSensorLinhaDir2();  

  bool maisEsq_Branco = (RefletESQ2 > BRA_PRE_ESQ2); // Mais esquerdo branco
  bool maisEsq_Preto = (RefletESQ2 < BRA_PRE_ESQ2);  // Mais esquerdo preto
  bool Esq_Branco = (RefletESQ > BRA_PRE_ESQ);       // Esquerdo branco
  bool Esq_Preto = (RefletESQ < BRA_PRE_ESQ);        // Esquerdo preto
  bool Dir_Branco = (RefletDIR > BRA_PRE_DIR);       // Dreito branco
  bool Dir_Preto = (RefletDIR < BRA_PRE_DIR);        // Direito preto
  bool maisDir_Branco = (RefletDIR2 > BRA_PRE_DIR);  // Mais direito branco
  bool maisDir_Preto = (RefletDIR2 < BRA_PRE_DIR);   // Mais direito preto
  
  
  if(maisEsq_Branco && Esq_Branco && Dir_Branco && maisDir_Branco) { // Todos branco
      robo.acionarMotores(70, 70);
  }
                                                                                                                  
  else if(maisEsq_Preto && Esq_Preto && Dir_Preto && maisDir_Preto) { // Todos preto
      robo.acionarMotores(70, 70);
  }                                                                                                                
  
  else if(maisEsq_Branco && Esq_Branco && Dir_Preto && maisDir_Preto){
      robo.acionarMotores(80, -80);
  }
   
  else if(Esq_Preto && maisEsq_Preto && Dir_Branco && maisDir_Branco){
      robo.acionarMotores(-80, 80);
    }

  else if(Esq_Branco && maisEsq_Preto && Dir_Branco && maisDir_Branco){
      robo.acionarMotores(-80, 80);
   }

  else if(Esq_Branco && maisEsq_Branco && Dir_Preto && maisDir_Branco){
      robo.acionarMotores(80, -80);
    }

  else if(Esq_Preto && maisEsq_Preto && Dir_Preto && maisDir_Branco){
      robo.acionarMotores(80, 80);
    }
}                                
                                                                                                                

