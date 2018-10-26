#include "Sala3.h"

Sala3::Sala3() {
	/* @Depreciating...
	limite_lateral = 0;
	limite_frontal = 0;*/
	fator_esq = 1;
	fator_dir = 1;

	distanciaAtual = 170;
	miniDistanciaAtual = 170;

	viu_bola = false;
}

/* @Depreciating...
void Sala3::setLimiteLateral(float valorLido) { limite_lateral = valorLido; }
void Sala3::setLimiteFrontal(float valorLido) { limite_frontal = valorLido; }

float Sala3::getLimiteLateral() { return limite_lateral; }
float Sala3::getLimiteFrontal() { return limite_frontal; }*/

void Sala3::portal() {

	// passando do portal
	robo.acionarMotores(70, 73);
	delay(200);
 	robo.acionarMotores(30, 33);
	delay(100);
	
	motores.parar(300);

	alinharParede(0);
	executar(0);
}

void Sala3::alinharParede(int qnt){

	// se qnt for 0, entao é a primeira vez que o robo alinha
	if (qnt == 0) {
		
		robo.desligarTodosLeds();

		// se o lado da rampa estiver posicionado a direita em relacao a frente da sala 3
		if (robo.lerSensorSonarEsq() > robo.lerSensorSonarDir()) {
			
			fator_esq = -1;
			fator_dir = 1;

			// sinaliza a escolha
			robo.ligarLed(1);
			delay(300);
			robo.desligarLed(1);//
		
		} else { // lado da rampa: esquerda
			
			fator_esq = 1;
			fator_dir = -1;

			// sinaliza a escolha
			robo.ligarLed(3);
			delay(300);
			robo.desligarLed(3);//

		}	 
	} else { // outros alinhamentos
	
		// prepara o giro de 270
		motores.parar(500);

		// @? testar roda parada e outra girando
		robo.acionarMotores(40 * fator_esq, 40 * fator_dir);
		delay(450);				

		motores.parar(500);

		robo.acionarMotores(40, 40);
		delay(300);				

		motores.parar(500);//

	}

	motores.parar(500);

	// vai um pouco para frente antes de se alinhar
	robo.acionarMotores(40 * fator_esq, 40 * fator_dir);
	delay(450);

	motores.parar(500);

	encostarRobo();
}

void Sala3::encostarRobo() {
	
	// duo-step: ajuda possivel falha no alinhamento
	robo.acionarMotores(-35, -35);
	delay(1200);

	robo.acionarMotores(30, 30);
	delay(250);

	robo.acionarMotores(-30, -30);
	delay(1200);	

	motores.parar(500);//
}

void Sala3::executar(int args){

	/*if (args != 0) {
		// se o lado da rampa for a direita em relacao a frente da sala3
		if (fator_esq == 1) {
			distanciaAtual = robo.lerSensorSonarEsq();	
		} else {
			distanciaAtual = robo.lerSensorSonarDir();
		}	
	}*/

	//int j = 0;

	while(1) {
		//++j;
		
		distanciaAnterior = distanciaAtual;

		filtrarErros(); // for {} ... média dos valores
		
		// erro início da procura
		robo.acionarMotores(25, 28);
		delay(60);
		robo.acionarMotores(0, 0);
		delay(300);
		
		float time = millis(); // tempo atual de execução
		
		// procurando bola
		procurarBola(time); // loop {} usando recursion		
		
	}

	motores.parar(1);
	robo.ligarTodosLeds();
	while(1);
}

void Sala3::filtrarErros() {

	int contErros = 0;

	float leitura = 0;

	for(int i = 0; i < 10; i++) {

		if(contErros > 5) break;

		// se o lado da rampa a direita em relacao a frente da sala3 for (int i = 0; i < count; ++i)
		{
			/* code */
		} 
		if (fator_esq == 1) {
			leitura = robo.lerSensorSonarEsq();	
		} else {
			leitura = robo.lerSensorSonarDir();
		}	
		
		if(leitura > 90) {
			robo.ligarLed(2);
			delay(200);
			robo.desligarLed(2);
			i--;
			contErros++;
		} else {
			distanciaAtual += leitura;
		}

	}

	robo.desligarLed(2);

	distanciaAtual /= 10;
}

void Sala3::procurarBola(int time) {

	robo.acionarMotores(25, 28);

	// para testar pneu parado e outro girando
	int velEsq = 40;
	int velDir = 40; //

	int dif = distanciaAtual - distanciaAnterior;

	
	// ACHOU A BOLA!
	if(dif > 3.3 && dif < 30) { // testar if reduzido para a identificacao da bola

		// testando pneu parado e outro girando
		if(fator_esq == -1) { // lado da rampa direita
			velEsq = 0;
		} else { // esquerda
			velDir = 0;
		}

		// !! fatores invertidos	
		robo.acionarMotores(velEsq * fator_dir, velDir * fator_esq);
		delay(500);

		distanciaAnterior = miniDistanciaAtual;

		miniDistanciaAtual = robo.lerSensorSonarFrontal();

		pegarBola();

		robo.desligarTodosLeds();
		robo.ligarLed(1);
			
	} 
	else if((millis() - time) > 3100) { // calibrar esse tempo

		robo.ligarTodosLeds();

		motores.parar(0);

		if (!viu_bola) {

			robo.desligarTodosLeds();
			
			// inverte alinhamento anterior
			fator_esq *= -1;
			fator_dir *= -1;

			alinharParede(1);

			executar(1);
		} else {
			// ?	
		}
	} else {
		procurarBola(time);
	}
}

void Sala3::pegarBola() {
	
	robo.desligarTodosLeds();

	// testando tempo max de procura
	float max_time = millis();
	while((miniDistanciaAtual > 10) || ((millis() - max_time) > 500)){

		motores.parar(500);

		//distanciaAnterior = miniDistanciaAtual;
		robo.ligarLed(2);

		// procurar duas vezes e voltar
		for (int i = 0; i < 2; i++) {

			robo.acionarMotores(25, 27);
			motores.parar(500);

			// procurando para esq
			for (int j = 0; j < 3; j++) {
				
				// sentinela esq
				robo.ligarLed(3);
				robo.acionarMotores(-30, 0);
				motores.parar(300); // + 300 * j
				robo.desligarLed(3);//

				if (robo.lerSensorSonarFrontal() < 3.3) {
					loop(); // ...?
				}

			}

			// procurando para dir
			for (int j = 0; j < 3; j++) {

				// sentinela dir
				robo.ligarLed(1);
				robo.acionarMotores(-30, 0);
				motores.parar(300); // + 300 * j
				robo.desligarLed(1);// 

				if (robo.lerSensorSonarFrontal() < 3.3) {
					achouBola = true;
					loop(); // ...?
				}	

			}

			delay(300); // + 300 * j
		}

				

		miniDistanciaAtual  = robo.lerSensorSonarFrontal();

	}

	if (!achouBola) {
		// voltar e se alinhar
		robo.acionarMotores(-30, -30);
		delay(1200); // ? ++	
	} else {
		loop();
		//salvarBola();
	}
}

void Sala3::loop(){ 
	robo.acionarMotores(0, 0);
	robo.ligarTodosLeds();
	while(1);
}
