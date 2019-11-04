// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string may contain open ( and closing parentheses ), the plus
// + or minus sign -, non-negative integers and empty spaces .
//
// Example 1:
//
// Input: "1 + 1"
// Output: 2
// Example 2:
//
// Input: " 2-1 + 2 "
// Output: 3
// Example 3:
//
// Input: "(1+(4+5+2)-3)+(6+8)"
// Output: 23
// Note:
// You may assume that the given expression is always valid.
// Do not use the eval built-in library function.

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> signs;
        stack<int> numbers;
        int res = 0;
        int n = 0;
        int si = 1;

        for (auto c : s) {
            if (isdigit(c)) {
                n = n * 10 + c - '0';
            } else {
                res += si * n;
                n = 0;
                if (c == '+') {
                    si = 1;
                } else if (c == '-') {
                    si = -1;
                } else if (c == '(') {
                    numbers.push(res);
                    res = 0;
                    signs.push(si);
                    si = 1;
                } else if (c == ')') {
                    res = numbers.top() + signs.top() * res;
                    numbers.pop();
                    signs.pop();
                }
            }
        }

        return res + si * n;
    }
};

/*
 1-(2-(1+2))
 1 2
 - -
 res=-1
 1+-(-1)
 2

 */

int main() {}
