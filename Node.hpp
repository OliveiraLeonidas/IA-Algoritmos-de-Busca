#include "Estado.hpp"

using namespace std;
// Representa uma estrutura de dados que armazena um estado
// e o pai que o originou.

class Node {
  private:
    Estado * estado;
    Node * pai;


  public:

  //Para a raíz da árvore.
  Node(Estado * estado);
  Node(Estado* estado, Node * pai);

  Estado * getEstado();
  Node * getPai();
};