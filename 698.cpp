// Given an array of integers nums and a positive integer k, find whether it's
// possible to divide this array into k non-empty subsets whose sums are all
// equal.
//
// Example 1:
// Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
// Output: True
// Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3),
// (2,3) with equal sums. Note:
//
// 1 <= k <= len(nums) <= 16.
// 0 < nums[i] < 10000.

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        vector<bool> visit(nums.size(), false);
        return canPartition(nums, visit, 0, k, target, 0);
    }

    bool canPartition(vector<int>& nums,
                      vector<bool>& visit,
                      int pos,
                      int k,
                      int& target,
                      int cur_sum) {
        if (k == 1) {
            return true;
        }

        if (cur_sum == target) {
            return canPartition(nums, visit, 0, k - 1, target, 0);
        }

        for (int i = pos; i < nums.size(); ++i) {
            if (!visit[i]) {
                visit[i] = true;
                if (canPartition(nums, visit, i + 1, k, target,
                                 cur_sum + nums[i])) {
                    return true;
                }
                visit[i] = false;
            }
        }

        return false;
    }
};
