#include "Estrategia.h"
Estrategia::Estrategia():fimDeCurso(FIM_DE_CURSO){

}

void Estrategia::configurar(){
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	//fimDeCurso.config();
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

void Estrategia::passeEncruzilhada_Direita(){
	while (!sensor.branco_branco_branco_branco()) {
		robo.acionarMotores(40, 40);
	}
	while (sensor.Esq_Branco()) {
		robo.acionarMotores(35, -35);
	}
	robo.acionarMotores(40, 40);
}

void Estrategia::passeEncruzilhada_Esquerda(){
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
	sensor.branco_preto_preto_preto()) {
	  robo.acionarMotores(-40, 0); 
	}
	else if (sensor.preto_branco_branco_branco() ||
	sensor.preto_preto_branco_branco() ||
	sensor.preto_preto_preto_branco()) {
	  robo.acionarMotores(0, -40); 
	}
  }
}

void Estrategia::alinharEncruzilhada(){   // tenta alinhar na encruzilhada T para ler o verde logo após.
  if(sensor.maisEsq_Preto()){ 
  	while(!sensor.maisDir_Preto()){robo.acionarMotores(0, 35);}
  }else if(sensor.maisDir_Preto()){
  	while(!sensor.maisEsq_Preto()){robo.acionarMotores(35, 0);}
  }else {
  	while(sensor.maisEsq_Branco() ^ sensor.maisDir_Branco()){
  		robo.acionarMotores(-35, -35);
  	}
  }
}

