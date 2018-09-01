// Given an array of scores that are non-negative integers. Player 1 picks one
// of the numbers from either end of the array followed by the player 2 and then
// player 1 and so on. Each time a player picks a number, that number will not
// be available for the next player. This continues until all the scores have
// been chosen. The player with the maximum score wins.
//
// Given an array of scores, predict whether player 1 is the winner. You can
// assume each player plays to maximize his score.
//
// Example 1:
// Input: [1, 5, 2]
// Output: False
// Explanation: Initially, player 1 can choose between 1 and 2.
// If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If
// player 2 chooses 5, then player 1 will be left with 1 (or 2). So, final score
// of player 1 is 1 + 2 = 3, and player 2 is 5. Hence, player 1 will never be
// the winner and you need to return False. Example 2: Input: [1, 5, 233, 7]
// Output: True
// Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5
// and 7. No matter which number player 2 choose, player 1 can choose 233.
// Finally, player 1 has more score (234) than player 2 (12), so you need to
// return True representing player1 can win. Note: 1 <= length of the array
// <= 20. Any scores in the given array are non-negative integers and will not
// exceed 10,000,000. If the scores of both players are equal, then player 1 is
// still the winner.

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n % 2 == 0) {
            return true;
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
            sum += nums[i];
        }

        for (int j = 0; j < n; ++j) {
            for (int i = j - 1; i >= 0; --i) {
                // we need to find max(dp[i+1][j]+nums[i], dp[i][j-1]+nums[j])
                // min(dp[i+2][j], dp[i+1][j-1])   min(dp[i+1][j-1], dp[i][j-2])
                int a = i + 1 < n && j - 1 >= 0 ? dp[i + 1][j - 1] : 0;
                int b = i + 2 < n ? dp[i + 2][j] : 0;
                int c = j - 2 < n ? dp[i][j - 2] : 0;
                dp[i][j] = max(min(a, b) + nums[i], min(a, c) + nums[j]);
            }
        }

        return dp[0][n - 1] * 2 >= sum;
    }
};

// The goal is maximize the sum of first player.
//
// We have a numeric array from 0 ~ n, i and j is the index. dp[i][j] means the
// max sum we can get if the array starts from i and ends to j.
//
// So dp[i][i] means only one coin and we pick firstly, dp[i][i+1] means there
// are two coins, we pick the larger one.
//
// To maximum our gain, dp[i][j] = max( nums[i] + dp[i + 1][j], dp[i][j - 1] +
// nums[j]), since we either will pick the i or j coin. But here dp[i + 1][j]
// and dp[i][j - 1] are not the values directly available for us, it depends on
// the move that our opponent make.
//
// Then we assume our opponent is as good as we are and always makes optimize
// move. The worse case is that we will get the minimal value out of all
// possible situation after our opponent makes its move.
//
// So the correct dp formula would be
// dp[i][j] = max( min (dp[i + 1][j - 1], dp[i + 2][ j]) + v[i], min (dp[i][j -
// 2], dp[i + 1][ j - 1]) + v[j]}) . If we pick i, then our opponent need to
// deal with subproblem dp[i + 1][j], it either picks from i + 2 or j - 1.
// Similarly, If we pick j, then our opponent need to deal with subproblem
// dp[i][j - 1] , it either pick from i + 1 or j - 2. We take the worse case
// into consideration so use min() here.
