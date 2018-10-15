// Given an array of integers nums sorted in ascending order, find the starting
// and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        auto start = lower_bound(nums.begin(), nums.end(), target);
        auto end = upper_bound(nums.begin(), nums.end(), target);
        if (start == nums.end() || *start != target) {
            return {-1, -1};
        }

        return {distance(nums.begin(), start), distance(nums.begin(), end) - 1};
    }
};

class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        int start, end;
        int left = 0, right = nums.size() - 1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        start = left;

        left = 0, right = nums.size(); // but not nums.size()-1
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        end = right;

        if (nums[start] != target) {
            return {-1, -1};
        }

        return {start, end - 1};
    }
};