void Estrategia::passeVerdeOuRedutor(){
		digitalWrite(10, HIGH);
		if (sensor.corEsq_verde() && (sensor.corDir_branco() || sensor.corDir_preto())){
			motores.parar(700);
			passeEncruzilhada_Esquerda();
		}
		else if (sensor.corDir_verde() && (sensor.corEsq_branco() || sensor.corEsq_preto())){
			motores.parar(700);
			passeEncruzilhada_Direita();
			
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
	motores.esquerda(VELPADRAO, VELPADRAO);
}
void Estrategia::vireDireita(){
	motores.direita(VELPADRAO, VELPADRAO);
}

void Estrategia::piscarLeds(){
	while (1){
		motores.parar(2000);
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
		  //piscarLeds();
	motores.parar(1000);

	robo.acionarMotores(-40, -40);
	delay(100);

	while(sensor.maisEsq_Branco()){
		robo.acionarMotores(40, -40);
	}

	motores.parar(1000);

	alinharObstaculo();

	robo.acionarMotores(40, -40);
	delay(130);
	
	motores.parar(1000);

	while (robo.lerSensorSonarDir() > 10){
		//digitalWrite(10, HIGH);
		robo.acionarMotores(40, 40);
	}

	motores.parar(1000);

	while(robo.lerSensorSonarDir() < 15){
		robo.acionarMotores(40, 40);
	}

	robo.acionarMotores(40, 40);
	delay(320);

	robo.acionarMotores(-40, 40);
	delay(540);

	while (robo.lerSensorSonarDir() > 15){
		//digitalWrite(10, HIGH);
		robo.acionarMotores(40, 40);
	}

	motores.parar(500);

	while(robo.lerSensorSonarDir() < 15){
		robo.acionarMotores(40, 40);
	}

	robo.acionarMotores(40, 40);
	delay(230);

	robo.acionarMotores(-40, 40);
	delay(540);

	robo.acionarMotores(40, 40);
	delay(320);

	while(sensor.Esq_Branco() && sensor.Dir_Branco()){
		robo.acionarMotores(40, 40);
	}

	motores.parar(300);

	while(sensor.Esq_Preto() && sensor.Dir_Preto()){
		robo.acionarMotores(40, 40);
	}

	while(sensor.Dir_Branco()){robo.acionarMotores(40, -40);}
	while(sensor.Dir_Preto()){robo.acionarMotores(40, -40);}



}

void Estrategia::miniSeguirLinha(){
	digitalWrite(10, HIGH);
	if(sensor.branco_branco_branco_branco()){
		motores.emFrente(85, 85);
	}else if(sensor.branco_preto_branco_branco() ||
		sensor.preto_branco_branco_branco()){
		robo.acionarMotores(75, 85);
	}else if(sensor.branco_branco_preto_branco() ||
		sensor.branco_branco_branco_preto()){
		robo.acionarMotores(85, 75);
	}else if (sensor.preto_preto_preto_preto()){
		//digitalWrite(11, HIGH);
		//digitalWrite(10, HIGH);
		/*robo.acionarMotores(80, 80);
		delay(800);
		robo.acionarMotores(40, -40);
		delay(810);
		while(1){robo.acionarMotores(0, 0);}*/
		motores.emFrente(85, 85);
	}
}

void Estrategia::boySala3() {
	motores.parar(500);
	
	robo.acionarMotores(75, 74);
	delay(800);
	robo.acionarMotores(40, -40);
	delay(540);

	while (robo.lerSensorSonarDir() < 4) {
		robo.acionarMotores(0,25);
	}

	while (1) {
		robo.acionarMotores(20,20);

		if (robo.lerSensorSonarDir() < 30) {
			motores.parar(200);

			while (!(robo.lerSensorSonarFrontal() < 20)) {
				robo.acionarMotores(-30,30);
			}

 			
 			motores.parar(500);

			while(robo.lerSensorSonarFrontal() > 3) {
				robo.acionarMotores(40,40);
			}

		} 
		else if (robo.lerSensorSonarFrontal() < 30) {
				motores.parar(300);
				

			while(robo.lerSensorSonarFrontal() > 3) {
				robo.acionarMotores(40,40);
			}			
		}	
	}
	//if (robo.lerSensorSonarFrontal()
}


void Estrategia::sigaLinha(){
	if(viuObstaculo()){
		 passeObstaculo();
	}
	else if(sensor.branco_branco_branco_branco() /*||
		sensor.preto_preto_preto_preto()*/){
		motores.emFrente(VELPADRAO, VELPADRAO);
		
	}
	
	// bloco de ações para curva 90º
	else if(sensor.preto_preto_branco_branco() ||
		sensor.preto_preto_preto_branco()) {
		motores.emFrente(VELPADRAO, VELPADRAO);
		delay(150);
		while(sensor.Esq_Branco()){	
			vireEsquerda();
		}while(sensor.Esq_Preto()){
			vireEsquerda();
		}
	}
	else if(sensor.branco_branco_preto_preto()||
		sensor.branco_preto_preto_preto()) {
		motores.emFrente(VELPADRAO, VELPADRAO);
		delay(150);
		while (sensor.Dir_Branco()){
			vireDireita();
		}while (sensor.Dir_Preto()){
			vireDireita();
		}
		
	} 
	// *********************************************

	// bloco de ações para correções
	else if (sensor.branco_preto_branco_branco()){
		robo.acionarMotores(-45, 45);
	}
	else if (sensor.branco_branco_preto_branco()){
		robo.acionarMotores(45, -45);
	}else if (sensor.preto_preto_preto_preto()){
		robo.acionarMotores(50, 50);
	}
	//**********************************************
	// bloco para o verde
	/*else if (sensor.branco_preto_branco_preto() ||
		sensor.preto_branco_preto_branco()){
		digitalWrite(10, HIGH);
		while(1){
			motores.parar(4);
		}
	}/*else if (sensor.preto_preto_preto_preto()){
		while(1){
			motores.parar(2);
		}
	 }*/
	//else if (sensor.preto_preto_preto_branco() ||
	//	sensor.branco_preto_preto_preto()){
		//digitalWrite(10, HIGH);
		/*motores.parar(600);
		alinharEncruzilhada();
		if (sensor.corEsq_verde()){
			
			motores.parar(500);
			motores.emFrente(40, 40);
			delay(240);
			motores.parar(500);;
			vireEsquerda();
			delay(600);
		}*/
		//while(1){motores.parar(2);}
		//motores.emFrente(50, 50); 
	//	}
	//**********************************************
	//delay(75);
}

bool Estrategia::viuObstaculo(){
	return (robo.lerSensorSonarFrontal() <= 10);
}

void Estrategia::executar(){ 
	if (robo.lerSensorSonarDir() <= 10.0){
		miniSeguirLinha();
 		//robo.acionarMotores(80, 80);
	}else{
		sigaLinha();
		//robo.acionarMotores(40, 40);
	}
}














