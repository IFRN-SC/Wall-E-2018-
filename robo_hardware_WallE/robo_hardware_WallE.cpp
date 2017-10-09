#include "robo_hardware_WallE.h"
#include <math.h>

Servo robo_hardware_WallE::servoGarra1;
Servo robo_hardware_WallE::servoGarra2;


robo_hardware_WallE::robo_hardware_WallE():									sensorCor(SENSOR_COR_DIR_POWER, SENSOR_COR_ESQ_POWER),
																sonarFrontal(SONAR_TRIGGER_FRONTAL, SONAR_ECHO_FRONTAL),
																sonarLateral(SONAR_TRIGGER_LATERAL, SONAR_ECHO_LATERAL)
{

}

void robo_hardware_WallE::tensao(float valor_por_cento,int pino){
  float k = 255/100.0;

  if(valor_por_cento < -100) 
    valor_por_cento = -100;	//se o valor passado em valor_por_cento for menor que -100 obriga-se o mmotor a ficar em -100
  if(valor_por_cento >  100) 
    valor_por_cento =  100;	//se o valor passado em valor_por_cento for maior que 100 obriga-se o mmotor a ficar em 100

  float valor_ate_255 = valor_por_cento * k;
  
  analogWrite(pino, abs(valor_ate_255)); 
}


void robo_hardware_WallE::configurar(bool habilitar_garra){
  Serial.begin(9600);

	//Com essas funcoes os sonares sao calibrados 
	//Quanto maior o valor de CALIBRACAO_SONAR menor a inclinacao da curva de calibracao 
	sonarFrontal.setDivisor(CALIBRACAO_SONAR, Ultrasonic::CM);  
	sonarLateral.setDivisor(CALIBRACAO_SONAR, Ultrasonic::CM);
  
	if(habilitar_garra){
  	servoGarra1.attach(SERVO_GARRA_1);
  	servoGarra2.attach(SERVO_GARRA_2);
	}

  pinMode(PWM_RODA_ESQUERDA, OUTPUT); 
  pinMode(PWM_RODA_DIREITA, OUTPUT); 
  pinMode(SENTIDO_RODA_ESQUERDA, OUTPUT); 
  pinMode(SENTIDO_RODA_DIREITA, OUTPUT);

  pinMode(BOTAO, INPUT_PULLUP);
}

boolean robo_hardware_WallE::lerSensorFimDeCurso(){
  return digitalRead(BOTAO); 
}

int robo_hardware_WallE::lerSensorDeLinha(int sensor){
  return analogRead(sensor);
}

void robo_hardware_WallE::acionarMotores(float motor1, float motor2){
 
  if(motor1 < 0){
    digitalWrite(SENTIDO_RODA_ESQUERDA, false);
    tensao(motor1,PWM_RODA_ESQUERDA);  
  }else{
    digitalWrite(SENTIDO_RODA_ESQUERDA, true);
    motor1 = 100 - motor1;
    tensao(motor1,PWM_RODA_ESQUERDA);  
  }
  
  if(motor2 < 0){
    digitalWrite(SENTIDO_RODA_DIREITA, false);
    tensao(motor2,PWM_RODA_DIREITA);  
  }else{
    digitalWrite(SENTIDO_RODA_DIREITA, true);
    motor2 = 100 - motor2;
    tensao(motor2,PWM_RODA_DIREITA);  
  }
    
}

float robo_hardware_WallE::lerSensorSonarFrontal(){
	long microsec = sonarFrontal.timing();
	return sonarFrontal.convert(microsec, Ultrasonic::CM);  //retorna a distância do sensor ao obstáculo em cm.
}

float robo_hardware_WallE::lerSensorSonarLateral(){
	long microsec = sonarLateral.timing();
	return sonarLateral.convert(microsec, Ultrasonic::CM);  //retorna a distância do sensor ao obstáculo em cm.
}

void robo_hardware_WallE::acionarServoGarra1(float angulo){
  servoGarra1.write(angulo);
}

void robo_hardware_WallE::acionarServoGarra2(float angulo){
  servoGarra2.write(angulo);
}

HSV robo_hardware_WallE::getHSV_Esquerdo(){
  return sensorCor.getHSV_esquerdo();
}

HSV robo_hardware_WallE::getHSV_Direito(){
  return sensorCor.getHSV_direito();
}

RGB robo_hardware_WallE::getRGB_Esquerdo(){
  return sensorCor.getRGB_esquerdo();
}

RGB robo_hardware_WallE::getRGB_Direito(){
  return sensorCor.getRGB_direito();
}

void  robo_hardware_WallE::salvarCalibracao(calibracao_dados calibraca_val){
	EEPROM.put(ENDERECO_EEPROM, calibraca_val);
}

void robo_hardware_WallE::lerCalibracao(calibracao_dados &cal){
	EEPROM.get(ENDERECO_EEPROM, cal);
}
