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
void Garra::subir() {setBraco(ANG_INICIAL_SUBIR_BRACO, ANG_FINAL_SUBIR_BRACO, DELAY);}
void Garra::baixar() {setBraco(ANG_INICIAL_BAIXAR_BRACO, ANG_FINAL_BAIXAR_BRACO, DELAY);}
void Garra::abrir() {setMao(ANG_INICIAL_ABRIR_MAO, ANG_FINAL_ABRIR_MAO, DELAY);}
void Garra::fechar() {setMao(ANG_INICIAL_FECHAR_MAO, ANG_FINAL_FECHAR_MAO, DELAY);}