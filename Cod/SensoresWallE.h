#ifndef SENSORESWALLE_H
#define	SENSORESWALLE_H

#include "robo_hardware2.h"
#include "Calibracao2.h"

class Sensores: public Calibracao2 {
		
	public:
		
	 inline bool corEsq_verde(){return corEsquerdo.ehVerde(robo.getHSVEsquerdo());}
	 inline bool corDir_verde(){return corDireito.ehVerde(robo.getHSVDireito());}
	 
	 inline bool corEsq_branco(){return corEsquerdo.ehBranco(robo.getHSVEsquerdo());}
	 inline bool corDir_branco(){return corDireito.ehBranco(robo.getHSVDireito());}
	 
	 inline bool corEsq_preto(){return corEsquerdo.ehPreto(robo.getHSVEsquerdo());}
	 inline bool corDir_preto(){return corDireito.ehPreto(robo.getHSVDireito());}
	 
	 bool branco_branco_branco_branco();
	 bool preto_preto_preto_preto();
  
	 bool branco_preto_branco_branco();
	 bool branco_branco_preto_branco();
	 bool preto_branco_branco_branco();
	 bool branco_branco_branco_preto();
  
	 bool preto_preto_branco_branco();
	 bool branco_branco_preto_preto();
	 bool branco_preto_preto_branco();
	 bool preto_branco_branco_preto();
	 bool preto_branco_preto_branco();
	 bool branco_preto_branco_preto();
  
	 bool preto_preto_preto_branco();
	 bool branco_preto_preto_preto();
	 bool preto_preto_branco_preto();
	 bool preto_branco_preto_preto();
	
	 bool maisEsq_Branco(); // Mais esquerdo branco
	 bool maisEsq_Preto(); // Mais esquerdo preto
	 bool Esq_Branco();      // Esquerdo branco
	 bool Esq_Preto();       // Esquerdo preto
	 bool Dir_Branco();       // Dreito branco
	 bool Dir_Preto();      // Direito preto
	 bool maisDir_Branco(); // Mais direito branco
	 bool maisDir_Preto(); // Mais direito preto
	 
	//inline float sonar_frontal(){return robo.lerSensorSonarFrontal();}

	 
	 Sensores();
	
	private:
	
};

#endif