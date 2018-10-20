#ifndef MOTORES_H
#define MOTORES_H

#include <robo_hardware2.h>

class Motores {
	private:
		#define VEL_DIR_FRENTE_RAMPA 92
		#define VEL_DIR_TRAS_RAMPA 70

		#define VEL_ESQ_FRENTE_RAMPA 85
		#define VEL_ESQ_TRAS_RAMPA 70

		#define VEL_DIR_FRENTE 52
		#define VEL_DIR_TRAS -52

		#define VEL_ESQ_FRENTE 45
		#define VEL_ESQ_TRAS -45
	public:
		inline void emFrente(){robo.acionarMotores(VEL_ESQ_FRENTE, VEL_DIR_FRENTE);}
		inline void direita(){robo.acionarMotores(VEL_ESQ_FRENTE, VEL_DIR_TRAS);} 
		inline void esquerda(){robo.acionarMotores(VEL_ESQ_TRAS, VEL_DIR_FRENTE);}  
		inline void paraTras(){robo.acionarMotores(VEL_ESQ_TRAS, VEL_DIR_TRAS);}

		inline void emFrenteRampa(){robo.acionarMotores(VEL_ESQ_FRENTE_RAMPA, VEL_DIR_FRENTE_RAMPA);}
		inline void direitaRampa(int decremento=0){robo.acionarMotores(VEL_ESQ_FRENTE_RAMPA, VEL_DIR_TRAS_RAMPA-decremento);} 
		inline void esquerdaRampa(int decremento=0){robo.acionarMotores(VEL_ESQ_TRAS_RAMPA-decremento, VEL_DIR_FRENTE_RAMPA);}  

		inline void parar(int tempo){robo.acionarMotores(0, 0); delay(tempo);}
};

#endif
