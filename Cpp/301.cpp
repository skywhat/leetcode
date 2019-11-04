// Remove the minimum number of invalid parentheses in order to make the input
// string valid. Return all possible results.
//
// Note: The input string may contain letters other than the parentheses ( and
// ).
//
// Example 1:
//
// Input: "()())()"
// Output: ["()()()", "(())()"]
// Example 2:
//
// Input: "(a)())()"
// Output: ["(a)()()", "(a())()"]
// Example 3:
//
// Input: ")("
// Output: [""]

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    char pair[2] = {'(', ')'};
    char _pair[2] = {')', '('};
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        remove(s, 0, 0, pair, res);
        return res;
    }
    void remove(string s,
                int last_i,
                int last_j,
                char* pair,
                vector<string>& res) {
        int stack = 0;
        for (int i = last_i; i < s.size(); ++i) {
            if (s[i] == pair[0])
                stack++;
            else if (s[i] == pair[1])
                stack--;
            if (stack >= 0)
                continue;
            for (int j = last_j; j <= i; ++j) {
                if (s[j] == pair[1] && (j == last_j || (s[j - 1] != s[j]))) {
                    remove(s.substr(0, j) + s.substr(j + 1), i, j, pair, res);
                    // if you just want to get only one valid string, add break
                    // below. break;
                }
            }
            return;
        }
        reverse(s.begin(), s.end());
        if (pair[0] == '(')
            // still need to check the reversed string to make it legal
            remove(s, 0, 0, _pair, res);
        else
            res.push_back(s);
    }
};

// just need one valid string
class Solution2 {
public:
    char pair[2] = {'(', ')'};
    char _pair[2] = {')', '('};
    string removeInvalidParentheses(string s) {
        remove(s, 0, 0, pair);
        return s;
    }
    void remove(string& s, int last_i, int last_j, char* pair) {
        int stack = 0;
        for (int i = last_i; i < s.size(); ++i) {
            if (s[i] == pair[0])
                stack++;
            else if (s[i] == pair[1])
                stack--;
            if (stack >= 0)
                continue;
            for (int j = last_j; j <= i; ++j) {
                if (s[j] == pair[1] && (j == last_j || s[j - 1] != s[j])) {
                    s.erase(s.begin() + j);
                    remove(s, i, j, pair);
                    break;
                }
            }
            return;
        }
        reverse(s.begin(), s.end());
        if (pair[0] == '(')
            remove(s, 0, 0, _pair);
    }
};

int main() {
    string test = "(a)())()";
    Solution2 s;
    string res = s.removeInvalidParentheses(test);
    cout << res << endl;

    return 0;
}

/*
 Key Points:

 Generate unique answer once and only once, do not rely on Set.
 Do not need preprocess.
 Runtime 3 ms.
 Explanation:
 We all know how to check a string of parentheses is valid using a stack. Or
 even simpler use a counter. The counter will increase when it is ‘(‘ and
 decrease when it is ‘)’. Whenever the counter is negative, we have more ‘)’
 than ‘(‘ in the prefix.

 To make the prefix valid, we need to remove a ‘)’. The problem is: which one?
 The answer is any one in the prefix. However, if we remove any one, we will
 generate duplicate results, for example: s = ()), we can remove s[1] or s[2]
 but the result is the same (). Thus, we restrict ourself to remove the first )
 in a series of concecutive )s.

 After the removal, the prefix is then valid. We then call the function
 recursively to solve the rest of the string. However, we need to keep another
 information: the last removal position. If we do not have this position, we
 will generate duplicate by removing two ‘)’ in two steps only with a different
 order. For this, we keep tracking the last removal position and only remove ‘)’
 after that.

 Now one may ask. What about ‘(‘? What if s = ‘(()(()’ in which we need remove
 ‘(‘? The answer is: do the same from right to left. However a cleverer idea is:
 reverse the string and reuse the code!
 */
