// Given an array which consists of non-negative integers and an integer m, you
// can split the array into m non-empty continuous subarrays. Write an algorithm
// to minimize the largest sum among these m subarrays.
//
// Note:
// If n is the length of array, assume the following constraints are satisfied:
//
// 1 ≤ n ≤ 1000
// 1 ≤ m ≤ min(50, n)
// Examples:
//
// Input:
// nums = [7,2,5,10,8]
// m = 2
//
// Output:
// 18
//
// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0;  // the maximum number
        int right = 0; // the sum of nums
        for (auto n : nums) {
            if (left < n)
                left = n;
            right += n;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (valid(mid, nums, m)) {
                right = mid;
            } else
                left = mid + 1;
        }

        return left;
    }

    bool valid(int target, const vector<int>& nums, int m) {
        int curSum = 0;
        int cnt = 1;

        for (size_t i = 0; i < nums.size(); ++i) {
            curSum += nums[i];
            if (curSum > target) {
                curSum = nums[i];
                if (++cnt > m)
                    return false;
            }
        }

        return true;
    }
};

int main() {
    vector<int> test = {7, 2, 5, 10, 8};
    int m = 2;
    Solution s;
    cout << s.splitArray(test, m) << endl;

    return 0;
}
