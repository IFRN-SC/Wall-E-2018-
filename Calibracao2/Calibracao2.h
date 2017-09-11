#include <robo_hardware.h> 
#include <Servo.h>


class Calibracao {
private:
	void esperarParaLer();
	void calibrarBranco();
	void calibrarPreto();

	float valor_sensor_dir;
	float valor_sensor_esq;
	float valor_sensor_esq2;
	float valor_sensor_dir2;

	float minimoPreto_sensor_dir;
	float minimoPreto_sensor_esq;
	float minimoPreto_sensor_esq2;
	float minimoPreto_sensor_dir2;

	float maximoBranco_sensor_dir;
	float maximoBranco_sensor_esq;
	float maximoBranco_sensor_esq2;
	float maximoBranco_sensor_dir2;

	float valorPreto_sensor_dir;
	float valorPreto_sensor_esq;
	float valorPreto_sensor_esq2;
	float valorPreto_sensor_dir2;

	float valorBranco_sensor_dir;
	float valorBranco_sensor_esq;
	float valorBranco_sensor_esq2;
	float valorBranco_sensor_dir2;

	char escolhaMenu;
	char escolhaBrancoPreto;

	char escolhaPreto;
	char escolhaBranco;
   
  
public:

	float BRA_PRE_DIR;
	float BRA_PRE_DIR2;
	float BRA_PRE_ESQ;
	float BRA_PRE_ESQ2;


	void Menu_calibrar();


}

