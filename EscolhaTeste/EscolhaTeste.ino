#include <robo_hardware2.h> 

float valorSensorFrontal;
float valorSensorDir;
float valorSensorEsq;

void setup(){
  Serial.begin(9600);
  robo.configurar(false);
}

void loop(){
    Serial.println("\n\n*Escolha o teste a ser feito: ");
    Serial.print(" [M] Motores \n [R] Refletância \n [S] Sonares \n");
  
  
  esperaLeitura();
  switch(Serial.read()){
    case 'M':
      testeMotores();
      break;
    case 'R':
      testeRefletancia();
      break;
    case 'S':
      testeSonar();
      break;
  }

}

void esperaLeitura(){
  while (!Serial.available()){}
}
void testeMotores(){
  Serial.println("******************** LIGUE O ROBÔ *****************\n\n");
  Serial.println(" [F] Ambos em FRENTE: ");
  Serial.println(" [T] Ambos para TRÁS: ");
  Serial.println(" [D] DIREITO em frente e esquerdo trás: ");
  Serial.println(" [E] direito em trás e ESQUERDO frente: ");  

  while(1){
    char c = Serial.read();
    switch(c){
      case 'F':
        robo.acionarMotores(40, 40);
        delay(1000);
        robo.acionarMotores(0, 0);
        break;
      case 'T':
        robo.acionarMotores(-40, -40);
        delay(1000);
        robo.acionarMotores(0, 0);
        break;
      case 'D':
        robo.acionarMotores(-40, 40);
        delay(1000);
        robo.acionarMotores(0, 0);
        break;
      case 'E':
        robo.acionarMotores(40, -40);
        delay(1000);
        robo.acionarMotores(0, 0);
        break;
    }
    if(c == 'X') break;
  }
}

void testeRefletancia(){
  while(Serial.read() != 'X'){
    Serial.println("+direito     direito     esquerdo     +esquerdo ");
    Serial.print(robo.lerSensorLinhaMaisDir()); //Imprime o valor do sensor pela porta serial
    Serial.print("       ");
    Serial.print(robo.lerSensorLinhaDir());
    Serial.print("       ");
    Serial.print(robo.lerSensorLinhaEsq());
    Serial.print("       ");
    Serial.println(robo.lerSensorLinhaMaisEsq());
    
    delay(1000);
  }
}
void testeSonar(){
 
  while(Serial.read() != 'X'){
    Serial.print("Esquerdo: : ");
    Serial.print(robo.lerSensorSonarEsq());
      
    Serial.print("  Frontal:  ");
    Serial.print(robo.lerSensorSonarFrontal());
  
    Serial.print("  Direito:  ");
    Serial.println(robo.lerSensorSonarDir());
    Serial.println();
      
    delay(500);
  }
}

