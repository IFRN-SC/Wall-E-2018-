#include "Calibracao2.h"


Calibracao2::Calibracao2(){
}


void Calibracao2::esperarParaLer (){
  while (!Serial.available()){}
}

void Calibracao2::calibrarVerde(){
	
	Serial.println(F("\n\nCOLOQUE O SENSOR DIREITO NO VERDE: "));
	esperarPosicionamentoCor();

	Serial.println(F("[D] Calibrar VERDE DIREITO"));
	
	esperarParaLer();
	controlador = Serial.read();

	
	if (controlador == 'D') {
		corDireito.setVerde(robo.getHSVDireito());
	}

	Serial.print(F("\n\nVerde direito: "));
	Serial.println(corDireito.getVerde().v);
	
	Serial.println(F("\n\nCOLOQUE O SENSOR ESQUERDO NO VERDE: "));
	esperarPosicionamentoCor();

	Serial.println(F("[E] Calibrar VERDE ESQUERDO"));
	
	esperarParaLer();
	controlador = Serial.read();


	if (controlador == 'E'){
		corEsquerdo.setVerde(robo.getHSVEsquerdo()); 
	}

	Serial.print(F("\n\nVerde esquerdo: "));
	Serial.println(corEsquerdo.getVerde().v);
	
	controlador = ' ';
	
}


void Calibracao2::calibrarCorPreto(){
	
	Serial.println(F("\n\nCOLOQUE O SENSOR DIREITO NO PRETO: "));	
	esperarPosicionamentoCor();

	Serial.println(F("[D] Calibrar PRETO DIREITO"));
	
	esperarParaLer();
	controlador = Serial.read();

	if (controlador == 'D') {
		corDireito.setPreto(robo.getHSVDireito());
	}

	Serial.print(F("\n\nPreto direito: "));
	Serial.println(corDireito.getPreto().v);
	
	Serial.println(F("\n\nCOLOQUE O SENSOR ESQUERDO NO PRETO: "));
	esperarPosicionamentoCor();

	Serial.println(F("[E] Calibrar PRETO ESQUERDO"));	
	
	esperarParaLer();
	controlador = Serial.read();
	

	if (controlador == 'E'){
		corEsquerdo.setPreto(robo.getHSVEsquerdo()); 
	}
	Serial.print(F("\n\nPreto esquerdo: "));
	Serial.println(corEsquerdo.getPreto().v);
	
	controlador = ' ';
	
}

void Calibracao2::calibrarCorBranco(){
	
	Serial.println(F("\n\nCOLOQUE OS SENSORES NO BRANCO: "));	
	esperarPosicionamentoCor();

	Serial.println(F("[B] Calibrar COR BRANCO"));
	
	esperarParaLer();
	controlador = Serial.read();
	

	if (controlador == 'B') {
		corDireito.setBranco(robo.getHSVDireito());
		corEsquerdo.setBranco(robo.getHSVEsquerdo());
	}

	Serial.print(F("Branco esquerdo: "));
	Serial.print(corEsquerdo.getBranco().v);
	Serial.print(F("\tBranco direito: \n\n"));
	Serial.print(corDireito.getBranco().v);



	controlador = ' ';
}

