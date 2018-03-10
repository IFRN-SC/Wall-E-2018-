#include "Estrategia.h"


void Estrategia::configurar(){
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
}
void Estrategia::calibrar(){
	Serial.println(F("Digite qualquer coisa para calibrar")); 	
	
	for(int i=0; i<10; i++){
		delay(500);
		Serial.print(F("Tentativa "));
		Serial.println(i);
		if(Serial.available()){
			Serial.read();
			sensor.Menu_calibrar();
		}
	}
	sensor.lerCalibracao();
}

void Estrategia::para(int tempo){
	robo.acionarMotores(0, 0);
	delay(tempo);
}

void Estrategia::passeEncruzilhadaDireita(){
	while (!sensor.branco_branco_branco_branco()) {
		robo.acionarMotores(40, 40);
	}
	while (sensor.Esq_Branco()) {
		robo.acionarMotores(35, -35);
	}
	robo.acionarMotores(40, 40);
}

void Estrategia::passeEncruzilhadaEsquerda(){
	while (!sensor.branco_branco_branco_branco()) {
		robo.acionarMotores(40, 40);
	}
	while (sensor.Dir_Branco()) {
		robo.acionarMotores(-35, 35);
	}
	robo.acionarMotores(40, 40);
}

bool Estrategia::desalinhado(){
	return (sensor.branco_branco_branco_preto() ||
	sensor.branco_branco_preto_preto() ||
	sensor.branco_preto_preto_preto() ||
	sensor.preto_branco_branco_branco() ||
	sensor.preto_preto_branco_branco() ||
	sensor.preto_preto_preto_branco() ||
	sensor.preto_branco_preto_branco() ||
	sensor.branco_preto_branco_preto());
}
void Estrategia::alinharObstaculo(){
  while(desalinhado()){
  
	if (sensor.branco_branco_branco_preto() ||
	sensor.branco_branco_preto_preto() ||
	sensor.branco_preto_preto_preto()) 
	{
	  robo.acionarMotores(-40, 0); 
	}
	else if (sensor.preto_branco_branco_branco() ||
	sensor.preto_preto_branco_branco() ||
	sensor.preto_preto_preto_branco()) 
	{
	  robo.acionarMotores(0, -40); 
	}
  }
}

void Estrategia::alinharEncruzilhada(){
  while(desalinhado()){
  		if (sensor.maisEsq_Preto()){
  			//para(500);
  			robo.acionarMotores(0,35);
  		}else if (sensor.maisDir_Preto()){
  			robo.acionarMotores(35,0);
  			
  		}
	 
  }
}

void Estrategia::passeVerdeOuRedutor(){
		digitalWrite(10, HIGH);
		if (sensor.corEsq_verde() && (sensor.corDir_branco() || sensor.corDir_preto())){
			para(700);
			passeEncruzilhadaEsquerda();
		}
		else if (sensor.corDir_verde() && (sensor.corEsq_branco() || sensor.corEsq_preto())){
			para(700);
			passeEncruzilhadaDireita();
			
		}
		else if (sensor.corDir_verde() && sensor.corEsq_verde()){
			while (!sensor.branco_branco_branco_branco()){
				robo.acionarMotores(35, -35);
			}
			
		}
		/*else if (sensor.corEsq_branco() && (sensor.corDir_branco() || sensor.corDir_preto()) ||
			sensor.corDir_branco() && (sensor.corEsq_branco() || sensor.corEsq_preto())){
			//digitalWrite(10, HIGH);
			robo.acionarMotores(-40, -40);
			delay(700);

			robo.acionarMotores(65, 65);
			delay(1200);

		}*/
		else {
			robo.acionarMotores(-35, -35);
			delay(400);
		}
}

void Estrategia::vireEsquerda(){
	mova.esquerda(VELPADRAO, VELPADRAO);
}
void Estrategia::vireDireita(){
	mova.direita(VELPADRAO, VELPADRAO);
}

void Estrategia::piscarLeds(){
	while (1){
		para(2000);
		digitalWrite(10, HIGH);
		delay(200);
		digitalWrite(10, LOW);
		delay(100);
		digitalWrite(11, HIGH);
		delay(200);
		digitalWrite(11, LOW);
		delay(100);
		digitalWrite(10, HIGH);
		delay(200);
		digitalWrite(10, LOW);
		delay(100);
		digitalWrite(11, HIGH);
		delay(200);
		digitalWrite(11, LOW);
		delay(100);
		digitalWrite(10, HIGH);
		delay(200);
		digitalWrite(10, LOW);
		delay(100);
		digitalWrite(11, HIGH);
		delay(200);
		digitalWrite(11, LOW);
		delay(100);
		break;
	}
}

void Estrategia::passeObstaculo(){

		  piscarLeds();

		  robo.acionarMotores(0, 0);
		  delay(300);
		  
		  robo.acionarMotores(-40, -40);
		  delay(150);
		  
		while (!sensor.branco_branco_branco_preto()){
		  robo.acionarMotores(-40, 40);
		}

		  alinharObstaculo();

		  para(1000);

		  robo.acionarMotores(40, 40);
		  delay(1120);

		  para(1000);

		  robo.acionarMotores(40, -40);
		  delay(700);

		  para(1000);

		  robo.acionarMotores(40, 40);
		  delay(1750);

		  para(1000);

		  robo.acionarMotores(40, -40);
		  delay(690);

		  while (sensor.branco_branco_branco_branco()){
			robo.acionarMotores(40, 40);
		  }

		  robo.acionarMotores(35, 35);
		  delay(250);

		  while (!(sensor.Dir_Preto())){
			robo.acionarMotores(-40, 40);
		  }
}

void Estrategia::sigaLinha(){
	if(viuObstaculo()){
		 passeObstaculo();
	}
	else if(sensor.branco_branco_branco_branco()){
		mova.emFrente(VELPADRAO, VELPADRAO);
	}
	
	// bloco de ações para curva 90º
	else if(sensor.preto_preto_branco_branco()/* ||
		sensor.preto_preto_preto_branco()*/) {
		digitalWrite(11, HIGH);
		mova.emFrente(VELPADRAO, VELPADRAO);
		delay(150);
		vireEsquerda();
		delay(600);
	}
	else if(sensor.branco_branco_preto_preto()/* ||
		sensor.branco_preto_preto_preto()*/) {
		digitalWrite(11, HIGH);
		mova.emFrente(VELPADRAO, VELPADRAO);
		delay(150);
		vireDireita();
		delay(600);
	} 
	// *********************************************

	// bloco de ações para correções
	else if (sensor.branco_preto_branco_branco()){
		vireEsquerda();
	}
	else if (sensor.branco_branco_preto_branco()){
		vireDireita();
	}
	//**********************************************
	
	// bloco para o verde
	/*else if (sensor.branco_preto_branco_preto() ||
		sensor.preto_branco_preto_branco()){
		digitalWrite(10, HIGH);
		alinharEncruzilhada();
		passeVerdeOuRedutor();
	}*/
	//**********************************************

}

bool Estrategia::viuObstaculo(){
	/*int contPulsos;
	if (robo.lerSensorSonarFrontal() <=10){
		contPulsos++;
	}

	if (contPulsos == 5){
		return true;
		contPulsos = 0;
	}else {
		return false;
	}*/
	return (robo.lerSensorSonarFrontal() <= 10);
}

void Estrategia::executar(){
		//configurar();
		sigaLinha();
	
}
