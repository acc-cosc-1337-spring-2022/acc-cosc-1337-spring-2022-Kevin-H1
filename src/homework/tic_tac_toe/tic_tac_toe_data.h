//h
#include<fstream>
#include<memory>
#include<vector>
#include<string>
#include"tic_tac_toe.h"


#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H


class TicTacToeData
{

public: 
    void save_game(const std::vector<std::unique_ptr<TicTacToe>>& games);
    std::vector<std::unique_ptr<TicTacToe>> get_games();

private:
        std::string file_name{"games_save.dat"};

};




#endif