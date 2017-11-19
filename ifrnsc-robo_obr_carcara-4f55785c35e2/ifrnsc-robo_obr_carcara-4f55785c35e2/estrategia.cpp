#include "estrategia.h"
#define DEBUG_SEM_MOV
#define DEBUG_COM_MOV

estrategia::estrategia(){
  
}

void estrategia::configura(){
  sensor.configura(false);

}


void estrategia::siga_linha(){
 /* if(sensor.eh_cinza_esquerdo() || sensor.eh_cinza_direito()){
    while(1){mover.parar();}
  }
 */
 
  if(sensor.branco_branco_branco_branco()){
    mover.andar_frente();
  }else if(sensor.branco_preto_branco_branco() ||
  sensor.preto_branco_branco_branco() ||
  sensor.preto_preto_branco_branco()  || 
  sensor.preto_preto_preto_branco()){
           
    mover.enrolar_esquerda();
    delay(20);
  

  }else if(sensor.branco_branco_preto_branco() ||
  sensor.branco_branco_branco_preto() ||
  sensor.branco_branco_preto_preto() ||
  sensor.branco_preto_preto_preto()){
    
    mover.enrolar_direita();
    delay(20);
  /*}else if(sensor.branco_preto_branco_preto() || sensor.preto_branco_preto_preto()){
    passe_encruzilhada_esquerda();
  }else if(sensor.preto_branco_preto_branco() || sensor.preto_preto_branco_preto()){
    passe_encruzilhada_direita();*/
  }else if(sensor.preto_preto_preto_preto() || sensor.preto_branco_branco_preto()){// || sensor.branco_preto_preto_branco() ){//  ){
   //mover.andar_tras();
    //mover.parar();
    //delay(200);
    //mover.andar_tras();
    //delay(70);
    int cont = 0;
    int cont_esquerdo = 0;
    int cont_direito = 0;
    mover.parar();
    boolean acheiVerde = false;
    
      if(sensor.eh_verde_esquerdo()){
        mover.parar();
        //delay(200);
        acheiVerde = true;
        cont_esquerdo++;
        passe_encruzilhada_esquerda();
        //break;
      }else if(sensor.eh_verde_direito()){
        mover.parar();
        //delay(200);
        acheiVerde = true;
        cont_direito++;
        passe_encruzilhada_direita();
        //break;
      }
    if(!acheiVerde){
      
      mover.andar_tras();
      delay(70);
      //procure_linha();
      
    }
   
  /*}else if(sensor.preto_preto_branco_preto()){
    mover.enrolar_esquerda();
    //delay(50);
  }else if(sensor.preto_branco_preto_preto()){
    mover.enrolar_direita();
    //delay(50);*/
  }else{
    mover.andar_frente();
  }
}

void estrategia::procure_linha(){
  lado_linha = !lado_linha;
  while(1){
    if(sensor.eh_verde_esquerdo()){
      passe_encruzilhada_esquerda();
      break;
    }else if(sensor.eh_verde_direito()){
      passe_encruzilhada_direita();
      break;
    }else{
      if(lado_linha){
        if(sensor.eh_preto_esquerdo()){
          if(sensor.eh_verde_esquerdo()){
            passe_encruzilhada_esquerda();
            break;
          }else if(sensor.eh_verde_direito()){
            passe_encruzilhada_direita();
            break;
          }else{
            break;
          }
        }else{
          mover.no_eixo_para_direita();
        }  
    }else{
        if(sensor.eh_preto_direito()){
          if(sensor.eh_verde_esquerdo()){
            passe_encruzilhada_esquerda();
            break;
          }else if(sensor.eh_verde_direito()){
            passe_encruzilhada_direita();
            break;
          }else{
            break;
          }
        }else{
          mover.no_eixo_para_esquerda();
        }
      }
    }
  
  }
  
  
  
}

void estrategia::passe_encruzilhada_esquerda(){
  mover.andar_frente();
  delay(220);
  
  while(sensor.eh_preto_esquerdo()){mover.no_eixo_para_esquerda();}
  while(!sensor.eh_preto_esquerdo()){mover.no_eixo_para_esquerda();} 
  while(!sensor.eh_branco_esquerdo()){mover.no_eixo_para_esquerda();}
 
}
void estrategia::passe_encruzilhada_direita(){
  mover.andar_frente();
  delay(220);
  
  while(sensor.eh_preto_direito()){mover.no_eixo_para_direita();}
  while(!sensor.eh_preto_direito()){mover.no_eixo_para_direita();} 
  while(!sensor.eh_branco_direito()){mover.no_eixo_para_direita();} 

}


