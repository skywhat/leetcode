// Given two words word1 and word2, find the minimum number of steps required to
// make word1 and word2 the same, where in each step you can delete one
// character in either string.
//
// Example 1:
// Input: "sea", "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make
// "eat" to "ea". Note: The length of given words won't exceed 500. Characters
// in given words can only be lower-case letters.

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return m + n - 2 * dp[m][n];
    }
};
