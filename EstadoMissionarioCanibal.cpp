#include "EstadoMissionarioCanibal.hpp"
#include <cstdlib>
#include <list>
#include <iostream>

using namespace std;

// Dois construtores sobrecarregados
EstadoMissionarioCanibal::EstadoMissionarioCanibal(int mE, int cE, int mD, int cD, char barco){
    this->pai = NULL;
    this->mE  = mE;
    this->cE  = cE;
    this->mD  = mD;
    this->cD  = cD;
    this->barco = barco;
}

EstadoMissionarioCanibal::EstadoMissionarioCanibal(Estado * pai, int mE, int cE, int mD, int cD, char barco){
    this->pai = pai;
    this->mE  = mE;
    this->cE  = cE;
    this->mD  = mD;
    this->cD  = cD;
    this->barco = barco;
}

bool EstadoMissionarioCanibal::ePossivel(){
     // Verifica se os números são válidos (não negativos e não excedem o total)
     if (this->mE < 0 || this->cE < 0 || this->mD < 0 || this->cD < 0)
     return false;
 
    if (this->mE > 3 || this->cE > 3 || this->mD > 3 || this->cD > 3)
        return false;
    
    // Verifica se o total de missionários e canibais é correto
    if (this->mE + this->mD != 3 || this->cE + this->cD != 3)
        return false;
    
    // Verifica a regra de segurança: não pode haver mais canibais que missionários
    // em qualquer margem, a menos que não haja missionários nessa margem
    if ((this->mE > 0 && this->cE > this->mE) || (this->mD > 0 && this->cD > this->mD))
        return false;
    
    return true;

}
    
// Implementação por sobrescita dos métodos da interface.
bool  EstadoMissionarioCanibal::eObjetivo(){
    return (this->mE == 3 && this->cE == 3 && this->mD == 0 && this->cD == 0 && this->barco == 'e');    
}

bool EstadoMissionarioCanibal::eigual(EstadoMissionarioCanibal* outro) {
  if (outro == nullptr) return false;
  
  return this->mE == outro->mE && 
         this->cE == outro->cE && 
         this->mD == outro->mD && 
         this->cD == outro->cD && 
         this->barco == outro->barco;
}

// Ações do problema
EstadoMissionarioCanibal * EstadoMissionarioCanibal::mover1Missionario(){
    EstadoMissionarioCanibal * filho;
    if(this->barco == 'e'){
        filho = new EstadoMissionarioCanibal(this, this->mE-1, this->cE, this->mD + 1, this->cD, 'd');
          
    }
    else{
        filho = new EstadoMissionarioCanibal(this, this->mE+1, this->cE, this->mD - 1, this->cD, 'e'); 
    }
    if(filho->ePossivel())
        return filho;
    
    return NULL;
}

EstadoMissionarioCanibal * EstadoMissionarioCanibal::mover2Missionario(){
    EstadoMissionarioCanibal * filho;
    if(this->barco == 'e'){
        filho = new EstadoMissionarioCanibal(this, this->mE-2, this->cE, this->mD + 2, this->cD, 'd');
    }
    else{
        filho = new EstadoMissionarioCanibal(this, this->mE+2, this->cE, this->mD - 2, this->cD, 'e'); 
    }
    if(filho->ePossivel())
        return filho;
    
    return NULL;
}

EstadoMissionarioCanibal * EstadoMissionarioCanibal::mover1Canibal(){
    EstadoMissionarioCanibal * filho;
    if(this->barco == 'e'){
        filho = new EstadoMissionarioCanibal(this, this->mE, this->cE-1, this->mD, this->cD+1, 'd');
          
    }
    else{
        filho = new EstadoMissionarioCanibal(this, this->mE, this->cE+1, this->mD, this->cD-1, 'e'); 
    }
    if(filho->ePossivel())
        return filho;
    
    return NULL;
}

EstadoMissionarioCanibal * EstadoMissionarioCanibal::mover2Canibal(){
    EstadoMissionarioCanibal * filho;
    if(this->barco == 'e'){
        filho = new EstadoMissionarioCanibal(this, this->mE, this->cE-2, this->mD, this->cD+2, 'd');
    }
    else{
        filho = new EstadoMissionarioCanibal(this, this->mE, this->cE+2, this->mD, this->cD-2, 'e'); 
    }
    if(filho->ePossivel())
        return filho;
    
    return NULL;
}

EstadoMissionarioCanibal * EstadoMissionarioCanibal::mover1Missionario1Canibal(){
    EstadoMissionarioCanibal * filho;
    if(this->barco == 'e'){
        filho = new EstadoMissionarioCanibal(this, this->mE-1, this->cE-1, this->mD+1, this->cD+1, 'd');
    }
    else{
        filho = new EstadoMissionarioCanibal(this, this->mE+1, this->cE+1, this->mD-1, this->cD-1, 'e'); 
    }
    if(filho->ePossivel())
        return filho;
    
    return NULL;
}


list <Estado *> EstadoMissionarioCanibal::expandir(){
    EstadoMissionarioCanibal * filho1 = this->mover1Missionario();
    if(filho1 != NULL){
        this->filhos.push_back(filho1);
    }
    EstadoMissionarioCanibal * filho2 = this->mover2Missionario();
    if(filho2 != NULL){
        this->filhos.push_back(filho2);
    }
    EstadoMissionarioCanibal * filho3 = this->mover1Missionario1Canibal();
    if(filho3 != NULL){
        this->filhos.push_back(filho3);
    }
    EstadoMissionarioCanibal * filho4 = this->mover1Canibal();
    if(filho4 != NULL){
        this->filhos.push_back(filho4);
    }
    EstadoMissionarioCanibal * filho5 = this->mover2Canibal();
    if(filho5 != NULL){
        this->filhos.push_back(filho5);
    }
    return this->filhos;
    
}

void EstadoMissionarioCanibal::imprime(){
    cout << this->mE << "M |   | " << this->mD << "M\n";
    if(this->barco == 'e'){
        cout << "   |*  |\n";
    }else{
        cout << "   |  *|\n";
    }
    cout << this->cE << "C |   | " << this->cD << "C\n\n";
}