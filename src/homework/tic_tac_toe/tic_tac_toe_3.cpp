#include "tic_tac_toe_3.h"



/*
class function check_column_win
Win by column if and return true if
0,3, and 6 are equal
1, 4, and 7
2, 5, and 8
else
false
*/

bool TicTacToe3::check_column_win()
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




/*
class function check_row_win
Win by row if
0, 1, 2 are equal
3,4,5 are equal
6,7,8 are equal
*/

bool TicTacToe3::check_row_win()
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



/*
class function check_diagonal_win
Win diagonally
0 1 2
3 4 5
6 7 8

*/

bool TicTacToe3::check_diagonal_win()
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