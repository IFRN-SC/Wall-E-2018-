#ifndef GARRA_H
#define GARRA_H

#include <robo_hardware2.h>

class Garra {

	private:
		#define DELAY 20
		
		#define ANG_INICIAL_SUBIR_BRACO 10
		#define ANG_FINAL_SUBIR_BRACO 80

		#define ANG_INICIAL_BAIXAR_BRACO 80
		#define ANG_FINAL_BAIXAR_BRACO 10

		#define ANG_INICIAL_ABRIR_MAO 90
		#define ANG_FINAL_ABRIR_MAO 0

		#define ANG_INICIAL_FECHAR_MAO 0
		#define ANG_FINAL_FECHAR_MAO 90
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