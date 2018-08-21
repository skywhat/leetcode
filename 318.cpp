/*

Given a string array words, find the maximum value of length(word[i]) *
length(word[j]) where the two words do not share common letters. You may assume
that each word will contain only lower case letters. If no such two words exist,
return 0.

Example 1:

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
Example 3:

Input: ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> distinct(n, 0);
        for (int i = 0; i < words.size(); ++i) {
            for (auto c : words[i]) {
                distinct[i] |= 1 << (c - 'a');
            }
        }

        int max_product = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if ((distinct[i] & distinct[j]) == 0) {
                    max_product = max(max_product,
                                      int(words[i].size() * words[j].size()));
                }
            }
        }

        return max_product;
    }
};

int main() {
    vector<string> test = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    Solution s;
    cout << s.maxProduct(test) << endl;
    return 0;
}
