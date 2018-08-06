#ifndef GARRA_H
#define GARRA_H

#include <robo_hardware2.h>

#define ANG_INIT 90

#define TEMPO 20

class Garra {

	public:
		/*
		void iniciar() { 

			robo.acionarServoGarra1(90); 
			robo.acionarServoGarra2(90);

		}*/

		void subir();
		void baixar();
		void abrir();
		void fechar();
	
};

#endif