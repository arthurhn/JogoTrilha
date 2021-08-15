#include "JogadorMaquina.h"

JogadorMaquina::JogadorMaquina() : Jogador(2, "CPU"){

}
// TODO Checar a condição do jogador está complementamente bloqueado
bool JogadorMaquina::jogada(Tabuleiro &tab, int fase, int &lost_pieces, Pilha &pilha, int &rodada, int &recovery_pieces){
   
   // Setup fase
   if(fase == 1){   
      static int check = 0;                        // Variável para armazenar a primeira jogada randõmica

      std::vector<int> positions(0);        // Vetor com posições x y
      std::vector<int> positions_free(0);   // Vetor com posições x y
      std::vector<int> pos_chosed(2);       // Vetor com posições x y escolhidas
      std::vector<int> pos_chosed_free(2);  // Vetor com posições x y escolhidas
      std::vector<int> pos_random(2);       // Vetor com a posição aleatória escolhida

      // Achar as posições escolhidas que não estão bloqueadas e retorna no vetor positions
      tab.findPiecesIA(positions, getId());  

      // Já foi feito pelo menos um posicionamento ou tem pelo menos uma posição não bloqueada
      if(positions.size() != 0){ 
         // Movimentação inteligente junto com aleatória -> coloca um posição junto com outra 

         // Escolhe uma posição aleatória das possíveis e retorna no vetor pos_chosed
         tab.chosePosAleatoria(positions, pos_chosed); 
         std::cout << pos_chosed[0] << std::endl; 
         std::cout << pos_chosed[1] << std::endl;   

         // Encontra os posicionamentos livres em volta da posição e retorna no vetor positions_free
         tab.posFreeAround(pos_chosed[0], pos_chosed[1], positions_free);  

         // Escolhe aleatoriamento um posicionamento livre e retorna no vetor pos_chosed_free
         tab.chosePosAleatoria(positions_free, pos_chosed_free);  

         // Faz a jogada
         tab.setPosicao(2, pos_chosed_free[0], pos_chosed_free[1]);

      // Movimentação aleatória -> Coloca um posição aleatoriamente no tabuleiro
      }else{

         // Escolhe uma posição aleatoriamente e retorna no vetor pos_random   
         tab.posAleatorio(pos_random);
         tab.setPosicao(2, pos_random[0], pos_random[1]);
         
      }

      // Checa o tabuleiro após a jogada 
      lost_pieces = tab.checaTabuleiro(getId());
      std::cout << lost_pieces << std::endl;
      
      int xlost, ylost;

      // Se houve um moinho formado
      if(lost_pieces != 0){
         for(int i = 0; i < lost_pieces; i++){
            // Remove um posição aleatória do player passado
            tab.removeIA(xlost, ylost);

            // Esvazia os moinhos desfeitos 
            tab.esvaziaMoinhos();
         }
      }

      // Armazena a jogada
      if(check == 0){
         Jogada move(getId(), pos_random[0], pos_random[1], lost_pieces, xlost, ylost);
         pilha.push(move);
         check ++;
      }else{
         Jogada move(getId(), pos_chosed_free[0], pos_chosed_free[1], lost_pieces);
         pilha.push(move);
      }

   }
   
   // Movement Fase - Posicinamento limitado
   if(fase == 2){ 
      std::vector<int> positions(0);        // Vetor com posiçõs x y
      std::vector<int> positions_free(0);   // Vetor com posiçõs x y
      std::vector<int> pos_chosed(2);       // Vetor com posiçõs x y escolhidas
      std::vector<int> pos_chosed_free(2);  // Vetor com posiçõs x y escolhidas

      // Achar as posições escolhidas que não estão bloqueadas
      tab.findPiecesIA(positions, getId()); 

      // Tem pelo menos uma posição não bloqueada
      if(positions.size() != 0){ 
         // Movimentação inteligente junto com aleatória -> coloca um posição junto com outra 

         // Escolhe uma posição aleatória das possíveis
         tab.chosePosAleatoria(positions, pos_chosed);   

         // Encontra os posicionamentos livres em volta da posição escolhida
         tab.posFreeAround(pos_chosed[0], pos_chosed[1], positions_free);  

         // Escolhe aleatoriamento um posicionamento livre
         tab.chosePosAleatoria(positions_free, pos_chosed_free);  
         
         // Faz a jogada
         tab.setPosicao(0, pos_chosed[0], pos_chosed[1]);
         tab.setPosicao(2, pos_chosed_free[0], pos_chosed_free[1]);

      // Movimentação aleatória -> Faz uma jogada aleatoriamente no tabuleiro 
      }else{   // Não existem jogadas possíveis
         std::cout << "Completamente bloqueado" << std::endl;
         return false;  
      }

      // Checa o tabuleiro após a jogada 
      lost_pieces = tab.checaTabuleiro(getId());

      // Se houve um moinho formado
      if(lost_pieces != 0){
         for(int i = 0; i < lost_pieces; i++){
            // Remove um posição aleatória do player passado
            tab.removeIA();

            // Esvazia os moinhos desfeitos 
            tab.esvaziaMoinhos();
         }
      }

   
   }
   
   // Movement Fase - Posicinamento ilimitado (jogador atingiu 3 peças) 
   if(fase == 3){  
      std::vector<int> positions(0);        // Vetor com posições x y
      std::vector<int> positions_free(0);   // Vetor com posições x y
      std::vector<int> pos_chosed(2);       // Vetor com posições x y escolhidas
      std::vector<int> pos_chosed_free(2);  // Vetor com posições x y escolhidas
      std::vector<int> pos_random(2);       // Vetor com a posição aleatória escolhida

      // Achar as posições escolhidas que não estão bloqueadas
      tab.findPiecesIA(positions, getId()); 
   
      // Escolhe uma posição aleatória das possíveis
      tab.chosePosAleatoria(positions, pos_chosed);

      // Encontra os posicionamentos livres em volta da posição escolhida
      tab.posFreeAround(pos_chosed[0], pos_chosed[1], positions_free); 

      // Escolhe uma posição aleatoriamente e retorna no vetor pos_random 
      tab.posAleatorio(pos_random);

      // Faz a jogada
      tab.setPosicao(0, pos_chosed[0], pos_chosed[1]);
      tab.setPosicao(2, pos_random[0], pos_random[1]);

      // Checa o tabuleiro após a jogada 
      lost_pieces = tab.checaTabuleiro(getId());

      // Se houve um moinho formado
      if(lost_pieces != 0){
         for(int i = 0; i < lost_pieces; i++){
            // Remove um posição aleatória do player passado
            tab.removeIA();

            // Esvazia os moinhos desfeitos 
            tab.esvaziaMoinhos();
         }
      }

   }   

   return true;   
}