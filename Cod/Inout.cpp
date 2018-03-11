#include "Inout.h"

void Inout::esperarParaLer (){
  while (!Serial.available()){}
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////


bool Inout::lerBool(bool booleano){
	esperarParaLer();
	return booleano = Serial.read();
}

char Inout::lerChar(char character){
	esperarParaLer();
	return character = Serial.read();
}
/*
String Inout::lerString(String stringer){
	return stringer = Serial.read();
}
*/

Byte Inout::lerByte(Byte byter){
	esperarParaLer();
	return byter = Serial.read();
}

short Inout::lerShort(short shorter){
	esperarParaLer();
	return shorter = Serial.read();
}

int Inout::lerInt(int integer){
	esperarParaLer();
	return integer = Serial.read();
}

long Inout::lerLong(long longer){
	esperarParaLer();
	return longer = Serial.read();
}

float Inout::lerFloat(float floater){
	esperarParaLer();
	return floater = Serial.read();
}





