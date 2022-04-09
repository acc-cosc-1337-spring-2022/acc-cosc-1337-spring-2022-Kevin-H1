//cpp
#include "tic_tac_toe.h"

using std::string; using std::cout;

bool TicTacToe::game_over()
{

    if(check_board_full())
    {
        winner = "C";
        return true;
    }
    else if(check_column_win())
    {
        set_winner();
        return true;
    }
    else if(check_diagonal_win())
    {
        set_winner();
        return true;
    }
    else if(check_row_win())
    {
        set_winner();
        return true;
    }
    return false;
    
}

void TicTacToe::start_game(string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position-1] = player;
    set_next_player();
}

void TicTacToe::display_board()const
{
    for(int i=0; i < 9; i+=3)
    {
        cout<<pegs[i]<<"|"<<pegs[i+1]<<"|"<<pegs[i+2]<<"\n";
    }
}

void TicTacToe::set_next_player()
{
    if(player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}

bool TicTacToe::check_board_full()
{
    for(auto peg: pegs)
    {
        if(peg == " ")
        {
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board()
{
    for(auto& peg: pegs)
    {
        peg = " ";
    }
}

//Part 2

bool TicTacToe::check_diagonal_win()
{
    if(pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X")
    {
        return true;
    }
    else if(pegs[2] == "X" && pegs[4] == "X" && pegs[6] == "X") 
    {
        return true;
    }
    else if (pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O")
    {
        return true;
    }
    else if (pegs[2] == "O" && pegs[4] == "O" && pegs[6] == "O")
    {
        return true;
    }
    return false;
}


bool TicTacToe::check_column_win()
{
    if(pegs[0] == "X" && pegs[3] == "X" && pegs[6] == "X")
    {
        return true;
    }
    else if(pegs[0] == "O" && pegs[3] == "O" && pegs[6] == "O")
    {
        return true;
    }
    else if(pegs[1] == "X" && pegs[4] == "X" && pegs[7] == "X")
    {
        return true;
    }
    else if(pegs[1] == "O" && pegs[4] == "O" && pegs[7] == "O")
    {
        return true;
    }
    else if(pegs[2] == "X" && pegs[5] == "X" && pegs[8] == "X")
    {
        return true;
    }
    else if(pegs[2] == "O" && pegs[5] == "O" && pegs[8] == "O")
    {
        return true;
    }
    return false;

}

bool TicTacToe::check_row_win()
{
    //first row
    if(pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X")
    {
        return true;
    }
    else if(pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O")
    {
        return true;
    }   
    //second row
    else if(pegs[3] == "X" && pegs[4] == "X" && pegs[5] == "X")
    {
        return true;
    }
    else if(pegs[3] == "O" && pegs[4] == "O" && pegs[5] == "O")
    {
        return true;
    }
    //third row 
    else if(pegs[6] == "X" && pegs[7] == "X" && pegs[8] == "X")
    {
        return true;
    }
    else if(pegs[6] == "X" && pegs[7] == "X" && pegs[8] == "X")
    {
        return true;
    }
    return false;

}

void TicTacToe::set_winner()
{
    if(player == "X")
    {
        winner = "O";
    }
    else
    {
        winner = "X";
    }
    
}