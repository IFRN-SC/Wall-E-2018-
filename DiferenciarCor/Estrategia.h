#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <robo_hardware.h>
#include "SensoresWallE.h"

class Estrategia {
	public:
		
		void executar();
		void calibrar(/*bool escolha*/);
		
		
	private:
		// bool realizarCali;
		Sensores sensor;
		
		bool desalinhado();
		void alinharObstaculo();
		
		bool viuObstaculo();
		
		void passeObstaculo();
		void sigaLinha();
};


#endif