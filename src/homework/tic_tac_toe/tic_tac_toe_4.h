//h
#include "tic_tac_toe.h"

#ifndef TIC_TAC_TOE_4_H
#define TIC_TAC_TOE_4_H

class TicTacToe4: public TicTacToe
{

public:
    //Constructor
    TicTacToe4(): TicTacToe(4){}

private:
    bool check_column_win()override;
    bool check_row_win()override;
    bool check_diagonal_win()override;

};



#endif