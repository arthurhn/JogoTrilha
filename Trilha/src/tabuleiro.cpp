#include "tabuleiro.h"
#include <vector>
#include <iostream>
#include <string>
#include <random>
#include <iomanip>

Tabuleiro::Tabuleiro(){}

Tabuleiro::~Tabuleiro(){}

void Tabuleiro::showTabuleiro()
{
   using namespace std;
   
   //printf("\033c");
   
   for(int k=0; k<3; k++)
      cout << AMARELO << "    " << k << "   ";

   cout << endl << endl;

   for(int i = 0; i < 8; i++){
     
      if(i==4)cout << AMARELO << "     " << i << " ";   //printa os numeros em volta
      else cout << i << "   ";

      if (i == 3){

         for(int j = 0; j < 3; j++){
            if (j == 2){
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j];
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j];
               else cout << AMARELO << tabuleiro[i][j];
               //cout << tabuleiro[i][j];
            }else{
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j] << AMARELO << "-";
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j] << AMARELO << "-";
               else cout << AMARELO << tabuleiro[i][j] << AMARELO << "-";
               //cout << tabuleiro[i][j] << "-";
            }
         }  
      continue;

      }else if (i == 4){

         for(int j = 0; j < 3; j++){
            if (j == 2){
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j];
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j];
               else cout << AMARELO << tabuleiro[i][j];
               //cout << tabuleiro[i][j];
            }else{
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j] << AMARELO << "-";
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j] << AMARELO << "-";
               else cout << AMARELO << tabuleiro[i][j] << AMARELO << "-";
               //cout << tabuleiro[i][j] << "-";
            }
         }

      }else if ((i == 1) or (i == 6)){ 
         cout << "| ";
         for(int j = 0; j < 3; j++){
            if (j == 2){
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j] << AMARELO << " |";
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j] << AMARELO << " |";
               else cout << AMARELO << tabuleiro[i][j] << AMARELO << " |";
               //cout << tabuleiro[i][j] << " |";
            }else{
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j] << AMARELO << "-----";
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j] << AMARELO << "-----";
               else cout << AMARELO << tabuleiro[i][j] << AMARELO << "-----";
               //cout << tabuleiro[i][j] << "-----";
            }
         }

      }else if ((i == 2) or (i == 5)){
         cout << "| | ";

         for(int j = 0; j < 3; j++){
            if (j == 2){
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j] << AMARELO << " | |";
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j] << AMARELO << " | |";
               else cout << AMARELO << tabuleiro[i][j] << AMARELO << " | |";
               //cout << tabuleiro[i][j] << " | |";
            }else{
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j] << AMARELO << "---";
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j] << AMARELO << "---";
               else cout << AMARELO << tabuleiro[i][j] << AMARELO << "---";
               //cout << tabuleiro[i][j] << "---";
            }
         }

      } else{

         for(int j = 0; j < 3; j++){
            if (j == 2){
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j];
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j];
               else cout << AMARELO << tabuleiro[i][j];
               //cout << tabuleiro[i][j];
            }else{
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j] << AMARELO << "-------";
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j] << AMARELO << "-------";
               else cout << AMARELO << tabuleiro[i][j] << "-------";
               //cout << tabuleiro[i][j] << "-------";
            }
         }

      } 
      cout << AMARELO << endl;

   }
}

void Tabuleiro::showTabuleiro(int pieces1, int pieces2)
{
   using namespace std;

   //printf("\033c");
   
   for(int k=0; k<3; k++)
      cout << AMARELO << "    " << k << "   ";

   cout << endl << endl;

   for(int i = 0; i < 8; i++){
     
      if(i==4)cout << AMARELO << "     " << i << " ";   //printa os numeros em volta
      else cout << i << "   ";

      if (i == 3){

         for(int j = 0; j < 3; j++){
            if (j == 2){
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j];
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j];
               else cout << AMARELO << tabuleiro[i][j];
               //cout << tabuleiro[i][j];
            }else{
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j] << AMARELO << "-";
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j] << AMARELO << "-";
               else cout << AMARELO << tabuleiro[i][j] << AMARELO << "-";
               //cout << tabuleiro[i][j] << "-";
            }
         }  
      continue;

      }else if (i == 4){

         for(int j = 0; j < 3; j++){
            if (j == 2){
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j];
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j];
               else cout << AMARELO << tabuleiro[i][j];
               //cout << tabuleiro[i][j];
            }else{
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j] << AMARELO << "-";
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j] << AMARELO << "-";
               else cout << AMARELO << tabuleiro[i][j] << AMARELO << "-";
               //cout << tabuleiro[i][j] << "-";
            }
         }

      }else if ((i == 1) or (i == 6)){ 
         cout << "| ";
         for(int j = 0; j < 3; j++){
            if (j == 2){
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j] << AMARELO << " |";
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j] << AMARELO << " |";
               else cout << AMARELO << tabuleiro[i][j] << AMARELO << " |";
               //cout << tabuleiro[i][j] << " |";
            }else{
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j] << AMARELO << "-----";
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j] << AMARELO << "-----";
               else cout << AMARELO << tabuleiro[i][j] << AMARELO << "-----";
               //cout << tabuleiro[i][j] << "-----";
            }
         }

      }else if ((i == 2) or (i == 5)){
         cout << "| | ";

         for(int j = 0; j < 3; j++){
            if (j == 2){
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j] << AMARELO << " | |";
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j] << AMARELO << " | |";
               else cout << AMARELO << tabuleiro[i][j] << AMARELO << " | |";
               //cout << tabuleiro[i][j] << " | |";
            }else{
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j] << AMARELO << "---";
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j] << AMARELO << "---";
               else cout << AMARELO << tabuleiro[i][j] << AMARELO << "---";
               //cout << tabuleiro[i][j] << "---";
            }
         }

      } else{

         for(int j = 0; j < 3; j++){
            if (j == 2){
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j];
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j];
               else cout << AMARELO << tabuleiro[i][j];
               //cout << tabuleiro[i][j];
            }else{
               if(tabuleiro[i][j]==1) cout << AZUL << tabuleiro[i][j] << AMARELO << "-------";
               else if(tabuleiro[i][j]==2) cout << VERMELHO  << tabuleiro[i][j] << AMARELO << "-------";
               else cout << AMARELO << tabuleiro[i][j] << "-------";
               //cout << tabuleiro[i][j] << "-------";
            }
         }

      } 

      cout << AMARELO << endl;

   }

   cout << "Numero de peças do jogador 1: " << pieces1 << endl;
   cout << "Numero de peças do jogador 2: " << pieces2 << endl;
   cout << endl;
}

