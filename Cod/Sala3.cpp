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

	alinharParede();

	while(1) {
		
		robo.acionarMotores(30, 30);
		
		if (robo.lerSensorSonarEsq() < limite_lateral) {
			motores.parar(500);

			robo.acionarMotores(-40, 40);
			delay(500);

			while(robo.lerSensorSonarFrontal() > 5) {
				robo.acionarMotores(30, 30);	
			}

			motores.parar(500);

			while(1){}

		}
		if (robo.lerSensorSonarFrontal() < limite_frontal) {
			motores.parar(500);

			while(robo.lerSensorSonarFrontal() > 5) {
				robo.acionarMotores(30, 30);	
			}

			motores.parar(500);

			while(1){}

		}
	}

}

void Sala3::alinharParede(){

	// Passando do portal
	robo.acionarMotores(70, 70);
	delay(300);
	robo.acionarMotores(30, 30);
	delay(100);
	
	motores.parar(300);

	// CONTANDO "DOIS PASSOS"

	for (int i = 0; i < 2; i++) {
		robo.ligarLed(3);
		robo.acionarMotores(40, 40);
		delay(100);
		robo.desligarLed(3);
	}

	motores.parar(500);
	
	// SE ALINHANDO NA PAREDE
	robo.acionarMotores(40, -40);
	delay(500);

	motores.parar(500);

	robo.acionarMotores(-35, -35);
	delay(250);

	robo.acionarMotores(30, 30);
	delay(250);

	robo.acionarMotores(-30, -30);
	delay(1000);	

	motores.parar(500);
	
}
