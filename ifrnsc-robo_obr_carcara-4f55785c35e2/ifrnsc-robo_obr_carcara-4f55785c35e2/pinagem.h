#ifndef PINAGEM_H
#define PINAGEM_H

class pinagem{

   
  #define PWM_RODA_ESQUERDA 7
  #define SENTIDO_RODA_ESQUERDA 6
  
  #define PWM_RODA_DIREITA 4
  #define SENTIDO_RODA_DIREITA 5
  
  #define SERVO_GARRA_1 8
  #define SERVO_GARRA_2 9
  
  #define BOTAO_A 23
  #define BOTAO_B 27
  #define BOTAO_C 39
  
  #define PINO_ECHO_FRENTE 18
  #define PINO_TRIGGER_FRENTE 19
  
  #define PINO_ECHO_LADO 12
  #define PINO_TRIGGER_LADO 11
  
  #define S2_ESQUERDO 50
  #define S3_ESQUERDO 52
  #define OUT_ESQUERDO 48

  #define S2_DIREITO 36
  #define S3_DIREITO 34
  #define OUT_DIREITO 38
  
  

  #define LED_AZUL 49
  #define LED_AMARELO 51
  #define LED_VERMELHO 53
  
  #define ENCODER_DIR_INTERRUPCAO 2
  #define ENCODER_ESQ_INTERRUPCAO 3  
  #define ENCODER_DIR 16
  #define ENCODER_ESQ 17  

  #if !defined(__AVR_ATmega2560__)
    #if defined(ENCODER_DIR_INTERRUPCAO)
      #if ENCODER_DIR_INTERRUPCAO != 2 && ENCODER_DIR_INTERRUPCAO != 3 && ENCODER_DIR_INTERRUPCAO != 18 && ENCODER_DIR_INTERRUPCAO != 19 && ENCODER_DIR_INTERRUPCAO != 20 && ENCODER_DIR_INTERRUPCAO != 21     
        #error: valor de ENCODER_DIR_INTERRUPCAO nao e uma interrupcao 
      #endif
    #endif
    #if defined(ENCODER_ESQ_INTERRUPCAO)
      #if ENCODER_ESQ_INTERRUPCAO != 2 && ENCODER_ESQ_INTERRUPCAO != 3 && ENCODER_ESQ_INTERRUPCAO != 18 && ENCODER_ESQ_INTERRUPCAO != 19 && ENCODER_ESQ_INTERRUPCAO != 20 && ENCODER_ESQ_INTERRUPCAO != 21     
        #error: valor de ENCODER_ESQ_INTERRUPCAO nao e uma interrupcao 
      #endif
    #endif
  #else
    #if defined(ENCODER_DIR_INTERRUPCAO)
      #if ENCODER_DIR_INTERRUPCAO != 3 && ENCODER_DIR_INTERRUPCAO != 2     
        #error: valor de ENCODER_DIR_INTERRUPCAO nao e uma interrupcao 
      #endif
    #endif
    #if defined(ENCODER_ESQ_INTERRUPCAO)
      #if ENCODER_ESQ_INTERRUPCAO != 3 && ENCODER_ESQ_INTERRUPCAO != 2     
        #error: valor de ENCODER_ESQ_INTERRUPCAO nao e uma interrupcao 
      #endif
    #endif    
  #endif  
  
  public:
  //Funcao para converter o pino do arduino para a interrupcao especifica que esta ligada ao pino 
  static int PinoParaInterrupcao(int Pino){
 
    switch (Pino){
      case 2:
        return 0;
      break;
      case 3:
        return 1;
      break;
      #if defined(__AVR_ATmega2560__)
      case 21:
        return 2;
        break;
      case 20:
        return 3;
        break;
      case 19:
        return 4;
        break;
      case 18:
        return 5;
        break;
      #endif
      default:     
        return 0;
      break;
    }
  }

};

#endif
