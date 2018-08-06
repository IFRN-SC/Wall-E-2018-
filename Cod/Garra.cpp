#include "Garra.h"

void Garra::subir(int ang_inicial, int ang_final, int tempo) {

	for(int i = ang_inicial; i >= ang_final; i++){

		robo.acionarServoGarra1(i);
		delay(tempo);

	}

}

void Garra::baixar(int ang_inicial, int ang_final, int tempo) {

	for(int i = ang_inicial; i >= ang_final; i--){

		robo.acionarServoGarra1(i);
		delay(tempo);

	}

}

void Garra::abrir(int ang_inicial, int ang_final, int tempo) {

	for(int i = ang_inicial; i >= ang_final; i--){

		robo.acionarServoGarra2(i);
		delay(tempo);

	}

}

void Garra::fechar(int ang_inicial, int ang_final, int tempo) {

	for(int i = ang_inicial; i >= ang_final; i++){

		robo.acionarServoGarra2(i);
		delay(tempo);

	}

}