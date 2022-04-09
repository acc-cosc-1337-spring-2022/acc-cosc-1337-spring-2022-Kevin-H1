#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "string"

using std::cout; using std::cin; using std::string;

int main() 
{	
	TicTacToeManager gameManager;
	TicTacToe game;
	string first_player;
	char choice;
	bool validation;
	int o,w,t;

	do
	{	
		o = 0;
		w = 0;
		t = 0;
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
		while(game.game_over() == false)
		{
			//Will ask for position
			cin>>game;
			//will display board
			cout<<game;
		}

		//Display winner
		cout<<"The winner is: "<<game.get_winner()<<"\n";
		//Add game to tictactoe manager vector
		gameManager.save_game(game);

		//display winners
		gameManager.get_winner_total(o,w,t);
		cout<<"Continue type Y: ";
		cin>>choice;
		

	}while(choice == 'Y' || choice == 'y');


	cout<<gameManager;

	gameManager.get_winner_total(o,w,t);
	return 0;
}