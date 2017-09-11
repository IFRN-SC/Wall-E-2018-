#include <Calibracao.h>


void Calibracao::esperarParaLer (){
  while (!Serial.available()){}
}

void Calibracao::calibrarBranco(){

  while (escolhaBranco != 'S') {
    Serial.println("Coloque todos os sensores no BRANCO");
    Serial.println("[C] Para CALIBRAR");
    Serial.println("[S] Para SAIR");
    esperarParaLer();
    escolhaBranco = Serial.read();

    if (escolhaBranco = 'C') {
      valorBranco_sensor_dir = robo.lerSensorLinhaDir();
      valorBranco_sensor_dir2 = robo.lerSensorLinhaDir2();
      valorBranco_sensor_esq = robo.lerSensorLinhaEsq();
      valorBranco_sensor_esq2 = robo.lerSensorLinhaEsq2();

      if (valorBranco_sensor_dir > maximoBranco_sensor_dir) {
        maximoBranco_sensor_dir = valorBranco_sensor_dir;
      }					
      
      if (valorBranco_sensor_dir2 > maximoBranco_sensor_dir2) {
        maximoBranco_sensor_dir2 = valorBranco_sensor_dir2;
      }

      if (valorBranco_sensor_esq > maximoBranco_sensor_esq) {
        maximoBranco_sensor_esq = valorBranco_sensor_esq;
      }

      if (valorBranco_sensor_esq2 > maximoBranco_sensor_esq2) {
        maximoBranco_sensor_esq2 = valorBranco_sensor_esq2;
      }
      
          
    }
  }
}

void Calibracao::calibrarPreto(){

  while (escolhaPreto != 'S') {
    Serial.println("Coloque todos os sensores no PRETO");
    Serial.println("[C] Para CALIBRAR");
    Serial.println("[S] Para SAIR");
    esperarParaLer();
    escolhaPreto = Serial.read();

    if (escolhaPreto = 'C') {
      valorPreto_sensor_dir = robo.lerSensorLinhaDir();
      valorPreto_sensor_dir2 = robo.lerSensorLinhaDir2();
      valorPreto_sensor_esq = robo.lerSensorLinhaEsq();
      valorPreto_sensor_esq2 = robo.lerSensorLinhaEsq2();

      if (valorPreto_sensor_dir < minimoPreto_sensor_dir) {
        minimoPreto_sensor_dir = valorPreto_sensor_dir;
      }
      
      if (valorPreto_sensor_dir2 < minimoPreto_sensor_dir2) {
        minimoPreto_sensor_dir2 = valorPreto_sensor_dir2;
      }

      if (valorPreto_sensor_esq < minimoPreto_sensor_esq) {
        minimoPreto_sensor_esq = valorPreto_sensor_esq;
      }

      if (valorPreto_sensor_esq2 < minimoPreto_sensor_esq2) {
        minimoPreto_sensor_esq2 = valorPreto_sensor_esq2;
      }
      
          
    }
  }
  
}

void Calibracao::Menu_calibrar() {

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
        
      }
    }
  }

  BRA_PRE_DIR = (minimoPreto_sensor_dir + maximoBranco_sensor_dir)/2;
  BRA_PRE_DIR2 = (minimoPreto_sensor_dir2 + maximoBranco_sensor_dir2)/2;
  BRA_PRE_ESQ = (minimoPreto_sensor_esq + maximoBranco_sensor_esq)/2;
  BRA_PRE_ESQ2 = (minimoPreto_sensor_esq2 + maximoBranco_sensor_esq2)/2;  
}

