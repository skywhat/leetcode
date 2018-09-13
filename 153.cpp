// Suppose an array sorted in ascending order is rotated at some pivot unknown
// to you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// You may assume no duplicate exists in the array.
//
// Example 1:
//
// Input: [3,4,5,1,2]
// Output: 1
// Example 2:
//
// Input: [4,5,6,7,0,1,2]
// Output: 0

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        if (n == 1 || nums[0] < nums[n - 1]) {
            return nums[0];
        }

        int i = 0, j = n - 1;
        while (i + 1 < j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] < nums[mid + 1] && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            } else if (nums[mid] > nums[0]) {
                i = mid;
            } else {
                j = mid;
            }
        }

        if (nums[i] < nums[i - 1]) {
            return nums[i];
        }

        return nums[j];
    }
};
