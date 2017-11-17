#include "Matematica.h"

Matematica::Matematica(){}

float Matematica::media(float n1, float n2, float x){
	return (n1*x + n2*(1 - x));
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