#include "Jogador.h"

Jogador::Jogador(int identi, const std::string &nome){
   setName(nome);
   id = identi;
   pieces = 9;
}

void Jogador::setName(const std::string &nome){
   if (nome.length() <= 15){
      name = nome; 
   }else{
      name = nome.substr(0, 15);
      std::cout << "Nome excede o total de caracteres" << std::endl;
   }
}

std::string Jogador::getName() const{
   return name;
}

void Jogador::decreasePiece(int pieces_number){
   for (int i = 0; i < pieces_number; i++){
      pieces--;
   }
}

int Jogador::getPiece() const{
   return pieces;
}

int Jogador::getId() const{
   return id;
}

void Jogador::printJogador() const{
   std::cout << "Nome do Jogador: ";
   getName();
   std::cout << std::endl;
   std::cout << "Id do jogador: " << getId() << std::endl;
   std::cout << "Quantidade de peças do jogador: " << getPiece() << std::endl;
}

void Jogador::increasePieces(int recovery_pieces){
   for (int i = 0; i < recovery_pieces; i++){
      pieces++;
   }
}

void Jogador::printName() const{
   std::cout << name;
}