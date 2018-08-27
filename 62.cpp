#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) {
            return uniquePaths(n, m);
        }

        vector<int> cur(m, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                cur[j] += cur[j - 1];
            }
        }

        return cur[m - 1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, 1));

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
};

int main() {
    int m = 3, n = 4;
    Solution s;
    cout << s.uniquePaths(m, n) << endl;

    return 0;
}
