// Given a string containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.
//
// An input string is valid if:
//
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.
//
// Example 1:
//
// Input: "()"
// Output: true
// Example 2:
//
// Input: "()[]{}"
// Output: true
// Example 3:
//
// Input: "(]"
// Output: false
// Example 4:
//
// Input: "([)]"
// Output: false
// Example 5:
//
// Input: "{[]}"
// Output: true


#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    return false;
                }
                st.pop();
            } else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    return false;
                }
                st.pop();
            } else if (c == '}') {
                if (st.empty() || st.top() != '{') {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};

int main() {}
