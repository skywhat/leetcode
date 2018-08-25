/*
According to the Wikipedia's article: "The Game of Life, also known simply as
Life, is a cellular automaton devised by the British mathematician John Horton
Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead
(0). Each cell interacts with its eight neighbors (horizontal, vertical,
diagonal) using the following four rules (taken from the above Wikipedia
article):

Any live cell with fewer than two live neighbors dies, as if caused by
under-population. Any live cell with two or three live neighbors lives on to the
next generation. Any live cell with more than three live neighbors dies, as if
by over-population.. Any dead cell with exactly three live neighbors becomes a
live cell, as if by reproduction. Write a function to compute the next state
(after one update) of the board given its current state. The next state is
created by applying the above rules simultaneously to every cell in the current
state, where births and deaths occur simultaneously.

Example:

Input:
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output:
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the
same time: You cannot update some cells first and then use their updated values
to update other cells. In this question, we represent the board using a 2D
array. In principle, the board is infinite, which would cause problems when the
active area encroaches the border of the array. How would you address these
problems?
*/

class Solution {
public:
    /*
    0=>0 00
    0=>1 10
    1=>0 01
    1=>1 11
    */
    vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                               {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (!m) {
            return;
        }
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (auto d : dir) {
                    int x = d[0] + i;
                    int y = d[1] + j;
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }

                    if (board[x][y] & 1) {
                        cnt++;
                    }
                }

                if (cnt >= 2 && cnt <= 3 && (board[i][j] & 1)) {
                    board[i][j] = 3;
                }

                if (cnt == 3 && board[i][j] == 0) {
                    board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
