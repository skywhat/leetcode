#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        s = '+' + s + '+';
        istringstream in(s);
        int res = 0;
        int term = 0;
        char op;

        while (in >> op) {
            if (op == '+' || op == '-') {
                res += term;
                in >> term;
                if (op == '-') {
                    term = -term;
                }
            } else {
                int temp;
                in >> temp;
                if (op == '*') {
                    term *= temp;
                } else {
                    term /= temp;
                }
            }
        }

        return res;
    }
};

class Solution2 {
public:
    int calculate(string s) {
        stack<int> nums;
        char sign = '+';
        int n = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                n = n * 10 + s[i] - '0';
            }
            if (!isspace(s[i]) && !isdigit(s[i]) || i == s.size() - 1) {
                if (sign == '+') {
                    nums.push(n);
                } else if (sign == '-') {
                    nums.push(-n);
                } else if (sign == '*' || sign == '/') {
                    int res = sign == '*' ? nums.top() * n : nums.top() / n;
                    nums.pop();
                    nums.push(res);
                }
                n = 0;
                sign = s[i];
            }
        }

        int res = 0;
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }

        return res;
    }
};

int main() {}
