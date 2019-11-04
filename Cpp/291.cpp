/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter
in pattern and a non-empty substring in str.

Example 1:

Input: pattern = "abab", str = "redblueredblue"
Output: true
Example 2:

Input: pattern = pattern = "aaaa", str = "asdasdasdasd"
Output: true
Example 3:

Input: pattern = "aabb", str = "xyzabcxzyabc"
Output: false
Notes:
You may assume both pattern and str contains only lowercase letters.
*/

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        unordered_set<string> s;

        return match(pattern, str, 0, 0, m, s);
    }

    bool match(const string& pattern,
               const string& str,
               int i,
               int j,
               unordered_map<char, string>& m,
               unordered_set<string>& s) {
        int pat_size = pattern.size();
        int str_size = str.size();
        if (pat_size == i && str_size == j) {
            return true;
        } else if (pat_size == i || str_size == j) {
            return false;
        }

        char ch = pattern[i];
        if (m.count(ch)) {
            string nextstr = m[ch];
            if (str.substr(j, nextstr.size()) != nextstr) {
                return false;
            }
            return match(pattern, str, i + 1, j + nextstr.size(), m, s);
        }

        for (int k = j; k < str_size; ++k) {
            string nextstr = str.substr(j, k - j + 1);
            if (s.count(nextstr)) {
                continue;
            }
            m[ch] = nextstr;
            s.insert(nextstr);
            if (match(pattern, str, i + 1, k + 1, m, s)) {
                return true;
            }
            m.erase(ch);
            s.erase(nextstr);
        }

        return false;
    }
};
