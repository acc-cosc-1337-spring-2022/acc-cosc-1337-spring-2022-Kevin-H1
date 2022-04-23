#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"


/* 
-------------------There are a lot of assesments that do not show up in the terminal--------------
----------------------------because there are too many test cases-------------------------------


*/


using std::unique_ptr; using std::make_unique; using std::cout;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}



//Tie
TEST_CASE("Test tic tac toe game over for a tie")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();

	game->start_game("X"); 

	game->mark_board(1);
	REQUIRE(false == game->game_over());

	game->mark_board(2);
	REQUIRE(false == game->game_over());

	game->mark_board(4);
	REQUIRE(false == game->game_over());

	game->mark_board(7);
	REQUIRE(false == game->game_over());

	game->mark_board(5);
	REQUIRE(false == game->game_over());

	game->mark_board(6);
	REQUIRE(false == game->game_over());

	game->mark_board(3);
	REQUIRE(false == game->game_over());

	game->mark_board(8);
	REQUIRE(false == game->game_over());

	game->mark_board(9);
	REQUIRE(true == game->game_over());

	REQUIRE("C" == game->get_winner());
}

TEST_CASE("Test first player set to X")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	REQUIRE("X" == game->get_player());
}

TEST_CASE("Test first player set to O")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("O");

	REQUIRE("O" == game->get_player());
}


//CHECK COLUMNS

TEST_CASE("Test check first column win")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(1);
	REQUIRE(false == game->game_over());
	game->mark_board(2);
	REQUIRE(false == game->game_over());
	game->mark_board(4);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(7);
	REQUIRE(true == game->game_over());
	
	REQUIRE("X" == game->get_winner());

}

TEST_CASE("Test check second column win")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(2);
	REQUIRE(false == game->game_over());
	game->mark_board(1);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(4);
	REQUIRE(false == game->game_over());
	game->mark_board(8);
	REQUIRE(true == game->game_over());
	
	REQUIRE("X" == game->get_winner());
	

}


TEST_CASE("Test check Third column win")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(3);
	REQUIRE(false == game->game_over());
	game->mark_board(2);
	REQUIRE(false == game->game_over());
	game->mark_board(6);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(9);
	REQUIRE(true == game->game_over());
	
	REQUIRE("X" == game->get_winner());

}


//CHECK ROWS


TEST_CASE("Test first row")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(1);
	REQUIRE(false == game->game_over());
	game->mark_board(4);
	REQUIRE(false == game->game_over());
	game->mark_board(2);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(3);
	REQUIRE(true == game->game_over());
	
	REQUIRE("X" == game->get_winner());
}

TEST_CASE("Test second row")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(4);
	REQUIRE(false == game->game_over());
	game->mark_board(3);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(2);
	REQUIRE(false == game->game_over());
	game->mark_board(6);
	REQUIRE(true == game->game_over());

	REQUIRE("X" == game->get_winner());
}

TEST_CASE("Test third row")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(7);
	REQUIRE(false == game->game_over());
	game->mark_board(4);
	REQUIRE(false == game->game_over());
	game->mark_board(8);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(9);
	REQUIRE(true == game->game_over());

	REQUIRE("X" == game->get_winner());
}

//CHECK DIAGONALLY

TEST_CASE("Test if someone won top left diagonally")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(1);
	REQUIRE(false == game->game_over());
	//O's turn
	game->mark_board(2);
	REQUIRE(false == game->game_over());
	//X's turn
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	//O's turn
	game->mark_board(4);
	REQUIRE(false == game->game_over());
	//x's turn
	game->mark_board(9);
	REQUIRE(game->game_over() == true);

	REQUIRE("X" == game->get_winner());
}

TEST_CASE("Test if someone won bot left diagonally")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");

	game->mark_board(7);
	REQUIRE(false == game->game_over());
	//O's turn
	game->mark_board(2);
	REQUIRE(false == game->game_over());
	//X's turn
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	//O's turn
	game->mark_board(4);
	REQUIRE(false == game->game_over());
	//x's turn
	game->mark_board(3);
	REQUIRE(game->game_over() == true);

	REQUIRE("X" == game->get_winner());
}

