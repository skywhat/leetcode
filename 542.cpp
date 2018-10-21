// Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
// each cell.
//
// The distance between two adjacent cells is 1.
// Example 1:
// Input:
//
// 0 0 0
// 0 1 0
// 0 0 0
// Output:
// 0 0 0
// 0 1 0
// 0 0 0
// Example 2:
// Input:
//
// 0 0 0
// 0 1 0
// 1 1 1
// Output:
// 0 0 0
// 0 1 0
// 1 2 1
// Note:
// The number of elements of the given matrix will not exceed 10,000.
// There are at least one 0 in the given matrix.
// The cells are adjacent in only four directions: up, down, left and right.

class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) {
            return {};
        }
        int n = matrix[0].size();

        vector<vector<int>> res(m, vector<int>(n, 0));
        queue<vector<int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                } else {
                    res[i][j] = INT_MAX;
                }
            }
        }

        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            for (auto d : dir) {
                int x = d[0] + pos[0];
                int y = d[1] + pos[1];
                if (x < 0 || x >= m || y < 0 || y >= n
                    || res[pos[0]][pos[1]] + 1 >= res[x][y]) {
                    continue;
                }
                res[x][y] = res[pos[0]][pos[1]] + 1;
                q.push({x, y});
            }
        }

        return res;
    }
};
