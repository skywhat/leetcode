// A 2d grid map of m rows and n columns is initially filled with water. We may
// perform an addLand operation which turns the water at position (row, col)
// into a land. Given a list of positions to operate, count the number of
// islands after each addLand operation. An island is surrounded by water and is
// formed by connecting adjacent lands horizontally or vertically. You may
// assume all four edges of the grid are all surrounded by water.
//
// Example:
//
// Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
// Output: [1,1,2,3]
// Explanation:
//
// Initially, the 2d grid grid is filled with water. (Assume 0 represents water
// and 1 represents land).
//
// 0 0 0
// 0 0 0
// 0 0 0
// Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
//
// 1 0 0
// 0 0 0   Number of islands = 1
// 0 0 0
// Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
//
// 1 1 0
// 0 0 0   Number of islands = 1
// 0 0 0
// Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
//
// 1 1 0
// 0 0 1   Number of islands = 2
// 0 0 0
// Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
//
// 1 1 0
// 0 0 1   Number of islands = 3
// 0 1 0
// Follow up:
//
// Can you do it in time complexity O(k log mn), where k is the length of the
// positions?

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        int cnt = 0;
        vector<int> res;
        vector<int> uf(m * n, 0);
        vector<vector<int>> board(m, vector<int>(n, 0));
        for (int i = 0; i < m * n; ++i) {
            uf[i] = i;
        }

        for (auto p : positions) {
            board[p.first][p.second] = 1;
            cnt++;
            int cur = find(uf, p.first * n + p.second);
            for (auto d : dir) {
                int x = p.first + d[0];
                int y = p.second + d[1];
                if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == 0) {
                    continue;
                }

                int nb = find(uf, x * n + y);
                if (nb != cur) {
                    uf[nb] = cur;
                    cnt--;
                }
            }
            res.push_back(cnt);
        }

        return res;
    }

    int find(vector<int>& uf, int id) {
        while (uf[id] != id) {
            uf[id] = uf[uf[id]];
            id = uf[id];
        }

        return id;
    }
};

int main() {}
