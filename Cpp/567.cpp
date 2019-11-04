// Given two strings s1 and s2, write a function to return true if s2 contains
// the permutation of s1. In other words, one of the first string's permutations
// is the substring of the second string. Example 1: Input:s1 = "ab" s2 =
// "eidbaooo" Output:True Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:
// Input:s1= "ab" s2 = "eidboaoo"
// Output: False
// Note:
// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int cnt = s1.size();
        vector<int> m(128, 0);
        for (auto c : s1) {
            m[c]++;
        }

        int start = 0, end = 0;
        while (end < s2.size()) {
            if (m[s2[end]] > 0) {
                cnt--;
            }
            m[s2[end]]--;
            end++;

            while (cnt == 0) {
                if (m[s2[start]] == 0) {
                    if (end - start == s1.size()) {
                        return true;
                    }
                }

                m[s2[start]]++;
                if (m[s2[start]] > 0) {
                    cnt++;
                }
                start++;
            }
        }

        return false;
    }
};

class Solution2 {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> m(128, 0);
        for (auto c : s1) {
            m[c]++;
        }

        int n = s1.size();
        int i = 0, j = n - 1;
        for (int k = i; k <= j; ++k) {
            m[s2[k]]--;
        }

        while (j < s2.size()) {
            if (allZero(m)) {
                return true;
            }
            m[s2[i++]]++;
            j++;
            if (j < s2.size()) {
                m[s2[j]]--;
            }
        }

        return false;
    }

    bool allZero(vector<int> m) {
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (m[ch] != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {}
