//cpp
#include "tic_tac_toe_manager.h"

using std::cout; using std::string;


void TicTacToeManager::save_game(TicTacToe b)
{
    games.push_back(b);
    update_winner_count(b.get_winner());
}

//works?
std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    for(auto var: manager.games)
    {
        out<<var<<"\n";
    }
    return out;
}


void TicTacToeManager::get_winner_total(int& o, int& w, int& t)
{
    o = o_win;
    w = x_win;
    t = ties;

    cout<<"X wins: "<<w<<"\n";
    cout<<"O wins: "<<o<<"\n";
    cout<<"Ties: "<<t<<"\n";

}

void TicTacToeManager::update_winner_count(std::string winner)
{
    if(winner == "X")
    {
        x_win +=1;
    }
    else if(winner == "O")
    {
        o_win +=1;
    }
    else
    {
        ties +=1;
    }
}