void Calibracao2::calibrarCinza(){
	
	Serial.println(F(" COLOQUE OS SENSORES NO CINZA: "));
	esperarPosicionamentoCor();

	Serial.println(F("[C] Calibrar COR CINZA"));
	
	esperarParaLer();
	controlador = Serial.read();

	if (controlador == 'C') {
		corDireito.setCinza(robo.getHSVDireito());
		corEsquerdo.setCinza(robo.getHSVEsquerdo());
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
  char escolhaBranco = ' ';
  while (escolhaBranco != SAIDA) {
    Serial.println(F("\nColoque todos os sensores no BRANCO"));
    
    esperarPosicionamento();

    Serial.println(F("[C] Para CALIBRAR"));
    Serial.println(F("[S] Para SAIR"));
    
    esperarParaLer();
    escolhaBranco = Serial.read();

    if (escolhaBranco == 'C') {
	  refletancia_dir.setBrancoMini(robo.lerSensorLinhaDirSemRuido());
	  refletancia_dir2.setBrancoMini(robo.lerSensorLinhaMaisDirSemRuido());
	  refletancia_esq.setBrancoMini(robo.lerSensorLinhaEsqSemRuido());
	  refletancia_esq2.setBrancoMini(robo.lerSensorLinhaMaisEsqSemRuido());

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

      Serial.println(F("[D] Para DESCARTAR"));
      Serial.println(F("[N] Para NÃO DESCARTAR"));
      esperarParaLer();
      
      if(Serial.read() == 'D'){
		refletancia_dir.resetBranco();
	  	refletancia_dir2.resetBranco();
	  	refletancia_esq.resetBranco();
	  	refletancia_esq2.resetBranco();      	
      	calibrarBranco();
      }
          
    }
    else {
      escolhaBranco = SAIDA;
    }
  }
}


void Calibracao2::calibrarPreto(){
	char escolhaPreto = ' ';
	while (escolhaPreto != SAIDA) {
		Serial.println(F("\nColoque todos os sensores no PRETO"));

		esperarPosicionamento();

		Serial.println(F("[C] Para CALIBRAR"));
		Serial.println(F("[S] Para SAIR"));
		
		esperarParaLer();
		escolhaPreto = Serial.read();

    if (escolhaPreto == 'C') {
	  refletancia_dir.setPretoMax(robo.lerSensorLinhaDirSemRuido());
	  refletancia_dir2.setPretoMax(robo.lerSensorLinhaMaisDirSemRuido());
	  refletancia_esq.setPretoMax(robo.lerSensorLinhaEsqSemRuido());
	  refletancia_esq2.setPretoMax(robo.lerSensorLinhaMaisEsqSemRuido());
	  
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

      Serial.println(F("[D] Para DESCARTAR"));
      Serial.println(F("[N] Para NÃO DESCARTAR"));
      esperarParaLer();
      
      if(Serial.read() == 'D'){
		refletancia_dir.resetPreto();
	  	refletancia_dir2.resetPreto();
	  	refletancia_esq.resetPreto();
	  	refletancia_esq2.resetPreto();      	
      	calibrarPreto();
      }
      
          
    }
    else {
      escolhaPreto = SAIDA;
    }
  }
  
}

void Calibracao2::esperarPosicionamento() {
	Serial.println();
	Serial.println(F("INSIRA ALGO NO SERIAL QUANDO TODOS OS SENSORES ESTIVEREM POSICIONADOS CORRETAMENTE.\n"));
	Serial.println(F("(maisEsq)	---		(Esq)		---		(Dir)		---		(maisDir)\n"));
	while(1) {
		Serial.print(robo.lerSensorLinhaMaisEsqSemRuido());
		Serial.print(F("		---		"));
		Serial.print(robo.lerSensorLinhaEsqSemRuido());
		Serial.print(F("		---		"));
		Serial.print(robo.lerSensorLinhaDirSemRuido());
		Serial.print(F("		---		"));
		Serial.print(robo.lerSensorLinhaMaisDirSemRuido());
		Serial.println();
		delay(1000);

		if(Serial.available()) {
			Serial.read();
			break;
		}
	}
}

void Calibracao2::esperarPosicionamentoCor() {
	Serial.println();
	Serial.println(F("INSIRA ALGO NO SERIAL QUANDO TODOS OS SENSORES ESTIVEREM POSICIONADOS CORRETAMENTE.\n"));
	Serial.println(F("(Esq [V])		---		(Dir [V])\n"));
	while(1) {
		Serial.print(robo.getHSVEsquerdo().v);
		Serial.print(F("		        ---		"));
		Serial.print(robo.getHSVDireito().v);
		Serial.println();
		delay(1000);

		if(Serial.available()) {
			Serial.read();
			break;
		}
	}
}

void Calibracao2::Menu_calibrar() {
  char escolhaInicial = ' ';
  char escolhaMenu = ' ';
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
	
	  cali.refletanciaDir = refletancia_dir.getSeparacao();
	  cali.refletanciaMaisDir = refletancia_dir2.getSeparacao();
	  cali.refletanciaEsq = refletancia_esq.getSeparacao();
	  cali.refletanciaMaisEsq = refletancia_esq2.getSeparacao();
	
	  /*
	  cali.refletanciaDir = 4.0;
	  cali.refletanciaMaisDir = 5.0;
	  cali.refletanciaEsq = 4.0;
	  cali.refletanciaMaisEsq = 5.0;
	  */
	
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
	  
	  refletancia_dir.setMedia(cali.refletanciaDir);
	  refletancia_dir2.setMedia(cali.refletanciaMaisDir);
	  refletancia_esq.setMedia(cali.refletanciaEsq);
	  refletancia_esq2.setMedia(cali.refletanciaMaisEsq);
	  
	  corEsquerdo.setBranco(cali.brancoEsq); 
	  corDireito.setBranco(cali.brancoDir);
	  
	  corEsquerdo.setPreto(cali.pretoEsq);
	  corDireito.setPreto(cali.pretoDir);
	  
	  corEsquerdo.setVerde(cali.verdeEsq);
	  corDireito.setVerde(cali.verdeDir);

	  Serial.println("mais esq, esq, dir, mais dir");
	  Serial.println(refletancia_esq2.getSeparacao());
	  Serial.println(refletancia_esq.getSeparacao());
	  Serial.println(refletancia_dir.getSeparacao());
	  Serial.println(refletancia_dir2.getSeparacao());
	  

 }
 


	
