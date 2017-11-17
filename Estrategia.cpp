#include "Estrategia.h"


void Estrategia::configurar(){
	pinMode(LED_BUILTIN, OUTPUT);
}
void Estrategia::calibrar(/*bool escolha*/){
	// realizarCali = escolha;
	Serial.println("Digite qualquer coisa para calibrar");
	for(int i=0; i<10; i++){
		delay(500);
		Serial.print("Tentativa ");
		Serial.println(i);
		if(Serial.available()){
			Serial.read();
			sensor.Menu_calibrar();
		}
	}
	sensor.lerCalibracao();
}

void Estrategia::para(int tempo){
	robo.acionarMotores(0, 0);
	delay(tempo);
}

void Estrategia::passeEncruzilhadaDireita(){
	while (!sensor.branco_branco_branco_branco()){	
		robo.acionarMotores(35, 35);
	}		
	robo.acionarMotores(0, 0);
	delay(400);
	
	/*while (!sensor.Esq_Preto()){
	robo.acionarMotores(-35, 35);
	}*/
	
	robo.acionarMotores(-35, 35);
	delay(1000);
	/*
	while (!sensor.Esq_Branco() && !sensor.Dir_Branco()){
	robo.acionarMotores(-35, 35);
	}*/
}

void Estrategia::passeEncruzilhadaEsquerda(){
	while (!sensor.branco_branco_branco_branco()){	
		robo.acionarMotores(35, 35);
	}		
	robo.acionarMotores(0, 0);
	delay(400);
	/*
	while (!sensor.Dir_Preto()){
	robo.acionarMotores(35, -35);
	}*/
	robo.acionarMotores(35, -35);
	delay(1000);
	/*
	while (!sensor.Dir_Branco() && !sensor.Esq_Branco()){
	robo.acionarMotores(35, -35);
	}*/
}

bool Estrategia::desalinhado(){
	return (sensor.branco_branco_branco_preto() ||
	sensor.branco_branco_preto_preto() ||
	sensor.branco_preto_preto_preto() ||
	sensor.preto_branco_branco_branco() ||
	sensor.preto_preto_branco_branco() ||
	sensor.preto_preto_preto_branco());
}
void Estrategia::alinharObstaculo(){
  while(desalinhado()){
  
	if (sensor.branco_branco_branco_preto() ||
	sensor.branco_branco_preto_preto() ||
	sensor.branco_preto_preto_preto()) 
	{
	  robo.acionarMotores(-35, 0); 
	}
	else if (sensor.preto_branco_branco_branco() ||
	sensor.preto_preto_branco_branco() ||
	sensor.preto_preto_preto_branco()) 
	{
	  robo.acionarMotores(0, -35); 
	}
  }
}

void Estrategia::alinharEncruzilhada(){
  while(!sensor.preto_preto_preto_preto()){
	
	// digitalWrite(LED_BUILTIN, HIGH);
  
	if (sensor.maisDir_Preto()) 
	{
	  robo.acionarMotores(35, 0); 
	}
	else if (sensor.maisEsq_Preto()) 
	{
	  robo.acionarMotores(0, 35); 
	}
  }
}

void Estrategia::passeVerde(){
	if (sensor.corEsq_verde() && (sensor.corDir_branco() || sensor.corDir_preto())){
			para(700);
			passeEncruzilhadaDireita();
		}
		else if (sensor.corDir_verde() && (sensor.corEsq_branco() || sensor.corEsq_preto())){
			para(700);
			passeEncruzilhadaEsquerda();
		}
		else if (sensor.corDir_verde() && sensor.corEsq_verde()){
			while (!sensor.corEsq_preto()){
				robo.acionarMotores(35, -35);
			}
		}
		else {
			robo.acionarMotores(-35, -35);
			delay(400);
		}
}

void Estrategia::passeObstaculo(){
		  robo.acionarMotores(0, 0);
		  delay(300);
		  
		  robo.acionarMotores(-35, -35);
		  delay(150);
		  
		while (!sensor.branco_branco_branco_preto()){
		  robo.acionarMotores(-35, 35);
		}
		/*
		  robo.acionarMotores(40, 40);
		  delay(200);
		*/
			
		  alinharObstaculo();

		  robo.acionarMotores(40, 40);
		  delay(1300);

		  robo.acionarMotores(40, -40);
		  delay(870);

		  robo.acionarMotores(40, 40);
		  delay(1810);

		  robo.acionarMotores(40, -40);
		  delay(750);

		  while (sensor.branco_branco_branco_branco()){
			robo.acionarMotores(35, 35);
		  }

		  robo.acionarMotores(35, 35);
		  delay(250);

		  while (!(sensor.Dir_Preto())){
			robo.acionarMotores(-35, 35);
		  }
}

void Estrategia::sigaLinha(){
	if(sensor.branco_branco_branco_branco() ||
	sensor.branco_preto_preto_branco()){
		robo.acionarMotores(60, 60);
	}
	
	else if (sensor.preto_preto_preto_branco()){
		robo.acionarMotores(-40, 40);
	}
	
	else if (sensor.branco_preto_preto_preto()){
		robo.acionarMotores(40, -40);
	}

	else if(sensor.branco_preto_branco_preto() || 
	sensor.preto_branco_preto_branco()||
	sensor.preto_preto_preto_preto()){
		 
		
		alinharEncruzilhada();
		para(1000);
		//digitalWrite(LED_BUILTIN, LOW);
		
		passeVerde();
	}

	else if (sensor.branco_preto_branco_branco() ||
	sensor.preto_branco_branco_branco()){
		 robo.acionarMotores(-40, 40);
		 // indicador = DIREITA;
		 contAlternadas++;
		 
		 if (contAlternadas > 55){
			contAlternadas = 0;
			robo.acionarMotores(35, 35);
		}
	} 
	
	else if (sensor.branco_branco_preto_branco() ||
	sensor.branco_branco_branco_preto()){
		
		robo.acionarMotores(40,-40);
		// indicador = ESQUERDA;
		contAlternadas++; 
		
		if (contAlternadas > 55){
			contAlternadas = 0;
			robo.acionarMotores(35, 35);
		}
	}
	
	else if (sensor.preto_preto_branco_branco()) {
		robo.acionarMotores(-40, 40);
		//indicador = 0;
	}

	else if(sensor.branco_branco_preto_preto()) {
		robo.acionarMotores(40, -40);
		//indicador = 0;
	}	
}

bool Estrategia::viuObstaculo(){
	
	return (sensor.sonar_frontal() <= 7);
	 robo.acionarMotores(0, 0);
}

void Estrategia::executar(){
	configurar();
	
	if(viuObstaculo()){
		
		passeObstaculo();
	}
	
	else {
		sigaLinha();
	}
}