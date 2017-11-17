#include "Matematica.h"

Matematica::Matematica(){}

float Matematica::media(float n1, float n2){
	return (n1 + n2)/2.0;
}

float Matematica::maximo(float n1, float n2){
	if (n1 > n2) {
		n2 = n1;
	}
	
	return n2;
}

float Matematica::minimo(float n1, float n2){
	if (n1 < n2) {
		n2 = n1;
	}
	
	return n2;
}