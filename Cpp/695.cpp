// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
// (representing land) connected 4-directionally (horizontal or vertical.) You
// may assume all four edges of the grid are surrounded by water.
//
// Find the maximum area of an island in the given 2D array. (If there is no
// island, the maximum area is 0.)
//
// Example 1:
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Given the above grid, return 6. Note the answer is not 11, because the island
// must be connected 4-directionally. Example 2:
// [[0,0,0,0,0,0,0,0]]
// Given the above grid, return 0.
// Note: The length of each dimension in the given grid does not exceed 50.

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int area = 0;
                flipToZero(grid, i, j, m, n, area);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }

    void flipToZero(vector<vector<int>>& grid,
                    int i,
                    int j,
                    int m,
                    int n,
                    int& area) {
        if (grid[i][j]) {
            grid[i][j] = 0;
            area++;
            if (i - 1 >= 0) {
                flipToZero(grid, i - 1, j, m, n, area);
            }
            if (i + 1 < m) {
                flipToZero(grid, i + 1, j, m, n, area);
            }
            if (j - 1 >= 0) {
                flipToZero(grid, i, j - 1, m, n, area);
            }
            if (j + 1 < n) {
                flipToZero(grid, i, j + 1, m, n, area);
            }
        }
    }
};

class Solution2 {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) {
            return 0;
        }
        int n = grid[0].size();

        int res = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    int cnt = 0;
                    dfs(grid, i, j, m, n, cnt);
                    res = max(res, cnt);
                }
            }
        }

        return res;
    }

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& grid,
             int i,
             int j,
             const int& m,
             const int& n,
             int& cnt) {
        cnt++;
        grid[i][j] = -1;

        for (auto d : dir) {
            int x = d[0] + i;
            int y = d[1] + j;
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) {
                continue;
            }
            dfs(grid, x, y, m, n, cnt);
        }
    }
};
