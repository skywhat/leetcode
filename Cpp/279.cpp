// Given a positive integer n, find the least number of perfect square numbers
// (for example, 1, 4, 9, 16, ...) which sum to n.
//
// Example 1:
//
// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:
//
// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};

class Solution2 {
public:
    vector<int> dp = {0};

    int numSquares(int n) {
        while (dp.size() <= n) {
            int min_cnt = INT_MAX;
            int cur = dp.size();
            for (int j = 1; j * j <= cur; ++j) {
                min_cnt = min(min_cnt, dp[cur - j * j] + 1);
            }
            dp.push_back(min_cnt);
        }

        return dp[n];
    }
};
