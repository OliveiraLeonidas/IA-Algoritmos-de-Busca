#include "Node.hpp"
#include "EstadoMissionarioCanibal.hpp"
#include <iostream>
#include <stack> // Pilha
#include <list>

using namespace std;

// Verifica se um estado já foi expandido anteriormente
bool jaExpandido(list<Estado*> expandidos, Estado* novoEstado) {
    EstadoMissionarioCanibal* novoEstadoMC = dynamic_cast<EstadoMissionarioCanibal*>(novoEstado);
    for (list<Estado*>::iterator it = expandidos.begin(); it != expandidos.end(); it++) {
        EstadoMissionarioCanibal* estado = dynamic_cast<EstadoMissionarioCanibal*>(*it);
        if (novoEstadoMC->eigual(estado)) return true;
    }
    return false;
}

int main() {
    // Lista de estados expandidos
    list<Estado*> expandidos;

    // Instanciar uma pilha de Nó (Node)
    stack<Node*>* pilha = new stack<Node*>();

    // Definir um estado inicial.
    Estado* inicial = new EstadoMissionarioCanibal(0, 0, 3, 3, 'd'); // Precisamos de uma classe que represente o problema.
    
    // Ponteiro para o estado candidato a expansão
    Estado* atual = inicial;
    EstadoMissionarioCanibal* atualMC = dynamic_cast<EstadoMissionarioCanibal*>(atual);

    // Empilhar o estado inicial;
    Node* topo = new Node(inicial); // Primeira raiz, que não tem pai!
    pilha->push(topo);

    // Enquanto o estado NÃO for o estado objetivo.
    while (!atual->eObjetivo() && !pilha->empty()) {
        // 1. Desempilhar o topo
        Node* topo = pilha->top();
        atual = topo->getEstado();
        pilha->pop();

        // EstadoMissionarioCanibal* atualMC = dynamic_cast<EstadoMissionarioCanibal*>(atual);
        // atualMC->imprime();

        // Guardando o estado a ser expandido na lista
        expandidos.push_back(atual);

        // 2. Gerar os filhos
        list<Estado*> filhos = atual->expandir();

        // 3. Empilhar os filhos
        for (list<Estado*>::iterator it = filhos.begin(); it != filhos.end(); it++) {
            // Criar uma estrutura No para cada um dos filhos;
            Estado* filho = *it;

            if (!jaExpandido(expandidos, filho)) {
                Node* novaFolha = new Node(filho, topo);
                pilha->push(novaFolha);
            } else {
                // Se o estado já foi expandido, liberar a memória
                delete filho;
            }
        }

        // Verificar se a pilha ficou vazia (caso em que não há solução)
        if (pilha->empty()) {
            cout << "Não há solução para o problema!" << endl;
            break;
        }

        // Pegar o próximo topo
        topo = pilha->top();
        atual = topo->getEstado();

        cout << "Tamanho da pilha: " << pilha->size() << endl;
    }

    // Subir na arvore a partir do caminho solução
    while(atual != NULL) {      
        EstadoMissionarioCanibal* atualMC = dynamic_cast<EstadoMissionarioCanibal*>(atual);
        atualMC->imprime();

        //subir na arvore
        atual = atualMC->getPai();
      
    }

    // Se encontrou a solução
    // if (atual->eObjetivo()) {
    //     cout << "Solução encontrada!" << endl;
        
    //     // Opcional: Reconstruir o caminho da solução
    //     stack<EstadoMissionarioCanibal*> caminho;
    //     Node* no = pilha->top();
        
    //     while (no != nullptr) {
    //         EstadoMissionarioCanibal* estadoMC = dynamic_cast<EstadoMissionarioCanibal*>(no->getEstado());
    //         caminho.push(estadoMC);
    //         no = no->getPai();
    //     }
        
    //     // cout << "Caminho da solução (do final para o início):" << endl;
    //     // while (!caminho.empty()) {
    //     //     caminho.top()->imprime();
    //     //     caminho.pop();
    //     // }
    // }

    // Liberar memória
    while (!pilha->empty()) {
        Node* no = pilha->top();
        pilha->pop();
        delete no;
    }
    delete pilha;

    // Liberar memória dos estados expandidos
    for (list<Estado*>::iterator it = expandidos.begin(); it != expandidos.end(); it++) {
        delete *it;
    }

    return 0;
}