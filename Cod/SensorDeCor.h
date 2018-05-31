#include "robo_hardware.h"
#include "Matematica.h"

class SensorDeCor {
	
	Matematica calcule;
	
	public:
		
		SensorDeCor();
		
		float SeparacaoVerdePretoV();
		float SeparacaoVerdePretoH();
		float SeparacaoBrancoPretoV();
		float SeparacaoBrancoVerdeV();
		
		HSV verde;
		HSV preto;
		HSV branco;
		HSV cinza;
		
		inline void setVerde(const HSV &v){verde = v;}
		inline void setBranco(const HSV &b){branco = b;}
		inline void setCinza(const HSV &c){cinza = c;}
		inline void setPreto(const HSV &p){preto = p;}
		
		inline HSV getVerde(){return verde;}
		inline HSV getBranco(){return branco;}
		inline HSV getCinza(){return cinza;}
		inline HSV getPreto(){return preto;}
		
		HSV leituraHSV;
		
		bool ehBranco(HSV hsvAt);
		bool ehVerde(HSV hsvAt);
		bool ehPreto(HSV hsvAt);
		bool ehQualquerCoisa(HSV hsvAt);
		
	private:
	
};