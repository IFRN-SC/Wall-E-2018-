#include "Sala3.h"

Sala3::Sala3() {
	limite_lateral = 0;
	limite_frontal = 0;
}

void Sala3::setLimiteLateral(float valorLido) { limite_lateral = valorLido; }
void Sala3::setLimiteFrontal(float valorLido) { limite_frontal = valorLido; }

float Sala3::getLimiteLateral() { return limite_lateral; }
float Sala3::getLimiteFrontal() { return limite_frontal; }

void Sala3::executar(){

	// Passando do portal
	robo.acionarMotores(70, 73);
	delay(300);
 	robo.acionarMotores(30, 33);
	delay(100);
	
	motores.parar(300);

	// CONTANDO "DOIS PASSOS"

	for (int i = 0; i < 2; i++) {

		robo.ligarLed(3);
		robo.acionarMotores(40, 40);
		delay(120);
		robo.desligarLed(3);

	}

	alinharParede();

	for (int i = 0; i < 5; i++) {
		robo.ligarLed(2);
		// achou vitima esquerda
		if (robo.lerSensorSonarEsq() < 10) {

			motores.parar(500);

			robo.acionarMotores(-40, 40);
			delay(500);

			motores.parar(200);

			// corrigindo posicao
			while(robo.lerSensorSonarFrontal() > 25) {
				robo.acionarMotores(30, -30);
				delay(100);
				motores.parar(800);
			}

			robo.ligarTodosLeds();
			motores.parar(500);
			robo.desligarTodosLeds();

			while(robo.lerSensorSonarFrontal() > 5) {
				robo.acionarMotores(30, 33);	
			}

			while(1){ motores.parar(500); }
		} 
		// achou vitima direita
		else if (robo.lerSensorSonarDir() < 10) {

			motores.parar(500);

			robo.acionarMotores(40, -40);
			delay(500);

			motores.parar(200);

			// corrigindo posicao
			while(robo.lerSensorSonarFrontal() > 25) {
				robo.acionarMotores(30, -30);
				delay(100);
				motores.parar(800);
			}

			robo.ligarTodosLeds();
			motores.parar(500);
			robo.desligarTodosLeds();

			while(robo.lerSensorSonarFrontal() > 5) {
				robo.acionarMotores(30, 33);	
			}

			while(1){ motores.parar(0); }

		}
		else if (robo.lerSensorSonarFrontal() < 4) {
			
			while(1){ motores.parar(0); }

		} 
		else {
			motores.emFrente(30, 33);
		}
		robo.ligarLed(1);
	}

	robo.desligarLed(1);
	robo.desligarLed(2);

	motores.parar(0);
	while(1) {}

}

void Sala3::alinharParede(){

	motores.parar(500);
	
	robo.acionarMotores(40, -40);
	delay(450);

	motores.parar(500);

	motores.emFrente(30, 33);
	delay(800);

	robo.ligarTodosLeds();
	delay(100);
	robo.desligarTodosLeds();

	motores.emFrente(30, 33);
	delay(350);

	robo.ligarTodosLeds();
	while(robo.lerSensorSonarDir() < 20) { robo.acionarMotores(-40, 40); }
	robo.desligarTodosLeds();

	robo.acionarMotores(-40, 40);
	delay(200);

	encostarRobo();
}

void Sala3::encostarRobo() {
	
	robo.acionarMotores(-35, -35);
	delay(1000);

	robo.acionarMotores(30, 30);
	delay(250);

	robo.acionarMotores(-30, -30);
	delay(1000);	

	motores.parar(500);

}
