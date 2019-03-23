#include "SensoresWallE.h"

Sensores::Sensores(){}

//void Sensores::Menu_calibrar(){
//  cali.Menu_calibrar();
//}

bool Sensores::maisEsq_Branco(bool comErro=false){
  if(comErro){
    return robo.lerSensorLinhaMaisEsq() > refletancia_esq2.getSeparacao();
  }else{
    return robo.lerSensorLinhaMaisEsqSemRuido() > refletancia_esq2.getSeparacao();
  }
}

bool Sensores::maisEsq_Preto(bool comErro=false){
  if(comErro){
    return robo.lerSensorLinhaMaisEsq() < refletancia_esq2.getSeparacao();
  }else{
    return robo.lerSensorLinhaMaisEsqSemRuido() < refletancia_esq2.getSeparacao();
  }
}

bool Sensores::Esq_Branco(bool comErro=false){
  if(comErro){
    return robo.lerSensorLinhaEsq() > refletancia_esq2.getSeparacao();
  }else{
    return robo.lerSensorLinhaEsqSemRuido() > refletancia_esq2.getSeparacao();
  }
}

bool Sensores::Esq_Preto(bool comErro=false){
  if(comErro){
    return robo.lerSensorLinhaEsq() < refletancia_esq2.getSeparacao();
  }else{
    return robo.lerSensorLinhaEsqSemRuido() < refletancia_esq2.getSeparacao();
  }
}

bool Sensores::Dir_Branco(bool comErro=false){
  if(comErro){
    return robo.lerSensorLinhaDir() > refletancia_esq2.getSeparacao();
  }else{
    return robo.lerSensorLinhaDirSemRuido() > refletancia_esq2.getSeparacao();
  }
}

bool Sensores::Dir_Preto(bool comErro=false){
  if(comErro){
    return robo.lerSensorLinhaDir() < refletancia_esq2.getSeparacao();
  }else{
    return robo.lerSensorLinhaDirSemRuido() < refletancia_esq2.getSeparacao();
  }  
}

bool Sensores::maisDir_Branco(bool comErro=false){
  if(comErro){
    return robo.lerSensorLinhaMaisDir() > refletancia_esq2.getSeparacao();
  }else{
    return robo.lerSensorLinhaMaisDirSemRuido() > refletancia_esq2.getSeparacao();
  } 
}   

bool Sensores::maisDir_Preto(bool comErro=false){
  if(comErro){
    return robo.lerSensorLinhaMaisDir() < refletancia_esq2.getSeparacao();
  }else{
    return robo.lerSensorLinhaMaisDirSemRuido() < refletancia_esq2.getSeparacao();
  }
}

bool Sensores::maisEsq_super(){
  return robo.lerSensorLinhaMaisEsq() > (refletancia_esq2.getSeparacao() + 20); 
} 
bool Sensores::esq_super(){
  return robo.lerSensorLinhaEsq() > (refletancia_esq.getSeparacao() + 20); 
} 
bool Sensores::dir_super(){
  return robo.lerSensorLinhaDir() > (refletancia_dir.getSeparacao() + 20); 
} 
bool Sensores::maisDir_super(){
  return robo.lerSensorLinhaMaisDir() > (refletancia_dir2.getSeparacao() + 20); 
} 

//*****//

bool Sensores::super_branco() {
  return (
    maisEsq_super() &&
    esq_super() &&
    dir_super() &&
    maisDir_super()
    );
}

bool Sensores::branco_branco_branco_branco(){
  return(
    maisEsq_Branco() &&
    Esq_Branco() &&
    Dir_Branco() &&
    maisDir_Branco()
  );
}
bool Sensores::preto_preto_preto_preto(){
  return(
    maisEsq_Preto() &&
    Esq_Preto() &&
    Dir_Preto() &&
    maisDir_Preto()
  );
}
  
bool Sensores::branco_preto_branco_branco(){
  return(
    maisEsq_Branco() &&
    Esq_Preto() &&
    Dir_Branco() &&
    maisDir_Branco()
  );
}
bool Sensores::branco_branco_preto_branco(){
  return(
    maisEsq_Branco() &&
    Esq_Branco() &&
    Dir_Preto() &&
    maisDir_Branco()
  );
}
bool Sensores::preto_branco_branco_branco(){
  return(
    maisEsq_Preto() &&
    Esq_Branco() &&
    Dir_Branco() &&
    maisDir_Branco()
  );
}
bool Sensores::branco_branco_branco_preto(){
  return(
    maisEsq_Branco() &&
    Esq_Branco() &&
    Dir_Branco() &&
    maisDir_Preto()
  );
}
  
bool Sensores::preto_preto_branco_branco(){
  return(
    maisEsq_Preto() &&
    Esq_Preto() &&
    Dir_Branco() &&
    maisDir_Branco()
  );
}
bool Sensores::branco_branco_preto_preto(){
  return(
    maisEsq_Branco() &&
    Esq_Branco() &&
    Dir_Preto() &&
    maisDir_Preto()
  );
}
bool Sensores::branco_preto_preto_branco(){
  return(
    maisEsq_Branco() &&
    Esq_Preto() &&
    Dir_Preto() &&
    maisDir_Branco()
  );
}
bool Sensores::preto_branco_branco_preto(){
  return(
    maisEsq_Preto() &&
    Esq_Branco() &&
    Dir_Branco() &&
    maisDir_Preto()
  );
}
bool Sensores::preto_branco_preto_branco(){
  return(
    maisEsq_Preto() &&
    Esq_Branco() &&
    Dir_Preto() &&
    maisDir_Branco()
  );
}
bool Sensores::branco_preto_branco_preto(){
  return(
    maisEsq_Branco() &&
    Esq_Preto() &&
    Dir_Branco() &&
    maisDir_Preto()
  );
}
  
bool Sensores::preto_preto_preto_branco(){
  return(
    maisEsq_Preto() &&
    Esq_Preto() &&
    Dir_Preto() &&
    maisDir_Branco()
  );
}
bool Sensores::branco_preto_preto_preto(){
  return(
    maisEsq_Branco() &&
    Esq_Preto() &&
    Dir_Preto() &&
    maisDir_Preto()
  );
}
bool Sensores::preto_preto_branco_preto(){
  return(
    maisEsq_Preto() &&
    Esq_Preto() &&
    Dir_Branco() &&
    maisDir_Preto()
  );
}
bool Sensores::preto_branco_preto_preto(){
  return(
    maisEsq_Preto() &&
    Esq_Branco() &&
    Dir_Preto() &&
    maisDir_Preto()
  );
}

















