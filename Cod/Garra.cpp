#include "Garra.h"

void Garra::setBraco(int angInicial, int angFinal, int tempo){
	if(angFinal > angInicial){
		for(int i = angInicial; i < angFinal; i++){
			robo.acionarServoGarra2(i);
			delay(tempo);
		}
	}else{
		for(int i = angInicial; i > angFinal; i--){
			robo.acionarServoGarra2(i);
			delay(tempo);
		}
	}
}

void Garra::setMao(int angInicial, int angFinal, int tempo){
	if(angFinal > angInicial){
		for(int i = angInicial; i < angFinal; i++){
			robo.acionarServoGarra1(i);
			delay(tempo);
		}
	}else{
		for(int i = angInicial; i > angFinal; i--){
			robo.acionarServoGarra1(i);
			delay(tempo);
		}
	}
}
void Garra::subir() {setBraco(10, 80, TEMP);}
void Garra::baixar() {setBraco(90, 10, TEMP);}
void Garra::abrir() {setMao(90, 0, TEMP);}
void Garra::fechar() {setMao(0, 120, TEMP);}