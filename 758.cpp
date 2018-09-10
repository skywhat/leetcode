// Given a set of keywords words and a string S, make all appearances of all
// keywords in S bold. Any letters between <b> and </b> tags become bold.
//
// The returned string should use the least number of tags possible, and of
// course the tags should form a valid combination.
//
// For example, given that words = ["ab", "bc"] and S = "aabcd", we should
// return "a<b>abc</b>d". Note that returning "a<b>a<b>b</b>c</b>d" would use
// more tags, so it is incorrect.
//
// Note:
//
// words has length in range [0, 50].
// words[i] has length in range [1, 10].
// S has length in range [0, 500].
// All characters in words[i] and S are lowercase letters.

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int len = S.size();
        vector<bool> bold(len, false);
        for (auto w : words) {
            int start = S.find(w, 0);
            while (start != string::npos) {
                for (int i = 0; i < w.size(); ++i) {
                    bold[i + start] = true;
                }
                start = S.find(w, start + 1);
            }
        }

        string res;
        int i = 0;
        while (i < len) {
            if (bold[i]) {
                res += "<b>";
                while (i < len && bold[i]) {
                    res += S[i++];
                }
                res += "</b>";
            }
            if (i < len) {
                res += S[i++];
            }
        }

        return res;
    }
};
