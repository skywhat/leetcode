#include<iostream>
#include<vector>

using namespace std;

class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<int> rows;
    vector<int> cols;
    int diag1;
    int diag2;
    int _n;
    TicTacToe(int n) {
        rows.reserve(n);
        rows.assign(n,0);
        cols.reserve(n);
        cols.assign(n,0);
        diag1=0;
        diag2=0;
        _n=n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add=player==1?1:-1;
        rows[row]+=add;
        cols[col]+=add;
        if(row==col)
            diag1+=add;
        if(row+col==_n-1)
            diag2+=add;
        if(abs(rows[row])==_n||abs(cols[col])==_n||abs(diag1)==_n||abs(diag2)==_n)
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
