// In a 2D grid of 0s and 1s, we change at most one 0 to a 1.
//
// After, what is the size of the largest island? (An island is a
// 4-directionally connected group of 1s).
//
// Example 1:
//
// Input: [[1, 0], [0, 1]]
// Output: 3
// Explanation: Change one 0 to 1 and connect two 1s, then we get an island with
// area = 3. Example 2:
//
// Input: [[1, 1], [1, 0]]
// Output: 4
// Explanation: Change the 0 to 1 and make the island bigger, only one island
// with area = 4. Example 3:
//
// Input: [[1, 1], [1, 1]]
// Output: 4
// Explanation: Can't change any 0 to 1, only one island with area = 4.
//
//
// Notes:
//
// 1 <= grid.length = grid[0].length <= 50.
// 0 <= grid[i][j] <= 1.

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) {
            return 0;
        }
        int n = grid[0].size();
        int res = 0;

        vector<int> sizes = {0, 0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    sizes.push_back(paint(grid, i, j, sizes.size(), m, n));
                    res = max(res, sizes.back());
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) {
                    set<int> colors;
                    for (auto d : dir) {
                        int x = d[0] + i;
                        int y = d[1] + j;
                        if (x < 0 || x >= m || y < 0 || y >= n) {
                            continue;
                        }
                        colors.insert(grid[x][y]);
                    }
                    int sum = 1;
                    for (auto c : colors) {
                        sum += sizes[c];
                    }
                    res = max(res, sum);
                }
            }
        }

        return res;
    }

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int paint(vector<vector<int>>& grid,
              int i,
              int j,
              int color,
              int m,
              int n) {
        if (grid[i][j] != 1) {
            return 0;
        }

        grid[i][j] = color;
        int area = 1;
        for (auto d : dir) {
            int x = d[0] + i;
            int y = d[1] + j;
            if (x < 0 || x >= m || y < 0 || y >= n) {
                continue;
            }
            area += paint(grid, x, y, color, m, n);
        }
        return area;
    }
};
