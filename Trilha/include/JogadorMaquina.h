#ifndef JOGADORMAQUINA_H
#define JOGADORMAQUINA_H

#include "Jogador.h" 

// Herda publicamente da classe abstrata jogador
class JogadorMaquina : public Jogador{  
	public:
      // Por padrão o nome é maquina
		JogadorMaquina();		

		// Faz a jogada correspondente ao tipo de jogador e a fase do jogo
		virtual bool jogada(Tabuleiro &tab, int fase, int &lost_pieces, Pilha& pilha, int &rodada, int &recovery_pieces) override;

};

#endif