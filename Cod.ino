#include <cor.h>
#include <pinagem.h>
#include <robo_hardware.h>
#include <Ultrasonic.h>
#include <SensoresWallE.h>

Sensores sensor;

void setup(){
  Serial.begin(9600);
  robo.configurar(false);
  sensor.Menu_calibrar();
  
}

void loop(){

    if(sensor.sonar_frontal() <= 8){
      robo.acionarMotores(0, 0);
      delay(300);
       
      robo.acionarMotores(-50, 50);
      delay(600);
    
      while (!sensor.preto_preto_preto_preto()){
        robo.acionarMotores(-35, -35);
        
        if (sensor.branco_branco_branco_preto() ||
        sensor.branco_branco_preto_preto() ||
        sensor.branco_preto_preto_preto()) 
        {
          robo.acionarMotores(-35, 0); 
        }
        else if (sensor.preto_branco_branco_branco() ||
        sensor.preto_preto_branco_branco() ||
        sensor.preto_preto_preto_branco()) 
        {
          robo.acionarMotores(0, -35); 
        }
        
      }

      robo.acionarMotores(40, 40);
      delay(1200);

      robo.acionarMotores(40, -40);
      delay(850);

      robo.acionarMotores(40, 40);
      delay(1700);

      robo.acionarMotores(40, -40);
      delay(850);

      while (sensor.branco_branco_branco_branco()){
        robo.acionarMotores(35, 35);
      }

      robo.acionarMotores(35, 35);
      delay(250);

      while (!(sensor.Dir_Preto())){
        robo.acionarMotores(-35, 35);
      }
    }
    

  if(sensor.branco_branco_branco_branco()){
    robo.acionarMotores(40, 40);
  }

  else if(sensor.branco_preto_branco_branco() ||
  sensor.preto_branco_branco_branco() ||
  sensor.preto_preto_branco_branco()  || 
  sensor.preto_preto_preto_branco()){
           
    robo.acionarMotores(-40, 40);
  }
  
  else if(sensor.branco_branco_preto_branco() ||
  sensor.branco_branco_branco_preto() ||
  sensor.branco_branco_preto_preto() ||
  sensor.branco_preto_preto_preto()){
    
    robo.acionarMotores(40, -40);
  } 
}                                
                                                                                                                

