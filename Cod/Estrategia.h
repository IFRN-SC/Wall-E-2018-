#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <robo_hardware.h>
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
		#define ESQUERDA 1
		#define DIREITA 2
		#define VELPADRAO 45
		#define FIM_DE_CURSO 12

		int t;
		Botao fimDeCurso;
		Motores motores;
		Sensores sensor;
		int contAlternadas = 0;
		int indicador;
		bool desalinhado(); 
		bool viuObstaculo();
		
		//void para(int tempo); !! 
		void passeVerde();
		void alinharEncruzilhada();
		void alinharObstaculo();
		void passeEncruzilhada_Direita();
		void passeEncruzilhada_Esquerda();
		void passeObstaculo();
    	void passeVerdeOuRedutor();
    	void vireEsquerda();
    	void vireDireita();
    	void piscarLeds();
    	void decida();


    	void boySala3();

    	void sigaLinha();
		void miniSeguirLinha();

};


#endif
