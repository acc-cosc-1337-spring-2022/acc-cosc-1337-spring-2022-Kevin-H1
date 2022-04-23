#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include"tic_tac_toe_data.h"
#include "string"

using std::cout; using std::cin; using std::string; using std::unique_ptr; using std::make_unique;

int main() 
{	
	TicTacToeData data;
	TicTacToeManager gameManager(data);
	unique_ptr<TicTacToe> game;
	string first_player;
	char choice;
	bool validation;
	bool game_validation;
	int o,w,t;


	do
	{	
		int game_ver;
		o = 0;
		w = 0;
		t = 0;
		validation = true;
		game_validation = true;
		//Game Select

		cout<<"Would you like to play 3x3 or 4x4 Tictactoe?: \n";
		cout<<"(Enter 3 or 4)\n";
		cin>>game_ver;
		while(game_validation)
		{
			if(game_ver == 3)
			{
				game = make_unique<TicTacToe3>();
				game_validation = false;
				break;
			}
			else if(game_ver == 4)
			{
				game = make_unique<TicTacToe4>();
				game_validation = false;
				break;
			}
			else
			{
				cout<<"Please enter a valid input (3 or 4):\n ";
				cin>>game_ver;
			}
		}



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
		game->start_game(first_player);


		//Game menu
		while(game->game_over() == false)
		{
			//Will ask for position
			cin>>*game;
			//will display board
			cout<<*game;
		}

		//Display winner
		cout<<"The winner is: "<<game->get_winner()<<"\n";
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