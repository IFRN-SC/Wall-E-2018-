
//nesse arquivo as funcoes devem ser somente declaradas
#ifndef ROBO_HARDWARE_H
#define ROBO_HARDWARE_H

#include "Ultrasonic.h"
#include <Arduino.h>
#include <Servo.h>
#include "encoder.h"

#include "cor.h"
#include "pinagem.h"

#include "EEPROM2.h"


struct Valores_cali_cor{
  HSV branco;
  HSV preto;
  HSV cinza;
  HSV verde;
};

struct Valores_cali_refletancia {
  int preto_refletancia;
  int branco_refletancia;
};

struct calibracao_dados{
         
        Valores_cali_refletancia mais_esq_refletancia;
        Valores_cali_refletancia esq_refletancia;
        Valores_cali_refletancia dir_refletancia;
        Valores_cali_refletancia mais_dir_refletancia;
  
        Valores_cali_cor direito_cor;
        Valores_cali_cor esquerdo_cor;
        
        char zona; 

};

class robo_hardware:private pinagem{
private:

  #define LIMITADOR_MOTOR 0.85
  #define MAX_10_BITS 1023.0
  #define ENDERECO_EEPROM 0 
  
public: 

  robo_hardware();
  void configurar();
  boolean lerSensorFimDeCurso();
  int lerSensorDeLinha(int sensor);
  int distanciaFrente();
  int distanciaLado();
  void acionarMotores(float motor1, float motor2);
  void acionarServoGarra1(float angulo);
  void acionarServoGarra2(float angulo);
  
  SensorCor corDireita;
  SensorCor corEsquerda;
  
  HSV getHSVEsquerdo();
  RGB getRGBEsquerdo();
  HSV getHSVDireito();
  RGB getRGBDireito();
  
  void salvarCalibracao(calibracao_dados cal);  
  void lerCalibracao(calibracao_dados &cal);
  
  inline const Encoder& getEncoderDir(){return encoderDir;}
  inline const Encoder& getEncoderEsq(){return encoderEsq;}
  
  inline static void calculaEncoderDir(){encoderDir.calculapulso();}
  inline static void calculaEncoderEsq(){encoderEsq.calculapulso();}

  void led_azul(boolean estado);
  void led_amarelo(boolean estado);
  void led_vermelho(boolean estado);
  
  boolean lerBotaoA();
  boolean lerBotaoB();
  boolean lerBotaoC();
  
  
private:
  
  Ultrasonic ultrasonic_frente;
  Ultrasonic ultrasonic_lado;
  static Servo servoGarra1;
  static Servo servoGarra2;
  void tensao(float valor_por_cento,int pino);
  static Encoder encoderDir;
  static Encoder encoderEsq;
  //SensorCor cor_direita(s2,s3, out);  
  

};

static robo_hardware robo;

#endif
