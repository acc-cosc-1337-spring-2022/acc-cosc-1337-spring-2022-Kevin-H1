#include "tic_tac_toe.h"
#include "string"

using std::cout; using std::cin; using std::string;

int main() 
{	
	TicTacToe game;
	string first_player;
	char choice;
	bool validation;

	do
	{
		validation = true;
		//Input validation
		cout<<"Enter first player or (X or O)\n";
		cin>>first_player;
		while(validation)
		{
			if(first_player == "X")
			{
				validation = false;
				break;
			}
			else if(first_player == "O")
			{
				validation = false;
				break;
			}
			else
			{
				cout<<"Please input an 'X' or 'O'\n";
				cin>>first_player;
			}
		}
		game.start_game(first_player);

		//Game menu
		int position;
		while(game.game_over() == false)
		{
			cout<<"Enter position [1-9]";
			cin>>position;
			game.mark_board(position);
			game.display_board();
		}

		//Display winner
		cout<<"The winner is: "<<game.get_winner()<<"\n";

		cout<<"Continue type Y: ";
		cin>>choice;

	}while(choice == 'Y' || choice == 'y');


	return 0;
}