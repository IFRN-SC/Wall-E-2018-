#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <robo_hardware.h>
#include "SensoresWallE.h"
#include "Movimentacao.h"
#include "Calibracao2.h"



class Estrategia {
	public:
		
		void executar();
		void calibrar();
		
		void configurar();
	private:
		// bool realizarCali;
		#define ESQUERDA 1
		#define DIREITA 2
		#define VELPADRAO 40

		int t;
		Movimentacao mova;
		Sensores sensor;
		int contAlternadas = 0;
		int indicador;
		bool desalinhado(); 
		bool viuObstaculo();
		
		void para(int tempo);
		void passeVerde();
		void alinharEncruzilhada();
		void alinharObstaculo();
		void passeEncruzilhadaDireita();
		void passeEncruzilhadaEsquerda();
		void passeObstaculo();
		void sigaLinha();
    	void passeVerdeOuRedutor();
    	void vireEsquerda();
    	void vireDireita();
    	void piscarLeds();
};


#endif
