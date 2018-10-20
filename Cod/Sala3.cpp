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
	delay(200);
 	robo.acionarMotores(30, 33);
	delay(100);
	
	motores.parar(300);

	alinharParede();

	
	float distanciaAtual = 123;
	int j = 0;
	
	float time = millis();
	while(1){
		++j;
		
		float distanciaAnterior = distanciaAtual;
		int contErros = 0;

		for(int i = 0; i < 10; i++){

			if(contErros > 5) break;

			float leitura = robo.lerSensorSonarEsq();	
			
			if(leitura > 70){
				i--;
				contErros++;
			}else{
				distanciaAtual += leitura;
			}


		}
		
		distanciaAtual /= 10;
		
		
		if (j == 1) {
			robo.acionarMotores(25, 28);
			delay(50);
			robo.acionarMotores(0, 0);
			delay(100);
		} else {
			robo.acionarMotores(25, 28);	
		}

		float miniDistanciaAtual = 123;
		if((distanciaAtual - distanciaAnterior) > 3.3)
		{
			robo.ligarLed(3);
			robo.acionarMotores(-40, 40);
			delay(450);

			distanciaAnterior = miniDistanciaAtual;

			miniDistanciaAtual = robo.lerSensorSonarFrontal();

			while(miniDistanciaAtual > 10){

				//distanciaAnterior = miniDistanciaAtual;
				robo.ligarLed(2);
				robo.acionarMotores(25, 27);
				//delay(50);
				//robo.desligarLed(2);
				//motores.parar(100);
				
				miniDistanciaAtual  = robo.lerSensorSonarFrontal();

			}
			break;	
		}
		if((millis() - time) > 3100) {
			robo.ligarLed(1);
			motores.parar(1);
			while(1);	
		}
	}

	motores.parar(1);
	robo.ligarTodosLeds();
	while(1);

}

void Sala3::alinharParede(){

	motores.parar(500);
	
	robo.acionarMotores(40, -40);
	delay(450);

	motores.parar(500);

	encostarRobo();

	robo.acionarMotores(30, 33);
	delay(100);

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
