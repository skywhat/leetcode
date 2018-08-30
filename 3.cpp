#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> m;
        int start = 0;
        int longest = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (m.count(s[i])) {
                start = max(start, m[s[i]] + 1);
            }
            m[s[i]] = i;
            longest = max(longest, i - start + 1);
        }

        return longest;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int start = 0, end = 0;
        int longest = 0;

        while (end < s.size()) {
            m[s[end]]++;
            while (m[s[end]] > 1) {
                if (end - start > longest) {
                    longest = end - start;
                }
                m[s[start]]--;
                start++;
            }
            end++;
        }

        return max(longest, end - start);
    }
};

class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(128, -1);
        int start = -1, end = 0;
        int longest = 0;

        for (int i = 0; i < s.size(); ++i) {
            // we find one character appear again which already within the gap
            // from start to i, update start
            if (pos[s[i]] > start) {
                start = pos[s[i]];
            }
            pos[s[i]] = i;
            longest = max(longest, i - start);
        }

        return longest;
    }
};

int main() {
    string testcase = "abcabcbb";
    string testcase1 = "dvdf";
    Solution s;
    cout << s.lengthOfLongestSubstring(testcase) << endl;

    return 0;
}
/*
 *        d     v     d     f
 *  -1    0     1     2     3
 *
 *  start i
 *
 *
 *        d     v     d     f
 *  -1    0     1     2     3
 *
 *  start       i
 *
 *
 *        d     v     d     f
 *  -1    0     1     2     3
 *
 *  start             i
 *(when d appear again, start should be in previous d position.)
 *
 *
 *        d     v     d     f
 *  -1    0     1     2     3
 *
 *      start         i
 *
 *
 *        d     v     d     f
 *  -1    0     1     2     3
 *
 *       start              i
 */
