#ifndef GARRA_H
#define GARRA_H

#include <robo_hardware2.h>

class Garra {

	public:
		void iniciar() { 

			robo.acionarServoGarra1(90); 
			robo.acionarServoGarra2(90);

		} 

		void subir(int ang_inicial, int ang_final, int tempo);
		void baixar(int ang_inicial, int ang_final, int tempo);
		void abrir(int ang_inicial, int ang_final, int tempo);
		void fechar(int ang_inicial, int ang_final, int tempo);
	
};

#endif