// Given two strings s and t, determine if they are both one edit distance
// apart.
//
// Note:
//
// There are 3 possiblities to satisify one edit distance apart:
//
// Insert a character into s to get t
// Delete a character from s to get t
// Replace a character of s to get t
// Example 1:
//
// Input: s = "ab", t = "acb"
// Output: true
// Explanation: We can insert 'c' into s to get t.
// Example 2:
//
// Input: s = "cab", t = "ad"
// Output: false
// Explanation: We cannot get t from s by only one step.
// Example 3:
//
// Input: s = "1203", t = "1213"
// Output: true
// Explanation: We can replace '0' with '1' to get t.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size() - 1;
        int n = t.size() - 1;
        if (m < n) {
            return isOneEditDistance(t, s);
        }

        if (s == t || (m - n) > 1) {
            return false;
        }
        int i = 0, j = 0;

        while (i <= m && j <= n) {
            if (s[i] != t[j]) {
                return m == n ? isSame(s, i + 1, t, j + 1)
                              : isSame(s, i + 1, t, j);
            }
            i++;
            j++;
        }

        return true;
    }

    bool isSame(string s, int i, string t, int j) {
        while (i < s.size() && j < t.size()) {
            if (s[i++] != t[j++]) {
                return false;
            }
        }
        return i == s.size() && j == t.size();
    }
};
/*
 teach
 teacher
 i
 j
 */

int main() {
    string t1 = "teacher";
    string t2 = "teach";

    Solution s;
    cout << s.isOneEditDistance(t1, t2) << endl;

    return 0;
}
