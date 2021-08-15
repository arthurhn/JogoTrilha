#include "Jogo.h"
#include <iostream>
#include <string>
#include<ios>
#include<limits>
#include <iomanip> 

int Jogo::getPhase(){
	return fase;
}

void Jogo::setPhase(int phase){
	fase = phase;
}

void Jogo::printRegras(Tabuleiro &tab){
	using namespace std;

	printf("\033c");     //limpa o terminal


	cout << "                                                                Regras\n"
		 << "1.O Tabuleiro: \n"
		 << "O tabuleiro foi dividido em linhas e colunas como uma matriz, porem sem todas as linhas alinhadas, ou seja, ele esta disposto assim: \n"
		 << endl;

	tab.showTabuleiro();

	cout << "Linhas estao numeradas de 0 a 7 e colunas de 0 a 2 \n"
		 << endl;


	cout << "2. Iniciando o jogo: \n"
		 << "Ao iniciar o jogo, o usuario sera capaz de inserir seu nome (no caso de 2 jogadores, o player 1 inserira primeiro e, em seguida, o player 2). \n";

	cout << endl << endl;

	cout << "3. Objetivos e como jogar: \n";
	cout << "O jogo consiste em fazer trilhas (ou moinhos) verticais ou horizontais ao alinhar 3 pecas no campo, a cada moinho formado por um jogador,"
		 << " o outro tem o direito de retirar do campo uma peca do adversario (**contanto que esta nao esteja em um moinho**). O objetivo e impedir o adversario de fazer trilhas, deixando-o "
		 << "com somente 2 pecas ou trava-lo, sem que ele possa realizar movimentos \n";


	cout << "O jogo se divide em 3 fases: a) posicionamento, b) movimentacao limitada e  c) movimentacao livre \n"
		 << endl;

	cout << "3.a)Posicionamento: \n"
		<< "Nesta fase, os jogadores posicionam alternadamente suas pecas, durante ela ja e possivel formar moinhos, entao muito cuidado! \n"
		<< "O posicionamento se faz inserindo os dados de posicao em x (de 0 a 7) e em y (de 0 a 2) da peca \n"
		<< endl
		<< "3.b)Movimentacao limitada: \n"
		<< "Durante esta fase, o jogador deve escolher uma peca sua para mover nas 4 direcoes: cima, baixo, esquerda ou direita, caso haja " 
		<< "espacos vazios adjacentes (determinados por zero). \n"
		<< "Para escolher a peca, o jogador deve determinar as coordenadas x e y **presentes** da peca que deseja mover, caso sejam validas, ele entao deve"
		<< " inserir as coordenadas x e y **para** as quais deseja move-la. \n"
		<< endl
		<< "3.c)Movimentacao livre: \n"
		<< "Esta e a ultima fase, ela comeca no momento em que um dos jogadores tem somente 3 pecas sobrando."
		<< "Aquele que tiver 3 pecas, entao, ganha o poder de mover-se para qualquer ponto vazio do campo, adjacente ou nao."
		<< "Caso ambos os jogadores estejam em movimentacao livre, isto e, com 3 pecas, eles terao 10 turnos para formar um moinho e retirar"
		<< " uma peca do adversario. Se nenhum dos dois for capaz de fazer isso, o jogo acaba em empate. \n"
		<< endl;

		cout << "4.Fim de jogo: \n"
			<< "Se um dos jogadores possui 2 pecas, logo nao pode formar moinhos, ele perde e o adversario e declarado vencedor. \n"
			<< "Ou caso ele nao tenha movimentos disponiveis, isto e, o adversario o travou no campo, o primeiro jogador tambem perdeu, o vencedor e o adversario.\n"
			<< endl
			<< endl
			<< endl;

		int x;
		// Já sai um valor interiro válida na faixa de valores passada
		validaInput(x, "Aperte 1 para continuar: ", 1);
		mainMenu();
}

void Jogo::printMenu(){
	using namespace std;
	//printf("\033c");     //limpa o terminal


	cout << AZUL << "   =============================" << VERMELHO << "=============================\n";

	cout << AMARELO << "      ________  ______    ___  ___    ___   ___  ________" << endl
			<< "      |       | | | \\ \\   | |  | |    | |   | | |  ___  |" << endl
			<< "         | |    | |__| |  | |  | |    | |___| | | |___| |" << endl
			<< "         | |    |  ____|  | |  | |    | |___| | | |___| |" << endl
			<< "         | |    | |  \\ \\  | |  | |__  | |   | | | |   | |" << endl
			<< "         |_|    |_|   \\_\\ |_|  |____| |_|   |_| |_|   |_|" << endl << endl;
	
	cout << VERMELHO << "   =============================" << AZUL << "=============================\n\n";
	

	cout << AMARELO << "                  Pressione 1 para 1 jogador" << endl
        << "                 Pressione 2 para 2 jogadores" << endl
        << "                    Pressione 0 para Regras" << endl;

}

