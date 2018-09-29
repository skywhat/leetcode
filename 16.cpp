// Given an array nums of n integers and an integer target, find three integers
// in nums such that the sum is closest to target. Return the sum of the three
// integers. You may assume that each input would have exactly one solution.
//
// Example:
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum, res;
        int dist = INT_MAX;

        for (int i = 0; i + 2 < nums.size(); ++i) {
            int j = i + 1, k = nums.size() - 1;

            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < dist) {
                    dist = abs(sum - target);
                    res = sum;
                    if (!dist) {
                        return res;
                    }
                }

                sum - target > 0 ? k-- : j++;
            }
        }

        return res;
    }
};

int main() {
    vector<int> test = {-1, 2, 1, -4};
    int target = 1;
    Solution s;
    cout << s.threeSumClosest(test, target) << endl;

    return 0;
}
