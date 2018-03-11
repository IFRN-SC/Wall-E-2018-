#ifndef REFLETANCIA_H
#define REFLETANCIA_H

#include "Matematica.h"

class Refletancia {
	public:
		void setBrancoMini(float valorBranco);
		void setPretoMax(float valorPreto);
		void setMedia(float valorSalvo);

		float getSeparacao();
		float getMinimoBranco();
		float getMaximoPreto();

		void calculeMedia();

		Refletancia();
		
	private:
		float lala;
		float minimoBranco;
		float maximoPreto;
		float media;

		Matematica calcule;
};
		

#endif