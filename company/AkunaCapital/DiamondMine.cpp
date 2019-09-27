#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int collect_max(vector<vector<int>> mat) {
        int n = mat.size();
        int p = n * 2 - 2;
        vector<vector<vector<int>>> dp(2 * n,
                                       vector<vector<int>>(n,
                                                           vector<int>(n, 0)));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                dp[0][i][j] = INT_MIN;
            }
        }

        dp[0][0][0] = mat[0][0];

        for (int step = 1; step <= p; ++step) {
            for (int i = 0; i < n; ++i) {
                for (int j = i; j < n; ++j) {
                    dp[step][i][j] = INT_MIN;
                    if (!isValid(step, i, j, n))
                        continue;
                    if (mat[i][step - i] == -1 || mat[j][step - j] == -1) {
                        dp[step][i][j] = INT_MIN;
                        continue;
                    }
                    if (i != j) {
                        dp[step][i][j]
                            = max(dp[step][i][j],
                                  getValue(step - 1, i - 1, j, n, dp));
                        dp[step][i][j]
                            = max(dp[step][i][j],
                                  getValue(step - 1, i - 1, j - 1, n, dp));
                        dp[step][i][j]
                            = max(dp[step][i][j],
                                  getValue(step - 1, i, j - 1, n, dp));
                        dp[step][i][j] = max(dp[step][i][j],
                                             getValue(step - 1, i, j, n, dp));
                        dp[step][i][j] += mat[i][step - i] + mat[j][step - j];
                    } else {
                        dp[step][i][j]
                            = max(dp[step][i][j],
                                  getValue(step - 1, i - 1, j, n, dp));
                        dp[step][i][j]
                            = max(dp[step][i][j],
                                  getValue(step - 1, i - 1, j - 1, n, dp));
                        dp[step][i][j] = max(dp[step][i][j],
                                             getValue(step - 1, i, j, n, dp));
                        dp[step][i][j] += mat[i][step - i];
                    }
                }
            }
        }
        return dp[p][n - 1][n - 1] == INT_MIN ? 0 : dp[p][n - 1][n - 1];
    }

    bool isValid(int step, int x1, int x2, int n) {
        int y1 = step - x1, y2 = step - x2;
        return x1 >= 0 && x1 < n && x2 >= 0 && x2 < n && y1 >= 0 && y1 < n
               && y2 >= 0 && y2 < n;
    }

    int getValue(int step,
                 int x1,
                 int x2,
                 int n,
                 vector<vector<vector<int>>>& dp) {
        return isValid(step, x1, x2, n) ? dp[step][x1][x2] : INT_MIN;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {
		{0, 1, 1},
		{1, 0, 1},
		{1, 1, 1}
	};

    vector<vector<int>> mat2 = {
		{0, 1, -1},
		{1, 0, -1},
		{1, 1, 1}
	};

    vector<vector<int>> mat3 = {
		{0, 1, 1},
		{1, 0, -1},
		{1, 1, -1}
	};

	vector<vector<int>> mat4 = {
		{1, 1, -1},
		{1, -1, 1},
		{-1, 1, 1},
	};

    cout << s.collect_max(mat4) << endl;

    return 0;
}
