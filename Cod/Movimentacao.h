#include <robo_hardware.h>

class Movimentacao {
	public:
		void emFrente(int velEsq, int velDir){robo.acionarMotores(velEsq, velDir);}
		void direita(int velEsq, int velDir){robo.acionarMotores(velEsq, velDir*(-1));}   // Delirante
		void esquerda(int velEsq, int velDir){robo.acionarMotores(velEsq*(-1), velDir);}  // Com fome
		void paraTras(int velEsq, int velDir){robo.acionarMotores(velEsq*(-1), velDir*(-1));}
};