int Tabuleiro::getPosicao(int i, int j){
   return tabuleiro[i][j];
}

bool Tabuleiro::setPosicao(int jogada, int i, int j){
   
   if(jogada == 0){ // Limpa a posição (necessário para fazer o movimento das peças)
      tabuleiro[i][j] = jogada;
      return true;
   }
   else if(IsPlaced(i, j)){   // Checa se a posição está ocupada 
      std::cout << "Posição já escolhida" << std::endl;
      return false;
   }
   
   tabuleiro[i][j] = jogada;
   return true;
}

bool Tabuleiro::IsPlaced(int i, int j){
	if(tabuleiro[i][j] != 0)
		return true;
	else
		return false;
}

int Tabuleiro::findMoinhoH(int player){
   int count = 0; // Num de moinhos novos

   for (int i = 0; i < 8; i ++){
      int j = 0;
      if (getPosicao(i, j) == player){
         j++;
         if (getPosicao(i, j) == player){
            j++;
            if (getPosicao(i, j) == player){
               if(!moinhoExiste(i, 0)){ // Inicializa o moinho caso ele não exista na horizontal
                  count++;
                  initMoinho(i, 0, player, 1);           
               }
            }
         }
      }
   }

   return count;

}

int Tabuleiro::findMoinhoV(int player){
   int count = 0;
   for (int j = 0; j < 3; j ++){                   // Checa as verticais do quadrado mais externo
      if (j == 0){                                 // Checa a linha vertical esquerda
         int i = 0;
         if (getPosicao(i, j) == player){
            i = 3;
            if (getPosicao(i, j) == player){
               i = 7;
               if (getPosicao(i, j) == player){
                  // Inicializa o moinho caso ele não exista na vertical
                  if (!moinhoExiste(0, 0)){ 
                     count++;
                     initMoinho(0, 0, player, 2);           
                  }
               }
            }
         }
      }
      if (j == 2){                                 // Checa a linha vertical direita
         int i = 0;
         if (getPosicao(0, j) == player){
            i = 4;
            if (getPosicao(i, j) == player){
               i = 7;
               if (getPosicao(i, j) == player){
                  // Inicializa o moinho caso ele não exista na vertical
                  if (!moinhoExiste(0, 2)){ 
                     count++;
                     initMoinho(0, 2, player, 2);           
                  }
               }
            }
         }
      }
      if (j == 1){                                 // Checa a linha vertical do meio
         int i = 0;
         if (getPosicao(0, j) == player){
            i = 1;
            if (getPosicao(i, j) == player){
               i = 2;
               if (getPosicao(i, j) == player){
                  // Inicializa o moinho caso ele não exista na vertical
                  if (!moinhoExiste(0, 1)){ 
                     count++;
                     initMoinho(0, 1, player, 2);           
                  }
               }
            }
         }
      }
   }

   for (int j = 0; j < 3; j ++){                   // Checa as verticais do quadrado do meio
      if (j == 0){                                 // Checa a linha vertical esquerda
         int i = 1;
         if (getPosicao(i, j) == player){
            i = 3;
            if (getPosicao(i, 1) == player){
               i = 6;
               if (getPosicao(i, j) == player){
                  // Inicializa o moinho caso ele não exista na vertical
                  if (!moinhoExiste(1, 0)){ 
                     count++;
                     initMoinho(1, 0, player, 2);           
                  }
               }
            }
         }
      }

      if (j == 2){                                 // Checa a linha vertical direita
         int i = 1;
         if (getPosicao(i, j) == player){
            i = 4;
            if (getPosicao(i, 1) == player){
               i = 6;
               if (getPosicao(i, j) == player){
                  if (!moinhoExiste(1, 2)){ 
                     count++;
                     initMoinho(1, 2, player, 2);           
                  }
               }
            }
         }
      }
   
   }

   for (int j = 0; j < 3; j ++){                   // Checa as verticais do quadrado mais interno
      if (j == 0){                                 // Checa a linha vertical esquerda
         int i = 2;
         if (getPosicao(i, j) == player){
            i = 3;
            if (getPosicao(i, 2) == player){
               i = 5;
               if (getPosicao(i, j) == player){
                  if (!moinhoExiste(2, 0)){ 
                     count++;
                     initMoinho(2, 0, player, 2);           
                  }
               }
            }
         }
      }

      if (j == 2){                                 // Checa a linha vertical direita
         int i = 2;
         if (getPosicao(i, j) == player){
            i = 4;
            if (getPosicao(i, 0) == player){
               i = 5;
               if (getPosicao(i, j) == player){
                  if (!moinhoExiste(2, 2)){ 
                     count++;
                     initMoinho(2, 2, player, 2);           
                  }
               }
            }
         }
      }
   
   }

   int i = 5;                                     
   if (getPosicao(i, 1) == player){                  // Checa a linha que começa na posição (5, 1)       
      i = 6;                         
      if (getPosicao(i, 1) == player){
         i = 7;
         if (getPosicao(i, 1) == player){
            if (!moinhoExiste(5, 1)){ 
               count++;
               initMoinho(5, 1, player, 2);           
            }
         }
      }
   }
   return count;

}

