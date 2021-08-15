#include "Moinho.h"
#include <iostream>

Moinho::Moinho(){
   direcao = 0;
   estado = 0;
   pos_j = -1;
   pos_i = -1;
}

void Moinho::setDirecao(int d){
   direcao = d;
}

void Moinho::setEstado(int e){
   estado = e;
}

void Moinho::setPos_i(int i){
   pos_i = i;
}

void Moinho::setPos_j(int j){
   pos_j = j;
}

int Moinho::getDirecao(){
   return direcao;
}

int Moinho::getEstado(){
   return estado;
}

int Moinho::getPos_i(){
   return pos_i;
}

int Moinho::getPos_j(){
   return pos_j;
}

void Moinho::showMoinho(){
   std::cout << "Direcao: " << getDirecao() << std::endl;
   std::cout << "Estado: " << getEstado() << std::endl;
   std::cout << "Pos i: " << getPos_i() << std::endl;
   std::cout << "Pos j: " << getPos_j() << std::endl;
}