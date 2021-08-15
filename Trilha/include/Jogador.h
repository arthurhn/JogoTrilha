#ifndef JOGADOR_H
#define JOGADOR_H
#include "tabuleiro.h"
#include <string>
#include <vector>
#include <iostream>

class Jogador{
	public:
		Jogador(int identi, const std::string &nome);
				

		// Configura o nome do jogador
		void setName(const std::string &nome);		

		// Retorna o nome do jogador			
		std::string getName() const;						

		// Tira o número de peças passado do jogador 
		void decreasePiece(int pieces);

		// Retorna o número de peças
		int getPiece() const; 						

		// Retorna o Id do jogador (player 1 ou 2)
		int getId() const;

		// Faz a jogada correspondente ao tipo de jogador e a fase do jogo (retorna false caso todas as posições estejam bloqueadas)
		virtual bool jogada(Tabuleiro &tab, int fase, int &lost_pieces, Pilha &pilha, int &rodada, int &recovery_pieces) = 0;

		// Imprime os dados do jogador
		void printJogador() const;

		// Imprime os dados do jogador
		void printName() const;

		// Incrementar peças para o jogador
		void increasePieces(int recovery_pieces);


	private:
		std::string name;				// Nome do jogador 
		int id;						// Player 1 ou 2
		int pieces;					// Número de peças 
		

};


#endif