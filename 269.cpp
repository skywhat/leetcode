// There is a new alien language which uses the latin alphabet. However, the
// order among letters are unknown to you. You receive a list of non-empty words
// from the dictionary, where words are sorted lexicographically by the rules of
// this new language. Derive the order of letters in this language.
//
// Example 1:
//
// Input:
// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
//
// Output: "wertf"
// Example 2:
//
// Input:
// [
//   "z",
//   "x"
// ]
//
// Output: "zx"
// Example 3:
//
// Input:
// [
//   "z",
//   "x",
//   "z"
// ]
//
// Output: ""
//
// Explanation: The order is invalid, so return "".
// Note:
//
// You may assume all letters are in lowercase.
// You may assume that if a is a prefix of b, then a must appear before b in the
// given dictionary. If the order is invalid, return an empty string. There may
// be multiple valid order of letters, return any one of them is fine.

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> suc, prev;
        unordered_set<char> all;

        string s;
        for (auto w : words) {
            all.insert(w.begin(), w.end());
            for (int i = 0; i < min(s.size(), w.size()); ++i) {
                if (s[i] != w[i]) {
                    suc[s[i]].insert(w[i]);
                    prev[w[i]].insert(s[i]);
                    break;
                }
            }
            s = w;
        }

        int sum = all.size();
        for (auto p : prev) {
            all.erase(p.first);
        }

        string res;
        while (all.size()) {
            int x = *all.begin();
            all.erase(x);
            res += x;
            for (auto next : suc[x]) {
                prev[next].erase(x);
                if (prev[next].empty()) {
                    all.insert(next);
                }
            }
        }

        return sum == res.size() ? res : "";
    }
};
