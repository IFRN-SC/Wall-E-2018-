#ifndef MOTORPASSO_H
#define MOTORPASSO_H

#include <Arduino.h>
#include <Stepper.h>

class MotorPasso{
	public:
		MotorPasso(const int passosPorRotacaoEsq,
				   const int passosPorRotacaoDir);
		MotorPasso();

		void acionarMotorPasso(int velEsq, int velDir);
		void acionarAngEsq(float ang, int vel);
		void acionarAngDir(float ang, int vel);

	private: 
		#define VELMAX 800

		#define N_PASSOS_DIR 1;
		#define N_PASSOS_ESQ 1;

		#define PINO_PASSO_DIR_1 5
		#define PINO_PASSO_DIR_2 6
		#define PINO_PASSO_DIR_3 7
		#define PINO_PASSO_DIR_4 8

		#define PINO_PASSO_ESQ_1 10
		#define PINO_PASSO_ESQ_2 11
		#define PINO_PASSO_ESQ_3 12
		#define PINO_PASSO_ESQ_4 13

		#define PASSOS_POR_ROTACAO_ESQ_DEFAULT 64
		#define PASSOS_POR_ROTACAO_DIR_DEFAULT 64

		const int PASSOS_POR_ROTACAO_DIR;
		const int PASSOS_POR_ROTACAO_ESQ;
		
		Stepper passoEsq, passoDir;

		int velEsq, velDir;
		inline int converteRPM(int velEmPercentual){return map(abs(velEmPercentual), 0, 100, 0, VELMAX);}
};

#endif