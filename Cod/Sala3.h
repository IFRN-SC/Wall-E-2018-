#ifndef SALA3_H
#define SALA3_H

class Sala3 {
	private:
		float limite_lateral;
		float limite_frontal;

	public:

		Sala3();

		void executar();

		void setLimiteLateral(float valorLido);
		void setLimiteFrontal(float valorLido);
		
		float getLimiteLateral();
		float getLimiteFrontal();

};

#endif