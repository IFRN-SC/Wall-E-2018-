#include "sensores.h"



sensores::sensores():sensorEsquerdo(A10),sensorMaisEsquerdo(A9),sensorDireito(A8),sensorMaisDireito(A11){
  
}

void sensores::luz(){
  Serial.print("+esquerdo: "); 
  Serial.print(sensorMaisEsquerdo.getLuz());
  Serial.print("   ||   ");
  Serial.print("esquerdo: "); 
  Serial.print(sensorEsquerdo.getLuz());
  Serial.print("   ||   ");
  Serial.print("direito: "); 
  Serial.print(sensorDireito.getLuz());
  Serial.print("   ||   ");
  Serial.print("+direitoo: "); 
  Serial.println(sensorMaisDireito.getLuz());
 
  
  
}  

boolean sensores::fim_de_curso_apertado(){
 return !robo.lerSensorFimDeCurso();
}

boolean sensores::branco_branco_branco_branco(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_branco_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::preto_preto_preto_preto(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_preto_direito() &&
    eh_preto_mais_direito()
  );
}
  
boolean sensores::branco_preto_branco_branco(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_branco_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::branco_branco_preto_branco(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_preto_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::preto_branco_branco_branco(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_branco_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::branco_branco_branco_preto(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_branco_direito() &&
    eh_preto_mais_direito()
  );
}
  
boolean sensores::preto_preto_branco_branco(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_branco_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::branco_branco_preto_preto(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_preto_direito() &&
    eh_preto_mais_direito()
  );
}
boolean sensores::branco_preto_preto_branco(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_preto_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::preto_branco_branco_preto(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_branco_direito() &&
    eh_preto_mais_direito()
  );
}
boolean sensores::preto_branco_preto_branco(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_preto_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::branco_preto_branco_preto(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_branco_direito() &&
    eh_preto_mais_direito()
  );
}
  
boolean sensores::preto_preto_preto_branco(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_preto_direito() &&
    eh_branco_mais_direito()
  );
}
boolean sensores::branco_preto_preto_preto(){
  return(
    eh_branco_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_preto_direito() &&
    eh_preto_mais_direito()
  );
}
boolean sensores::preto_preto_branco_preto(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_preto_esquerdo() &&
    eh_branco_direito() &&
    eh_preto_mais_direito()
  );
}
boolean sensores::preto_branco_preto_preto(){
  return(
    eh_preto_mais_esquerdo() &&
    eh_branco_esquerdo() &&
    eh_preto_direito() &&
    eh_preto_mais_direito()
  );
}
  
  
int sensores::distancia_lado(){return robo.distanciaLado();}
int sensores::distancia_frente(){return robo.distanciaFrente();}  


boolean sensores::configura(boolean realizar_cali){
    if(realizar_cali){
      lerCalibracao();
      calibrar();
    }
    else {
      lerCalibracao();
    }
}

void sensores::espereCor(){
  char controle = 's';
  while(1){
    if(expor_v_direito){
      hsv_direito = robo.getHSVDireito();
      Serial.print("V direito  -->   ");
      Serial.println(hsv_direito.h);
    }else if(expor_v_esquerdo){
      hsv_esquerdo = robo.getHSVEsquerdo();
      Serial.print("V esquerdo  -->   ");
      Serial.println(hsv_esquerdo.h);
    
    }else{
      luz();
    }
    //delay(500);
    controle = Serial.read();
    if(controle == 'c'){
      controle = 's';
      break;
    }
  } 
}

void sensores::lerCalibracao(){
  robo.lerCalibracao(calibracao_val);
  
  // inicializando variavel da zona de resgate
  zona_resgate = calibracao_val.zona;
  
  // inicializando os valores dos sensores de refletancia esquerdo
  sensorMaisEsquerdo.calibrar(calibracao_val.mais_esq_refletancia.branco_refletancia, calibracao_val.mais_esq_refletancia.preto_refletancia);  
  sensorEsquerdo.calibrar(calibracao_val.esq_refletancia.branco_refletancia, calibracao_val.esq_refletancia.preto_refletancia);
  
  // inicializando os valores dos sensores de refletancia direito
  sensorDireito.calibrar(calibracao_val.dir_refletancia.branco_refletancia, calibracao_val.dir_refletancia.preto_refletancia);
  sensorMaisDireito.calibrar(calibracao_val.mais_dir_refletancia.branco_refletancia, calibracao_val.mais_dir_refletancia.preto_refletancia);
  
  // inicializando os valores dos sensores de cor direito
  corDireito.setPreto(calibracao_val.direito_cor.preto);
  corDireito.setBranco(calibracao_val.direito_cor.branco);
  corDireito.setVerde(calibracao_val.direito_cor.verde); 
  corDireito.setCinza(calibracao_val.direito_cor.cinza);
  
  // inicializando os valores dos sensores de cor esquerdo
  corEsquerdo.setBranco(calibracao_val.esquerdo_cor.branco);
  corEsquerdo.setPreto(calibracao_val.esquerdo_cor.preto);
  corEsquerdo.setVerde(calibracao_val.esquerdo_cor.verde);
  corEsquerdo.setCinza(calibracao_val.esquerdo_cor.cinza);
  
  // calibrando sensores de cor
  corDireito.calibrar();  
  corEsquerdo.calibrar();
  
}

