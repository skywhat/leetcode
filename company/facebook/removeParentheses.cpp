/*
 *remove invalid Parentheses just return the longest one in linear time
 */

#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string remove(string s) {
        stack<char> left;
        stack<char> right;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                left.push(i);
            else if (s[i] == ')') {
                if (left.empty()) {
                    right.push(i);
                } else {
                    left.pop();
                }
            }
        }
        /*
         you can also use set to store the left and right stack position.
         check is it exists when you construct a new valid parentheses
         */
        while (!left.empty()) {
            s[left.top()] = '*';
            left.pop();
        }
        while (!right.empty()) {
            s[right.top()] = '*';
            right.pop();
        }
        string res;
        for (auto c : s) {
            if (c != '*')
                res += c;
        }
        return res;
    }
};

int main() {
    Solution s;
    string test1 = "(()(";
    string expected1 = "()";
    string test2 = "))()()";
    string expected2 = "()()";

    assert(s.remove(test1) == expected1);
    cout << "test1 passed" << endl;

    assert(s.remove(test2) == expected2);
    cout << "test2 passed" << endl;

    return 0;
}
