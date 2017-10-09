#include <robo_hardware.h> 
#include <Servo.h>

//********PINOS PARA SENSORES REFLETANCIA***********//
//
//SENSOR_LINHA_DIREITO2  A0  //Define o pino do sensor de refletancia esquerdo 
//SENSOR_LINHA_DIREITO  A1  //Define o pino do sensor de refletancia direito
//SENSOR_LINHA_ESQUERDO   A2
//SENSOR_LINHA_ESQUERDO2  A3
//
//*********PINOS PARA SENSORES REFLETANCIA*********//

float valor_sensor_dir;
float valor_sensor_esq;
float valor_sensor_esq2;
float valor_sensor_dir2;

float maximoPreto_sensor_dir;
float maximoPreto_sensor_esq;
float maximoPreto_sensor_esq2;
float maximoPreto_sensor_dir2;

float minimoBranco_sensor_dir;
float minimoBranco_sensor_esq;
float minimoBranco_sensor_esq2;
float minimoBranco_sensor_dir2;

float BRA_PRE_DIR;
float BRA_PRE_DIR2;
float BRA_PRE_ESQ;
float BRA_PRE_ESQ2;



HSV leituraSensorCor;
HSV preto;
HSV verde;
HSV branco;
HSV cinza;


void esperarParaLer (){
  while (!Serial.available()){}
}

void calibrarBranco(){

  char escolhaBranco = "";
  
  float valorBranco_sensor_dir;
  float valorBranco_sensor_esq;
  float valorBranco_sensor_esq2;
  float valorBranco_sensor_dir2;

  while (escolhaBranco != 'S') {
    Serial.println("Coloque todos os sensores no BRANCO");
    Serial.println("[C] Para CALIBRAR");
    Serial.println("[S] Para SAIR");
    esperarParaLer();
    escolhaBranco = Serial.read();

    if (escolhaBranco == 'C') {
      valorBranco_sensor_dir = robo.lerSensorLinhaDir();
      valorBranco_sensor_dir2 = robo.lerSensorLinhaDir2();
      valorBranco_sensor_esq = robo.lerSensorLinhaEsq();
      valorBranco_sensor_esq2 = robo.lerSensorLinhaEsq2();

      if (valorBranco_sensor_dir < minimoBranco_sensor_dir) {
        minimoBranco_sensor_dir = valorBranco_sensor_dir;
      }
      
      if (valorBranco_sensor_dir2 < minimoBranco_sensor_dir2) {
        minimoBranco_sensor_dir2 = valorBranco_sensor_dir2;
      }

      if (valorBranco_sensor_esq < minimoBranco_sensor_esq) {
        minimoBranco_sensor_esq = valorBranco_sensor_esq;
      }

      if (valorBranco_sensor_esq2 < minimoBranco_sensor_esq2) {
        minimoBranco_sensor_esq2 = valorBranco_sensor_esq2;
      }
      
          
    }
    else {
      escolhaBranco = 'S';
    }
  }
}

void calibrarPreto(){

  char escolhaPreto = "";
  
  float valorPreto_sensor_dir;
  float valorPreto_sensor_esq;
  float valorPreto_sensor_esq2;
  float valorPreto_sensor_dir2;

  
  while (escolhaPreto != 'S') {
    Serial.println("Coloque todos os sensores no PRETO");
    Serial.println("[C] Para CALIBRAR");
    Serial.println("[S] Para SAIR");
    esperarParaLer();
    escolhaPreto = Serial.read();
    
    if (escolhaPreto == 'C') {
      valorPreto_sensor_dir = robo.lerSensorLinhaDir();
      valorPreto_sensor_dir2 = robo.lerSensorLinhaDir2();
      valorPreto_sensor_esq = robo.lerSensorLinhaEsq();
      valorPreto_sensor_esq2 = robo.lerSensorLinhaEsq2();

      if (valorPreto_sensor_dir > maximoPreto_sensor_dir) {
        maximoPreto_sensor_dir = valorPreto_sensor_dir;
      }
      
      if (valorPreto_sensor_dir2 > maximoPreto_sensor_dir2) {
        maximoPreto_sensor_dir2 = valorPreto_sensor_dir2;
      }

      if (valorPreto_sensor_esq > maximoPreto_sensor_esq) {
        maximoPreto_sensor_esq = valorPreto_sensor_esq;
      }

      if (valorPreto_sensor_esq2 > maximoPreto_sensor_esq2) {
        maximoPreto_sensor_esq2 = valorPreto_sensor_esq2;
      }
      
          
    }
    else {
      escolhaPreto = 'S';
    }
  }
  
}

void Menu_calibrar() {

char escolhaMenu = "";
char escolhaBrancoPreto = "";


  while (escolhaMenu != 'S') { 
     Serial.println("[C] Começar calibração");
     Serial.println("[S] Sair da calibração");
     esperarParaLer();
     escolhaMenu = Serial.read();
     
     if (escolhaMenu == 'C'){
      while (escolhaBrancoPreto != 'S') { 
        Serial.println("[B] Calibrar BRANCO");
        Serial.println("[P] Calibrar PRETO");
        Serial.println("[S] SAIR");
        esperarParaLer();
        escolhaBrancoPreto = Serial.read();
        
        if (escolhaBrancoPreto == 'B') {
          calibrarBranco();           
        }
        else if (escolhaBrancoPreto == 'P') {
          calibrarPreto();
        }
        else {
          escolhaBrancoPreto = 'S';
        }
        
      }
      escolhaBrancoPreto = '.';
    }
  }


  BRA_PRE_DIR = (maximoPreto_sensor_dir + minimoBranco_sensor_dir)/2;
  BRA_PRE_DIR2 = (maximoPreto_sensor_dir2 + minimoBranco_sensor_dir2)/2;
  BRA_PRE_ESQ = (maximoPreto_sensor_esq + minimoBranco_sensor_esq)/2;
  BRA_PRE_ESQ2 = (maximoPreto_sensor_esq2 + minimoBranco_sensor_esq2)/2;  
}

void setup(){
  Serial.begin(9600);
	Menu_calibrar();
  
	robo.configurar(false);
}

void loop(){
	valor_sensor_esq = robo.lerSensorLinhaEsq(); //le um valor do sensor. O sensor retornar um valor de 0 100
 	valor_sensor_dir = robo.lerSensorLinhaDir(); //le um valor do sensor. O sensor retornar um valor de 0 100
  valor_sensor_dir2 = robo.lerSensorLinhaDir2();
  valor_sensor_esq2 = robo.lerSensorLinhaEsq2();

  
	Serial.print("     direito e: ");
	Serial.print(valor_sensor_dir); //Imprime o valor do sensor pela porta serial

  Serial.print("    + direito e: ");
  Serial.print(valor_sensor_dir2); //Imprime o valor do sensor pela porta serial

  Serial.print("    + esquerdo e: ");
	Serial.print(valor_sensor_esq2); //Imprime o valor do sensor pela porta serial

  Serial.print("     esquerdo e: ");
  Serial.println(valor_sensor_esq); //Imprime o valor do sensor pela porta serial
  
	delay(500);

}

