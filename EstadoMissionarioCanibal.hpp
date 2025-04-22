#ifndef ESTADO_MISSIONARIO_CANIBAL_H
#define ESTADO_MISSIONARIO_CANIBAL_H

// Incluir a interface que será implementada
#include "Estado.hpp"
#include <list>

class EstadoMissionarioCanibal : public Estado {
  private:
    // atributos do problema.
    int mE;
    int mD;
    int cE;
    int cD;
    char barco;

    list<Estado *> filhos;
  
  public:
    Estado * pai;
    // Dois construtores sobrecarregados
    EstadoMissionarioCanibal(int mE, int cE, int mD, int cD, char barco);
    EstadoMissionarioCanibal(Estado * pai, int mE, int cE, int mD, int cD, char barco);
    
    // Implementação por sobrescita dos métodos da interface.
    bool eObjetivo();
    list<Estado *> expandir();
    
    // Método para verificar se dois estados são iguais
    bool eigual(EstadoMissionarioCanibal* outro);
    
    // Método para exibir na tela o estado.
    void imprime();
    
    // restrições do problema
    bool ePossivel();
    
    // Ações do problema
    EstadoMissionarioCanibal * mover1Missionario();
    EstadoMissionarioCanibal * mover2Missionario();
    EstadoMissionarioCanibal * mover1Canibal();
    EstadoMissionarioCanibal * mover2Canibal();
    EstadoMissionarioCanibal * mover1Missionario1Canibal();
};

#endif