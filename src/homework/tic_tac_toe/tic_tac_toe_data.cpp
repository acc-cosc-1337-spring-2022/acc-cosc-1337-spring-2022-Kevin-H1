//cpp
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include<memory>
using std::ofstream; using std::ifstream; using std::unique_ptr; using std::make_unique; using std::getline;

void TicTacToeData::save_game(const std::vector<std::unique_ptr<TicTacToe>>& games)
{
    ofstream out_file;
    out_file.open("games_save.dat");
    for(auto& g: games)
    {
        for(auto s: g->get_pegs())
        {
            int size_of_peg = s.size();
            while(size_of_peg > 0)
            {
                out_file<<s[size_of_peg];
            }
            out_file<<g->get_winner()<<"\n";
        }
    }
    out_file.close();

}


std::vector<std::unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
    std::vector<unique_ptr<TicTacToe>> boards;
    ifstream out_file;
    out_file.open("games_save.dat");
    std::string line; 
    std::vector<std::string> pegs;

    while(std::getline(out_file, line))
    {
        std::string ch;
        std::string winner;
        int numSize = line.size();
        for(int i = 0; i < numSize - 1; i++)
        {
            ch = ch + line[i];   
        }
        pegs.push_back(ch);
        winner = winner + line[numSize];

        std::unique_ptr<TicTacToe> board;
        
        if(ch.size() == 9)
        {
            board = make_unique<TicTacToe3>(pegs, winner);
            boards.push_back(std::move(board));
        }
        else if(ch.size() == 16)
        {
            board = make_unique<TicTacToe4>(pegs, winner);
            boards.push_back(std::move(board));
        }    
        
    }
    out_file.close();
    return boards;
}

