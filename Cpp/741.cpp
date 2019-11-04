// In a N x N grid representing a field of cherries, each cell is one of three
// possible integers.
//
// 0 means the cell is empty, so you can pass through;
// 1 means the cell contains a cherry, that you can pick up and pass through;
// -1 means the cell contains a thorn that blocks your way.
// Your task is to collect maximum number of cherries possible by following the
// rules below:
//
// Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or
// down through valid path cells (cells with value 0 or 1); After reaching (N-1,
// N-1), returning to (0, 0) by moving left or up through valid path cells; When
// passing through a path cell containing a cherry, you pick it up and the cell
// becomes an empty cell (0); If there is no valid path between (0, 0) and (N-1,
// N-1), then no cherries can be collected. Example 1: Input: grid =
// [[0, 1, -1],
//  [1, 0, -1],
//  [1, 1,  1]]
// Output: 5
// Explanation:
// The player started at (0, 0) and went down, down, right right to reach (2,
// 2). 4 cherries were picked up during this single trip, and the matrix becomes
// [[0,1,-1],[0,0,-1],[0,0,0]]. Then, the player went left, up, up, left to
// return home, picking up one more cherry. The total number of cherries picked
// up is 5, and this is the maximum possible. Note:
//
// grid is an N by N 2D array, with 1 <= N <= 50.
// Each grid[i][j] is an integer in the set {-1, 0, 1}.
// It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        int step = 2 * n - 2;
        vector<vector<vector<int>>> dp(step + 1,
                                       vector<vector<int>>(n,
                                                           vector<int>(n, -1)));
        dp[0][0][0] = grid[0][0];

        for (int p = 1; p <= step; ++p) {
            for (int i = 0; i <= p && i < n; ++i) {
                for (int j = i; j <= p && j < n; ++j) {
                    int yi = p - i;
                    int yj = p - j;
                    if (yi >= n || yj >= n) {
                        continue;
                    }
                    if (grid[i][yi] == -1 || grid[j][yj] == -1) {
                        continue;
                    }

                    int max_val = dp[p - 1][i][j];

                    if (i > 0 && j > 0) {
                        max_val = max(max_val, dp[p - 1][i - 1][j - 1]);
                    }

                    if (i != j && j > 0) {
                        max_val = max(max_val, dp[p - 1][i][j - 1]);
                    }

                    if (i > 0) {
                        max_val = max(max_val, dp[p - 1][i - 1][j]);
                    }

                    if (max_val == -1) {
                        continue;
                    }

                    if (i == j) {
                        dp[p][i][j] = max_val + grid[i][yi];
                    } else {
                        dp[p][i][j] = max_val + grid[i][yi] + grid[j][yj];
                    }
                }
            }
        }

        return dp[step][n - 1][n - 1] == -1 ? 0 : dp[step][n - 1][n - 1];
    }
};

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        int step = 2 * n - 2;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0] = grid[0][0];

        for (int p = 1; p <= step; ++p) {
            vector<vector<int>> cur(n, vector<int>(n, -1));
            for (int i = 0; i <= p && i < n; ++i) {
                for (int j = i; j <= p && j < n; ++j) {
                    int yi = p - i;
                    int yj = p - j;
                    if (yi >= n || yj >= n) {
                        continue;
                    }
                    if (grid[i][yi] == -1 || grid[j][yj] == -1) {
                        continue;
                    }

                    int max_val = dp[i][j];

                    if (i > 0 && j > 0) {
                        max_val = max(max_val, dp[i - 1][j - 1]);
                    }

                    if (i != j && j > 0) {
                        max_val = max(max_val, dp[i][j - 1]);
                    }

                    if (i > 0) {
                        max_val = max(max_val, dp[i - 1][j]);
                    }

                    if (max_val == -1) {
                        continue;
                    }

                    if (i == j) {
                        cur[i][j] = max_val + grid[i][yi];
                    } else {
                        cur[i][j] = max_val + grid[i][yi] + grid[j][yj];
                    }
                }
            }
            dp = move(cur);
        }

        return dp[n - 1][n - 1] == -1 ? 0 : dp[n - 1][n - 1];
    }
};
