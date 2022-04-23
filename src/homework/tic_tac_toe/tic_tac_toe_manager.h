//h
#include <string>
#include <vector>
#include <iostream>
#include<memory>

#include "tic_tac_toe_data.h"
#include "tic_tac_toe.h"


#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H


class TicTacToeManager
{

friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);

public:
    TicTacToeManager() = default;
    TicTacToeManager(TicTacToeData& data_param): data(data_param){}

    ~TicTacToeManager(){data.save_game(games);}

    void save_game(std::unique_ptr<TicTacToe>& b);
    void get_winner_total(int& out, int& w, int& t);

    void update_winner_totals(std::vector<std::unique_ptr<TicTacToe>> board_games);
private:

    std::vector<std::unique_ptr<TicTacToe>> games;
    //std::vector<TicTacToe> games;
    int x_win = 0;
    int o_win = 0;
    int ties = 0;
    void update_winner_count(std::string winner);
    TicTacToeData data;

};



#endif