void sensores::calibrar(){
  
  int branco_mais_esquerdo, branco_esquerdo, branco_direito, branco_mais_direito;
  int preto_mais_esquerdo, preto_esquerdo, preto_direito, preto_mais_direito;
 
  char controle = 's';
  
  
  
  Serial.println("Aperte 'c' para calibrar o branco");
  espereCor();
  branco_mais_esquerdo = sensorMaisEsquerdo.getLuz();
  branco_esquerdo = sensorEsquerdo.getLuz();
  branco_mais_direito = sensorMaisDireito.getLuz();
  branco_direito = sensorDireito.getLuz();  
  //corDireito.setBranco(robo.getHSVDireito());
 // corEsquerdo.setBranco(robo.getHSVEsquerdo());

  Serial.println("Aperte 'c' para calibrar o preto luz");
  espereCor();
  preto_mais_esquerdo = sensorMaisEsquerdo.getLuz();
  preto_esquerdo = sensorEsquerdo.getLuz();
  preto_mais_direito = sensorMaisDireito.getLuz();
  preto_direito = sensorDireito.getLuz();
  
  //fazendo medias dos sensores de refletancia
    
  sensorMaisEsquerdo.calibrar(branco_mais_esquerdo,preto_mais_esquerdo);  
  sensorEsquerdo.calibrar(branco_esquerdo,preto_esquerdo);
  sensorDireito.calibrar(branco_direito,preto_direito);
  sensorMaisDireito.calibrar(branco_mais_direito,preto_mais_direito);

  // /colocando na struct os valores dos sensores de refletancia
  calibracao_val.mais_esq_refletancia = sensorMaisEsquerdo.getCaliVal();
  calibracao_val.esq_refletancia = sensorEsquerdo.getCaliVal(); 
  calibracao_val.dir_refletancia = sensorDireito.getCaliVal(); 
  calibracao_val.mais_dir_refletancia = sensorMaisDireito.getCaliVal();
  
  
  /*sensorMaisEsquerdo.calibrar(355,920);  
  sensorEsquerdo.calibrar(393,915);
  sensorDireito.calibrar(500,916);
  sensorMaisDireito.calibrar(380,936);  
  */

  expor_v_direito = true;
  
  Serial.println("Aperte 'c' para calibrar o preto COR direito");
  espereCor();
  corDireito.setPreto(robo.getHSVDireito());
  
  Serial.println("Aperte 'c' para calibrar o verde COR direito");
  espereCor();
  corDireito.setVerde(robo.getHSVDireito()); 
  

  
  expor_v_direito = false;
  expor_v_esquerdo = true;
  

  Serial.println("Aperte 'c' para calibrar o preto COR esquerdo");
  espereCor();
  corEsquerdo.setPreto(robo.getHSVEsquerdo());
    
  Serial.println("Aperte 'c' para calibrar o verde esquerdo");
  espereCor();
  corEsquerdo.setVerde(robo.getHSVEsquerdo());

  
  Serial.println("Aperte 'c' para calibrar o cinza COR");
  espereCor();
  corDireito.setCinza(robo.getHSVDireito());
  corEsquerdo.setCinza(robo.getHSVEsquerdo());
 

  corDireito.calibrar();  
  corEsquerdo.calibrar();
  
  
  Serial.println("Escolha a zona de regaste: a- esquerda / b- direita / c- bunda");
  while (Serial.available() <= 0); // esperando informacao na serial
  zona_resgate = (char)Serial.read(); // salvando valor da zona
  
  calibracao_val.zona = zona_resgate; // salvando valor da zona
  
  
  calibracao_val.direito_cor = corDireito.getCaliVal();
  calibracao_val.esquerdo_cor = corEsquerdo.getCaliVal(); // colocando na struct os valores dos HSV do sensor esquerdo
  
  robo.salvarCalibracao(calibracao_val);
}
