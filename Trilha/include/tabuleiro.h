#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "Moinho.h"
#include "Pilha.h"

#include <vector>
#include <string>


class Tabuleiro{

   private:
      Moinho Moinho_p1[4], Moinho_p2[4];
      // std::array< std::array<int, 3>, 8> tabuleiro = {}; -> melhor implememtação do tabuleiro
      int tabuleiro[8][3] = {
      {0, 0, 0}, 
      {0, 0, 0}, 
      {0, 0, 0}, 
      {0, 0, 0},      
      {0, 0, 0}, 
      {0, 0, 0}, 
      {0, 0, 0}, 
      {0, 0, 0}};

      // Funções auxiliares

      // Encontra moinho Horizontal
      int findMoinhoH(int player); 

      // Encontra moinho Vertical                      
      int findMoinhoV(int player);    

      // Retorna uma posição vazia pra colocar o novo moinho                   
      int posVaziaMoinho(int player);  

      // Retorna true caso o monhos já exista                   
      bool moinhoExiste(int i, int j);   

      // Inicializa o moinho encontrado                
      void initMoinho(int i, int j, int player, int d); 

      // Retorna true se o moinho passado ainda existe 
      bool existeMoinho(int i, int j, int d, int player);

      // Configura o moinho da posição passada como vazio 
      void limpaMoinho(int pos, int player); 

      // Encontra moinhos novos e os inicializa e retorna o numero de moinhos novos do player passado
      int findMoinho(int player);

      // Retorna true caso o moinho do player passado esteja vazio                  
      bool isVazio(int pos, int player); 
      

      // Checa se a posição está bloqueada para movimentação ou posicionamento complementar na horizontal (retorna true caso seja)
      bool posBlockedH(int i, int j);

      // Checa se a posição está bloqueada para movimentação ou posicionamento complementar na horizontal (retorna true caso seja)
      bool posBlockedV(int i, int j);

      // Inicializa o vetor com as posição livre a volta da posição passada na vertical
      void posFreeAroundV(int i, int j, std::vector< int > &positions_free);

      // Inicializa o vetor com as posição livre a volta da posição passada na horizontal
      void posFreeAroundH(int i, int j, std::vector< int > &positions_free);

      //Cor vermelha para imprimir no terminal
      const std::string VERMELHO = "\033[1;31;1m";

      //Cor azul para imprimir no terminal
      const std::string AZUL = "\033[1;34;1m";

      //Cor amarela para imprimir no terminal
      const std::string AMARELO = "\033[1;33;1m";

   public:
      Tabuleiro();
      ~Tabuleiro();

      // Printa Tabuleiro com a informação da quant. de peça dos players
      void showTabuleiro(int pieces1, int pieces2);

      // Printa Tabuleiro com a informação da quant. de peça dos players
      void showTabuleiro();     

      // Coloca uma posição na matriz                           
      bool setPosicao(int jogada, int i, int j); 

      // Retorna o que há em determinada posição da matriz      
      int getPosicao(int i, int j); 

      // Retorna true caso haja um posicionamento na posição passada                   
      bool IsPlaced(int i, int j);    

      // Imprime os dados dos moinhos                      
      void showMoinhos();   

      // Checa tabuleiro criando moinhos novos e os destruindo para o player passado. Retorna o numero de moinhos novos
      int checaTabuleiro(int player); 

      // Move a peça de uma posição para outra sem limitação na setupFase 
      void movePieceIlimitada(int x, int y, int player);

      // Faz um posicionameto aleatório (inicializa o vetor pos_random com a posição)
      void posAleatorio(std::vector<int> &pos_random);

      // Procurar as posições no tabuleiro e as retorna dentro do vetor
      void findPiecesIA(std::vector< int > &vetor, int player);

      // Escolhe uma posição aleatória das passadas 
      void chosePosAleatoria(std::vector< int > &positions, std::vector< int > &pos_chosed);

      // Checa se a posição está bloqueada para movimentação ou posicionamento complementar (retorna true caso seja)
      bool posBlocked(int i, int j);

      // Inicializa o vetor com as posição livre a volta da posição passada
      void posFreeAround(int i, int j, std::vector< int > &positions_free); 

      // Tira peças do adversários correspodente ao número de moinhos formados e a posição passada (Retorna o número de moinhos formados do player passado)
      int removeEnemyPieces(int player, int &xl, int &yl); 

       // Tira peças do adversários correspodente ao número de moinhos formados e a posição passada (Retorna o número de moinhos formados do player passado)
      int removeEnemyPieces(int player); 

      // Valida a entrada só para inteiros 
      void validaInteger(int& in, std::string out);

	   // Valida a entrada só para posiçõs no tabuleiro
      void validaInput(int& in, std::string out, int valor_max); 

      // Valida a entrada para voltar uma jogada
      void validaValor(int& in, std::string out, int valor);

      // Remove uma peça aleatoriamente do inimigo
      void removeIA();

      // Remove uma peça aleatoriamente do inimigo
      void removeIA(int &xl, int &yl);

      // Esvazia os moinhos que não existem mais para os players. Retorna o número de moinhos esvaziados dos dois players
      int esvaziaMoinhos(); 

      // Checa se o player escolheu a peça correta para fazer o posicionamento e a apaga (retorna true para posicionamento correto)
      bool checkPiece(int x, int y, int player);

      // Checa se a movimentação horizontal limitada é válida (Retorna true caso seja) 
      bool checkMoveY(int x_old, int y_old, int x_new, int y_new, int player);

      // Checa se a movimentação vertical limitada é válida (Retorna true caso seja)
      bool checkMoveX(int x_old, int y_old, int x_new, int y_new, int player);

      // Reconstroi o tabuleiro e retorna o número de peças perdidas do jogador
      int voltaJogada(Pilha &pilha, int player);

};


#endif 