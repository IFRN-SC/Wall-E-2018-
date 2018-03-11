#ifndef INOUT_H
#define INOUT_H

#include <Arduino.h>

class Inout {
public:
	bool lerBool(bool booleano);
	char lerChar(char character);
	//String lerString(String stringer); 		// ?? @isaacmarlon > String?
	//Byte lerByte(Byte byter);  				// ?? @isaacmarlon > Byte? 
	short lerShort(short shorter);
	int lerInt(int integer);
	long lerLong(long longer);
	float lerFloat(float floater);
	//double lerDouble(long longer);

	// Inout inout <- esse objeto tem que ser declarado onde vai ser usado. (calibracao)
	// Se você instancia uma função no .cpp, ela deve ser declarada aqui. (estavam comentadas)
private:
	void esperarParaLer();
};
#endif