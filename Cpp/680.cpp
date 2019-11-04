#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return valid(s, i + 1, j) || valid(s, i, j - 1);
            }
            i++;
            j--;
        }

        return true;
    }

    bool valid(string s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    string test = "abca";
    cout << s.validPalindrome(test) << endl;

    return 0;
}
