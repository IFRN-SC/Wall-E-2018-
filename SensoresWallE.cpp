#include "SensoresWallE.h"

Sensores::Sensores(){}

//void Sensores::Menu_calibrar(){
//	cali.Menu_calibrar();
//}

bool Sensores::maisEsq_Branco(){
	if (robo.lerSensorLinhaEsq2() > getSeparacaoEsq2()){
		return true;	
	}
	else {
		return false;
	}
}

bool Sensores::maisEsq_Preto(){
	if (robo.lerSensorLinhaEsq2() < getSeparacaoEsq2()) {
		return true;
	}
	else {
		return false;
	}
}

bool Sensores::Esq_Branco(){
	if (robo.lerSensorLinhaEsq() > getSeparacaoEsq()) {
		return true;	
	}
	else {
		return false;
	}
}

bool Sensores::Esq_Preto(){
	if (robo.lerSensorLinhaEsq() < getSeparacaoEsq()) {
		return true;	
	}
	else {
		return false;
	}
}

bool Sensores::Dir_Branco(){
	if(robo.lerSensorLinhaDir() > getSeparacaoDir()){
		return true;
	}
	else {
		return false;
	}	
}

bool Sensores::Dir_Preto(){
	if(robo.lerSensorLinhaDir() < getSeparacaoDir()){
		return true;
	}
	else {
		return false;
	}		
}

bool Sensores::maisDir_Branco(){
	if(robo.lerSensorLinhaDir2() > getSeparacaoDir2()){
		return true;
	}
	else {
		return false;
	}	
}   

bool Sensores::maisDir_Preto(){
	if(robo.lerSensorLinhaDir2() < getSeparacaoDir2()){
		return true;
	}
	else {
		return false;
	}
} 

//*****//

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

















