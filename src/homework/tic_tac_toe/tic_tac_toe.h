//h
#include <string>
#include <vector>
#include <iostream>
#include <memory>


#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToe
{

friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
friend std::istream& operator>>(std::istream& in, TicTacToe& game);

public:
    //constructor
    TicTacToe(int size): pegs(size * size, " "){}
    TicTacToe(std::vector<std::string> p, std::string win): pegs(p), winner(win){}
    


    bool game_over();
    void start_game(std::string first_player);
    void mark_board(int position);

    std::string get_player()const{return player;}    
    std::string get_winner()const{return winner;}

    std::vector<std::string> get_pegs()const{return pegs;}


protected:
    std::vector<std::string> pegs;

    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();


private:

    std::string player;
    //std::vector<std::string> pegs{9, " "};
    void set_next_player();
    bool check_board_full();
    void clear_board();
    
    std::string winner;
    //bool check_column_win();
    //bool check_row_win();
    //bool check_diagonal_win();
    void set_winner();
};

#endif