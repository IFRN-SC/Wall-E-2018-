#include <Arduino.h>

class Encoder{
  #define VEL_MAX_ENCODER_POR_MILI_SEGUNDOS 1.9
  #define NUM_MAX_PULSOS_POR_ROTACAO 341.2  //11 pulsos do encoder vezes reducao de 34.02
  #define _360_GRAUS 360
  
  const byte pino_interrupcao;
  const byte pino2;
  byte Encoder_C1Last;
   //Variaveis modificadas na interrupcao 
   //Volatile indica ao compilador que o mesmo nao pode fazer otimizacoes nessa variavel que atrapalhariam a interrupcao 
  volatile long duracao;
  volatile boolean Direcao;
  
  double velocidade=0; //velocidade em pusos/segundo
  unsigned long tempo_ant=0;
  long duracao_ant=0;
  const int amostragem_vel=10; //tempo de amostragem em milesegundos 
  
  float angulo_absoluto_anterior;
  float angulo_relativo;
  
  
  public:
  inline void config(){pinMode(pino2, INPUT);}
  Encoder(byte pino_interrupcao, byte pino2);
  void calculapulso();
  
  inline void resetDuracao(){duracao=0;}
  inline long getDuracao()const{return duracao;}
  inline boolean getDirecao()const{return Direcao;}
  //inline void setAmostragemVel(int amostragem){amostragem_vel = amostragem;}
  inline int getPinoInterrupcao()const{return pino_interrupcao;}
  
  inline float getAnguloAbsoluto()const {return (duracao/NUM_MAX_PULSOS_POR_ROTACAO) * _360_GRAUS; }
  float getAnguloRelativo();
  void CalculaAnguloRelativo();
  
  inline double getVelocidade()const{return velocidade;}
  
  void calculaVelocidade();

};
