// Given a string s, return all the palindromic permutations (without
// duplicates) of it. Return an empty list if no palindromic permutation could
// be form.
//
// Example 1:
//
// Input: "aabb"
// Output: ["abba", "baab"]
// Example 2:
//
// Input: "abc"
// Output: []

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        map<char, int> dict;
        for (auto c : s) {
            dict[c]++;
        }

        int odd = 0;
        char odd_char;
        string half;

        for (auto item : dict) {
            if (item.second & 1) {
                if (++odd > 1) {
                    return {};
                }
                odd_char = item.first;
            }
            half += string(item.second / 2, item.first);
        }

        vector<string> all = permutation(half);
        vector<string> res;
        for (auto s : all) {
            string next(s.rbegin(), s.rend());
            res.push_back(s + (odd ? string(1, odd_char) : "") + next);
        }

        return res;
    }

    vector<string> permutation(string s) {
        vector<string> res = {s};
        while (next_permutation(s.begin(), s.end())) {
            res.push_back(s);
        }

        return res;
    }
};
