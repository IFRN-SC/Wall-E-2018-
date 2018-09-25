#ifndef REFLETANCIA_H
#define REFLETANCIA_H

#include "Matematica.h"

class Refletancia {
	public:
		void setBrancoMini(float valorBranco);
		void setPretoMax(float valorPreto);
		void setMedia(float valorSalvo);

		//void descartarValores();

		float getSeparacao();
		float getMinimoBranco();
		float getMaximoPreto();

		void calculeMedia();
		inline void resetPreto(){maximoPreto = 0;};
		inline void resetBranco(){minimoBranco = 101;};

		Refletancia();
		
	private:
		float minimoBranco;
		float maximoPreto;
		float media;

		Matematica calcule;
};
		

#endif