boolean estrategia::vejo_obstaculo(int distancia_dada,int distancia_obstaculo){
  if(distancia_dada <= distancia_obstaculo){
    return true;
  }else{
    return false;
  }
}

boolean estrategia::vejo_rampa(){
  if(sensor.distancia_lado() <= 7){
    return true;
  }else{
    return false;
  }
}

void estrategia::suba_rampa(){
  if(sensor.branco_preto_branco_branco()){
    robo.acionarMotores(60,85);
  }else if(sensor.branco_branco_preto_branco()){
    robo.acionarMotores(80,60);
  }else if(sensor.preto_branco_branco_branco()){
    robo.acionarMotores(-50,50);
  }else if(sensor.branco_branco_branco_preto()){
    robo.acionarMotores(50,-50);  
  }else{
    robo.acionarMotores(80,85);
  }

}

void estrategia::passe_obstaculo(){
//para o robo e alinha ele na linha antes do obstculo  
  int cont_erro = 0;
  mover.parar();
  delay(200);
  alinhe();
//para o robo por um segundo   
  mover.parar();
  delay(1000);
//ande para frente at ver obstculo  
  while(1){
    if(!(vejo_obstaculo(robo.distanciaLado(),12))){
      robo.acionarMotores(40,40);
    }else{
      mover.parar();
      cont_erro++;
    }
    //se obstaculo for visto 3 vezes saia do estado  
    if(cont_erro >=3){
      cont_erro = 0;
      break;      
    }
  }
//ander para frente ate parar de ver obstaculo
  while(1){
    if(vejo_obstaculo(robo.distanciaLado(),12)){
      robo.acionarMotores(40,40);
    }else{
      mover.parar();
      cont_erro++;
    }
    //se obstaculo deixa de ser visto 3 vezes saia do estado  
    if(cont_erro >=10){
      cont_erro = 0;
      break;      
    }
  
  }
  
//parar por um segundo  
  mover.parar();
  delay(1000);

//enrolar para esquerda aproximadamente 90 graus  
  mover.no_eixo_para_esquerda();
  delay(600);

//parar por um segundo    
  mover.parar();
  delay(1000);
  
//ande para frente ate ver obstaculo
  while(1){
    if(!(vejo_obstaculo(robo.distanciaLado(),12))){
      robo.acionarMotores(40,40);
    }else{
      mover.parar();
      cont_erro++;
    }
    //se obstaculo for visto 3 vezes saia do estado  
    if(cont_erro >=3){
      cont_erro = 0;
      break;      
    }
  }
  //while(vejo_obstaculo(robo.distanciaLado())){robo.acionarMotores(40,40);}
  robo.acionarMotores(40,40);
  delay(500);
  
  mover.parar();
  delay(1000);
  
  mover.no_eixo_para_esquerda();
  delay(520);
  
  
  
  
  while(!(sensor.eh_preto_mais_esquerdo() || sensor.eh_preto_esquerdo() || sensor.eh_preto_direito() || sensor.eh_preto_mais_direito())){
    robo.acionarMotores(40,40);
  }
  
  
 
  mover.andar_frente();
  delay(200);
  
  while(!sensor.eh_preto_mais_direito()){mover.no_eixo_para_direita();}
  while(!sensor.eh_preto_direito()){mover.no_eixo_para_direita();} 
  while(!sensor.eh_branco_direito()){mover.no_eixo_para_direita();}   
  
}

void estrategia::alinhe(){
  mover.no_eixo_para_direita();
  delay(600);
  int cont_erro = 0;
 
  
  while(!(sensor.eh_preto_mais_esquerdo() && sensor.eh_preto_esquerdo() && sensor.eh_preto_direito())){
    //if(sensor.eh_branco_mais_esquerdo() && sensor.eh_branco_esquerdo()){
      
    //}
    if(sensor.eh_preto_mais_esquerdo()){
      mover.no_eixo_para_direita();
      delay(20);
    }else if(sensor.eh_preto_direito()){
      mover.no_eixo_para_esquerda();
      delay(20);
    }else{
      robo.acionarMotores(-35,-35);  
    }
  }
}


void estrategia::run(){
  /*if(vejo_obstaculo(robo.distanciaFrente(),DISTANCIA_OBSTACULO)){
    robo.led_verde(true);
    mover.parar();
    delay(1000);
    
    passe_obstaculo();
  }else{
    siga_linha();    
  }*/
  siga_linha();
  //suba_rampa();
   //passe_obstaculo
}
