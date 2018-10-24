// Given two strings S and T, return if they are equal when both are typed into
// empty text editors. # means a backspace character.
//
// Example 1:
//
// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
// Example 2:
//
// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
// Example 3:
//
// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
// Example 4:
//
// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
// Note:
//
// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.
// Follow up:
//
// Can you solve it in O(N) time and O(1) space?

class Solution {
    class Solution {
    public:
        bool backspaceCompare(string S, string T) {
            return decode(S) == decode(T);
        }

        string decode(string s) {
            string res;

            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '#') {
                    if (!res.empty()) {
                        res.pop_back();
                    }
                } else {
                    res += s[i];
                }
            }

            return res;
        }
    }
};

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int m = S.size() - 1, n = T.size() - 1;
        while (1) {
            int skip1 = 0, skip2 = 0;
            while (m >= 0) {
                if (S[m] == '#') {
                    m--;
                    skip1++;
                } else if (skip1 > 0) {
                    m--;
                    skip1--;
                } else {
                    break;
                }
            }

            while (n >= 0) {
                if (T[n] == '#') {
                    n--;
                    skip2++;
                } else if (skip2 > 0) {
                    n--;
                    skip2--;
                } else {
                    break;
                }
            }

            if (m >= 0 && n >= 0) {
                if (S[m] != T[n]) {
                    return false;
                }
                m--;
                n--;
            } else {
                return m == -1 && n == -1;
            }
        }
    }
};
