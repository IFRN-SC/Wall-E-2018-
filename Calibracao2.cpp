#include "Calibracao2.h"


Calibracao2::Calibracao2 (){
	escolhaInicial = ' ';
	escolhaMenu = ' ';
	escolhaBranco = ' ';
	escolhaPreto = ' ';
	
	
	minimoBranco_sensor_dir = 100;
	minimoBranco_sensor_esq = 100;
	minimoBranco_sensor_esq2 = 100;
	minimoBranco_sensor_dir2 = 100;
}

void Calibracao2::calculeMedia(){
	mediaDir = calcule.media(maximoPreto_sensor_dir, minimoBranco_sensor_dir, 0.3); 
	mediaDir2 = calcule.media(maximoPreto_sensor_dir2, minimoBranco_sensor_dir2, 0.3);
	mediaEsq = calcule.media(maximoPreto_sensor_esq, minimoBranco_sensor_esq, 0.3);
	mediaEsq2 = calcule.media(maximoPreto_sensor_esq2, minimoBranco_sensor_esq2, 0.3);
}

void Calibracao2::esperarParaLer (){
  while (!Serial.available()){}
}

float Calibracao2::getSeparacaoDir (){
	return mediaDir;
}

float Calibracao2::getSeparacaoDir2 (){
	return mediaDir2;
}

float Calibracao2::getSeparacaoEsq (){
	return mediaEsq;
}

float Calibracao2::getSeparacaoEsq2 (){
	return mediaEsq2;
}

void Calibracao2::calibrarVerde(){
	
	Serial.println(F(" COLOQUE O SENSOR DIREITO NO VERDE: "));
	Serial.println(F("[D] Calibrar VERDE DIREITO"));
	esperarParaLer();
	controlador = Serial.read();
	
	if (controlador == 'D') {
		corDireito.setVerde(robo.getHSV_Direito());
	}
	
	Serial.println(F( "COLOQUE O SENSOR ESQUERDO NO VERDE: "));
	Serial.println(F("[E] Calibrar VERDE ESQUERDO"));
	esperarParaLer();
	controlador = Serial.read();
	
	if (controlador == 'E'){
		corEsquerdo.setVerde(robo.getHSV_Esquerdo()); 
	}
	
	controlador = ' ';
	
}


void Calibracao2::calibrarCorPreto(){
	
	Serial.println(F(" COLOQUE O SENSOR DIREITO NO PRETO: "));
	Serial.println(F("[D] Calibrar PRETO DIREITO"));
	esperarParaLer();
	controlador = Serial.read();
	
	if (controlador == 'D') {
		corDireito.setPreto(robo.getHSV_Direito());
	}
	
	Serial.println(F( "COLOQUE O SENSOR ESQUERDO NO PRETO: "));
	Serial.println(F("[E] Calibrar PRETO ESQUERDO"));
	esperarParaLer();
	controlador = Serial.read();
	
	if (controlador == 'E'){
		corEsquerdo.setPreto(robo.getHSV_Esquerdo()); 
	}
	
	controlador = ' ';
	
}

void Calibracao2::calibrarCorBranco(){
	
	Serial.println(F(" COLOQUE OS SENSORES NO BRANCO: "));
	Serial.println(F("[B] Calibrar COR BRANCO"));
	esperarParaLer();
	controlador = Serial.read();
	
	if (controlador == 'B') {
		corDireito.setBranco(robo.getHSV_Direito());
		corEsquerdo.setBranco(robo.getHSV_Esquerdo());
	}

	controlador = ' ';
}

void Calibracao2::calibrarCinza(){
	
	Serial.println(F(" COLOQUE OS SENSORES NO CINZA: "));
	Serial.println(F("[C] Calibrar COR CINZA"));
	esperarParaLer();
	controlador = Serial.read();
	
	if (controlador == 'C') {
		corDireito.setCinza(robo.getHSV_Direito());
		corEsquerdo.setCinza(robo.getHSV_Esquerdo());
	}
	
	controlador = ' ';
}


void Calibracao2::calibrarCor(){
	while (escolhaCor != SAIDA){
		Serial.println(F("[V] Para calibrar o VERDE"));
		Serial.println(F("[C] Para calibrar o CINZA"));
		Serial.println(F("[B] Para calibrar o BRANCO"));
		Serial.println(F("[P] Para calibrar o PRETO"));
		Serial.println(F("[M] MENU INICIAL"));
		Serial.println(F("[S] SAIR"));
		esperarParaLer();
		escolhaCor = Serial.read();
		
		switch (escolhaCor) {
		
			case 'V':
				calibrarVerde();
				break;
			case 'C':
				calibrarCinza();
				break;
			case 'B':
				calibrarCorBranco();
				break;
			case 'P':
				calibrarCorPreto();
				break;
			case 'M':
				Menu_calibrar();
				break;
			default:
				escolhaCor = SAIDA;
		}
	}
	escolhaCor = ' ';
}

