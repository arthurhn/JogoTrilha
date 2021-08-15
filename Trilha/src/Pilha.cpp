#include "Pilha.h"

Pilha::Pilha(): topo{-1}, capacidade{200}{
   elementos = new Jogada[capacidade];
}

Pilha::Pilha(const Pilha &copy){
   topo = copy.topo;
   capacidade = copy.capacidade;
   int tamanho = topo + 1;

   elementos = new Jogada[capacidade];

   for(int i = 0; i < tamanho; i++){
      this->elementos[i] = copy.elementos[i];
   }
}

Pilha::~Pilha(){
   delete[] elementos;
}

Jogada Pilha:: elemTopo() const{
   if (isEmpty()){
      return {};
   }
   return elementos[topo];
}

int Pilha::getCapacidade() const{
   return capacidade;
}

void Pilha::push(Jogada elem){
   topo++;
   elementos[topo] = elem;
   return;
}


void Pilha::pop(){
   if(isEmpty()) {
      return;
   }
   topo--;
   return;
}

int Pilha::size() const{
   return topo + 1;
}


bool Pilha::isEmpty() const{
   return (topo == -1);
}

bool Pilha::isFull() const{
   return topo + 1 == capacidade;
}


int Pilha::freeSpace() const{
   return capacidade - (topo + 1);
}