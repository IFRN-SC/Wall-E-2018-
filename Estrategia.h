#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <robo_hardware.h>
#include "SensoresWallE.h"

#define ESQUERDA 1
#define DIREITA 2

class Estrategia {
	public:
		
		void executar();
		void calibrar(/*bool escolha*/);
		
		void configurar();
		
		
	private:
		// bool realizarCali;
		Sensores sensor;
		int contAlternadas = 0;
		int indicador;
		bool desalinhado();
		bool viuObstaculo();
		
		void para(int tempo);
		
		void alinharEncruzilhada();
		void alinharObstaculo();
		void passeEncruzilhadaDireita();
		void passeEncruzilhadaEsquerda();
		void passeObstaculo();
		void sigaLinha();
};


#endif