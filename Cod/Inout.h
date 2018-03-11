#ifndef INOUT_H
#define INOUT_H

class Inout {
public:
	bool lerBool(bool booleano);
	char lerChar(char character);
	//String lerString(String stringer); 		// ?? @isaacmarlon > String?
	//Byte lerByte(Byte byter);  				// ?? @isaacmarlon > Byte? 
	//short lerShort(short shorter);
	int lerInt(int integer);
	//long lerLong();
	float lerFloat(float floater);
	//double lerDouble(long longer);

	Inout inout;
private:
	void esperarParaLer();
};
#endif