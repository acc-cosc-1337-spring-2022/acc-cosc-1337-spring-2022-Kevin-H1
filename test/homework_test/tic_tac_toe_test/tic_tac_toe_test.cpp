#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"


TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

//Tie
TEST_CASE("Test tic tac toe game over for a tie")
{
	TicTacToe game;

	game.start_game("X"); 

	game.mark_board(1);
	REQUIRE(false == game.game_over());

	game.mark_board(2);
	REQUIRE(false == game.game_over());

	game.mark_board(4);
	REQUIRE(false == game.game_over());

	game.mark_board(7);
	REQUIRE(false == game.game_over());

	game.mark_board(5);
	REQUIRE(false == game.game_over());

	game.mark_board(6);
	REQUIRE(false == game.game_over());

	game.mark_board(3);
	REQUIRE(false == game.game_over());

	game.mark_board(8);
	REQUIRE(false == game.game_over());

	game.mark_board(9);
	REQUIRE(true == game.game_over());

	REQUIRE("C" == game.get_winner());
}

TEST_CASE("Test first player set to X")
{
	TicTacToe game;
	game.start_game("X");

	REQUIRE("X" == game.get_player());
}

TEST_CASE("Test first player set to O")
{
	TicTacToe game;
	game.start_game("O");

	REQUIRE("O" == game.get_player());
}


//CHECK COLUMNS

TEST_CASE("Test check first column win")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(false == game.game_over());
	game.mark_board(2);
	REQUIRE(false == game.game_over());
	game.mark_board(4);
	REQUIRE(false == game.game_over());
	game.mark_board(5);
	REQUIRE(false == game.game_over());
	game.mark_board(7);
	REQUIRE(true == game.game_over());
	
	REQUIRE("X" == game.get_winner());

}

TEST_CASE("Test check second column win")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(2);
	REQUIRE(false == game.game_over());
	game.mark_board(1);
	REQUIRE(false == game.game_over());
	game.mark_board(5);
	REQUIRE(false == game.game_over());
	game.mark_board(4);
	REQUIRE(false == game.game_over());
	game.mark_board(8);
	REQUIRE(true == game.game_over());
	
	REQUIRE("X" == game.get_winner());
	

}


TEST_CASE("Test check Third column win")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(3);
	REQUIRE(false == game.game_over());
	game.mark_board(2);
	REQUIRE(false == game.game_over());
	game.mark_board(6);
	REQUIRE(false == game.game_over());
	game.mark_board(5);
	REQUIRE(false == game.game_over());
	game.mark_board(9);
	REQUIRE(true == game.game_over());
	
	REQUIRE("X" == game.get_winner());

}


//CHECK ROWS


TEST_CASE("Test first row")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(false == game.game_over());
	game.mark_board(4);
	REQUIRE(false == game.game_over());
	game.mark_board(2);
	REQUIRE(false == game.game_over());
	game.mark_board(5);
	REQUIRE(false == game.game_over());
	game.mark_board(3);
	REQUIRE(true == game.game_over());
	
	REQUIRE("X" == game.get_winner());
}

TEST_CASE("Test second row")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(4);
	REQUIRE(false == game.game_over());
	game.mark_board(3);
	REQUIRE(false == game.game_over());
	game.mark_board(5);
	REQUIRE(false == game.game_over());
	game.mark_board(2);
	REQUIRE(false == game.game_over());
	game.mark_board(6);
	REQUIRE(true == game.game_over());

	REQUIRE("X" == game.get_winner());
}

TEST_CASE("Test third row")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(7);
	REQUIRE(false == game.game_over());
	game.mark_board(4);
	REQUIRE(false == game.game_over());
	game.mark_board(8);
	REQUIRE(false == game.game_over());
	game.mark_board(5);
	REQUIRE(false == game.game_over());
	game.mark_board(9);
	REQUIRE(true == game.game_over());

	REQUIRE("X" == game.get_winner());
}

//CHECK DIAGONALLY

TEST_CASE("Test if someone won top left diagonally")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(false == game.game_over());
	//O's turn
	game.mark_board(2);
	REQUIRE(false == game.game_over());
	//X's turn
	game.mark_board(5);
	REQUIRE(false == game.game_over());
	//O's turn
	game.mark_board(4);
	REQUIRE(false == game.game_over());
	//x's turn
	game.mark_board(9);
	REQUIRE(game.game_over() == true);

	REQUIRE("X" == game.get_winner());
}

TEST_CASE("Test if someone won bot left diagonally")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(7);
	REQUIRE(false == game.game_over());
	//O's turn
	game.mark_board(2);
	REQUIRE(false == game.game_over());
	//X's turn
	game.mark_board(5);
	REQUIRE(false == game.game_over());
	//O's turn
	game.mark_board(4);
	REQUIRE(false == game.game_over());
	//x's turn
	game.mark_board(3);
	REQUIRE(game.game_over() == true);

	REQUIRE("X" == game.get_winner());
}

TEST_CASE("Test get_winner_total function")
{
	TicTacToe game;
	TicTacToeManager gameManager;

	int o,w,t;

	//X wins
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(false == game.game_over());
	game.mark_board(4);
	REQUIRE(false == game.game_over());
	game.mark_board(2);
	REQUIRE(false == game.game_over());
	game.mark_board(5);
	REQUIRE(false == game.game_over());
	game.mark_board(3);
	REQUIRE(true == game.game_over());

	gameManager.save_game(game);

	//O wins
	game.start_game("O");

	game.mark_board(1);
	REQUIRE(false == game.game_over());

	game.mark_board(4);
	REQUIRE(false == game.game_over());

	game.mark_board(2);
	REQUIRE(false == game.game_over());

	game.mark_board(5);
	REQUIRE(false == game.game_over());

	game.mark_board(3);
	REQUIRE(true == game.game_over());

	gameManager.save_game(game);


	//Tie
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(false == game.game_over());

	game.mark_board(2);
	REQUIRE(false == game.game_over());

	game.mark_board(3);
	REQUIRE(false == game.game_over());

	game.mark_board(5);
	REQUIRE(false == game.game_over());

	game.mark_board(4);
	REQUIRE(false == game.game_over());

	game.mark_board(7);
	REQUIRE(false == game.game_over());

	game.mark_board(6);
	REQUIRE(false == game.game_over());

	game.mark_board(9);
	REQUIRE(false == game.game_over());

	game.mark_board(8);
	REQUIRE(true == game.game_over());

	gameManager.save_game(game);


	gameManager.get_winner_total(o,w,t);

	REQUIRE(o == 1);
	REQUIRE(w == 1);
	REQUIRE(t == 1);
}
