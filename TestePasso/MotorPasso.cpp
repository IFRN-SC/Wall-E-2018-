#include "MotorPasso.h"

MotorPasso::MotorPasso(const int passosPorRotacaoEsq,
				   	   const int passosPorRotacaoDir): 
		PASSOS_POR_ROTACAO_ESQ(passosPorRotacaoEsq), PASSOS_POR_ROTACAO_DIR(passosPorRotacaoDir),
		
		passoEsq(PASSOS_POR_ROTACAO_ESQ, PINO_PASSO_ESQ_1, PINO_PASSO_ESQ_3, PINO_PASSO_ESQ_2, PINO_PASSO_ESQ_4),
		passoDir(PASSOS_POR_ROTACAO_DIR, PINO_PASSO_DIR_1, PINO_PASSO_DIR_3, PINO_PASSO_DIR_2, PINO_PASSO_DIR_4)

{}

MotorPasso::MotorPasso():
		PASSOS_POR_ROTACAO_ESQ(PASSOS_POR_ROTACAO_ESQ_DEFAULT), PASSOS_POR_ROTACAO_DIR(PASSOS_POR_ROTACAO_DIR_DEFAULT),
		
		passoEsq(PASSOS_POR_ROTACAO_ESQ, PINO_PASSO_ESQ_1, PINO_PASSO_ESQ_3, PINO_PASSO_ESQ_2, PINO_PASSO_ESQ_4),
		passoDir(PASSOS_POR_ROTACAO_DIR, PINO_PASSO_DIR_1, PINO_PASSO_DIR_3, PINO_PASSO_DIR_2, PINO_PASSO_DIR_4)
{}

void MotorPasso::acionarMotorPasso(int velEsq, int velDir){
	this->velEsq = converteRPM(velEsq);
	this->velDir = converteRPM(velDir);

	passoEsq.setSpeed(this->velEsq);
	passoDir.setSpeed(this->velDir);

	int nPassoEsq = N_PASSOS_ESQ;
	int nPassoDir = N_PASSOS_DIR;

	if(velEsq < 0) nPassoEsq *= -1;
	if(velDir < 0) nPassoDir *= -1;
	
	passoEsq.step(nPassoEsq);
	passoDir.step(nPassoDir);
}

void MotorPasso::acionarAngEsq(float ang, int vel=50){
	this->velEsq = converteRPM(vel);
	passoEsq.setSpeed(this->velEsq);

	int nPassos = map(abs(ang), 0, 360, 0, PASSOS_POR_ROTACAO_ESQ);
	
	if(ang < 0) nPassos *= -1;
	passoEsq.step(nPassos);
}

void MotorPasso::acionarAngDir(float ang, int vel=50){
	this->velDir = converteRPM(vel);
	passoDir.setSpeed(this->velDir);

	int nPassos = map(abs(ang), 0, 360, 0, PASSOS_POR_ROTACAO_DIR);
	
	if(ang < 0) nPassos *= -1;
	passoDir.step(nPassos);
}

