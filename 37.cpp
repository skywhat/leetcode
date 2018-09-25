#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { solve(board); }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ++ch) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    bool isValid(vector<vector<char>>& board, int i, int j, char x) {
        for (int k = 0; k < 9; ++k) {
            if (board[i][k] == x || board[k][j] == x
                || board[i / 3 * 3 + k / 3][j / 3 * 3 + k % 3] == x) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    string sudoku
        = "..9748...7.........2.1.9.....7...24..64.1.59..98...3.....8.3.2......"
          "...6...2759..";
    vector<vector<char>> v;
    for (int i = 0; i < 9; ++i) {
        vector<char> tmp(sudoku.begin() + i * 9, sudoku.begin() + i * 9 + 9);
        v.push_back(tmp);
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    Solution s;
    s.solveSudoku(v);
    cout << "AFTER SOLVE SUDOKU:" << endl;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