int Tabuleiro::findMoinho(int player){
   return findMoinhoV(player) + findMoinhoH(player);
}

int Tabuleiro::posVaziaMoinho(int player){
   if (player == 1){
      for(int i = 0; i < 4; i++){
         if(Moinho_p1[i].getEstado() == 0){
            return i;
         }
      } 
   }else if (player == 2){
      for(int i = 0; i < 4; i ++){
         if(Moinho_p2[i].getEstado() == 0){
            return i;
         }
      } 
   }

   std::cerr << "vetor cheio" << std::endl; 
   return -1;
} 

void Tabuleiro::showMoinhos(){
   std::cout << "-MOINHO PLAYER 1-" << std::endl << std::endl;

   for(int i = 0; i < 4; i++){
      std::cout << "Moinho " << i << std::endl;
      Moinho_p1[i].showMoinho();
      std::cout << "---------" << std::endl << std::endl;
   }

   std::cout << std::endl
             << "-MOINHO PLAYER 2-" << std::endl
             << std::endl;

   for(int i = 0; i < 4; i++){
      std::cout << "Moinho " << i << std::endl;
      Moinho_p2[i].showMoinho();
      std::cout << "---------" << std::endl << std::endl;
   }
}

bool Tabuleiro::moinhoExiste(int i, int j){
   for(int l = 0; l < 4; l++){   // Itera sobre o vetor de moinhos
      if(Moinho_p1[l].getPos_i() == i && Moinho_p1[l].getPos_j() == j){
         return true;      // Retorna true caso o moinho já exista
      }
      if(Moinho_p2[l].getPos_i() == i && Moinho_p2[l].getPos_j() == j){
         return true;      // Retorna true caso o moinho já exista
      }
   }

   return false;           // Retorna false caso não
}

void Tabuleiro::initMoinho(int i, int j, int player, int d){
   int l = posVaziaMoinho(player);
   if (player == 1){
      Moinho_p1[l].setDirecao(d);
      Moinho_p1[l].setEstado(1);
      Moinho_p1[l].setPos_i(i);
      Moinho_p1[l].setPos_j(j);
   }else{
      Moinho_p2[l].setDirecao(d);
      Moinho_p2[l].setEstado(1);
      Moinho_p2[l].setPos_i(i);
      Moinho_p2[l].setPos_j(j);
   }
}

int Tabuleiro::esvaziaMoinhos(){
   int count = 0;

   // Checa para o player 1
   for (int l = 0; l < 4; l++){
      if (!isVazio(l, 1)){
         if (!existeMoinho(Moinho_p1[l].getPos_i(), Moinho_p1[l].getPos_j(), Moinho_p1[l].getDirecao(), 1) ){
            count++;
            limpaMoinho(l, 1);
         }
      }
   }
   
   // Checa para o player 2
   for (int l = 0; l < 4; l++){
      if(!isVazio(l, 2)){
         if (!existeMoinho(Moinho_p2[l].getPos_i(), Moinho_p2[l].getPos_j(), Moinho_p2[l].getDirecao(), 2) ){
            count++;
            limpaMoinho(l, 2);
         }
      }
   }
   return count;
}  

