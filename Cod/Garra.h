#ifndef GARRA_H
#define GARRA_H

#include <robo_hardware2.h>

class Garra {

	private:
		#define DELAY 10
		
		#define ANG_INICIAL_SUBIR_BRACO 10
		#define ANG_FINAL_SUBIR_BRACO 110

		#define ANG_INICIAL_BAIXAR_BRACO 110
		#define ANG_FINAL_BAIXAR_BRACO 10

		#define ANG_INICIAL_ABRIR_MAO 100
		#define ANG_FINAL_ABRIR_MAO 180

		#define ANG_INICIAL_FECHAR_MAO 180
		#define ANG_FINAL_FECHAR_MAO 100
	public:
		void iniciar() { 

			robo.acionarServoGarra1(90); 
			robo.acionarServoGarra2(90);

		} 

		void setMao(int angInicial, int angFinal, int tempo);
		void setBraco(int angInicial, int angFinal, int tempo);
		
		inline void subir()  { robo.acionarServoGarra2(ANG_INICIAL_SUBIR_BRACO,ANG_FINAL_SUBIR_BRACO, DELAY); }
		inline void baixar() { robo.acionarServoGarra2(ANG_INICIAL_BAIXAR_BRACO,ANG_FINAL_BAIXAR_BRACO, DELAY); }
		inline void abrir()  { robo.acionarServoGarra1(ANG_INICIAL_ABRIR_MAO,ANG_FINAL_ABRIR_MAO, DELAY); }
		inline void fechar() { robo.acionarServoGarra1(ANG_INICIAL_FECHAR_MAO,ANG_FINAL_FECHAR_MAO, DELAY); }
	
};

#endif