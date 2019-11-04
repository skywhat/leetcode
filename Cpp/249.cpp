// Given a string, we can "shift" each of its letter to its successive letter,
// for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
//
// "abc" -> "bcd" -> ... -> "xyz"
// Given a list of strings which contains only lowercase alphabets, group all
// strings that belong to the same shifting sequence.
//
// Example:
//
// Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
// Output:
// [
//   ["abc","bcd","xyz"],
//   ["az","ba"],
//   ["acef"],
//   ["a","z"]
// ]

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        for (auto&& s : strings) {
            m[fingerPrint(s)].push_back(s);
        }

        for (auto m_list : m) {
            sort(m_list.second.begin(), m_list.second.end());
            res.push_back(m_list.second);
        }

        return res;
    }

    string fingerPrint(const string& s) {
        string res;
        for (int i = 1; i < s.size(); ++i) {
            int gap = s[i] - s[i - 1];
            if (gap < 0) {
                gap += 26;
            }
            res += string(1, 'a' + gap);
        }
        return res;
    }
};

/*
az 25
ba -1
*/
