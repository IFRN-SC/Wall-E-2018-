#include <Servo.h>
#include "sensores.h"
#include "robo_hardware.h"
#include "estrategia.h"
HSV hsvEsquerdo;
//RGB rgbDireito;
//sensores sensor;
/*float h_media=0;
float v_media=0;
int janela=20;*/

estrategia ex;
///SensorCor teste(S2_DIREITO,S3_DIREITO,OUT_DIREITO);

void setup(){   
  //robo.configurar();
  Serial.begin(9600);
  ex.configura();
  Serial.end();
  delay(1000);
}


void loop(){
  ex.run();
  /*
  //sensor.luz();
  h_media=0;
  for(int i=0; i < janela; i++){
    hsvEsquerdo = teste.getHSV();
    h_media += hsvEsquerdo.h;
    v_media += hsvEsquerdo.v;
  }
  h_media = h_media/janela;
  v_media = v_media/janela;
  //
  //robo.acionarMotores(50,50);
  //Serial.println(robo.distanciaLado());
  Serial.print("h: ");
  Serial.print(h_media);
  Serial.print(" v: ");
  Serial.println(v_media);

  delay(300);
*/

  
}


