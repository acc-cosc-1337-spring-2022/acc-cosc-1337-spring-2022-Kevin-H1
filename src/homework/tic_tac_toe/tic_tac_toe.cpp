//cpp
#include "tic_tac_toe.h"
#include "tic_tac_toe_4.h"

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
    return false;

}


bool TicTacToe::check_column_win()
{
    return false;

}

bool TicTacToe::check_row_win()
{
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


std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    if(game.pegs.size() == 9)
    {
        for(int i=0; i < 9; i+=3)
        {
            out<<game.pegs[i]<<"|"<<game.pegs[i+1]<<"|"<<game.pegs[i+2]<<"\n";
        
        }
        return out;
    }
    else if (game.pegs.size() == 16)
    {
        {
            for(int i=0; i < 16; i+=4)
            {
                out<<game.pegs[i]<<"|"<<game.pegs[i+1]<<"|"<<game.pegs[i+2]<<"|"<<game.pegs[i+3]<<"\n";
            }
            return out;
        }
    }
    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int pos;
    if(game.pegs.size() == 9)
    {
        cout<<"Enter position [1-9]: ";
        in>>pos;
        game.mark_board(pos);
        return in;
    }
    else
    {
        cout<<"Enter position [1-16]: ";
        in>>pos;
        game.mark_board(pos);
        return in;
    }
    
    return in;
}
