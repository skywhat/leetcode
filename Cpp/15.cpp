/*
Given an array nums of n integers, are there elements a, b, c in nums such that
a + b + c = 0? Find all unique triplets in the array which gives the sum of
zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) {
            return res;
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < n; ++i) {
            if (nums[i] > 0) {
                continue;
            }

            if (i > 0 && (nums[i] == nums[i - 1])) {
                continue;
            }

            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
                break;
            }

            if (nums[i] + nums[n - 2] + nums[n - 1] < 0) {
                continue;
            }

            int start = i + 1, end = n - 1;
            while (start < end) {
                if (nums[i] + nums[start] + nums[end] < 0) {
                    start++;
                } else if (nums[i] + nums[start] + nums[end] > 0) {
                    end--;
                } else {
                    res.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    while (start < end && (nums[start - 1] == nums[start])) {
                        start++;
                    }
                    end--;
                    while (start < end && (nums[end + 1] == nums[end])) {
                        end--;
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> test = {-1, 0, 1, 0};
    vector<int> test1 = {-1, 0, 1, 2, -1, 4};
    Solution s;
    vector<vector<int>> res = s.threeSum(test);
    for (auto row : res) {
        cout << "[";
        for (auto elem : row) {
            cout << elem << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}

/*
 *follow up:
 *three sum, which allows duplicates and each number could be used.
 *change three code snippet
 *
 * 1. i<nums.size()
 * 2. start=i
 * 3. start<=end
 *
 *follow up 2:
 *the array cannot be sorted
 *convert it to two sum problem.
 *
 *
 */
