// Write a function to find the longest common prefix string amongst an array of
// strings.
//
// If there is no common prefix, return an empty string "".
//
// Example 1:
//
// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:
//
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// Note:
//
// All given inputs are in lowercase letters a-z.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (!n) {
            return "";
        }

        for (int k = 0; k < strs[0].size(); ++k) {
            for (int i = 1; i < n; ++i) {
                if (strs[i][k] != strs[0][k]) {
                    return strs[0].substr(0, k);
                }
            }
        }

        return strs[0];
    }
};
