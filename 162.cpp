// A peak element is an element that is greater than its neighbors.
//
// Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and
// return its index.
//
// The array may contain multiple peaks, in that case return the index to any
// one of the peaks is fine.
//
// You may imagine that nums[-1] = nums[n] = -∞.
//
// Example 1:
//
// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index
// number 2. Example 2:
//
// Input: nums = [1,2,1,3,5,6,4]
// Output: 1 or 5
// Explanation: Your function can return either index number 1 where the peak
// element is 2,
//              or index number 5 where the peak element is 6.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;

        while (i + 1 < j) {
            int m = i + (j - i) / 2;
            if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1]) {
                return m;
            } else if (nums[m] < nums[m + 1]) {
                i = m;
            } else {
                j = m;
            }
        }

        return nums[i] > nums[j] ? i : j;
    }
};

int main() {
    vector<int> v = {-2147483648, -2147483647};
    Solution s;
    cout << s.findPeakElement(v) << endl;

    return 0;
}
