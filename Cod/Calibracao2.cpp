#include "Calibracao2.h"


Calibracao2::Calibracao2(){
	escolhaInicial = ' ';
	escolhaMenu = ' ';
	escolhaBranco = ' ';
	escolhaPreto = ' ';
}


void Calibracao2::esperarParaLer (){
  while (!Serial.available()){}
}

void Calibracao2::calibrarVerde(){
	
	Serial.println(F(" COLOQUE O SENSOR DIREITO NO VERDE: "));
	Serial.println(F("[D] Calibrar VERDE DIREITO"));
	
	esperarParaLer();
	controlador = Serial.read();

	
	if (controlador == 'D') {
		corDireito.setVerde(robo.getHsvDireito());
	}
	
	Serial.println(F( "COLOQUE O SENSOR ESQUERDO NO VERDE: "));
	Serial.println(F("[E] Calibrar VERDE ESQUERDO"));

	esperarParaLer();
	controlador = Serial.read();


	if (controlador == 'E'){
		corEsquerdo.setVerde(robo.getHsvEsquerdo()); 
	}
	
	controlador = ' ';
	
}


void Calibracao2::calibrarCorPreto(){
	
	Serial.println(F(" COLOQUE O SENSOR DIREITO NO PRETO: "));
	Serial.println(F("[D] Calibrar PRETO DIREITO"));
	
	esperarParaLer();
	controlador = Serial.read();

	if (controlador == 'D') {
		corDireito.setPreto(robo.getHsvDireito());
	}
	
	Serial.println(F( "COLOQUE O SENSOR ESQUERDO NO PRETO: "));
	Serial.println(F("[E] Calibrar PRETO ESQUERDO"));
	
	esperarParaLer();
	controlador = Serial.read();
	

	if (controlador == 'E'){
		corEsquerdo.setPreto(robo.getHsvEsquerdo()); 
	}
	
	controlador = ' ';
	
}

void Calibracao2::calibrarCorBranco(){
	
	Serial.println(F(" COLOQUE OS SENSORES NO BRANCO: "));
	Serial.println(F("[B] Calibrar COR BRANCO"));
	
	esperarParaLer();
	controlador = Serial.read();
	

	if (controlador == 'B') {
		corDireito.setBranco(robo.getHsvDireito());
		corEsquerdo.setBranco(robo.getHsvEsquerdo());
	}

	controlador = ' ';
}

void Calibracao2::calibrarCinza(){
	
	Serial.println(F(" COLOQUE OS SENSORES NO CINZA: "));
	Serial.println(F("[C] Calibrar COR CINZA"));
	
	esperarParaLer();
	controlador = Serial.read();

	if (controlador == 'C') {
		corDireito.setCinza(robo.getHsvDireito());
		corEsquerdo.setCinza(robo.getHsvEsquerdo());
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
	  refletancia_dir.setBrancoMini(robo.lerSensorLinhaDir());
	  refletancia_dir2.setBrancoMini(robo.lerSensorLinhaMaisDir());
	  refletancia_esq.setBrancoMini(robo.lerSensorLinhaEsq());
	  refletancia_esq2.setBrancoMini(robo.lerSensorLinhaMaisEsq());

	  Serial.println("  ");
      Serial.println(F("Valores lidos: "));
      Serial.print(refletancia_esq2.getMinimoBranco());
      Serial.print(F(" --- "));
      Serial.print(refletancia_esq.getMinimoBranco());
      Serial.print(F(" --- "));
      Serial.print(refletancia_dir.getMinimoBranco());
      Serial.print(F(" --- "));
      Serial.println(refletancia_dir2.getMinimoBranco());
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
	  refletancia_dir.setPretoMax(robo.lerSensorLinhaDir());
	  refletancia_dir2.setPretoMax(robo.lerSensorLinhaMaisDir());
	  refletancia_esq.setPretoMax(robo.lerSensorLinhaEsq());
	  refletancia_esq2.setPretoMax(robo.lerSensorLinhaMaisEsq());
	  
	  Serial.println("  ");
      Serial.println(F("Valores lidos: "));
      Serial.print(refletancia_esq2.getMaximoPreto());
      Serial.print(F(" --- "));
      Serial.print(refletancia_esq.getMaximoPreto());
      Serial.print(F(" --- "));
      Serial.print(refletancia_dir.getMaximoPreto());
      Serial.print(F(" --- "));
      Serial.println(refletancia_dir2.getMaximoPreto());
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
	  
	  refletancia_esq2.calculeMedia();
	  refletancia_esq.calculeMedia();
	  refletancia_dir.calculeMedia();
	  refletancia_dir2.calculeMedia();
	  
	  cali.refletancia_dir = refletancia_dir.getSeparacao();
	  cali.refletancia_mais_dir = refletancia_dir2.getSeparacao();
	  cali.refletancia_esq = refletancia_esq.getSeparacao();
	  cali.refletancia_mais_esq = refletancia_esq2.getSeparacao();
	
	  cali.brancoEsq = corEsquerdo.getBranco();
	  cali.brancoDir = corDireito.getBranco();
	
	  cali.pretoEsq = corEsquerdo.getPreto();
	  cali.pretoDir = corDireito.getPreto();
	
	  cali.verdeEsq = corEsquerdo.getVerde();
	  cali.verdeDir = corDireito.getVerde();
	
	  robo.salvarCalibracao(cali);
	
	}
  }
	 
 }
 
 
 void Calibracao2::lerCalibracao(){
	 robo.lerCalibracao(cali);
	  
	  refletancia_dir.setMedia(cali.refletancia_dir);
	  refletancia_dir2.setMedia(cali.refletancia_mais_dir);
	  refletancia_esq.setMedia(cali.refletancia_esq);
	  refletancia_esq2.setMedia(cali.refletancia_mais_esq);
	  
	  corEsquerdo.setBranco(cali.brancoEsq); 
	  corDireito.setBranco(cali.brancoDir);
	  
	  corEsquerdo.setPreto(cali.pretoEsq);
	  corDireito.setPreto(cali.pretoDir);
	  
	  corEsquerdo.setVerde(cali.verdeEsq);
	  corDireito.setVerde(cali.verdeDir);

 }
 


	