bool Tabuleiro::existeMoinho(int i, int j, int d, int player){
   if (d == 1){
      if (getPosicao(i, j) == player){
         j++;
         if (getPosicao(i, j) == player){
            j++;
            if (getPosicao(i, j) == player){
               return true;
            }
         }
      }
   }else if(d == 2){
      if (j == 0 && i == 0){  // Checa a linha vertical esquerda mais externa
         if (getPosicao(i, j) == player){
            i = 3;
            if (getPosicao(i, j) == player){
               i = 7;
               if (getPosicao(i, j) == player){
                  return true;
               }
            }
         }
      }else if (j == 2 && i == 0){  // Checa a linha vertical direita mais externa
         if (getPosicao(i, j) == player){
            i = 4;
            if (getPosicao(i, j) == player){
               i = 7;
               if (getPosicao(i, j) == player){
                  return true;
               }
            }
         }
      }else if (j == 1 && i == 0){  // Checa a linha vertical do meio mais externa
         if (getPosicao(i, j) == player){
            i++;
            if (getPosicao(i, j) == player){
               i++;
               if (getPosicao(i, j) == player){
                  return true;
               }
            }
         }
      }else if (j == 0 && i == 1){   // Checa a linha vertical esquerda do quadrado do meio
         if (getPosicao(i, j) == player){
            i = 3;
            if (getPosicao(i, 1) == player){
               i = 6;
               if (getPosicao(i, j) == player){
                  return true;
               }
            }
         }
      }else if (j == 2 && i == 1){  // Checa a linha vertical direita do quadrado do meio
         if (getPosicao(i, j) == player){
            i = 4;
            if (getPosicao(i, 1) == player){
               i = 6;
               if (getPosicao(i, j) == player){
                  return true;
               }
            }
         }
      }else if (j == 0 && i == 2){  // Checa a linha vertical esquerda do quadrado mais interno
         if (getPosicao(i, j) == player){
            i = 3;
            if (getPosicao(i, 2) == player){
               i = 5;
               if (getPosicao(i, j) == player){
                  return true;
               }
            }
         }
      }else if (j == 2 && i == 2){  // Checa a linha vertical direita do quadrado mais interno
         if (getPosicao(i, j) == player){
            i = 4;
            if (getPosicao(i, 0) == player){
               i = 5;
               if (getPosicao(i, j) == player){
                  return true;
               }
            }
         }
      }else if (j == 1 && i == 5){  // Checa que começa na posição (5, 1)                 
         if (getPosicao(i, j) == player){
            i++;
            if (getPosicao(i, 1) == player){
               i++;
               if (getPosicao(i, 1) == player){
                  return true;
               }
            }
         }
      }
   }

   return false;
}

void Tabuleiro::limpaMoinho(int pos, int player){
   if (player == 1){
      Moinho_p1[pos].setDirecao(0);
      Moinho_p1[pos].setEstado(0);
      Moinho_p1[pos].setPos_i(-1);
      Moinho_p1[pos].setPos_j(-1);
   }else{
      Moinho_p2[pos].setDirecao(0);
      Moinho_p2[pos].setEstado(0);
      Moinho_p2[pos].setPos_i(-1);
      Moinho_p2[pos].setPos_j(-1);
   }
}

int Tabuleiro::checaTabuleiro(int player){
   int t = esvaziaMoinhos();

   return findMoinho(player);
}
                 
bool Tabuleiro::isVazio(int pos, int player){
   if(player == 1){
      if (Moinho_p1[pos].getEstado() == 0){
         return true;
      }
   }else{
      if (Moinho_p2[pos].getEstado() == 0){
         return true;
      }
   } 

   return false;
}

void Tabuleiro::movePieceIlimitada(int x, int y, int player){

	setPosicao(player, x, y);
}

bool Tabuleiro::checkPiece(int x, int y, int player){
   std::vector<int> positions(0);
   findPiecesIA(positions, player);

   for(unsigned i = 0; i < positions.size(); i = i + 2){
         if((positions[i] == x) and (positions[i + 1] == y)){
            setPosicao(0, x, y);
            return true;
         }
         
      }
   return false;
}

bool Tabuleiro::checkMoveY(int x_old, int y_old, int x_new, int y_new, int player){

   if(x_old == x_new){  // Checa se a movimentação é horizontal se não for não precia checar

      // Checa as bordas do movimento lateral
      if (y_new > 2 or y_new < 0){
         return false;

      // Checa as posições válidas do movimento latereal 
      }else if( (y_old == 0) || (y_old == 2) ){ // Checas as pontas
         if (y_new != 1){
            return false;
         }
      }else if(y_old == 1){   // Checa o meio
         if ( y_new == 1 ){
            return false;
         }
      }
   }

   return true;   // Inseriu uma posição válida

   
}
   
