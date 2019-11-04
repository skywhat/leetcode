#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int usedrow[9][9] = {0};
        int usedcol[9][9] = {0};
        int usedboard[9][9] = {0};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                int n = board[i][j] - '1';
                int k = i / 3 * 3 + j / 3;
                if (usedrow[i][n] || usedcol[j][n] || usedboard[k][n]) {
                    return false;
                }
                usedrow[i][n] = usedcol[j][n] = usedboard[k][n] = 1;
            }
        }

        return true;
    }
};

class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> valid(10, false);
        for (int i = 0; i < 9; ++i) {
            fill(valid.begin(), valid.end(), false);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (valid[board[i][j] - '0']) {
                        return false;
                    }
                    valid[board[i][j] - '0'] = true;
                }
            }
        }

        for (int i = 0; i < 9; ++i) {
            fill(valid.begin(), valid.end(), false);
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] != '.') {
                    if (valid[board[j][i] - '0']) {
                        return false;
                    }
                    valid[board[j][i] - '0'] = true;
                }
            }
        }

        vector<int> region = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        for (auto r : region) {
            fill(valid.begin(), valid.end(), false);
            for (int i = (r / 3) * 3; i < (r / 3) * 3 + 3; ++i) {
                for (int j = (r % 3) * 3; j < (r % 3) * 3 + 3; ++j) {
                    if (board[i][j] != '.') {
                        if (valid[board[i][j] - '0']) {
                            return false;
                        }
                        valid[board[i][j] - '0'] = true;
                    }
                }
            }
        }

        return true;
    }
};

int main() {}
