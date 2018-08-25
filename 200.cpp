/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of
islands. An island is surrounded by water and is formed by connecting adjacent
lands horizontally or vertically. You may assume all four edges of the grid are
all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int cnt = 0;
        const int m = grid.size();
        const int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    cnt++;
                    flipToZero(grid, m, n, i, j);
                }
            }
        }
        return cnt;
    }

    void flipToZero(vector<vector<char>>& grid,
                    const int& m,
                    const int& n,
                    int i,
                    int j) {
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        if (i + 1 < m)
            flipToZero(grid, m, n, i + 1, j);
        if (i - 1 >= 0)
            flipToZero(grid, m, n, i - 1, j);
        if (j + 1 < n)
            flipToZero(grid, m, n, i, j + 1);
        if (j - 1 >= 0)
            flipToZero(grid, m, n, i, j - 1);
    }
};

// union find
class Solution2 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (!m) {
            return 0;
        }
        int n = grid[0].size();

        int cnt = 0;
        vector<int> uf(m * n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                uf[i * n + j] = i * n + j;
                if (grid[i][j] == '1') {
                    cnt++;
                }
            }
        }

        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }

                int cur = i * n + j;
                for (auto d : dir) {
                    int x = i + d[0];
                    int y = j + d[1];
                    if (x < 0 || x >= m || y < 0 || y >= n
                        || grid[x][y] == '0') {
                        continue;
                    }

                    int nb = x * n + y;
                    int cur_root = find(uf, cur);
                    int nb_root = find(uf, nb);
                    if (cur_root != nb_root) {
                        uf[nb_root] = cur_root;
                        cnt--;
                    }
                }
            }
        }

        return cnt;
    }

    int find(vector<int>& uf, int id) {
        while (uf[id] != id) {
            uf[id] = uf[uf[id]];
            id = uf[id];
        }

        return id;
    }
};

/*
 example:

 0 1 0
 1 0 1
 0 1 0

 For the central 0, it could be visited at most five times
 Thus the time complexity of DFS solution would be O(n)
 */
