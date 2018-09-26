/*
https://leetcode.com/problems/word-search/#/description



Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
 where "adjacent" cells are those horizontally or vertically neighboring. The
same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) {
            return true;
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (search(board, i, j, 0, word)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool search(vector<vector<char>>& board,
                int i,
                int j,
                int pos,
                const string& word) {
        if (pos + 1 == word.size()) {
            return word[pos] == board[i][j];
        }

        if (board[i][j] != word[pos]) {
            return false;
        }

        char x = board[i][j];
        board[i][j] = '#';

        for (auto d : dir) {
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
                continue;
            }

            if (search(board, x, y, pos + 1, word)) {
                return true;
            }
        }

        board[i][j] = x;

        return false;
    }
};

class Solution2 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        int m = board.size();
        int n = board[0].size();
        set<pair<int, int>> help;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (find(board, word, 0, i, j, m, n, help))
                        return true;
                }
            }
        }
        return false;
    }
    bool find(vector<vector<char>>& board,
              const string& word,
              int pos,
              int x,
              int y,
              const int& m,
              const int& n,
              set<pair<int, int>>& s) {
        if (pos + 1 == word.size()) {
            return word[pos] == board[x][y] && !s.count({x, y});
        }
        if (board[x][y] != word[pos] || s.count({x, y}))
            return false;
        s.insert({x, y});
        if ((x + 1 < m && find(board, word, pos + 1, x + 1, y, m, n, s))
            || (x - 1 >= 0 && find(board, word, pos + 1, x - 1, y, m, n, s))
            || (y + 1 < n && find(board, word, pos + 1, x, y + 1, m, n, s))
            || (y - 1 >= 0 && find(board, word, pos + 1, x, y - 1, m, n, s)))
            return true;
        s.erase({x, y});
        return false;
    }
};

int main() {
    Solution2 s;
    vector<vector<char>> t = {{'h', 'e', 'l', 'l', 'o'}};
    /*
    vector<vector<char>> v = {
        {"ABCE"},
        {"SFCS"},
        {"ADEE" },
        {"ABCCED"}
    };
    */
    string word = "lleh";
    cout << s.exist(t, word);

    return 0;
}
