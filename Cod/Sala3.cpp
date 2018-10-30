#include "Sala3.h"

Sala3::Sala3() {
	fator_esq = 1;
	fator_dir = 1;

	ladoA = false;
	ladoB = false;
	ladoC = false;

	qntVerificoes = 0;
	qntExecucoes = 0;

	tParede = 4200;

	viu_bola = false;
}

void Sala3::portal() {

	// passando do portal
 	robo.acionarMotores(30, 33);
	delay(100);
	
	motores.parar(300);

	alinharParede(0);
	
	// saindo da parede
	robo.acionarMotores(30, 30);
	delay(30);
	robo.acionarMotores(0, 0);//

	acharArea(1);
	acharArea(2);

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

			// sinaliza o lado
			ledSinal(1);
		
		} else { // lado da rampa: esquerda
			
			fator_esq = 1;
			fator_dir = -1;

			// sinaliza o lado
			ledSinal(3);

		}

		motores.parar(500);
		
	} else { // outros alinhamentos
		
		fator_esq *= -1;
		fator_dir *= -1;

		if (fator_esq == -1) {
			ledSinal(3);
		} else {
			ledSinal(1);
		}

		// prepara o giro de 270
		motores.parar(500);

		// @? testar roda parada e outra girando
		robo.acionarMotores(40 * fator_esq, 40 * fator_dir);
		delay(400);				

		motores.parar(500);

		robo.acionarMotores(40, 40);
		delay(300);				

		motores.parar(500);//

	}

	//acharArea(2);

	// gira pro alinhamento
	robo.acionarMotores(40 * fator_esq, 40 * fator_dir);
	delay(450);

	motores.parar(500);
	encostarRobo();

	//acharArea(1);
	
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

void Sala3::acharArea(int lado) {

	++qntVerificoes;

	robo.ligarTodosLeds();
	delay(1000);
	robo.desligarTodosLeds();
	
	if (!ladoA && !ladoB && !ladoC) {
		
		float valorLido = 0;

		for (int i = 0; i < 2; i++) {
			if (lado == 1) { // ladoA
				valorLido += robo.lerSensorSonarEsq();
			} else { // ladoB
				valorLido += robo.lerSensorSonarFrontal();
			}
			delay(300);
		}

		if ((valorLido/2) >= 70) { // entao achou a area
			if (lado == 1) { //ladoA
				ledSinal(1);
				ladoA = true;
			} else { // ladoB
				ledSinal(2);
				ladoB = true;
			}
		} else {
			if (qntVerificoes == 1) { // entao ladoC
				ledSinal(3);
				ladoC = true;
			}
		}

	}

	delay(1000);
	robo.desligarTodosLeds();
}

void Sala3::executar(int args){

	++qntExecucoes;

	float tInicial = millis();
	float tAtual = millis();

	garra.abrir();
	garra.baixar();

	if (ladoB) {
		tParede -= 500;
	}

	while ((tAtual - tInicial) < tParede) {
		robo.acionarMotores(20, 24);
		tAtual = millis();
	}

	garra.fechar();

	// ir um pouco para tras e verificar a bola na garra
	robo.ligarLed(2);
	motores.parar(400);
	robo.acionarMotores(-25, -27);
	delay(800);
	robo.desligarLed(2);//

	motores.parar(300);

	garra.abrir();
	garra.subir();

	if (robo.lerSensorSonarFrontal() <= 10) {
		viu_bola = true;
	}

	if (viu_bola) {
		salvarBola();
	} else {

		sentinela();

		robo.acionarMotores(28, 30);
		delay(200);

		alinharParede(qntExecucoes);
		executar(1);
	}

}

void Sala3::salvarBola() {

	garra.baixar();
	garra.fechar();
	garra.subir();

	fator_esq *= -1;
	fator_dir *= -1;

	robo.acionarMotores(40 * fator_esq, 40 * fator_dir);
	delay(400);

	float tInicial = millis();
	float tAtual = millis();

	while ((tAtual - tInicial) < 600) {
		robo.acionarMotores(20, 24);
		tAtual = millis();
	}

	motores.parar(300);

	if (ladoA) {
		robo.acionarMotores(40 , -40);
		delay(450);
	} /*else if (ladoB) {
		robo.acionarMotores(-40, 40);
		delay(450);
	} */else {
		robo.acionarMotores(-40, 40);
		delay(450);
	}

	encostarRobo();

	robo.acionarMotores(28, 30);
	delay(400);

	motores.parar(300);

	robo.acionarMotores(40 * fator_esq, 40 * fator_dir);
	delay(800);

	motores.parar(300);

	garra.baixar();
	garra.abrir();

	loop(); //  :)))))))))))))))))))))))))

}

