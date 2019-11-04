// Given a string S, check if the letters can be rearranged so that two
// characters that are adjacent to each other are not the same.
//
// If possible, output any possible result.  If not possible, return the empty
// string.
//
// Example 1:
//
// Input: S = "aab"
// Output: "aba"
// Example 2:
//
// Input: S = "aaab"
// Output: ""
// Note:
//
// S will consist of lowercase letters and have length in range [1, 500].

class Solution {
public:
    struct comp {
        bool operator()(pair<char, int>& l, pair<char, int>& r) {
            return l.second < r.second;
        }
    };

    string reorganizeString(string S) {
        unordered_map<char, int> dict;
        for (auto c : S) {
            if (++dict[c] > (S.size() + 1) / 2) {
                return "";
            }
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> q;
        for (auto item : dict) {
            q.push({item.first, item.second});
        }

        string res;
        while (!q.empty()) {
            if (q.size() == 1) {
                if (q.top().second > 1) {
                    return "";
                }
                return res + q.top().first;
            }
            auto one = q.top();
            q.pop();
            auto two = q.top();
            q.pop();
            res += string(1, one.first) + string(1, two.first);
            if (--one.second) {
                q.push(one);
            }
            if (--two.second) {
                q.push(two);
            }
        }

        return res;
    }
};
