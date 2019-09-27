// Given a string s and a list of strings dict, you need to add a closed pair of
// bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two
// such substrings overlap, you need to wrap them together by only one pair of
// closed bold tag. Also, if two substrings wrapped by bold tags are
// consecutive, you need to combine them. Example 1: Input: s = "abcxyz123" dict
// = ["abc","123"] Output:
// "<b>abc</b>xyz<b>123</b>"
// Example 2:
// Input:
// s = "aaabbcc"
// dict = ["aaa","aab","bc"]
// Output:
// "<b>aaabbc</b>c"
// Note:
// The given dict won't contain duplicates, and its length won't exceed 100.
// All the strings in input have length in range [1, 1000].

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int len = s.size();
        vector<bool> bold(len, false);
        for (auto w : dict) {
            int start = s.find(w, 0);
            while (start != string::npos) {
                for (int i = 0; i < w.size(); ++i) {
                    bold[i + start] = true;
                }
                start = s.find(w, start + 1);
            }
        }

        string res;
        int i = 0;
        while (i < len) {
            if (bold[i]) {
                res += "<b>";
                while (i < len && bold[i]) {
                    res += s[i++];
                }
                res += "</b>";
            }
            if (i < len) {
                res += s[i++];
            }
        }

        return res;
    }
};
