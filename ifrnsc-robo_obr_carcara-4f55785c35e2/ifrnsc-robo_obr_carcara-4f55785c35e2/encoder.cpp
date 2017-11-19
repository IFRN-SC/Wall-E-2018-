#include "encoder.h"

Encoder::Encoder(byte pino_c1, byte pino_c2):
pino_interrupcao(pino_c1), 
pino2(pino_c2)
{
  duracao=0;
}

void Encoder::calculapulso(){
  int Lstate = digitalRead(pino_interrupcao);
  if ((Encoder_C1Last == LOW) && Lstate == HIGH){
    
    int val = digitalRead(pino2);
//    Serial.println(val);
    if (val == LOW && Direcao)    {
      Direcao = false; //Reverse
      
    }
    else if (val == HIGH && !Direcao)    {
           
      Direcao = true;  //Forward
    }
  }
  Encoder_C1Last = Lstate;
 
  if (!Direcao)  duracao--;
  else  duracao++;
}

void Encoder::calculaVelocidade(){
  
  unsigned long tempo_atual = millis();
  unsigned long timeChange = (tempo_atual - tempo_ant);
  if(timeChange>=amostragem_vel){
    velocidade = (duracao - duracao_ant)/((double)(timeChange));
    velocidade = 100*velocidade/VEL_MAX_ENCODER_POR_MILI_SEGUNDOS;
    //Serial.println(duracao);// - duracao_ant);
    duracao_ant = duracao;
    tempo_ant = tempo_atual;

  }
  
}

float Encoder::getAnguloRelativo(){
  CalculaAnguloRelativo();
  return  angulo_relativo; 
}

void Encoder::CalculaAnguloRelativo(){
  float angulo_absoluto_atual = getAnguloAbsoluto();
  
  angulo_relativo = angulo_absoluto_atual - angulo_absoluto_anterior;  
  angulo_absoluto_anterior = angulo_absoluto_atual;
  
}
