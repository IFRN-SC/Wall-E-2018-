#ifndef SALA3_H
#define SALA3_H

#include <robo_hardware2.h>
#include "Motores.h"

class Sala3 {
	private:
		float limite_lateral;
		float limite_frontal;

		char ladoRampa;

		Motores motores;

		void alinharParede();
		void alinharParede2();

		void encostarRobo();

	public:

		Sala3();

		void executar();

		void setLimiteLateral(float valorLido);
		void setLimiteFrontal(float valorLido);
		
		float getLimiteLateral();
		float getLimiteFrontal();

};

#endif