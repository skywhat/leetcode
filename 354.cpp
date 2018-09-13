// You have a number of envelopes with widths and heights given as a pair of
// integers (w, h). One envelope can fit into another if and only if both the
// width and height of one envelope is greater than the width and height of the
// other envelope.
//
// What is the maximum number of envelopes can you Russian doll? (put one inside
// other)
//
// Note:
// Rotation is not allowed.
//
// Example:
//
// Input: [[5,4],[6,4],[6,7],[2,3]]
// Output: 3
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3]
// => [5,4] => [6,7]).

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [](pair<int, int> i, pair<int, int> j) {
                 return (i.first < j.first)
                        || (i.first == j.first && i.second < j.second);
             });

        int n = envelopes.size();
        vector<int> dp(n, 1);
        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j].first < envelopes[i].first
                    && envelopes[j].second < envelopes[i].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_len = max(max_len, dp[i]);
        }

        return max_len;
    }
};