void Jogo::mainMenu(){
	printMenu();
	
	Jogador *jogadores[2];
	int x;
	std::string nome1, nome2;
	
	validaInput(x, "Sua entrada: ", 2);

	switch(x){
		case 1:{
			std::cout << "Jogador 1, insira seu nome\n";
			std::cin >> std::setw(50) >> nome1;

			JogadorHumano j1_(1, nome1);

			JogadorMaquina cpu_;

			jogadores[0] = &j1_;
			jogadores[1] = &cpu_;

			Tabuleiro tab_;

			Setup_phase(tab_, jogadores);
			break;
		}	

		case 2:{
			std::cout << "Jogador 1, insira seu nome\n";
			std::cin >> std::setw(50) >> nome1;
			JogadorHumano j1_(1, nome1);
			//chamada de construtor de 2 jogadores
			std::cout << "Jogador 2, insira seu nome\n";
			std::cin >> std::setw(50) >> nome2;
			JogadorHumano j2_(2, nome2);

			jogadores[0] = &j1_;
			jogadores[1] = &j2_;

			Tabuleiro tab_;

			Setup_phase(tab_, jogadores);
			break;
			}

		case 0:{
			Tabuleiro tab;
			printRegras(tab);
			tab.~Tabuleiro();
			break;
		}

		default:{
			std::cout << "Insira um numero valido \n"
					  << std::endl;

			int y;
			validaInput(y, "Aperte 1 para voltar ao menu: ", 1);
			mainMenu();

			break;
		}

	}
}

void Jogo::Setup_phase(Tabuleiro &tab, Jogador** jogadores){		
	Pilha pilha;
	int enemy_pieces = 0;
	int recovery_pieces = 0;
	setPhase(1);

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');	// limpa o  buffer

	// Itera sobre o número de jogada na Setup_phase
	for(int i = 0; i < 18; i++){
		
		tab.showTabuleiro(jogadores[0]->getPiece(), jogadores[1]->getPiece());

		// Faz a jogada
		jogadores[i % 2]->jogada(tab, getPhase(), enemy_pieces, pilha, i, recovery_pieces);

		if(enemy_pieces != 0){
			// Tira as peças do jogador inimigo
			jogadores[(i + 1) % 2]->decreasePiece(enemy_pieces);	
		}

		if(recovery_pieces != 0){
			// Incrementar peças do jogador inimigo
			jogadores[(i + 1) % 2]->increasePieces(recovery_pieces);	
			recovery_pieces = 0;
		}
		
	}
	
	// Destroi a pilha
	pilha.~Pilha();
	Movement_phase(tab, jogadores);
}

void Jogo::Movement_phase(Tabuleiro &tab, Jogador** jogadores){
	Pilha pilha;
	int rp = 0;
	int i = 0;					// Iterador do vetor de jogadores
	int cont = 20;				// Para contar 10 jogadas na fase 3
	int enemy_pieces = 0;


	while((jogadores[0]->getPiece() >= 3) and (jogadores[1]->getPiece() >= 3)){		//jogo acontece enquanto 3 pecas ou mais de cada jogador estiverem no campo
		tab.showTabuleiro(jogadores[0]->getPiece(), jogadores[1]->getPiece());
		// Confere se tá na fase 2 ou 3

		// Jogador está na fase 3 (atingiu três peças na movement fase)
		if(jogadores[i%2]->getPiece() == 3){

			// Está na fase 3				
			setPhase(3);		

			if(jogadores[(i + 1) % 2]->getPiece() == 3) cont--;

		// Jogador está na fase 2 (ainda não atingiu três peças na movement fase)
		}else{

			// Está na fase 2
			setPhase(2);		
		}
		
		// Comportamento padrao

		// Faz a jogada
		jogadores[i%2]->jogada(tab, getPhase(), enemy_pieces, pilha, i, rp);

		// Decremetar as peças do inimigo
		if(enemy_pieces != 0){
			// Tira as peças do jogador inimigo
			jogadores[(i + 1)%2]->decreasePiece(enemy_pieces);	
		}
		
		// Verifica se deu empate
		if(cont == 0){
			GameEnd();
			break;
		}
		
		i++;

	}//while

	// Destroi a pilha
	pilha.~Pilha();
	GameEnd(jogadores);
}

void Jogo::GameEnd(Jogador** jogadores){
	
	if(jogadores[0]->getPiece()==2){
		std::cout << jogadores[1]->getName() << " ganhou! \n";
	
	}else if(jogadores[1]->getPiece()==2){
		std::cout << jogadores[0]->getName() << " ganhou! \n";
	
	}

	int y;
	validaInput(y, "Aperte 1 para voltar ao menu: ", 1);
	mainMenu();
}

void Jogo::GameEnd(){
	std::cout << "Empate! \n";

	int y;
	validaInput(y, "Aperte 1 para voltar ao menu: ", 1);
	mainMenu();
}

void Jogo::GameEnd(int player, std::string player1_name, std::string player2_name){
	if(player == 1)
		std::cout << player1_name << "nao tem mais movimentos, j2 ganhou \n";
	else	
		std::cout << player2_name << "nao tem mais movimentos, j1 ganhou \n";

	int y;
	validaInput(y, "Aperte 1 para voltar ao menu: ", 1);
	mainMenu();
}

void Jogo::validaInteger(int& in, std::string out){
	
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


void Jogo::validaInput(int& in, std::string out, int val_max){

	validaInteger(in, out);

	while(in < 0 || in > val_max){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		validaInteger(in, out);
	}

}