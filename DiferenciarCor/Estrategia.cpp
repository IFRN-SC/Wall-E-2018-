#include "Estrategia.h"

void Estrategia::calibrar(/*bool escolha*/){
	// realizarCali = escolha;
	
	//if (realizarCali){
		sensor.Menu_calibrar();
	//}
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
  while (!sensor.preto_preto_preto_preto()){
	
	robo.acionarMotores(-35, -35);
	
  }
  
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

void Estrategia::passeObstaculo(){
		  robo.acionarMotores(0, 0);
		  delay(300);
		   
		  robo.acionarMotores(-50, 50);
		  delay(630);
		  
		  robo.acionarMotores(40, 40);
		  delay(200);
		
			
		  alinharObstaculo();

		  robo.acionarMotores(40, 40);
		  delay(1200);

		  robo.acionarMotores(40, -40);
		  delay(850);

		  robo.acionarMotores(40, 40);
		  delay(1650);

		  robo.acionarMotores(40, -40);
		  delay(650);

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
	if(sensor.branco_branco_branco_branco()){
		robo.acionarMotores(45, 45);
	}

	else if(sensor.branco_preto_branco_branco() ||
	  sensor.preto_branco_branco_branco() || 
	  sensor.preto_preto_preto_branco()){
		
		robo.acionarMotores(-40, 40);
	}
	  
	else if(sensor.branco_branco_preto_branco() ||
	  sensor.branco_branco_branco_preto() ||
	  sensor.branco_preto_preto_preto()){
		
		robo.acionarMotores(40, -40);
	  } 

	else if (sensor.preto_preto_branco_branco()){
		 
		while(!sensor.branco_branco_branco_branco()){
		  robo.acionarMotores(40, 40);
		}

		while(!sensor.branco_branco_preto_branco()){
		  robo.acionarMotores(-40, 40);
		}
	  
		while(!sensor.branco_branco_branco_branco()){
		  robo.acionarMotores(40, -40);
		}
	}

	  

	else if (sensor.branco_branco_preto_preto()){
		 
		while(!sensor.branco_branco_branco_branco()){
		  robo.acionarMotores(40, 40);
		}

		while(!sensor.branco_preto_branco_branco()){
		  robo.acionarMotores(40, -40);
		}

		while(!sensor.branco_branco_branco_branco()){
		  robo.acionarMotores(-40, 40);
		}
	}
}

bool Estrategia::viuObstaculo(){
	return (sensor.sonar_frontal() <= 7);
}

void Estrategia::executar(){
	if(viuObstaculo()){
		passeObstaculo();
	}
	
	else {
		sigaLinha();
	}
}