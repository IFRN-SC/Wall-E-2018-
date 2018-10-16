#include "SensoresWallE.h"

Sensores::Sensores(){}

//void Sensores::Menu_calibrar(){
//  cali.Menu_calibrar();
//}

bool Sensores::maisEsq_Branco(){
  if (robo.lerSensorLinhaMaisEsq() > refletancia_esq2.getSeparacao()){
    return true;  
  }
  else {
    return false;
  }
}

bool Sensores::maisEsq_Preto(){
  if (robo.lerSensorLinhaMaisEsq() < refletancia_esq2.getSeparacao()) {
    return true;
  }
  else {
    return false;
  }
}

bool Sensores::Esq_Branco(){
  if (robo.lerSensorLinhaEsq() > refletancia_esq.getSeparacao()) {
    return true;  
  }
  else {
    return false;
  }
}

bool Sensores::Esq_Preto(){
  if (robo.lerSensorLinhaEsq() < refletancia_esq.getSeparacao()) {
    return true;  
  }
  else {
    return false;
  }
}

bool Sensores::Dir_Branco(){
  if(robo.lerSensorLinhaDir() > refletancia_dir.getSeparacao()){
    return true;
  }
  else {
    return false;
  } 
}

bool Sensores::Dir_Preto(){
  if(robo.lerSensorLinhaDir() < refletancia_dir.getSeparacao()){
    return true;
  }
  else {
    return false;
  }   
}

bool Sensores::maisDir_Branco(){
  if(robo.lerSensorLinhaMaisDir() > refletancia_dir2.getSeparacao()){
    return true;
  }
  else {
    return false;
  } 
}   

bool Sensores::maisDir_Preto(){
  if(robo.lerSensorLinhaMaisDir() < refletancia_dir2.getSeparacao()){
    return true;
  }
  else {
    return false;
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

















