/*
Given an unsorted array of integers, find the length of the longest consecutive
elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
Therefore its length is 4.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (auto&& n : s) {
            if (!s.count(n - 1)) {
                int cnt = 1;
                while (s.count(n + cnt)) {
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};
