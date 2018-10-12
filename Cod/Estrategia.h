#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <robo_hardware2.h>
#include "SensoresWallE.h"
#include "Motores.h"
#include "Calibracao2.h"
#include "Garra.h"

#include "Sala3.h"

class Estrategia {
	public:
		Estrategia();
		void executar();
		void calibrar();
		void verificar();
		
		void configurar();
	private:
		// bool realizarCali;
		#define ESQUERDA 1
		#define DIREITA 2
		#define VELESQ 45
		#define VELDIR 45
		#define FIM_DE_CURSO 12
		#define COM_GANHO 0

		long tAntes = 0;
		bool jaVi = false;
		Botao fimDeCurso;
		Motores motores;
		Sensores sensor;

		/****/

		Garra garra;

		Sala3 sala3;

		/****/


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
    	void piscarLeds(int vezes);
    	void decida();


    	void boySala3();
    	void resgate();	

    	void sigaLinha();
		void miniSeguirLinha();
		void miniSeguirLinha(int n);

};


#endif
