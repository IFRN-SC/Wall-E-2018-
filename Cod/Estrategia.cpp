#include "Estrategia.h"
Estrategia::Estrategia():fimDeCurso(FIM_DE_CURSO){

}

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

void Estrategia::verificar(){
	if(sensor.viuRampa()){
		robo.ligarLed(1);
		while(sensor.viuRampa()){
			robo.acionarMotores(50, 57);
		}
		robo.desligarLed(1);
		sala3.portal();
	}
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
  /*while(sensor.Esq_Branco()){
  	robo.acionarMotores(0, -40);
  }
  robo.acionarMotores(0, -40);
  delay(180);*/
  while(sensor.maisEsq_Branco()){
  	robo.acionarMotores(-40, 0);
  	delay(200);
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

	while(sensor.maisDir_Branco()){
		robo.acionarMotores(-40, 40);
	}

	motores.parar(1000);

	alinharObstaculo();

	/*robo.acionarMotores(40, -43);
	delay(52);*/

	motores.parar(1000);

	while (robo.lerSensorSonarDir() > 15){
		//digitalWrite(10, HIGH);
		robo.acionarMotores(40, 43);
	}

	motores.parar(1000);

	while(robo.lerSensorSonarDir() < 15){
		robo.ligarLed(3);
		robo.acionarMotores(40, 43);
		delay(200);
	}
	robo.desligarLed(3);

	//robo.acionarMotores(40, 43);
	//delay(230);

	motores.parar(500);

	robo.acionarMotores(40, -40);
	delay(800);

	motores.parar(300);

	while (robo.lerSensorSonarDir() > 15){
		//digitalWrite(10, HIGH);
		robo.acionarMotores(40, 43);
		delay(250);
	}

	motores.parar(500);

	while(robo.lerSensorSonarDir() < 15){
		robo.acionarMotores(40, 43);
		delay(150);
	}

//	robo.acionarMotores(40, 43);
//	delay(95);

	robo.acionarMotores(40, -40);
	delay(800);

	//robo.acionarMotores(40, 40);
	//delay(250);

	while(sensor.Esq_Branco() && sensor.Dir_Branco()){
		robo.acionarMotores(40, 40);
	}

	//motores.parar(300);

	while(sensor.Esq_Preto() && sensor.Dir_Preto()){
		robo.acionarMotores(40, 40);
	}

	while(sensor.Esq_Branco()){robo.acionarMotores(-40, 40);}
	while(sensor.Esq_Preto()){robo.acionarMotores(-40, 40);}

//	while(1){motores.parar(400);}

}

void Estrategia::miniSeguirLinha(){
	while(sensor.viuRampa()){
		if (sensor.branco_branco_branco_branco()) {
			motores.emFrenteRampa();
		}
		else if(sensor.branco_preto_branco_branco() ||
				sensor.preto_preto_branco_branco())
		{
			motores.esquerdaRampa();
		}else if(sensor.preto_branco_branco_branco()){
			motores.esquerdaRampa(15);
		}
		else if(sensor.branco_branco_preto_branco() ||
				sensor.branco_branco_preto_preto())
		{
			motores.direitaRampa();
		}else if(sensor.branco_branco_branco_preto()){
			motores.direitaRampa(10);
		}
		else{
			motores.emFrenteRampa();
		}
	}
	robo.desligarLed(2);
	motores.emFrenteRampa();
	delay(150);
	sala3.portal();
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

	robo.acionarMotores(-35, -35);
	delay(1000);

	robo.acionarMotores(30, 30);
	delay(250);

	robo.acionarMotores(-30, -30);
	delay(1000);

	motores.parar(500);


	double atual = 100;
	double anterior = 0;
	robo.acionarMotores(30, 33);

	while(robo.lerSensorSonarFrontal() > 3.3){
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
	//resgate();


	while(1){
		robo.acionarMotores(0,0);
		piscarLeds(10);
	}


}

void Estrategia::alinhaEsquerda(){
	while(sensor.maisEsq_Preto()){motores.emFrente();}
	while(sensor.Esq_Branco() && sensor.maisEsq_Branco()){robo.acionarMotores(-28, -28);}
}

void Estrategia::alinhaDireita(){
	while(sensor.maisDir_Preto()){motores.emFrente();}
	while(sensor.Dir_Branco() && sensor.maisDir_Branco()){robo.acionarMotores(-28, -28);}
}

bool Estrategia::temPretoEsquerda(){
	int ant = millis();
	bool temPretoEsquerda =  false;
	while((millis() -  ant) < 500){
		robo.acionarMotores(-40, 0);
		if(sensor.maisEsq_Preto()){
			temPretoEsquerda = true;
			break;
		}
	}
	return temPretoEsquerda;
}
bool Estrategia::temPretoDireita(){
	int ant = millis();
	bool temPretoDireita =  false;
	while((millis() -  ant) < 500){
		robo.acionarMotores(0, -40);
		if(sensor.maisDir_Preto()){
			temPretoDireita = true;
			break;
		}
	}
	return temPretoDireita;
}
void Estrategia::vireEsquerda(bool temVerde=true){
	while(sensor.maisEsq_Preto()){motores.emFrente();}
	while(sensor.Esq_Preto()){motores.esquerda();}
	delay(90);

	/*if(!temPretoDireita()){
		robo.acionarMotores(0, 40);
		delay(500);*/
		if(temVerde){
			robo.ligarLed(1);
			while(sensor.maisEsq_Preto()){motores.esquerda();}
			while(sensor.Esq_Branco()){motores.esquerda();}
			while(sensor.Esq_Preto()){motores.esquerda();}
		}else{
			while(sensor.Dir_Branco()){motores.esquerda();}
			while(!(sensor.Dir_Branco() && sensor.maisDir_Branco())){motores.direita();}
		}
		robo.desligarLed(1);

		//pareInfinito(1);
	/*}else{
			pareInfinito(1);
	}*/
}

void Estrategia::vireDireita(bool temVerde=true){
	while(sensor.maisDir_Preto()){motores.emFrente();}
	while(sensor.Dir_Preto()){motores.direita();}
	delay(90);

	/*if(!temPretoEsquerda()){
		robo.acionarMotores(40, 0);
		delay(500);*/
		if(temVerde){
			robo.ligarLed(3);
			while(sensor.maisDir_Branco()){motores.direita();}
			while(sensor.maisDir_Preto()){motores.direita();}
		//	while(sensor.Dir_Branco()){motores.direita();}
			while(sensor.Dir_Preto()) {motores.direita();}
		}else{
			while(sensor.Esq_Branco()){motores.direita();}
			while(!(sensor.Esq_Branco() && sensor.maisEsq_Branco())) {motores.esquerda();}
		}
		robo.desligarLed(3);
	/*}else{
			while(sensor.maisEsq_Preto()){robo.acionarMotores(0,-40);}
			while(sensor.maisEsq_Branco()){robo.acionarMotores(40,0);}
			if(sensor.viuBecoSemSaida()) robo.ligarLed(2);
			else robo.ligarLed(1);
			pareInfinito(3);
	}*/
}

void Estrategia::sigaLinha(){
	if(sensor.branco_branco_branco_branco()){
		motores.emFrente();
	}

	// curva 90º
	else if(sensor.preto_preto_branco_branco() ||
		sensor.preto_preto_preto_branco()) {

		//alinhaEsquerda();
		//motores.parar(200);
		vireEsquerda();
		//robo.acionarMotores(-30, 37);
	}
	else if(sensor.branco_branco_preto_preto() ||
		sensor.branco_preto_preto_preto()) {

		//alinhaDireita();
		//motores.parar(200);
		vireDireita();
		//robo.acionarMotores(30, -37);
	}
	// *********************************************

	// correções
	else if (sensor.branco_preto_branco_branco()){
		motores.esquerda();
		//robo.acionarMotores(15, 37);
	}
	else if (sensor.branco_branco_preto_branco()){
		motores.direita();
		//robo.acionarMotores(30, 19);
	}
	// **********************************************

	// beco sem saída
	/*else if(sensor.Esq_Preto() && sensor.Dir_Preto()){
		alinhaBecoSemSaida();
	}*/
}
void Estrategia::alinhaBecoSemSaida(){
	motores.parar(1000);
	piscarLeds(3);
	while(!sensor.maisDir_Branco() && !sensor.maisDir_Branco()){robo.acionarMotores(25, 28);}
	while(sensor.maisDir_Branco()){robo.acionarMotores(0, -25);}
	while(sensor.maisEsq_Branco()){robo.acionarMotores(-25, 0);}
	motores.parar(400);

	if(sensor.viuBecoSemSaida()){
		motores.parar(300);
		for(int i = 0; i < 10; i++){
			robo.ligarLed(3);
			delay(50);
			robo.desligarLed(3);
			delay(50);
		}
		robo.acionarMotores(30, 30);
		delay(200);
		robo.acionarMotores(40, -40);
		delay(840);

		while(sensor.maisDir_Preto()){motores.direita();}
		while(sensor.maisDir_Branco()){motores.direita();}
		while(sensor.Dir_Branco()){motores.direita();}
		while(sensor.Dir_Preto()){motores.direita();}

	}else{
		motores.parar(200);
		for(int i = 0; i < 10; i++){
			robo.ligarLed(1);
			delay(50);
			robo.desligarLed(1);
			delay(50);
		}
		while(1);
	}

	//while(1){robo.acionarMotores(0,0);}
}


void Estrategia::procuraBola(){
	while(robo.lerSensorSonarFrontal() > 9){
		robo.acionarMotores(25, -29);
		delay(100);
		robo.acionarMotores(0,0);
		delay(300);
	}
	while(1){
		robo.acionarMotores(0,0);
		piscarLeds(2);
	}
}
void Estrategia::pareInfinito(int led=3){
	while(1){
		motores.parar(10);
		robo.ligarLed(led);
		delay(300);
		robo.desligarLed(led);
		delay(300);
	}
}
void Estrategia::executar(){
	if(sensor.viuRampa()){
		robo.ligarLed(2);
		miniSeguirLinha();
		sala3.portal();
	}else if(sensor.viuObstaculo()){
		passeObstaculo();
	}else{
		robo.desligarLed(2);
		sigaLinha();
	}
/*
	if(sensor.corEsq_verde()) robo.ligarLed(3);
	else robo.desligarLed(3);

	if(sensor.corDir_verde()) robo.ligarLed(1);
	else robo.desligarLed(1);*/
	//boySala3();
	//procuraBola();
	//resgate();
}
