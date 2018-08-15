#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    const string operands = "+-*/";

public:
    string reverseAlgebraicExpression(string exp) {
        if (exp.size() <= 1) {
            return exp;
        }

        reverse(exp.begin(), exp.end());
        auto begin = exp.begin();
        int i = 0, j = 0;

        while (j <= exp.size()) {
            if (operands.find(exp[j]) != string::npos || j == exp.size()) {
                if (operands.find(exp[j + 1]) != string::npos) {
                    j++;
                }
                reverse(begin + i, begin + j);
                i = j + 1;
            }
            j++;
        }

        return exp;
    }
};

int main() {
    string test1 = "1*2+9-23";
    string expected1 = "23-9+2*1";
    string test2 = "10.4*32.7/12";
    string expected2 = "12/32.7*10.4";
    string test3 = "1*2.4+-9.6-23.89";
    string expected3 = "23.89--9.6+2.4*1";

    Solution s;
    cout << (s.reverseAlgebraicExpression(test1) == expected1) << endl;
    cout << (s.reverseAlgebraicExpression(test2) == expected2) << endl;
    cout << (s.reverseAlgebraicExpression(test3) == expected3) << endl;

    return 0;
}
