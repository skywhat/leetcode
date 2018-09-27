// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
// (representing land) connected 4-directionally (horizontal or vertical.) You
// may assume all four edges of the grid are surrounded by water.
//
// Count the number of distinct islands. An island is considered to be the same
// as another if and only if one island can be translated (and not rotated or
// reflected) to equal the other.
//
// Example 1:
// 11000
// 11000
// 00011
// 00011
// Given the above grid map, return 1.
// Example 2:
// 11011
// 10000
// 00001
// 11011
// Given the above grid map, return 3.
//
// Notice that:
// 11
// 1
// and
//  1
// 11
// are considered different island shapes, because we do not consider reflection
// / rotation. Note: The length of each dimension in the given grid does not
// exceed 50.

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }

        set<vector<pair<int, int>>> island;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    vector<pair<int, int>> temp;
                    dfs(grid, temp, i, j, i, j);
                    island.insert(temp);
                }
            }
        }

        return island.size();
    }

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& grid,
             vector<pair<int, int>>& temp,
             int start_i,
             int start_j,
             int i,
             int j) {
        grid[i][j] = 0;
        temp.push_back({i - start_i, j - start_j});
        for (auto d : dir) {
            int x = d[0] + i;
            int y = d[1] + j;
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()
                || grid[x][y] == 0) {
                continue;
            }
            dfs(grid, temp, start_i, start_j, x, y);
        }
    }
};
