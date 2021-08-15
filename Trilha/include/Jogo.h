#ifndef JOGO_H
#define JOGO_H

#include "tabuleiro.h"
#include "JogadorHumano.h"
#include "JogadorMaquina.h"
#include "Jogador.h" 
#include "Pilha.h"

class Jogo{
	private:
		int fase;	// Indica em qual o fase o jogo está 

		//Cor vermelha para imprimir no terminal
      	const std::string VERMELHO = "\033[1;31;1m";
		
		//Cor azul para imprimir no terminal
		const std::string AZUL = "\033[1;34;1m";

		//Cor amarela para imprimir no terminal
		const std::string AMARELO = "\033[1;33;1m";
	public:

		//Retorna o valor da fase
		int getPhase();

		//Muda o valor da fase
		void setPhase(int phase);

		//Imprime as regras
		void printRegras(Tabuleiro &tab);

		//Imprime o menu
		void printMenu();

		// Apresenta o menu
		void mainMenu();

		// Fase 1 - Corresponde a fase de posicionamento das peças
		void Setup_phase(Tabuleiro &tab, Jogador** jogadores);	

		// Fase 2 - Corresponde a fase de posicionamento limitado das peças
		void Movement_phase(Tabuleiro &tab, Jogador** jogadores);	

		// Fim do Jogo 
		void GameEnd(Jogador** jogadores);

		// Sobrecarga para empate
		void GameEnd();

		// Sobrecarga para movimentos travados
		void GameEnd(int player, std::string player1_name, std::string player2_name);

		// Valida a entrada só para inteiros 
      void validaInteger(int& in, std::string out);

		// Valida a entrada só para posiçõs no tabuleiro
      void validaInput(int& in, std::string out, int valor_max); 
};



#endif