void Sala3::sentinela() {
	// procurar duas vezes e voltar
	for (int i = 0; i < 2; i++) {

		// procurando para esq
		for (int j = 0; j < 3; j++) {
			
			// sentinela esq
			robo.ligarLed(3);
			robo.acionarMotores(-30, 30);
			delay(200);
			motores.parar(300);
			robo.desligarLed(3);//

			if (robo.lerSensorSonarFrontal() < 3.3) {
				viu_bola = true;
				ledSinal(3);
			}

		}

		// procurando para dir
		for (int j = 0; j < 3; j++) {

			// sentinela dir
			robo.ligarLed(1);
			robo.acionarMotores(30, -30);
			delay(200);
			motores.parar(400);
			robo.desligarLed(1);// 

			if (robo.lerSensorSonarFrontal() < 3.3) {
				viu_bola = true;
				ledSinal(1);
			}	

		}

		delay(300);
	}

	if (viu_bola) {
		salvarBola();
	}
}

/*
void Sala3::filtrarErros() {


	// evita erros
	ledSinal(2);
	robo.acionarMotores(30, 30);
	delay(30);//

	int contErros = 0;

	float leitura = 0;

	// sinalizacao do filtro
	robo.ligarLed(2);
	motores.parar(150);
	robo.ligarLed(1);
	robo.desligarLed(2);
	delay(30);
	robo.desligarLed(1);//

	for(int i = 0; i < 10; i++) {

		if(contErros > 5) {
			robo.desligarTodosLeds();
			robo.acionarMotores(30, 30);
			delay(20);
			robo.acionarMotores(0, 0);
			--contErros;
		}

		// se o lado da rampa a direita em relacao a frente da sala3 
		if (fator_esq == 1) {
			ledSinal(3);
			leitura = robo.lerSensorSonarEsq();	
		} else {
			ledSinal(1);
			leitura = robo.lerSensorSonarDir();
		}	
		
		if(leitura > 70) {
			ledSinal(2);
			i--;
			contErros++;
		} else {
			ledSinal(1);
			distanciaAtual += leitura;
		}

	}

	robo.desligarTodosLeds();

	distanciaAtual /= 10;
}

void Sala3::procurarBola(int time) {

	robo.desligarTodosLeds();

	robo.acionarMotores(25, 28);

	// para testar pneu parado e outro girando
	int velEsq = 40;
	int velDir = 40;//

	distanciaAnterior = distanciaAtual;

	// se o lado da rampa a direita em relacao a frente da sala3 
	if (fator_esq == 1) {
		robo.ligarLed(3);
		distanciaAtual = robo.lerSensorSonarEsq();
	} else {
		robo.ligarLed(1);
		distanciaAtual = robo.lerSensorSonarDir();
	}

	float dif = distanciaAtual - distanciaAnterior;
	
	// ACHOU A BOLA!
	if(dif > 3.3 && dif < 10) { // testar if reduzido para a identificacao da bola	

		robo.desligarTodosLeds();
		motores.parar(200);

		// se o lado da rampa a direita em relacao a frente da sala3 
		
		distanciaAnterior = distanciaAtual;

		if (fator_esq == 1) {
			robo.ligarLed(3);
			miniDistanciaAtual = robo.lerSensorSonarEsq();
		} else {
			robo.ligarLed(1);
			miniDistanciaAtual = robo.lerSensorSonarDir();
		}

		robo.acionarMotores(-30, -30);
		delay(20);
		//time_parede += 100;

		dif = miniDistanciaAtual - distanciaAnterior;

		if (dif > 3.3 && dif < 10) {
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
		} else {
			ledSinal(2);
			procurarBola(time);
		}
			
	} 
	else if((millis() - time) > tParede) { // calibrar esse tempo

		robo.ligarTodosLeds();

		motores.parar(0);

		if (!viu_bola) {

			robo.desligarTodosLeds();
			
			// inverte alinhamento anterior
			fator_esq *= -1;
			fator_dir *= -1;

			alinharParede(1);

			executar(1);
		} 
	} else {
		procurarBola(time); // foi mial recursion
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
					viu_bola = true;
					loop(); // ...?
				}	

			}

			delay(300); // + 300 * j
		}

				

		miniDistanciaAtual  = robo.lerSensorSonarFrontal();

	}

	if (!viu_bola) {
		// voltar e se alinhar
		robo.acionarMotores(-30, -30);
		delay(1200); // ? ++	
	} else {
		loop();
		//salvarBola();
	}
}
*/
void Sala3::ledSinal(int i) {
	robo.ligarLed(i);
	delay(200);
	robo.desligarLed(i);
}

void Sala3::loop(){ 
	robo.acionarMotores(0, 0);
	robo.ligarTodosLeds();
	while(1);
}
