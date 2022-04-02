#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

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

	game.mark_board(2);
	
	game.mark_board(4);

	game.mark_board(5);

	game.mark_board(7);

	REQUIRE(true == game.game_over());

}

TEST_CASE("Test check second column win")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(2);

	game.mark_board(1);
	
	game.mark_board(5);

	game.mark_board(4);

	game.mark_board(8);

	REQUIRE(true == game.game_over());

}


TEST_CASE("Test check Third column win")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(3);

	game.mark_board(2);
	
	game.mark_board(6);

	game.mark_board(5);

	game.mark_board(9);

	REQUIRE(true == game.game_over());

}


//CHECK ROWS


TEST_CASE("Test first row")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);
	
	game.mark_board(4);

	game.mark_board(2);

	game.mark_board(5);

	game.mark_board(3);

	REQUIRE(true == game.game_over());
}

TEST_CASE("Test second row")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(4);
	
	game.mark_board(3);

	game.mark_board(5);

	game.mark_board(2);

	game.mark_board(6);

	REQUIRE(true == game.game_over());
}

TEST_CASE("Test third row")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(7);
	
	game.mark_board(4);

	game.mark_board(8);

	game.mark_board(5);

	game.mark_board(9);

	REQUIRE(true == game.game_over());
}

//CHECK DIAGONALLY

TEST_CASE("Test if someone won top left diagonally")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);
	//O's turn
	game.mark_board(2);
	//X's turn
	game.mark_board(5);
	//O's turn
	game.mark_board(4);
	//x's turn
	game.mark_board(9);

	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test if someone won bot left diagonally")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(7);
	//O's turn
	game.mark_board(2);
	//X's turn
	game.mark_board(5);
	//O's turn
	game.mark_board(4);
	//x's turn
	game.mark_board(3);

	REQUIRE(game.game_over() == true);
}
