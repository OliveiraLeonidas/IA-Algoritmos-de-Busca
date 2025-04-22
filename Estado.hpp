#ifndef ESTADO_H
#define ESTADO_H
#include <list>
using namespace std;

class Estado {
public:
  // verificar se é o estado objetivo (método abstrato)
  virtual bool eObjetivo() = 0;

  //Representa a expansão do estado, gerando uma lista de filhos
  virtual list<Estado*> expandir() = 0;
};

#endif