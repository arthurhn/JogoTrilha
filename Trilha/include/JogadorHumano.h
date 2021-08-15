#ifndef JOGADORHUMANO_H
#define JOGADORHUMANO_H

#include "Jogador.h" 

// Herda publicamente da classe abstrata jogador
class JogadorHumano : public Jogador{  
	public:
		JogadorHumano(int identi, const std::string &nome);		

		// Faz a jogada correspondente ao tipo de jogador e a fase do jogo
		virtual bool jogada(Tabuleiro &tab, int fase, int &lost_pieces, Pilha &pilha, int &rodada, int &recovery_pieces) override;
		
};

#endif