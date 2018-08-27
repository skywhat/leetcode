#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (!obstacleGrid[i - 1][j - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};

class Solution2 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        for (auto& row : obstacleGrid) {
            for (auto& elem : row)
                if (elem == 1)
                    elem = -1;
        }
        if (obstacleGrid[0][0] == -1)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        obstacleGrid[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i - 1][0] == -1 || obstacleGrid[i][0] == -1)
                obstacleGrid[i][0] = -1;
            else
                obstacleGrid[i][0] = obstacleGrid[i - 1][0];
        }
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j - 1] == -1 || obstacleGrid[0][j] == -1)
                obstacleGrid[0][j] = -1;
            else
                obstacleGrid[0][j] = obstacleGrid[0][j - 1];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == -1)
                    continue;
                else {
                    obstacleGrid[i][j] = (obstacleGrid[i - 1][j] == -1
                                              ? 0
                                              : obstacleGrid[i - 1][j])
                                         + (obstacleGrid[i][j - 1] == -1
                                                ? 0
                                                : obstacleGrid[i][j - 1]);
                }
            }
        }
        return obstacleGrid[m - 1][n - 1] == -1 ? 0
                                                : obstacleGrid[m - 1][n - 1];
    }
};
