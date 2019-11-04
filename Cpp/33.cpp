// Suppose an array sorted in ascending order is rotated at some pivot unknown
// to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its
// index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }

        if (nums[0] < nums[n - 1]) {
            return binarySearch(nums, 0, n - 1, target);
        }

        int pivot = findPivot(nums);

        return target >= nums[0] ? binarySearch(nums, 0, pivot, target)
                                 : binarySearch(nums, pivot + 1, n - 1, target);
    }

    int binarySearch(vector<int>& nums, int left, int right, int target) {
        int mid;
        while (left + 1 < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (nums[left] == target) {
            return left;
        }
        if (nums[right] == target) {
            return right;
        }

        return -1;
    }

    int findPivot(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i + 1 < j) {
            int m = i + (j - i) / 2;
            if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1]) {
                return m;
            } else if (nums[m] < nums[0]) {
                j = m;
            } else {
                i = m;
            }
        }

        return nums[i] > nums[i + 1] ? i : j;
    }
};

int main() {}