TEST_CASE("Test get_winner_total function")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	TicTacToeManager gameManager;

	int o,w,t;

	//X wins
	game->start_game("X");

	game->mark_board(1);
	REQUIRE(false == game->game_over());
	game->mark_board(4);
	REQUIRE(false == game->game_over());
	game->mark_board(2);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(3);
	REQUIRE(true == game->game_over());

	gameManager.save_game(game);

	//O wins
	game->start_game("O");

	game->mark_board(1);
	REQUIRE(false == game->game_over());

	game->mark_board(4);
	REQUIRE(false == game->game_over());

	game->mark_board(2);
	REQUIRE(false == game->game_over());

	game->mark_board(5);
	REQUIRE(false == game->game_over());

	game->mark_board(3);
	REQUIRE(true == game->game_over());

	gameManager.save_game(game);


	//Tie
	game->start_game("X");

	game->mark_board(1);
	REQUIRE(false == game->game_over());

	game->mark_board(2);
	REQUIRE(false == game->game_over());

	game->mark_board(3);
	REQUIRE(false == game->game_over());

	game->mark_board(5);
	REQUIRE(false == game->game_over());

	game->mark_board(4);
	REQUIRE(false == game->game_over());

	game->mark_board(7);
	REQUIRE(false == game->game_over());

	game->mark_board(6);
	REQUIRE(false == game->game_over());

	game->mark_board(9);
	REQUIRE(false == game->game_over());

	game->mark_board(8);
	REQUIRE(true == game->game_over());

	gameManager.save_game(game);


	gameManager.get_winner_total(o,w,t);

	REQUIRE(o == 1);
	REQUIRE(w == 1);
	REQUIRE(t == 1);
}

// Tic Tac Toe 4 Tests

//Tie
TEST_CASE("Test TicTacToe4 tie")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();

	game->start_game("X");
	
	game->mark_board(2);
	REQUIRE(false == game->game_over());
	game->mark_board(1);
	REQUIRE(false == game->game_over());
	game->mark_board(3);
	REQUIRE(false == game->game_over());
	game->mark_board(4);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(6);
	REQUIRE(false == game->game_over());
	game->mark_board(8);
	REQUIRE(false == game->game_over());
	game->mark_board(7);
	REQUIRE(false == game->game_over());
	game->mark_board(10);
	REQUIRE(false == game->game_over());
	game->mark_board(9);
	REQUIRE(false == game->game_over());
	game->mark_board(11);
	REQUIRE(false == game->game_over());
	game->mark_board(12);
	REQUIRE(false == game->game_over());
	game->mark_board(13);
	REQUIRE(false == game->game_over());
	game->mark_board(14);
	REQUIRE(false == game->game_over());
	game->mark_board(16);
	REQUIRE(false == game->game_over());
	game->mark_board(15);
	REQUIRE(true == game->game_over());

	REQUIRE("C" == game->get_winner());
}

TEST_CASE("Test tictactoe4 first player set to X")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	REQUIRE("X" == game->get_player());
}

TEST_CASE("Test tictactoe 4 first player set to O")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("O");

	REQUIRE("O" == game->get_player());
}

//COLUMNS
TEST_CASE("Test tictactoe4 check first column win")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(1);
	REQUIRE(false == game->game_over());
	game->mark_board(2);
	REQUIRE(false == game->game_over());

	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(3);
	REQUIRE(false == game->game_over());

	game->mark_board(9);
	REQUIRE(false == game->game_over());
	game->mark_board(6);
	REQUIRE(false == game->game_over());

	game->mark_board(13);
	REQUIRE(true == game->game_over());
	
	
	REQUIRE("X" == game->get_winner());
}

TEST_CASE("Test tictactoe4 check second column win")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(2);
	REQUIRE(false == game->game_over());
	game->mark_board(1);
	REQUIRE(false == game->game_over());

	game->mark_board(6);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());

	game->mark_board(10);
	REQUIRE(false == game->game_over());
	game->mark_board(9);
	REQUIRE(false == game->game_over());

	game->mark_board(14);
	REQUIRE(true == game->game_over());
	
	
	REQUIRE("X" == game->get_winner());
	
}

TEST_CASE("Test tictactoe4 check third column win")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(3);
	REQUIRE(false == game->game_over());
	game->mark_board(1);
	REQUIRE(false == game->game_over());

	game->mark_board(7);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());

	game->mark_board(11);
	REQUIRE(false == game->game_over());
	game->mark_board(9);
	REQUIRE(false == game->game_over());

	game->mark_board(15);
	REQUIRE(true == game->game_over());
	
	
	REQUIRE("X" == game->get_winner());
	
}

TEST_CASE("Test tictactoe4 check fourth column win")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(4);
	REQUIRE(false == game->game_over());
	game->mark_board(1);
	REQUIRE(false == game->game_over());

	game->mark_board(8);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());

	game->mark_board(12);
	REQUIRE(false == game->game_over());
	game->mark_board(9);
	REQUIRE(false == game->game_over());

	game->mark_board(16);
	REQUIRE(true == game->game_over());
	
	
	REQUIRE("X" == game->get_winner());
	
}

//ROWS
TEST_CASE("Test tictactoe4 first row")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(1);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());

	game->mark_board(2);
	REQUIRE(false == game->game_over());
	game->mark_board(6);
	REQUIRE(false == game->game_over());

	game->mark_board(3);
	REQUIRE(false == game->game_over());
	game->mark_board(7);
	REQUIRE(false == game->game_over());

	game->mark_board(4);
	REQUIRE(true == game->game_over());
	
	
	REQUIRE("X" == game->get_winner());
}

