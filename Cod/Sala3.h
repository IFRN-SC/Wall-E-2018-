#ifndef SALA3_H	
#define SALA3_H

#include <robo_hardware2.h>
#include "Motores.h"

class Sala3 {
	private:
		/* @Depreciating...
		float limite_lateral;
		float limite_frontal;*/

		float distanciaAnterior;
		float distanciaAtual;
		float miniDistanciaAtual;

		// Dependendo da posicao da rampa
		int fator_esq;
		int fator_dir;

		int time_parede;

		bool viu_bola;

		Motores motores;

		void alinharParede(int qnt);

		void procurarBola(int time);
		void pegarBola();

		void encostarRobo();

		void filtrarErros();
		void ledSinal(int i);

		void loop();

	public:

		Sala3();

		void portal();

		void executar(int args);

		/* @Depreciating...
		void setLimiteLateral(float valorLido);
		void setLimiteFrontal(float valorLido);
		
		float getLimiteLateral();
		float getLimiteFrontal();*/

};

#endif