#include "tic_tac_toe.h"
#include "string"

using std::cout; using std::cin; using std::string;

int main() 
{	
	TicTacToe game;
	string first_player;
	char choice;



	do
	{



		cout<<"Enter first player or (X or O)\n";
		cin>>first_player;
		game.start_game(first_player);

		int position;
		while(game.game_over() == false)
		{
			cout<<"Enter position [1-9]";
			cin>>position;
			game.mark_board(position);
			game.display_board();
		}


		cout<<"Continue type Y: ";
		cin>>choice;


	}while(choice == 'Y' || choice == 'y');


	return 0;
}