bool Tabuleiro::checkMoveX(int x_old, int y_old, int x_new, int y_new, int player){

   if(x_old != x_new){  // Só entra se for uma movimentação vertical

      // Checa as bordas do movimento vertical
      if (x_new > 7 || x_new < 0){
         return false;
      }

      // Checa as posições válidas do movimento vertical

      // Checa a vertical mais externa esquerda
      if( (x_old == 0 && y_old == 0) || (x_old == 7 && y_old == 0) ){ 
         if (x_new != 3 || y_new != 0){
            return false;
         } 
      }else if( (x_old == 3) && (y_old == 0) ){
         if ( ((x_new != 0) && (x_new != 7)) || (y_new != 0)){
            return false;
         }
      }

      // Checa a vertical mais externa direita
      if( (x_old == 0 && y_old == 2) || (x_old == 7 && y_old == 2) ){ 
         if (x_new != 4 || y_new != 2){
            return false;
         } 
      }else if( (x_old == 4) && (y_old == 2) ){
         if ( ((x_new != 0) && (x_new != 7)) || (y_new != 2) ){
            return false;
         }
      }
 
      // Checa a vertical do meio superior
      if( (x_old == 0 && y_old == 1) || (x_old == 2 && y_old == 1) ){ 
         if (x_new != 1 || y_new != 1){
            return false;
         } 
      }else if( (x_old == 1) && (y_old == 1) ){
         if ( ((x_new != 2) && (x_new != 0)) || (y_new != 1) ){
            return false;
         }
      }

      // Checa a vertical do meio inferior
      if( (x_old == 5 && y_old == 1) || (x_old == 7 && y_old == 1) ){ 
         if (x_new != 6 || y_new != 1){
            return false;
         } 
      }else if( (x_old == 6) && (y_old == 1) ){
         if ( ((x_new != 5) && (x_new != 7)) || (y_new != 1)){
            return false;
         }
      }

      // Checa a vertical do meio esquerda
      if( (x_old == 1 && y_old == 0) || (x_old == 6 && y_old == 0) ){ 
         if (x_new != 3 || y_new != 1){
            return false;
         } 
      }else if( (x_old == 3) && (y_old == 1) ){
         if ( ((x_new != 1) && (x_new != 6)) || (y_new != 0) ){
            return false;
         }
      }

      // Checa a vertical do meio direita
      if( (x_old == 1 && y_old == 2) || (x_old == 6 && y_old == 2) ){ 
         if (x_new != 4 || y_new != 1){
            return false;
         } 
      }else if( (x_old == 4) && (y_old == 1) ){
         if ( ((x_new != 1) && (x_new != 6)) || (y_new != 2) ){
            return false;
         }
      }

      // Checa a vertical  interna esquerda
      if( (x_old == 2 && y_old == 0) || (x_old == 5 && y_old == 0) ){ 
         if (x_new != 3 || y_new != 2){
            return false;
         } 
      }else if( (x_old == 3) && (y_old == 2) ){
         if ( ((x_new != 2) && (x_new != 5)) || (y_new != 0) ){
            return false;
         }
      }

      // Checa a vertical interna direita
      if( (x_old == 2 && y_old == 2) || (x_old == 5 && y_old == 2) ){ 
         if (x_new != 4 || y_new != 0){
            return false;
         } 
      }else if( (x_old == 4) && (y_old == 0) ){
         if ( ((x_new != 2) && (x_new != 5)) || (y_new != 2)){
            return false;
         }
      }

   }

   return true;
}

void Tabuleiro::posAleatorio(std::vector<int> &pos_random){

   std::random_device r;
	
   std::default_random_engine e1(r());
   std::uniform_int_distribution<int> uniform_dist_1(0, 7);

   std::default_random_engine e2(r());
   std::uniform_int_distribution<int> uniform_dist_2(0, 2);


   int x, y;
   do{
   
      x = uniform_dist_1(e1);   // Gera a posição x aleatória
      y = uniform_dist_2(e2);   // Gera a posição y aleatória

   }while(IsPlaced(x, y)); // Executa até achar uma posicão livre   

   pos_random[0] = x;
   pos_random[1] = y;

}

void Tabuleiro::findPiecesIA(std::vector< int > &vetor, int player){
   for (int i = 0; i < 8; i++){
      for(int j = 0; j < 3; j++){
         if(tabuleiro[i][j] == player){
            if (!posBlocked(i, j)){
               vetor.push_back(i);
               vetor.push_back(j);
               vetor.resize(vetor.size());
            }
         }
      }
   }

}

void Tabuleiro::chosePosAleatoria(std::vector< int > &positions, std::vector< int > &pos_chosed){
   std::random_device r;
   std::default_random_engine e(r());

   int resto, count = 0;
   int i;

   for(unsigned j = 0; j < positions.size(); j++){
      count++;
   }

   std::uniform_int_distribution<int> uniform_dist(0, (count - 2));

   if (positions.size() == 2){
      i = 0;
   }else{
      do{
         i = uniform_dist(e); 
         resto = i % 2;

      }while(resto != 0);  // Executa até achar uma posição válida para o i
   }

   unsigned x = static_cast<unsigned> (i);

   pos_chosed[0] = positions[x];
   pos_chosed[1] = positions[x + 1];
   
}

bool Tabuleiro::posBlocked(int i, int j){
   if(posBlockedH(i, j) && posBlockedV(i, j)){  // Checa se a peça está bloqueda na horizontal e vertical
      return true;
   }
   return false;

}

