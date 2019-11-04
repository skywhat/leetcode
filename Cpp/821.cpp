// Given a string S and a character C, return an array of integers representing
// the shortest distance from the character C in the string.
//
// Example 1:
//
// Input: S = "loveleetcode", C = 'e'
// Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
//
//
// Note:
//
// S string length is in [1, 10000].
// C is a single character, and guaranteed to be in string S.
// All letters in S and C are lowercase.

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> res(n, n); // n is the maximum distance we could have
        int pos = -n;
        for (int i = 0; i < n; ++i) {
            if (S[i] == C) {
                pos = i;
            }
            res[i] = min(res[i], i - pos);
        }

        pos = 2 * n;
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] == C) {
                pos = i;
            }
            res[i] = min(res[i], pos - i);
        }

        return res;
    }
};

class Solution2 {
public:
    vector<int> shortestToChar(string S, char C) {
        set<int> collect;
        int pos = S.find(C);
        while (pos != string::npos) {
            collect.insert(pos);
            pos = S.find(C, pos + 1);
        }

        int n = S.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            if (S[i] != C) {
                int min_dist = n;
                for (auto pos : collect) {
                    min_dist = min(min_dist, abs(pos - i));
                }
                res[i] = min_dist;
            }
        }

        return res;
    }
};
