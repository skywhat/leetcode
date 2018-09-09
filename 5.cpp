#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int maxLen = 0;

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i <= j; ++i) {
                dp[i][j]
                    = (s[i] == s[j]) && (i + 1 >= j - 1 ? 1 : dp[i + 1][j - 1]);

                if (dp[i][j] && (maxLen <= j - i + 1)) {
                    maxLen = j - i + 1;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    Solution s;
    string test = "babad";
    cout << s.longestPalindrome(test) << endl;

    return 0;
}
