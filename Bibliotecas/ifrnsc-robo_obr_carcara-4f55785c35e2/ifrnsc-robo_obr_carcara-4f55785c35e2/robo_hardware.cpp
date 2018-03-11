#include "robo_hardware.h"
#include <math.h>

Servo robo_hardware::servoGarra1;
Servo robo_hardware::servoGarra2;
Encoder robo_hardware::encoderEsq(ENCODER_ESQ_INTERRUPCAO, ENCODER_ESQ);
Encoder robo_hardware::encoderDir(ENCODER_DIR_INTERRUPCAO, ENCODER_DIR);

robo_hardware::robo_hardware():corDireita(S2_DIREITO,S3_DIREITO,OUT_DIREITO),
                               corEsquerda(S2_ESQUERDO,S3_ESQUERDO,OUT_ESQUERDO),
                               ultrasonic_frente(PINO_TRIGGER_FRENTE, PINO_ECHO_FRENTE),
                               ultrasonic_lado(PINO_TRIGGER_LADO, PINO_ECHO_LADO)
                               {
  robo.configurar();
  //leituraTag(SS_PIN, RST_PIN);
  
  

}

void robo_hardware::tensao(float valor_por_cento,int pino){
  float k = 255/100.0;
  float valor_ate_255 = valor_por_cento * k;
  analogWrite(pino, abs(valor_ate_255)); 
}

void robo_hardware::configurar(){
  Serial.begin(9600);
  
  servoGarra1.attach(SERVO_GARRA_1);
  servoGarra2.attach(SERVO_GARRA_2);
/* 
  pinMode(2, OUTPUT);  
  digitalWrite(2, HIGH);
  
  pinMode(3, OUTPUT);  
  digitalWrite(3, HIGH);
*/
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  pinMode(PWM_RODA_ESQUERDA, OUTPUT); 
  pinMode(PWM_RODA_DIREITA, OUTPUT); 
  pinMode(SENTIDO_RODA_ESQUERDA, OUTPUT); 
  pinMode(SENTIDO_RODA_DIREITA, OUTPUT);

  pinMode(BOTAO_A, INPUT);
  pinMode(BOTAO_B, INPUT);
  pinMode(BOTAO_C, INPUT);
  
  attachInterrupt(pinagem::PinoParaInterrupcao(encoderEsq.getPinoInterrupcao()), calculaEncoderEsq, CHANGE);
  attachInterrupt(pinagem::PinoParaInterrupcao(encoderDir.getPinoInterrupcao()), calculaEncoderDir, CHANGE);
  
}

/*boolean robo_hardware::lerSensorFimDeCurso(){
  return digitalRead(BOTAO); 
}*/

int robo_hardware::lerSensorDeLinha(int sensor){
  return analogRead(sensor);
}

void robo_hardware::acionarMotores(float motor1, float motor2){
  motor1 = motor1*LIMITADOR_MOTOR;
  motor2 = motor2*LIMITADOR_MOTOR;
  
   if(motor1 < 0 && motor1 >= -100){
    digitalWrite(SENTIDO_RODA_ESQUERDA, false);
    tensao(motor1,PWM_RODA_ESQUERDA);  
  }else if(motor1 >= 0 && motor1 <= 100){
    digitalWrite(SENTIDO_RODA_ESQUERDA, true);
    motor1 = motor1 - 100;
    tensao(motor1,PWM_RODA_ESQUERDA);  
  }
  
  if(motor2 < 0 && motor2 >= -100){
    digitalWrite(SENTIDO_RODA_DIREITA, false);
    tensao(motor2,PWM_RODA_DIREITA);  
  }else if(motor2 >= 0 && motor2 <= 100){
    digitalWrite(SENTIDO_RODA_DIREITA, true);
    motor2 = motor2 - 100;
    tensao(motor2,PWM_RODA_DIREITA);  
  }
  // teste pra ver se ta ok 
}

void robo_hardware::acionarServoGarra1(float angulo){
  servoGarra1.write(angulo);
}

void robo_hardware::acionarServoGarra2(float angulo){
  servoGarra2.write(angulo);
}

HSV robo_hardware::getHSVEsquerdo(){
  return corEsquerda.getHSV();
}

HSV robo_hardware::getHSVDireito(){
  return corDireita.getHSV();
}

RGB robo_hardware::getRGBEsquerdo(){
  return corEsquerda.getRGB();
}

RGB robo_hardware::getRGBDireito(){
  return corDireita.getRGB();
}

int robo_hardware::distanciaFrente(){
  long microsec = 0;
  float distanciaCm = 0;
  microsec = ultrasonic_frente.timing();
  distanciaCm = ultrasonic_frente.convert(microsec, Ultrasonic::CM);
  return distanciaCm;
}

int robo_hardware::distanciaLado(){
  long microsec = 0;
  float distanciaCm = 0;
  microsec = ultrasonic_lado.timing();
  distanciaCm = ultrasonic_lado.convert(microsec, Ultrasonic::CM);
  return distanciaCm;
}

void  robo_hardware::salvarCalibracao(calibracao_dados calibraca_val){
	EEPROM.put(ENDERECO_EEPROM, calibraca_val);
}

void robo_hardware::lerCalibracao(calibracao_dados &cal){
	EEPROM.get(ENDERECO_EEPROM, cal);
}

void robo_hardware::led_azul(boolean estado){
  digitalWrite(LED_AZUL, estado);
}

void robo_hardware::led_amarelo(boolean estado){
  digitalWrite(LED_AMARELO, estado);
}

void robo_hardware::led_vermelho(boolean estado){
  digitalWrite(LED_VERMELHO, estado);
}

boolean robo_hardware::lerBotaoA(){
  return digitalRead(BOTAO_A);
}

boolean robo_hardware::lerBotaoB(){
  return digitalRead(BOTAO_B);
}

boolean robo_hardware::lerBotaoC(){
  return digitalRead(BOTAO_C);
}
