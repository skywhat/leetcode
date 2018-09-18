// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may
// not use the same element twice.
//
// Example:
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(nums[i])) {
                return {m[nums[i]], i};
            } else {
                m[target - nums[i]] = i;
            }
        }

        return {};
    }
};

int main() {
    vector<int> testcase = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    vector<int> res = s.twoSum(testcase, target);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << ", ";
    }
    cout << endl;

    return 0;
}
