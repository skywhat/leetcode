// Given a string s , find the length of the longest substring t  that contains
// at most 2 distinct characters.
//
// Example 1:
//
// Input: "eceba"
// Output: 3
// Explanation: t is "ece" which its length is 3.
// Example 2:
//
// Input: "ccaabbb"
// Output: 5
// Explanation: t is "aabbb" which its length is 5.

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int max_cnt = 0;
        int cnt = 0;
        vector<int> m(128, 0);

        for (int i = 0, j = -1; i < s.size(); ++i) {
            cnt += m[s[i]] == 0;
            m[s[i]]++;
            while (cnt > 2) {
                j++;
                m[s[j]]--;
                cnt -= m[s[j]] == 0;
            }
            max_cnt = max(max_cnt, i - j);
        }

        return max_cnt;
    }
};
