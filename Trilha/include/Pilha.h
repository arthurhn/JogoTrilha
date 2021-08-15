#ifndef PILHA_H
#define PILHA_H

#include "Jogada.h"

// Pilha genérica
class Pilha{
   private:
      int topo;                    // Topo da pilha 
      int capacidade;              // Capacidade da pilha
      Jogada* elementos;              // Ponteiro de elementos (Vetor)

   public:
      Pilha();
      Pilha(const Pilha &);   // Construtor de cópia para lidar o ponteiro flutuante
      ~Pilha();

      // Retorna o numero de elementos 
      int size() const;

      // Retorna o elemento no topo
      Jogada elemTopo() const;
      
      // Retorna a capaciade
      int getCapacidade() const;
      
      // Empilha
      void push(Jogada elem);   

      // Desempilha
      void pop();

      // Retorna true caso a pilha esteja vazia 
      bool isEmpty() const;

      // Retorna se a pilha esta cheia 
      bool isFull() const;

      // Retorna o espaço disponível
      int freeSpace() const;
};


#endif