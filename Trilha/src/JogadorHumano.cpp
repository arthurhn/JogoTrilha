#include "JogadorHumano.h"
#include <iostream>

JogadorHumano::JogadorHumano(int identi, const std::string &nome) : Jogador(identi, nome){}

bool JogadorHumano::jogada(Tabuleiro &tab, int fase, int &lost_pieces, Pilha &pilha, int &rodada, int &recovery_pieces) {

   if (fase == 1){   // Setup fase
      int x, y;               // variáveis de movimentação
      int v, rp;              // variáveis da pilha
      int x_enemy, y_enemy;

      // Checa se tá na rodada inicial na qual não pode voltar jogada
      if(rodada != 0){
         // Perguntar ao player se ele quer voltar a jogada
         tab.validaValor(v, "Entre -1 para voltar a jogada e qualquer outro valor para continuar: ", -1);
         if(v == -1){  

            // Reconstrói o tabuleiro
            for(int j = 0; j < 2; j++){
               rp = tab.voltaJogada(pilha, getId()); 
               if(j == 0 && rp != 0){
                  // Volta uma peça ao jogador
                  increasePieces(rp);
                  rp = 0;
               }
               // Setar a váriavel de incremento de peças do adversário
               recovery_pieces = rp;
            }

            // Volta para a rodada anterior do player (volta dois turnos)
            rodada = rodada - 2;
            tab.showTabuleiro();
         }
      }
      

      std::cout << getName();
      tab.validaInput(x, ", insira a coordenada x que voce quer posicionar a peca: ", 7);

      std::cout << getName();
      tab.validaInput(y, ", insira a coordenada y que voce quer posicionar a peca: ", 2);
      
      while(tab.IsPlaced(x,y) == true){
         std::cout << "Posicao invalida \n";
         std::cout << getName();
         tab.validaInput(x, ", insira a coordenada x que voce quer posicionar a peca: ", 7);

         std::cout << getName();
         tab.validaInput(y, ", insira a coordenada y que voce quer posicionar a peca: ", 2);
      }
      
      int xlost, ylost;

      tab.setPosicao(getId(), x, y);

      lost_pieces = tab.removeEnemyPieces(getId(), xlost, ylost);

      // Armazena a jogada
      Jogada move(getId(), x, y, lost_pieces, xlost, ylost);
      pilha.push(move);
   }
   
   if (fase == 2){   // Movement Fase - Posicinamento limitado
      bool checkX, checkY;
      int x_old, y_old, x_new, y_new;

      std::vector<int> positions(0);
      tab.findPiecesIA(positions, getId());

      // Jogador completamente bloqueado
      if (positions.size() == 0){   
         return false;
      }

      std::cout << getName();
      tab.validaInput(x_old, ", insira a coordenada x de uma peca que voce deseja mover: ", 7);

      std::cout << getName();
      tab.validaInput(y_old, ", insira a coordenada y de uma peca que voce deseja mover: ", 2);
      
      while(!tab.checkPiece( x_old, y_old, getId() ) ){
         std::cout << "Posicao invalida \n";

         std::cout << getName();
         tab.validaInput(x_old, ", insira a coordenada x de uma peca que voce deseja mover: ", 7);

         std::cout << getName();
         tab.validaInput(y_old, ", insira a coordenada y de uma peca que voce deseja mover: ", 2);
      }


      std::cout << getName();
      tab.validaInput(x_new, ", agora insira a coordenada x para a qual voce quer mover a peca: ", 7);

      std::cout << getName();
      tab.validaInput(y_new, ", agora insira a coordenada y para a qual voce quer mover a peca: ", 2);

      // Checa se a posição y é válida (Movimentação lateral)
      checkY = tab.checkMoveY(x_old, y_old, x_new, y_new, getId());

      // Checa se a posição x é válida (Movimentação vertical)   
      checkX = tab.checkMoveX(x_old, y_old, x_new, y_new, getId());

      while ( !(checkY && checkX) ){   // Executa até inserir uma posição válida 

         std::cout << "Posição inválida inserida. Insira outro valor x y: ";
         
         std::cout << getName();
         tab.validaInput(x_new, ", agora insira a coordenada x para a qual voce quer mover a peca: ", 7);

         std::cout << getName();
         tab.validaInput(y_new, ", agora insira a coordenada y para a qual voce quer mover a peca: ", 2);

         // Checa se a posição y é válida (Movimentação lateral)
         checkY = tab.checkMoveY(x_old, y_old, x_new, y_new, getId());

         // Checa se a posição x é válida (Movimentação vertical)   
         checkX = tab.checkMoveX(x_old, y_old, x_new, y_new, getId());

      } 

      tab.setPosicao(getId(), x_new, y_new);

      lost_pieces = tab.removeEnemyPieces(getId());

   }
   
   if (fase == 3){   // Movement Fase - Posicinamento ilimitado (jogador atingiu 3 peças) 
      int x_old, y_old, x_new, y_new;

      std::cout << getName();
      tab.validaInput(x_old, ", insira a coordenada x de uma peca que voce deseja mover: ", 7);

      std::cout << getName();
      tab.validaInput(y_old, ", insira a coordenada y de uma peca que voce deseja mover: ", 2);
      
      // Checa se inseriu uma posição válida e já apaga a peça antiga
      while(!tab.checkPiece( x_old, y_old, getId() ) ){
         std::cout << "Posicao invalida \n";

         std::cout << getName();
         tab.validaInput(x_old, ", insira a coordenada x de uma peca que voce deseja mover: ", 7);

         std::cout << getName();
         tab.validaInput(y_old, ", insira a coordenada y de uma peca que voce deseja mover: ", 2);
      }

      std::cout << getName();
      tab.validaInput(x_new, ", agora insira a coordenada x para a qual voce quer mover a peca: ", 7);

      std::cout << getName();
      tab.validaInput(y_new, ", agora insira a coordenada y para a qual voce quer mover a peca: ", 2);
      
      while(tab.IsPlaced(x_new,y_new) == true){
         std::cout << "Posicao invalida \n";

         std::cout << getName();
         tab.validaInput(x_new, ", agora insira a coordenada x para a qual voce quer mover a peca: ", 7);

         std::cout << getName();
         tab.validaInput(y_new, ", agora insira a coordenada y para a qual voce quer mover a peca: ", 2);
      }

      tab.setPosicao(getId(), x_new, y_new);

      lost_pieces = tab.removeEnemyPieces(getId());
      
   }

   return true;
}