bool Tabuleiro::posBlockedH(int i, int j){   
   int left, right;
   left = j - 1;
   right = j + 1;

   if ( (left < 0) || (right > 2) ){   // Checa se tá na borda 
      if(IsPlaced(i, 1)){ // Checa se a pos do meio ta ocupada
         return true;
      }
   }else{   // Tá no meio
      if (IsPlaced(i, 0) && IsPlaced(i, 2) ){   // Checa a posição esquerda
         return true;
      }
   }

   return false;
}

bool Tabuleiro::posBlockedV(int i, int j){   
   // Checa as extremidades
   if( (i == 0 && j == 0) || (i == 7 && j == 0) ){ // Checa a coluna direira mais externa
      if (IsPlaced(3, 0)){
         return true;
      }
   }
   if( (i == 0 && j == 2) || (i == 7 && j == 2) ){ // Checa a coluna esquerda mais externa
      if (IsPlaced(4, 2)){
         return true;
      }
   }
   if( (i == 1 && j == 0) || (i == 6 && j == 0) ){ // Checa a coluna direita do meio
      if (IsPlaced(3, 1)){
         return true;
      }
   }
   if( (i == 1 && j == 2) || (i == 6 && j == 2) ){ // Checa a coluna esquerda do meio
      if (IsPlaced(4, 1)){
         return true;
      }
   }
   if( (i == 2 && j == 0) || (i == 5 && j == 0) ){ // Checa a coluna direita mais interna
      if (IsPlaced(3, 2)){
         return true;
      }
   }
   if( (i == 2 && j == 2) || (i == 5 && j == 2) ){ // Checa a coluna esquerda mais interna
      if (IsPlaced(4, 0)){
         return true;
      }
   }
   if( (i == 0 && j == 1) || (i == 2 && j == 1) ){ // Checa a coluna superior mais interna
      if (IsPlaced(1, 1)){
         return true;
      }
   }
   if( (i == 5 && j == 1) || (i == 7 && j == 1) ){ // Checa a coluna inferior mais interna
      if (IsPlaced(6, 1)){
         return true;
      }
   }

   // Checa os meios
   if (i == 3 && j == 0){  // Checa a coluna direita mais externa
      if (IsPlaced(0, 0) && IsPlaced(7, 0)){ 
         return true;
      }
   }
   if (i == 4 && j == 2){  // Checa a coluna esquerda mais externa
      if (IsPlaced(0, 2) && IsPlaced(7, 2)){ 
         return true;
      }
   }
   if (i == 3 && j == 1){  // Checa a coluna direita do meio
      if (IsPlaced(1, 0) && IsPlaced(6, 0)){ 
         return true;
      }
   }
   if (i == 4 && j == 1){  // Checa a coluna esquerda do meio
      if (IsPlaced(1, 2) && IsPlaced(6, 2)){ 
         return true;
      }
   }
   if (i == 3 && j == 2){  // Checa a coluna direita mais interna
      if (IsPlaced(5, 0) && IsPlaced(2, 0)){ 
         return true;
      }
   }
   if (i == 4 && j == 0){  // Checa a coluna esquerda mais interna
      if (IsPlaced(2, 2) && IsPlaced(5, 2)){ 
         return true;
      }
   }
   if (i == 1 && j == 1){  // Checa a coluna superior
      if (IsPlaced(0, 1) && IsPlaced(2, 1)){ 
         return true;
      }
   }
   if (i == 6 && j == 1){  // Checa a coluna inferior
      if (IsPlaced(5, 1) && IsPlaced(7, 1)){ 
         return true;
      }
   }
   

   return false;

}

void Tabuleiro::posFreeAroundH(int i, int j, std::vector< int > &positions_free){  
   int left, right;
   left = j - 1;
   right = j + 1;

   if ( (left < 0) || (right > 2) ){   // Checa se tá na borda 
      if(!IsPlaced(i, 1)){ // Checa se a pos do meio ta ocupada
         positions_free.push_back(i);
         positions_free.push_back(1);
         positions_free.resize(positions_free.size());
      }
   }else{   // Tá no meio
      if (!IsPlaced(i, 0)){   // Checa a posição esquerda
         positions_free.push_back(i);
         positions_free.push_back(0);
         positions_free.resize(positions_free.size());
      }
      if (!IsPlaced(i, 2)){   // Checa a posição direita
         positions_free.push_back(i);
         positions_free.push_back(2);
         positions_free.resize(positions_free.size());
      }
   }
}

