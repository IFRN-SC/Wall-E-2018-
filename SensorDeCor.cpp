#include "SensorDeCor.h"

SensorDeCor::SensorDeCor(){}


float SensorDeCor::SeparacaoBrancoPretoV(){
	return calcule.media(branco.v, preto.v);
}

float SensorDeCor::SeparacaoVerdePretoV(){
	return calcule.media(verde.v, preto.v);
}

float SensorDeCor::SeparacaoVerdePretoH(){
	return calcule.media(verde.h, preto.h);
}

float SensorDeCor::SeparacaoBrancoVerdeV(){
	return calcule.media(branco.v, verde.v);
}
/*
bool SensorDeCor::ehBordaBrancoVerde(HSV hsvAt){
	leituraHSV = hsvAt;
	return ()
	
}*/

bool SensorDeCor::ehBranco(HSV hsvAt){
	 leituraHSV = hsvAt;
	 return (leituraHSV.v > SeparacaoBrancoPretoV());
}

bool SensorDeCor::ehVerde(HSV hsvAt){
	 leituraHSV = hsvAt;
	 return (/*(leituraHSV.h < preto.h + 3 && */leituraHSV.v > SeparacaoBrancoVerdeV() || leituraHSV.v < SeparacaoVerdePretoV());
}

bool SensorDeCor::ehPreto(HSV hsvAt){
	 leituraHSV = hsvAt;
	 return (leituraHSV.v > SeparacaoVerdePretoV() && leituraHSV.v < SeparacaoBrancoVerdeV()) ;
}





