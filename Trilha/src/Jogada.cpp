#include "Jogada.h"

Jogada::Jogada(){
   jogador = -1;
   x_old = -1;
   y_old = -1;
   x_lost = -1;
   y_lost = -1;
   lost_pieces = -1;
}



Jogada::Jogada(int id, int xo, int yo, int lps, int xl, int yl) : 
jogador{id}, x_old{xo}, y_old{yo}, lost_pieces{lps}, x_lost{xl}, y_lost{yl} {}

int Jogada::getJogador()const {
   return jogador;
}

int Jogada::getLostPiece()const {
   return lost_pieces;
}

void Jogada::InitPos_old(std::vector<int> &pos_old){
   pos_old[0] = x_old;
   pos_old[1] = y_old;
}

void Jogada::InitPos_lost(std::vector<int> &pos_lost){
   pos_lost[0] = x_lost;
   pos_lost[1] = y_lost;
}