void Calibracao2::calibrarBranco(){

  while (escolhaBranco != SAIDA) {
    Serial.println(F("Coloque todos os sensores no BRANCO"));
    Serial.println(F("[C] Para CALIBRAR"));
    Serial.println(F("[S] Para SAIR"));
    esperarParaLer();
    escolhaBranco = Serial.read();

    if (escolhaBranco == 'C') {
      valorBranco_sensor_dir = robo.lerSensorLinhaDir();
      valorBranco_sensor_dir2 = robo.lerSensorLinhaDir2();
      valorBranco_sensor_esq = robo.lerSensorLinhaEsq();
      valorBranco_sensor_esq2 = robo.lerSensorLinhaEsq2();

      minimoBranco_sensor_dir = calcule.minimo(valorBranco_sensor_dir, minimoBranco_sensor_dir);
	  minimoBranco_sensor_dir2 = calcule.minimo(valorBranco_sensor_dir2, minimoBranco_sensor_dir2);
	  minimoBranco_sensor_esq = calcule.minimo(valorBranco_sensor_esq, minimoBranco_sensor_esq);
	  minimoBranco_sensor_esq2 = calcule.minimo(valorBranco_sensor_esq2, minimoBranco_sensor_esq2);
	  
	  Serial.println("  ");
      Serial.println(F("Valores lidos: "));
      Serial.print(minimoBranco_sensor_esq2);
      Serial.print(F(" --- "));
      Serial.print(minimoBranco_sensor_esq);
      Serial.print(F(" --- "));
      Serial.print(minimoBranco_sensor_dir);
      Serial.print(F(" --- "));
      Serial.println(minimoBranco_sensor_dir2);
      Serial.println(F(" "));
      
          
    }
    else {
      escolhaBranco = SAIDA;
    }
  }
}

void Calibracao2::calibrarPreto(){

	while (escolhaPreto != SAIDA) {
		Serial.println(F("Coloque todos os sensores no PRETO"));
		Serial.println(F("[C] Para CALIBRAR"));
		Serial.println(F("[S] Para SAIR"));
		esperarParaLer();
		escolhaPreto = Serial.read();
    
    if (escolhaPreto == 'C') {
      valorPreto_sensor_dir = robo.lerSensorLinhaDir();
      valorPreto_sensor_dir2 = robo.lerSensorLinhaDir2();
      valorPreto_sensor_esq = robo.lerSensorLinhaEsq();
      valorPreto_sensor_esq2 = robo.lerSensorLinhaEsq2();

      maximoPreto_sensor_dir = calcule.maximo(valorPreto_sensor_dir, maximoPreto_sensor_dir);
	  maximoPreto_sensor_dir2 = calcule.maximo(valorPreto_sensor_dir2, maximoPreto_sensor_dir2);
	  maximoPreto_sensor_esq = calcule.maximo(valorPreto_sensor_esq, maximoPreto_sensor_esq);
	  maximoPreto_sensor_esq2 = calcule.maximo(valorPreto_sensor_esq2, maximoPreto_sensor_esq2);
	  
	  Serial.println("  ");
      Serial.println(F("Valores lidos: "));
      Serial.print(maximoPreto_sensor_esq2);
      Serial.print(F(" --- "));
      Serial.print(maximoPreto_sensor_esq);
      Serial.print(F(" --- "));
      Serial.print(maximoPreto_sensor_dir);
      Serial.print(F(" --- "));
      Serial.println(maximoPreto_sensor_dir2);
      Serial.println(F(" "));
      
          
    }
    else {
      escolhaPreto = SAIDA;
    }
  }
  
}

void Calibracao2::Menu_calibrar() {
	
  while (escolhaInicial != SAIDA) { 
     Serial.println(F("[C] Começar calibração"));
     Serial.println(F("[S] Sair da calibração"));
     esperarParaLer();
     escolhaInicial = Serial.read();
     
     if (escolhaInicial == 'C'){
      while (escolhaMenu != SAIDA) { 
        Serial.println(F("[B] Calibrar BRANCO REFLETÂNCIA"));
        Serial.println(F("[P] Calibrar PRETO REFLETÂNCIA"));
		Serial.println(F("[C] Calibrar COR"));
        Serial.println(F("[S] SAIR"));
        esperarParaLer();
        escolhaMenu = Serial.read();
        
        if (escolhaMenu == 'B') {
          calibrarBranco();           
        }
        else if (escolhaMenu == 'P') {
          calibrarPreto();
        }
		else if (escolhaMenu == 'C'){
			calibrarCor();
		}
        else {
          escolhaMenu = SAIDA;
        }
        
      }
      escolhaMenu = ' ';
	  
	  calculeMedia();
	  
	  cali.refletancia_dir = getSeparacaoDir();
	  cali.refletancia_mais_dir = getSeparacaoDir2();
	  cali.refletancia_esq = getSeparacaoEsq();
	  cali.refletancia_mais_esq = getSeparacaoEsq2();
	
	  cali.brancoEsq = corEsquerdo.getBranco();
	  cali.brancoDir = corDireito.getBranco();
	
	  cali.pretoEsq = corEsquerdo.getPreto();
	  cali.pretoDir = corDireito.getPreto();
	
	  cali.verdeEsq = corEsquerdo.getVerde();
	  cali.verdeDir = corDireito.getVerde();
	
	  robo.salvarCalibracao(cali);
	
	}
  }
	  	  
	  
	  /*
	  Serial.println(mediaEsq2);
	  Serial.println(mediaEsq);
	  Serial.println(mediaDir);
	  Serial.println(mediaDir2);
	*/
 }
 
 void Calibracao2::lerCalibracao(){
	 robo.lerCalibracao(cali);
	  
	  mediaDir = cali.refletancia_dir;
	  mediaDir2 = cali.refletancia_mais_dir;
	  mediaEsq = cali.refletancia_esq;
	  mediaEsq2 = cali.refletancia_mais_esq;
	  
	  corEsquerdo.setBranco(cali.brancoEsq); 
	  corDireito.setBranco(cali.brancoDir);
	  
	  corEsquerdo.setPreto(cali.pretoEsq);
	  corDireito.setPreto(cali.pretoDir);
	  
	  corEsquerdo.setVerde(cali.verdeEsq);
	  corDireito.setVerde(cali.verdeDir);

 }
 


	