void Tabuleiro::posFreeAroundV(int i, int j, std::vector< int > &positions_free){
   if( (i == 0 && j == 0) || (i == 7 && j == 0) ){ // Checa a coluna direira mais externa
      if (!IsPlaced(3, 0)){
         positions_free.push_back(3);
         positions_free.push_back(0);
         positions_free.resize(positions_free.size());
      }
   }
   if( (i == 0 && j == 2) || (i == 7 && j == 2) ){ // Checa a coluna esquerda mais externa
      if (!IsPlaced(4, 2)){
         positions_free.push_back(4);
         positions_free.push_back(2);
         positions_free.resize(positions_free.size());
      }
   }
   if( (i == 1 && j == 0) || (i == 6 && j == 0) ){ // Checa a coluna direita do meio
      if (!IsPlaced(3, 1)){
         positions_free.push_back(3);
         positions_free.push_back(1);
         positions_free.resize(positions_free.size());
      }
   }
   if( (i == 1 && j == 2) || (i == 6 && j == 2) ){ // Checa a coluna esquerda do meio
      if (!IsPlaced(4, 1)){
         positions_free.push_back(4);
         positions_free.push_back(1);
         positions_free.resize(positions_free.size());
      }
   }
   if( (i == 2 && j == 0) || (i == 5 && j == 0) ){ // Checa a coluna direita mais interna
      if (!IsPlaced(3, 2)){
         positions_free.push_back(3);
         positions_free.push_back(2);
         positions_free.resize(positions_free.size());
      }
   }
   if( (i == 2 && j == 2) || (i == 5 && j == 2) ){ // Checa a coluna esquerda mais interna
      if (!IsPlaced(4, 0)){
         positions_free.push_back(4);
         positions_free.push_back(0);
         positions_free.resize(positions_free.size());
      }
   }
   if( (i == 0 && j == 1) || (i == 2 && j == 1) ){ // Checa a coluna superior mais interna
      if (!IsPlaced(1, 1)){
         positions_free.push_back(1);
         positions_free.push_back(1);
         positions_free.resize(positions_free.size());
      }
   }
   if( (i == 5 && j == 1) || (i == 7 && j == 1) ){ // Checa a coluna inferior mais interna
      if (!IsPlaced(6, 1)){
         positions_free.push_back(6);
         positions_free.push_back(1);
         positions_free.resize(positions_free.size());
      }
   }

   if (i == 3 && j == 0){  // Checa a coluna direita mais externa
      if (!IsPlaced(0, 0)){ 
         positions_free.push_back(0);
         positions_free.push_back(0);
         positions_free.resize(positions_free.size());
      }
      if(!IsPlaced(7, 0)){
         positions_free.push_back(7);
         positions_free.push_back(0);
         positions_free.resize(positions_free.size());
      }
   }
   if (i == 4 && j == 2){  // Checa a coluna esquerda mais externa
      if (!IsPlaced(0, 2)){ 
         positions_free.push_back(0);
         positions_free.push_back(2);
         positions_free.resize(positions_free.size());
      }
      if(!IsPlaced(7, 2)){
         positions_free.push_back(7);
         positions_free.push_back(2);
         positions_free.resize(positions_free.size());
      }
   }
   if (i == 3 && j == 1){  // Checa a coluna direita do meio
      if (!IsPlaced(1, 0)){ 
         positions_free.push_back(1);
         positions_free.push_back(0);
         positions_free.resize(positions_free.size());
      }
      if(!IsPlaced(6, 0)){
         positions_free.push_back(6);
         positions_free.push_back(0);
         positions_free.resize(positions_free.size());
      }
   }
   if (i == 4 && j == 1){  // Checa a coluna esquerda do meio
      if (!IsPlaced(1, 2)){ 
         positions_free.push_back(1);
         positions_free.push_back(2);
         positions_free.resize(positions_free.size());
      }
      if(!IsPlaced(6, 2)){
         positions_free.push_back(6);
         positions_free.push_back(2);
         positions_free.resize(positions_free.size());
      }
   }
   if (i == 3 && j == 2){  // Checa a coluna direita mais interna
      if (!IsPlaced(2, 0)){ 
         positions_free.push_back(2);
         positions_free.push_back(0);
         positions_free.resize(positions_free.size());
      }
      if(!IsPlaced(5, 0)){
         positions_free.push_back(5);
         positions_free.push_back(0);
         positions_free.resize(positions_free.size());
      }
   }
   if (i == 4 && j == 0){  // Checa a coluna esquerda mais interna
      if (!IsPlaced(2, 2)){ 
         positions_free.push_back(2);
         positions_free.push_back(2);
         positions_free.resize(positions_free.size());
      }
      if(!IsPlaced(5, 2)){
         positions_free.push_back(5);
         positions_free.push_back(2);
         positions_free.resize(positions_free.size());
      }
   }
   if (i == 1 && j == 1){  // Checa a coluna superior
      if (!IsPlaced(0, 1)){ 
         positions_free.push_back(0);
         positions_free.push_back(1);
         positions_free.resize(positions_free.size());
      }
      if(!IsPlaced(2, 1)){
         positions_free.push_back(2);
         positions_free.push_back(1);
         positions_free.resize(positions_free.size());
      }
   }
   if (i == 6 && j == 1){  // Checa a coluna inferior
      if (!IsPlaced(5, 1)){ 
         positions_free.push_back(5);
         positions_free.push_back(1);
         positions_free.resize(positions_free.size());
      }
      if(!IsPlaced(7, 1)){
         positions_free.push_back(7);
         positions_free.push_back(1);
         positions_free.resize(positions_free.size());
      }
   }
}

