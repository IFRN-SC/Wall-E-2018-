#ifndef MOTORES_H
#define MOTORES_H

#include <robo_hardware2.h>

class Motores {
	public:
		void emFrente(int velEsq, int velDir){robo.acionarMotores(velEsq, velDir);}
		void direita(int velEsq, int velDir){robo.acionarMotores(velEsq, velDir*(-1));}   // Delirante
		void esquerda(int velEsq, int velDir){robo.acionarMotores(velEsq*(-1), velDir);}  // Com fome
		void paraTras(int velEsq, int velDir){robo.acionarMotores(velEsq*(-1), velDir*(-1));}
		void parar(int tempo){robo.acionarMotores(0, 0); delay(tempo);}
};

#endif
