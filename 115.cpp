// Given a string S and a string T, count the number of distinct subsequences of
// S which equals T.
//
// A subsequence of a string is a new string which is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters. (ie, "ACE" is a
// subsequence of "ABCDE" while "AEC" is not).
//
// Example 1:
//
// Input: S = "rabbbit", T = "rabbit"
// Output: 3
// Explanation:
//
// As shown below, there are 3 ways you can generate "rabbit" from S.
// (The caret symbol ^ means the chosen letters)
//
// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
// Example 2:
//
// Input: S = "babgbag", T = "bag"
// Output: 5
// Explanation:
//
// As shown below, there are 5 ways you can generate "bag" from S.
// (The caret symbol ^ means the chosen letters)
//
// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m < n) {
            return 0;
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= m; ++i) {
                dp[i][j] = dp[i - 1][j]
                           + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }

        return dp[m][n];
    }
};

// if s[i-1] != t[j-1]
// the distinct subsequences wouldn not include s[i-1], so all distinct
// subsequences come from s[0....i-2] dp[i][j] = dp[i-1][j]
//
// if s[i-1] == t[j-1]
// we have two options, the subsequences include s[i-1] or not
// if include, then dp[i-1][j-1]
// if not include, then dp[i-1][j]
// so dp[i][j] = dp[i-1][j-1]+dp[i-1][j]

//         r a b i t
//       0 1 2 3 4 5
// ------------------
//   0 | 1 0 0 0 0 0
// r 1 | 1 1 0 0 0 0
// a 2 | 1 1 1 0 0 0
// b 3 | 1 1 1 1 0 0
// b 4 | 1 1 1 2 0 0
// b 5 | 1 1 1 3 0 0
// i 6 | 1 1 1 3 3 0
// t 7 | 1 1 1 3 3 3
