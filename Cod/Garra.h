#ifndef GARRA_H
#define GARRA_H

#include <robo_hardware2.h>

class Garra {

	private:
		#define TEMP 20

	public:
		void iniciar() { 

			robo.acionarServoGarra1(90); 
			robo.acionarServoGarra2(90);

		} 

		void setMao(int angInicial, int angFinal, int tempo);
		void setBraco(int angInicial, int angFinal, int tempo);
		
		void subir();
		void baixar();
		void abrir();
		void fechar();
	
};

#endif