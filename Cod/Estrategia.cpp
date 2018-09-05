#include "Estrategia.h"
Estrategia::Estrategia():fimDeCurso(FIM_DE_CURSO){}

void Estrategia::calibrar(){
	Serial.println(F("Digite qualquer coisa para calibrar")); 	
	
	for(int i=0; i<10; i++){
		robo.ligarTodosLeds();
		delay(250);
		Serial.print(F("Tentativa "));
		Serial.println(i);

		if(Serial.available()){
			Serial.read();	
			sensor.Menu_calibrar(); 
		}

		robo.desligarTodosLeds();
		delay(250);
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
  while(sensor.maisDir_Branco()){
  	robo.acionarMotores(0, -40);
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
	motores.esquerda(VELESQ, VELDIR);
}
void Estrategia::vireDireita(){
	motores.direita(VELESQ, VELDIR);
}

void Estrategia::piscarLeds(int vezes){
	for(int i = 0; i <= vezes; i++){
		robo.ligarTodosLeds();
		delay(250);
		robo.desligarTodosLeds();
		delay(100);
	}
}

void Estrategia::passeObstaculo(){
		  
	motores.parar(1000);
	
	piscarLeds(4);
	
	robo.acionarMotores(-40, -40);
	delay(60);

	while(sensor.maisEsq_Branco()){
		robo.acionarMotores(40, -40);
	}

	motores.parar(1000);

	alinharObstaculo();

	/*robo.acionarMotores(40, -43);
	delay(52);*/
	
	motores.parar(1000);

	while (robo.lerSensorSonarEsq() > 15){
		//digitalWrite(10, HIGH);
		robo.acionarMotores(40, 43);
	}

	motores.parar(1000);

	while(robo.lerSensorSonarEsq() < 15){
		robo.ligarLed(3);
		robo.acionarMotores(40, 43);
		delay(200);
	}
	robo.desligarLed(3);

	//robo.acionarMotores(40, 43);
	//delay(230);

	motores.parar(500);

	robo.acionarMotores(-40, 40);
	delay(396);

	motores.parar(300);

	while (robo.lerSensorSonarEsq() > 15){
		//digitalWrite(10, HIGH);
		robo.acionarMotores(40, 43);
		delay(100);
	}

	motores.parar(500);

	while(robo.lerSensorSonarEsq() < 15){
		robo.acionarMotores(40, 43);
		delay(150);
	}

//	robo.acionarMotores(40, 43);
//	delay(95);

	robo.acionarMotores(-40, 40);
	delay(396);

	robo.acionarMotores(40, 40);
	delay(200);

	while(sensor.Esq_Branco() && sensor.Dir_Branco()){
		robo.acionarMotores(40, 40);
	}

	motores.parar(300);

	while(sensor.Esq_Preto() && sensor.Dir_Preto()){
		robo.acionarMotores(40, 40);
	}

	while(sensor.Dir_Branco()){robo.acionarMotores(40, -40);}
	while(sensor.Dir_Preto()){robo.acionarMotores(40, -40);}

//	while(1){motores.parar(400);}

}

void Estrategia::miniSeguirLinha(){
	if(sensor.branco_branco_branco_branco()){
		motores.emFrente(85, 88);
	}else if(sensor.branco_preto_branco_branco() ||
		sensor.preto_branco_branco_branco() ||
		sensor.preto_preto_branco_branco()){
		robo.acionarMotores(70, 85);
	}else if(sensor.branco_branco_preto_branco() ||
		sensor.branco_branco_branco_preto()||
		sensor.branco_branco_preto_preto()){
		robo.acionarMotores(85, 70);
	}else if (sensor.preto_preto_preto_preto()){
		//digitalWrite(11, HIGH);
		//digitalWrite(10, HIGH);
		/*robo.acionarMotores(80, 80);
		delay(800);
		robo.acionarMotores(40, -40);
		delay(810);
		while(1){robo.acionarMotores(0, 0);}*/
		motores.emFrente(85, 88);
		//delay(40);

//		boySala3();
	}else{
		motores.emFrente(85, 85);
	}
}

void Estrategia::resgate(){

	//garra.iniciar();

	//garra.subir();
	garra.abrir();
  	garra.baixar();
  	garra.fechar();
  	garra.subir();

}

void Estrategia::boySala3() {
	motores.parar(500);
	robo.acionarMotores(40, -40);
	delay(500);

	motores.parar(500);

	robo.acionarMotores(-30, -30);
	delay(180);

	motores.parar(500);

	double atual = 100;
	double anterior = 0;
	robo.acionarMotores(30, 33);

	while(1){
		anterior = atual;
		for(int i = 0; i < 10; i++){
			atual = robo.lerSensorSonarEsq();
		}

		if((atual - anterior) > 3.3){
			robo.acionarMotores(0,0);
			break;
		} 
	}

	motores.parar(500);
	robo.acionarMotores(-23, 23);
	delay(1000);
	motores.parar(500);

	while(robo.lerSensorSonarFrontal() > anterior){
		robo.acionarMotores(-25, 25);
	}
	motores.parar(400);

	while(robo.lerSensorSonarFrontal() > 9){
		robo.acionarMotores(23, 23);
	}
	
	motores.parar(700);
	resgate();


	while(1){
		robo.acionarMotores(0,0);
		piscarLeds(10);
	}

	
}


void Estrategia::sigaLinha(){
	if(sensor.branco_branco_branco_branco() /*||
		sensor.preto_preto_preto_preto()*/){
		motores.emFrente(VELESQ, VELDIR);
		
	}
	
	// bloco de ações para curva 90º
	else if(sensor.preto_preto_branco_branco() ||
		sensor.preto_preto_preto_branco()) {
		
		while(sensor.maisEsq_Preto()){
			motores.emFrente(VELESQ, VELDIR);
			delay(90);
		}

		while(sensor.Esq_Branco()){vireEsquerda();}
		while(sensor.Esq_Preto()){vireEsquerda();}
	}
	else if(sensor.branco_branco_preto_preto()||
		sensor.branco_preto_preto_preto()) {
		while(sensor.maisDir_Preto()){
			motores.emFrente(VELESQ, VELDIR);
			delay(90);
		}
		while (sensor.Dir_Branco()){vireDireita();}
		while (sensor.Dir_Preto()){vireDireita();}
		
	} 
	// *********************************************

	// bloco de ações para correções
	else if (sensor.branco_preto_branco_branco()){
		robo.acionarMotores(-40, 40);
	}
	else if (sensor.branco_branco_preto_branco()){
		robo.acionarMotores(40, -40);
	}


	/*else if (sensor.preto_preto_preto_preto()){
		robo.acionarMotores(50,50);
	}*/
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

void Estrategia::executar(){ 
	if(sensor.viuRampa()){
		robo.ligarLed(2);
		miniSeguirLinha();
	}else if(sensor.viuObstaculo()){
		passeObstaculo();
	}else{
		robo.desligarLed(2);
		sigaLinha();
	}
	//boySala3();
}














