class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_val = 0;
        for (auto n : nums) {
            max_val = max(max_val, n);
        }

        vector<int> dp(max_val + 1, 0);
        for (auto n : nums) {
            dp[n] += n;
        }

        for (int i = 2; i <= max_val; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + dp[i]);
        }

        return dp[max_val];
    }
};

/*
another solution:
https://github.com/skywhat/leetcode/blob/master/company/AkunaCapital/DeleteAndEarn.cpp
*/
