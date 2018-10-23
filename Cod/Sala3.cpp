#include "Sala3.h"

Sala3::Sala3() {
	limite_lateral = 0;
	limite_frontal = 0;
	fator_esq = 1;
	fator_dir = 1;

	distanciaAtual = 170;

	viu_bola = false;
}

void Sala3::setLimiteLateral(float valorLido) { limite_lateral = valorLido; }
void Sala3::setLimiteFrontal(float valorLido) { limite_frontal = valorLido; }

float Sala3::getLimiteLateral() { return limite_lateral; }
float Sala3::getLimiteFrontal() { return limite_frontal; }

void Sala3::portal() {
	// Passando do portal
	robo.acionarMotores(70, 73);
	delay(200);
 	robo.acionarMotores(30, 33);
	delay(100);
	
	motores.parar(300);

	alinharParede(0);

	executar(0);
}

void Sala3::executar(int args){

	if (args != 0) {
		// se o lado da rampa for a direita em relacao a frente da sala3
		if (fator_esq == 1) {
			distanciaAtual = robo.lerSensorSonarEsq();	
		} else {
			distanciaAtual = robo.lerSensorSonarDir();
		}	
	} else {
		robo.acionarMotores(0, 0);
		while(1) {

		}
	}

	int j = 0;
	
	float time = millis();

	float leitura = 0;

	while(1){
		++j;
		
		float distanciaAnterior = distanciaAtual;
		int contErros = 0;

		for(int i = 0; i < 10; i++){

			if(contErros > 5) break;

			// se o lado da rampa for a direita em relacao a frente da sala3
			if (fator_esq == 1) {
				leitura = robo.lerSensorSonarEsq();	
			} else {
				leitura = robo.lerSensorSonarDir();
			}	
			
			if(leitura > 60){
				robo.ligarLed(2);
				i--;
				contErros++;
			}else{
				distanciaAtual += leitura;
			}

			robo.desligarLed(2);

		}
		
		distanciaAtual /= 10;
		
		if (j == 1) {
			robo.acionarMotores(25, 28);
			delay(50);
			robo.acionarMotores(0, 0);
			delay(100);
		}

		robo.acionarMotores(25, 28);

		float miniDistanciaAtual = 123;

		int velEsq = 40;
		int velDir = 40;

		if((distanciaAtual - distanciaAnterior) > 3.3)
		{
			robo.ligarLed(3);

			// testando pneu parado e outro girando
			if(fator_esq == -1) {
				velEsq = 0;
			} else {
				velDir = 0;
			}

			// !! fatores invertidos	
			robo.acionarMotores(velEsq * fator_dir, velDir * fator_esq);
			delay(500);

			distanciaAnterior = miniDistanciaAtual;

			miniDistanciaAtual = robo.lerSensorSonarFrontal();

			procurarBola();

			robo.desligarTodosLeds();
			robo.ligarLed(1);
				
		}
		if((millis() - time) > 3100) {

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
				while(1);	
			}
				
		}
	}

	motores.parar(1);
	robo.ligarTodosLeds();
	while(1);

}

void Sala3::procurarBola() {
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
				robo.acionarMotores(-30, 0);
				motores.parar(300); // + 300

				if (robo.lerSensorSonarFrontal() < 3.3) {
					motores.parar(0);
					robo.ligarTodosLeds();
					while(1);
				}

				//voltar
				if (j == 3) {

				}	

			}

			// procurando para dir
			for (int j = 0; j < 3; j++) {
				robo.acionarMotores(-30, 0);
				motores.parar(300); // + 300

				if (robo.lerSensorSonarFrontal() < 3.3) {
					motores.parar(0);
					robo.ligarTodosLeds();
					while(1);
				}	

			}

			delay(300); // + 30
		}

		// se nao achou
		robo.acionarMotores(-30, -30);
		delay(1200);

		motores.parar(0);
		robo.ligarTodosLeds();
		while(1);				


		//delay(50);
		//robo.desligarLed(2);
		//motores.parar(100);
		
		miniDistanciaAtual  = robo.lerSensorSonarFrontal();

	}

	while(1) {
		robo.acionarMotores(0, 0);
	}

	if (miniDistanciaAtual < 10) {
		viu_bola = true;	
	} else {
		/* procurar bola por um tempo...
		senao achou, voltar para a parede e procurar novamente*/
		// executar()?
	}
}

void Sala3::alinharParede(int qnt){

	// se qnt for 0, entao é a primeira vez que o robo alinha
	if (qnt == 0) {

		// lado da rampa posicionado a direita em relacao a frente da sala 3
		if (robo.lerSensorSonarEsq() > robo.lerSensorSonarDir()) {
			fator_esq = -1;
			fator_dir = 1;
		} else {
			fator_esq = 1;
			fator_dir = -1;
		}	
	} else {
	
		// prepara o giro de 270
		motores.parar(500);

		robo.acionarMotores(40 * fator_esq, 40 * fator_dir);
		delay(450);				

		motores.parar(500);

		robo.acionarMotores(40, 40);
		delay(300);				

		motores.parar(500);

	}

	motores.parar(500);

	robo.acionarMotores(40 * fator_esq, 40 * fator_dir);
	delay(450);

	motores.parar(500);

	encostarRobo();

	/*
	robo.acionarMotores(30, 33);
	delay(100);*/

	/*robo.acionarMotores(30, 33);
	delay(800);

	robo.ligarTodosLeds();
	delay(100);
	robo.desligarTodosLeds();

	robo.acionarMotores(30, 33);
	delay(350);

	robo.ligarTodosLeds();
	while(robo.lerSensorSonarDir() < 20) { robo.acionarMotores(-40, 40); }
	robo.desligarTodosLeds();

	robo.acionarMotores(-40, 40);
	delay(450);

	encostarRobo();*/
}

void Sala3::encostarRobo() {
	
	robo.acionarMotores(-35, -35);
	delay(1200);

	robo.acionarMotores(30, 30);
	delay(250);

	robo.acionarMotores(-30, -30);
	delay(1200);	

	motores.parar(500);

}
