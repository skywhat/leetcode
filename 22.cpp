/*
Given n pairs of parentheses, write a function to generate all combinations of
well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, n, n, "");
        return res;
    }

    void generate(vector<string>& res, int left, int right, string c) {
        if (left == 0 && right == 0) {
            res.push_back(c);
            return;
        }

        if (left < right) {
            generate(res, left, right - 1, c + ')');
        }

        if (left) {
            generate(res, left - 1, right, c + '(');
        }
    }
};
