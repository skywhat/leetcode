/*

Given a string, your task is to count how many palindromic substrings in this
string.

The substrings with different start indexes or end indexes are counted as
different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            extendPalindromic(s, i, i, count);
            extendPalindromic(s, i, i + 1, count);
        }

        return count;
    }

    void extendPalindromic(const string& s, int i, int j, int& count) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
    }
};

int main() {
    string test = "abc";
    Solution s;
    cout << s.countSubstrings(test) << endl;

    return 0;
}
