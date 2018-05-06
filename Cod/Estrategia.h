#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <robo_hardware2.h>
#include "SensoresWallE.h"
#include "Motores.h"
#include "Calibracao2.h"
#include "Botao.h"


class Estrategia {
	public:
		Estrategia();
		void executar();
		void calibrar();
		
		void configurar();
	private:
		// bool realizarCali;

		// CONSTANTES
		#define ESQUERDA 1
		#define DIREITA 2
		#define VELPADRAO 50
		#define FIM_DE_CURSO 12

		// VARIÁVEIS
		int t;
		int contAlternadas = 0;
		int indicador;
		
		// OBJETOS 		
		Botao fimDeCurso;
		Motores motores;
		Sensores sensor;
		
		// LINHA
		void sigaLinha();
		void alinharEncruzilhada();
		void passeEncruzilhada_Direita();
		void passeEncruzilhada_Esquerda();
    	void passeVerdeOuRedutor();
    	
    	// MOVIMENTAÇÃO
    	void vireEsquerda();
    	void vireDireita();

		// OBSTÁCULO
		bool viuObstaculo();
		void passeObstaculo();
		void alinharObstaculo();
		bool desalinhado(); 
		
		// VERDE
		void passeVerde();


		// COMUNICAÇÃO
    	void piscarLeds();

		//void para(int tempo); !! 
};


#endif
