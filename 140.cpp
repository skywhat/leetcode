/*
Given a non-empty string s and a dictionary wordDict containing a list of
non-empty words, add spaces in s to construct a sentence where each word is a
valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the
segmentation. You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/

class Solution {
private:
    unordered_set<string> words;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        words.clear();
        copy(wordDict.begin(), wordDict.end(), inserter(words, words.end()));

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j]) {
                    if (words.count(s.substr(j, i - j))) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }

        vector<string> res;
        if (dp[n]) {
            constructSentence(s, dp, 0, res, "");
        }
        return res;
    }

    void constructSentence(const string& s,
                           const vector<int>& dp,
                           int pos,
                           vector<string>& res,
                           string temp) {
        for (int i = pos + 1; i < dp.size(); ++i) {
            if (dp[i]) {
                string new_word = s.substr(pos, i - pos);
                if (words.count(new_word)) {
                    if (i + 1 == dp.size()) {
                        res.push_back(temp + new_word);
                        return;
                    }
                    constructSentence(s, dp, i, res, temp + new_word + " ");
                }
            }
        }
    }
};