void Tabuleiro::posFreeAround(int i, int j, std::vector< int > &positions_free){
   posFreeAroundV(i, j, positions_free);
   posFreeAroundH(i, j, positions_free);
}

int Tabuleiro::removeEnemyPieces(int player, int &xl, int &yl){
   int pieces = 0;
   int x_enemy, y_enemy, enemy_player;

   pieces = checaTabuleiro(player);

   // Identifica o player inimigo
   if(player == 1){
      enemy_player = 2;
   }else{
      enemy_player = 1;
   }

   // Só entra quando tem peças para retirar
   if (pieces != 0){
      
      showTabuleiro();

      // Escolha do player
      for(int i = 0; i < pieces; i++){
         validaInput(x_enemy, "Entre com o posicionamento x do player inimigo: ", 7);
         validaInput(y_enemy, "Entre com o posicionamento y do player inimigo: ", 2);

         while(getPosicao(x_enemy, y_enemy) != enemy_player){
            std::cout << "Posição inválida" << std::endl;
            validaInput(x_enemy, "Entre com o posicionamento x do player inimigo: ", 7);
            validaInput(y_enemy, "Entre com o posicionamento y do player inimigo: ", 2);
         }

         setPosicao(0, x_enemy, y_enemy);
         xl = x_enemy;
         yl = y_enemy;
         esvaziaMoinhos();
      }
   }

   return pieces;
}

int Tabuleiro::removeEnemyPieces(int player){
   int pieces = 0;
   int x_enemy, y_enemy, enemy_player;

   pieces = checaTabuleiro(player);

   // Identifica o player inimigo
   if(player == 1){
      enemy_player = 2;
   }else{
      enemy_player = 1;
   }

   // Só entra quando tem peças para retirar
   if (pieces != 0){
      
      showTabuleiro();

      // Escolha do player
      for(int i = 0; i < pieces; i++){
         validaInput(x_enemy, "Entre com o posicionamento x do player inimigo: ", 7);
         validaInput(y_enemy, "Entre com o posicionamento y do player inimigo: ", 2);

         while(getPosicao(x_enemy, y_enemy) != enemy_player){
            std::cout << "Posição inválida" << std::endl;
            validaInput(x_enemy, "Entre com o posicionamento x do player inimigo: ", 7);
            validaInput(y_enemy, "Entre com o posicionamento y do player inimigo: ", 2);
         }

         setPosicao(0, x_enemy, y_enemy);
         esvaziaMoinhos();
      }
   }

   return pieces;
}

void Tabuleiro::validaInteger(int& in, std::string out){
	
	std::cout << out;
	std::cin >> std::setw(1) >> in;

	while(!std::cin.good()){
		// Reporta o erro
		std::cout << "Entrada inválida. Tente novamente:" << std::endl;
		std::cout << out;

		// Limpa o fluxo de entrada
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// Pega a entrada novamente 
		std::cin >> std::setw(1) >> in;
	}
}

void Tabuleiro::validaInput(int& in, std::string out, int val_max){

	validaInteger(in, out);

	while(in < 0 || in > val_max){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		validaInteger(in, out);
	}

}

void Tabuleiro::removeIA(){
   std::vector<int> pos_enemy(0);
   std::vector<int> pos_chosed(2);

   findPiecesIA(pos_enemy, 1);
   chosePosAleatoria(pos_enemy, pos_chosed);

   setPosicao(0, pos_chosed[0], pos_chosed[1]);

}

void Tabuleiro::removeIA(int &xl, int &yl){
   std::vector<int> pos_enemy(0);
   std::vector<int> pos_chosed(2);

   findPiecesIA(pos_enemy, 1);
   chosePosAleatoria(pos_enemy, pos_chosed);

   setPosicao(0, pos_chosed[0], pos_chosed[1]);
   xl = pos_chosed[0];
   yl = pos_chosed[1];

}

void Tabuleiro::validaValor(int& in, std::string out, int valor){
   validaInteger(in, out);
}

int Tabuleiro::voltaJogada(Pilha &pilha, int player){
   int enemy_player;
   if(player == 1){
      enemy_player = 2;
   }else{
      enemy_player = 1;
   }

   int return_pieces;

   // Desempilha
   Jogada j = pilha.elemTopo();
   pilha.pop();

   // Reconstroi o tabuleiro
   std::vector<int> pos_old(2);
   j.InitPos_old(pos_old);
   setPosicao(0,pos_old[0], pos_old[1]);
   

   // Esvazia os moinhos destruidos na resconstrução
   esvaziaMoinhos();

   // Checar se fez um moinho na jogada 
   return_pieces = j.getLostPiece();

   if(return_pieces != 0){
      std::cout << "Entrei" << std::endl;
      // Refaz a jogada aonde o jogador perdeu peça
      std::vector<int> pos_lost(2);
      j.InitPos_lost(pos_lost);
      setPosicao(enemy_player, pos_lost[0], pos_lost[1]);
   }

   // Retorna o número de peças a serem devolvidas
   return return_pieces;

}