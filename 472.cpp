// Given a list of words (without duplicates), please write a program that
// returns all concatenated words in the given list of words. A concatenated
// word is defined as a string that is comprised entirely of at least two
// shorter words in the given array.
//
// Example:
// Input:
// ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
//
// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
//
// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
//  "dogcatsdog" can be concatenated by "dog", "cats" and "dog";
// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
// Note:
// The number of elements of the given array will not exceed 10,000
// The length sum of elements in the given array will not exceed 600,000.
// All the input string will only include lower case letters.
// The returned elements order does not matter.

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> words_set(words.begin(), words.end());
        vector<string> res;

        for (int k = 0; k < words.size(); ++k) {
            int n = words[k].size();
            vector<int> dp(n + 1, 0);
            dp[0] = 1;

            for (int i = 1; i <= n; ++i) {
                for (int j = i - 1; j >= 0; --j) {
                    if (dp[j]) {
                        if (i - j < n
                            && words_set.count(words[k].substr(j, i - j))) {
                            dp[i] = 1;
                            break;
                        }
                    }
                }
            }

            if (n != 0 && dp[n]) {
                res.push_back(words[k]);
            }
        }

        return res;
    }
};
