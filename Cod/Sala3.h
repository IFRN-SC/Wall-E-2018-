#ifndef SALA3_H	
#define SALA3_H

#include <robo_hardware2.h>
#include "Motores.h"
#include "Garra.h"

class Sala3 {
	private:

		// Dependendo da posicao da rampa
		int fator_esq;
		int fator_dir;

		bool ladoA;
		bool ladoB;
		bool ladoC;

		// area de resgate
		int qntVerificoes;

		int qntExecucoes;
		int tParede;

		bool viu_bola;

		Motores motores;
		Garra garra;

		void alinharParede(int qnt);

		void acharArea(int lado);

		void sentinela();

		void procurarBola(int time);
		void salvarBola();
		//void pegarBola();
		void encostarRobo();

		void filtrarErros();
		void ledSinal(int i);

		void loop();

	public:

		Sala3();

		void portal();

		void executar(int args);

};

#endif