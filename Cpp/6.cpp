// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
// of rows like this: (you may want to display this pattern in a fixed font for
// better legibility)
//
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
//
// Write the code that will take a string and make this conversion given a
// number of rows:
//
// string convert(string s, int numRows);
// Example 1:
//
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:
//
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
//
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int n = s.size();
        vector<int> index(n);
        int width = 2 * numRows - 2;
        int pos = 0;

        for (int i = 1; i <= numRows; ++i) {
            if (i == 1 || i == numRows) {
                int j = i - 1;
                while (j < n) {
                    index[pos++] = j;
                    j += width;
                }
            } else {
                vector<int> step = {width - 2 * i + 2, 2 * i - 2};
                int cnt = 1;
                int j = i - 1;
                while (j < n) {
                    index[pos++] = j;
                    j += cnt++ % 2 ? step[0] : step[1];
                }
            }
        }

        string res;
        for (int i = 0; i < n; ++i) {
            res += s[index[i]];
        }

        return res;
    }
};

int main() {
    string test = "PAYPALISHIRING";
    string test1 = "ABCDE";
    Solution s;
    int numRows = 3;
    cout << s.convert(test, numRows) << endl;

    return 0;
}
