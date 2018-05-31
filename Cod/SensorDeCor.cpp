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
	return (leituraHSV.v < verde.v*1.2);;
}

bool SensorDeCor::ehPreto(HSV hsvAt){
	 leituraHSV = hsvAt;
	 return (leituraHSV.v > SeparacaoVerdePretoV() && leituraHSV.v < SeparacaoBrancoVerdeV()) ;
}

bool SensorDeCor::ehQualquerCoisa(HSV hsvAt){
	leituraHSV = hsvAt;
	return (leituraHSV.v > verde.v*1.2);
}





