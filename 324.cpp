// Given an unsorted array nums, reorder it such that nums[0] < nums[1] >
// nums[2] < nums[3]....
//
// Example 1:
//
// Input: nums = [1, 5, 1, 1, 6, 4]
// Output: One possible answer is [1, 4, 1, 5, 1, 6].
// Example 2:
//
// Input: nums = [1, 3, 2, 2, 3, 1]
// Output: One possible answer is [2, 3, 1, 3, 1, 2].
// Note:
// You may assume all input has valid answer.
//
// Follow Up:
// Can you do it in O(n) time and/or in-place with O(1) extra space?

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> help(nums);
        sort(help.begin(), help.end());
        for (int i = 0, k = (n - 1) / 2, l = n - 1; i < n; ++i) {
            nums[i] = help[i & 1 ? l-- : k--];
        }
    }
};
/*

odd:
0 1 2 3 4 5 6
6 5 4
3 2 1 0

3 6 2 5 1 4 0

even:
0 1 2 3 4 5 6 7
7 6 5 4
3 2 1 0

3 7 2 6 1 5 0 4

a b c d
=>
1. a c b d  wrong
2. a d b c  wrong
3. b c a d  wrong
4. b d a c  right

ensure consecutive numbers won't be adjacent after wiggling
*/
