#include "Refletancia.h"

Refletancia::Refletancia() {
	minimoBranco = 101;
	maximoPreto = 0;
	media = 0;
}

void Refletancia::setMedia(float valorSalvo){
	media = valorSalvo;
}

void Refletancia::setBrancoMini(float valorBranco){
	minimoBranco = calcule.minimo(valorBranco,minimoBranco);
}

void Refletancia::setPretoMax(float valorPreto){
	maximoPreto = calcule.maximo(valorPreto,maximoPreto);
}

float Refletancia::getMinimoBranco(){
	return minimoBranco;
}

float Refletancia::getMaximoPreto(){
	return maximoPreto;
}

float Refletancia::getSeparacao() {
	return media;
}

void Refletancia::calculeMedia(){
	media = calcule.media(maximoPreto,minimoBranco, 0.5);
}