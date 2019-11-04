// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(res, nums, 0);
        return res;
    }

    void permute(vector<vector<int>>& res, vector<int>& nums, int pos) {
        if (pos >= nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = pos; i < nums.size(); ++i) {
            swap(nums[i], nums[pos]);
            permute(res, nums, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }
};

int main() {
    vector<int> test = {1, 2, 3, 4};
    Solution s;
    vector<vector<int>> res = s.permute(test);
    for (auto row : res) {
        cout << "[";
        for (auto elem : row) {
            cout << elem << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
