// perm_identity
// Check if binary representation of a number is palindrome
// Given an integer ‘x’, write a C function that returns true if binary
// representation of x is palindrome else return false.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isBinaryPalindrome(int n) {
        if (n < 2) {
            return true;
        }

        int left = -1;
        int temp = n;
        while (temp) {
            temp = temp >> 1;
            left++;
        }

        int right = 0;
        while (left > right) {
            if (kthPosition(n, left) != kthPosition(n, right)) {
                return false;
            }
            left--;
            right++;
        }

        return true;
    }

    int kthPosition(int n, int k) { return (n >> k) & 1; }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 2, 3, 4, 5};

    for (auto n : nums) {
        cout << s.isBinaryPalindrome(n) << endl;
    }

    return 0;
}
