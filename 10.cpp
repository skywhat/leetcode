#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
        if (p[1] == '*') {
            return isMatch(s, p.substr(2))
                   || !s.empty() && (s[0] == p[0] || p[0] == '.')
                          && isMatch(s.substr(1), p);
        } else
            return !s.empty() && (s[0] == p[0] || p[0] == '.')
                   && isMatch(s.substr(1), p.substr(1));
    }
};

class Solution2 {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j > 1 && p[j - 1] == '*' && dp[0][j - 2];
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] != '*') {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                               && dp[i - 1][j - 1];
                } else {
                    if (j > 1) {
                        dp[i][j] = dp[i][j - 2]
                                   || (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                                          && dp[i - 1][j];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};

int main() {}
