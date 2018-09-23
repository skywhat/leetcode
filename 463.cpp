#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) {
            return 0;
        }
        int n = grid[0].size();

        int brick = 0;
        int seam = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    brick++;
                    for (auto d : dir) {
                        int x = i + d[0];
                        int y = j + d[1];
                        if (x < 0 || x >= m || y < 0 || y >= n) {
                            continue;
                        }
                        if (grid[x][y]) {
                            seam++;
                        }
                    }
                }
            }
        }

        return brick * 4 - seam;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
    };

    int expect = 16;
    Solution s;
    cout << (s.islandPerimeter(grid) == expect) << endl;

    return 0;
}
