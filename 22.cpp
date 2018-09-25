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

class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", 0, 0, n);
        return res;
    }

    void generate(vector<string>& res, string s, int left, int right, int n) {
        if (left > n || left < right) {
            return;
        }

        if (right == n) {
            res.push_back(s);
            return;
        }

        generate(res, s + "(", left + 1, right, n);
        generate(res, s + ")", left, right + 1, n);
    }
};
