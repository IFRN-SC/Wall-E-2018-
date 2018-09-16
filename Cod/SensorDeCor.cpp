#include "SensorDeCor.h"

SensorDeCor::SensorDeCor(){}


float SensorDeCor::SeparacaoBrancoPretoV(){
	return calcule.media(branco.v, preto.v);
}

float SensorDeCor::SeparacaoVerdePretoV(){
	return calcule.media(verde.v, preto.v)*0.85;
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
	 //Serial.println(SeparacaoVerdePretoV());
	 return (leituraHSV.v < SeparacaoVerdePretoV());
}

bool SensorDeCor::ehPreto(HSV hsvAt){
	 leituraHSV = hsvAt;
	 return (leituraHSV.v > SeparacaoVerdePretoV() && leituraHSV.v < SeparacaoBrancoVerdeV()) ;
}





