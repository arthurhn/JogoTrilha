#ifndef JOGADA_H
#define JOGADA_H

#include <vector>

class Jogada{
   private:
      int jogador;
      int x_old, y_old;       // Posição nova
      int lost_pieces;
      int x_lost, y_lost;

   public:
      Jogada();
      Jogada(int id, int xo, int yo, int lps = 0, int xl = -1, int yl = -1);

      // Retorna o jogador
      int getJogador() const;

      // Retorna true caso o jogador inimigo tenha perdido peça 
      int getLostPiece() const;

      // Inicializa o vetor passado com as posições antigas 
      void InitPos_old(std::vector<int> &pos_old);

      void InitPos_lost(std::vector<int> &pos_lost);
      
};

#endif
