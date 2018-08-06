#include "Garra.h"

void Garra::subir() {

	for(int i = ANG_INIT; i >= 0; i++){

		robo.acionarServoGarra1(i);
		delay(TEMPO);

	}

}

void Garra::baixar() {

	for(int i = ANG_INIT; i >= 0; i--){

		robo.acionarServoGarra1(i);
		delay(TEMPO);

	}

}

void Garra::abrir() {

	for(int i = ANG_INIT; i >= 0; i--){

		robo.acionarServoGarra2(i);
		delay(TEMPO);

	}

}

void Garra::fechar() {

	for(int i = 0; i >= ANG_INIT; i++){

		robo.acionarServoGarra2(i);
		delay(TEMPO);

	}

}