TEST_CASE("Test tictactoe4 second row")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(1);
	REQUIRE(false == game->game_over());

	game->mark_board(6);
	REQUIRE(false == game->game_over());
	game->mark_board(2);
	REQUIRE(false == game->game_over());

	game->mark_board(7);
	REQUIRE(false == game->game_over());
	game->mark_board(3);
	REQUIRE(false == game->game_over());

	game->mark_board(8);
	REQUIRE(true == game->game_over());
	
	
	REQUIRE("X" == game->get_winner());
}

TEST_CASE("Test tictactoe4 third row")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(9);
	REQUIRE(false == game->game_over());
	game->mark_board(1);
	REQUIRE(false == game->game_over());

	game->mark_board(10);
	REQUIRE(false == game->game_over());
	game->mark_board(2);
	REQUIRE(false == game->game_over());

	game->mark_board(11);
	REQUIRE(false == game->game_over());
	game->mark_board(3);
	REQUIRE(false == game->game_over());

	game->mark_board(12);
	REQUIRE(true == game->game_over());
	
	
	REQUIRE("X" == game->get_winner());
}

TEST_CASE("Test tictactoe4 fourth row")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(13);
	REQUIRE(false == game->game_over());
	game->mark_board(1);
	REQUIRE(false == game->game_over());

	game->mark_board(14);
	REQUIRE(false == game->game_over());
	game->mark_board(2);
	REQUIRE(false == game->game_over());

	game->mark_board(15);
	REQUIRE(false == game->game_over());
	game->mark_board(3);
	REQUIRE(false == game->game_over());

	game->mark_board(16);
	REQUIRE(true == game->game_over());
	
	
	REQUIRE("X" == game->get_winner());
}

//DIAGONALS

TEST_CASE("Test tictactoe4 top left diagonal")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(1);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());

	game->mark_board(6);
	REQUIRE(false == game->game_over());
	game->mark_board(9);
	REQUIRE(false == game->game_over());

	game->mark_board(11);
	REQUIRE(false == game->game_over());
	game->mark_board(13);
	REQUIRE(false == game->game_over());

	game->mark_board(16);
	REQUIRE(true == game->game_over());
	
	REQUIRE("X" == game->get_winner());
}

TEST_CASE("Test tictactoe4 top right diagonal")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");

	game->mark_board(4);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());

	game->mark_board(7);
	REQUIRE(false == game->game_over());
	game->mark_board(9);
	REQUIRE(false == game->game_over());

	game->mark_board(10);
	REQUIRE(false == game->game_over());
	game->mark_board(2);
	REQUIRE(false == game->game_over());

	game->mark_board(13);
	REQUIRE(true == game->game_over());
	
	REQUIRE("X" == game->get_winner());
}

//Get winner total
TEST_CASE("Test tictactoe 4 get_winner_total funciton")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	TicTacToeManager gameManager;

	int o,w,t;

	//X wins
	game->start_game("X");

	game->mark_board(1);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(2);
	REQUIRE(false == game->game_over());
	game->mark_board(6);
	REQUIRE(false == game->game_over());
	game->mark_board(3);
	REQUIRE(false == game->game_over());
	game->mark_board(7);
	REQUIRE(false == game->game_over());
	game->mark_board(4);
	REQUIRE(true == game->game_over());

	gameManager.save_game(game);

	//O wins
	game->start_game("O");

	game->mark_board(1);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(2);
	REQUIRE(false == game->game_over());
	game->mark_board(6);
	REQUIRE(false == game->game_over());
	game->mark_board(3);
	REQUIRE(false == game->game_over());
	game->mark_board(7);
	REQUIRE(false == game->game_over());
	game->mark_board(4);
	REQUIRE(true == game->game_over());

	gameManager.save_game(game);

	//Tie
	game->start_game("X");
	
	game->mark_board(2);
	REQUIRE(false == game->game_over());
	game->mark_board(1);
	REQUIRE(false == game->game_over());
	game->mark_board(3);
	REQUIRE(false == game->game_over());
	game->mark_board(4);
	REQUIRE(false == game->game_over());
	game->mark_board(5);
	REQUIRE(false == game->game_over());
	game->mark_board(6);
	REQUIRE(false == game->game_over());
	game->mark_board(8);
	REQUIRE(false == game->game_over());
	game->mark_board(7);
	REQUIRE(false == game->game_over());
	game->mark_board(10);
	REQUIRE(false == game->game_over());
	game->mark_board(9);
	REQUIRE(false == game->game_over());
	game->mark_board(11);
	REQUIRE(false == game->game_over());
	game->mark_board(12);
	REQUIRE(false == game->game_over());
	game->mark_board(13);
	REQUIRE(false == game->game_over());
	game->mark_board(14);
	REQUIRE(false == game->game_over());
	game->mark_board(16);
	REQUIRE(false == game->game_over());
	game->mark_board(15);
	REQUIRE(true == game->game_over());

	gameManager.save_game(game);

	gameManager.get_winner_total(o,w,t);

	REQUIRE(o == 1);
	REQUIRE(w == 1);
	REQUIRE(t == 1);
}
