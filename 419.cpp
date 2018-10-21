// Given an 2D board, count how many battleships are in it. The battleships are
// represented with 'X's, empty slots are represented with '.'s. You may assume
// the following rules: You receive a valid board, made of only battleships or
// empty slots. Battleships can only be placed horizontally or vertically. In
// other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1
// (N rows, 1 column), where N can be of any size. At least one horizontal or
// vertical cell separates between two battleships - there are no adjacent
// battleships. Example: X..X
// ...X
// ...X
// In the above board there are 2 battleships.
// Invalid Example:
// ...X
// XXXX
// ...X
// This is an invalid board that you will not receive - as battleships will
// always have a cell separating between them. Follow up: Could you do it in
// one-pass, using only O(1) extra memory and without modifying the value of the
// board?

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.size() == 0)
            return 0;
        int res = 0;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'X') {
                    res++;
                    board[i][j] = '.';
                    flip(board, i, j);
                }
            }
        }

        return res;
    }

    void flip(vector<vector<char>>& board, int row, int col) {
        for (int i = row + 1; i < board.size(); ++i) {
            if (board[i][col] == 'X') {
                board[i][col] = '.';
            } else {
                break;
            }
        }

        for (int j = col + 1; j < board[0].size(); ++j) {
            if (board[row][j] == 'X') {
                board[row][j] = '.';
            } else {
                break;
            }
        }
    }
};

class Solution2 {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.size() == 0)
            return 0;
        int res = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (i > 0 && board[i - 1][j] == 'X') {
                    continue;
                }
                if (j > 0 && board[i][j - 1] == 'X') {
                    continue;
                }
                res++;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<char>> test1
        = {{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};

    vector<vector<char>> test2 = {{'X', 'X', 'X'}};

    for (auto row : test1) {
        for (auto elem : row)
            cout << elem;
        cout << endl;
    }
    Solution s;
    cout << s.countBattleships(test1) << endl;

    return 0;
}
