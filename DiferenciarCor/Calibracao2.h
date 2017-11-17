#include <robo_hardware.h> 
#include <Servo.h>
#include "SensorDeCor.h"
 
class Calibracao2 {
	
	

private:
	Matematica calcule;
	calibracao_dados cali;
	
	bool realizarCali;
	
	const char SAIDA = 'S'; 
	
	float mediaEsq;
	float mediaEsq2;
	float mediaDir;
	float mediaDir2;
	
	void calculeMedia();
	
	void esperarParaLer();
	void calibrarBranco();
	void calibrarPreto();
	
	void calibrarCor();
	void calibrarCorPreto();
	void calibrarCorBranco();
	void calibrarVerde();
	void calibrarCinza();
	
	float valor_sensor_dir;
	float valor_sensor_esq;
	float valor_sensor_esq2;
	float valor_sensor_dir2;

	float maximoPreto_sensor_dir;
	float maximoPreto_sensor_esq;
	float maximoPreto_sensor_esq2;
	float maximoPreto_sensor_dir2;

	float minimoBranco_sensor_dir;
	float minimoBranco_sensor_esq;
	float minimoBranco_sensor_esq2;
	float minimoBranco_sensor_dir2;

	float valorPreto_sensor_dir;
	float valorPreto_sensor_esq;
	float valorPreto_sensor_esq2;
	float valorPreto_sensor_dir2;

	float valorBranco_sensor_dir;
	float valorBranco_sensor_esq;
	float valorBranco_sensor_esq2;
	float valorBranco_sensor_dir2;
	
	char escolhaInicial;
	char escolhaMenu;
	char escolhaBrancoPreto;

	char escolhaPreto;
	char escolhaBranco;
	
	char escolhaCor;
	char controlador;
   
  
public:
 
	Calibracao2();
	
	float getSeparacaoDir();
	float getSeparacaoDir2();
	float getSeparacaoEsq();
	float getSeparacaoEsq2();

	void Menu_calibrar();
	
protected: 
	SensorDeCor corDireito, corEsquerdo;
};

