// Given a list of unique words, find all pairs of distinct indices (i, j) in
// the given list, so that the concatenation of the two words, i.e. words[i] +
// words[j] is a palindrome.
//
// Example 1:
//
// Input: ["abcd","dcba","lls","s","sssll"]
// Output: [[0,1],[1,0],[3,2],[2,4]]
// Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
// Example 2:
//
// Input: ["bat","tab","cat"]
// Output: [[0,1],[1,0]]
// Explanation: The palindromes are ["battab","tabbat"]

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); ++i) {
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            m[temp] = i;
        }

        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);

                // left|right + word2
                if (m.count(left) && isPalindrome(right) && m[left] != i) {
                    res.push_back({i, m[left]});
                }

                // word2 + left|right
                if (m.count(right) && isPalindrome(left) && m[right] != i
                    && left != "") {
                    res.push_back({m[right], i});
                }
            }
        }

        return res;
    }

    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};
//
// We have to deal with duplicated pairs generated in the loop: So when this will happen?
// Assuming two words: 0: abc vs. 1: cba
// // 0: abc|null + cba : {0, 1} pair
// // 1: abc + null|cba : {0,1} pair again
// So we only count once when middle part is null to avoid duplicated pairs.
