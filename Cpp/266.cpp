// Given a string, determine if a permutation of the string could form a
// palindrome.
//
// Example 1:
//
// Input: "code"
// Output: false
// Example 2:
//
// Input: "aab"
// Output: true
// Example 3:
//
// Input: "carerac"
// Output: true

class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> m(128, 0);
        for (auto c : s) {
            m[c]++;
        }
        int odd = 0;
        for (int ch = 0; ch < 128; ++ch) {
            if (m[ch] & 1) {
                odd++;
            }
        }

        return odd <= 1;
    }
};

class Solution2 {
public:
    bool canPermutePalindrome(string s) {
        bitset<128> b;
        for (auto c : s) {
            b[c].flip();
        }
        return b.count() < 2;
    }
};
