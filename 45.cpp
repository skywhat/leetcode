// Given an array of non-negative integers, you are initially positioned at the
// first index of the array.
//
// Each element in the array represents your maximum jump length at that
// position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// Example:
//
// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Note:
//
// You can assume that you can always reach the last index.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }

        int step = 0;
        int next = 0;
        int max_des = 0;

        for (int i = 0; i < n - 1; ++i) {
            max_des = max(max_des, i + nums[i]);
            if (i == next) {
                step++;
                next = max_des;
            }

            if (max_des >= n - 1) {
                return step + (next >= n - 1 ? 0 : 1);
            }
        }

        return -1;
    }
};

int main() {
    vector<int> test = {2, 3, 1, 1, 4};
    Solution s;
    cout << s.jump(test) << endl;

    return 0;
}
