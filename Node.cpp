#include "Node.hpp"
#include <cstdlib>

using namespace std;

Node::Node(Estado * estado) {
  this->estado = estado;
  this->pai = NULL;
}

Node::Node(Estado * estado, Node * pai) {
  this->estado = estado;
  this->pai = pai;
}

Estado * Node::getEstado() {
  return this->estado;
}

Node * Node::getPai(){
  return this->pai;
}