#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubarrayIsArithmeticProgression(vector<int> nums) {
        int n = nums.size();
        int res = 0;

        for (int i = 0; i + 2 < n; ++i) {
            int diff = nums[i + 1] - nums[i];
            for (int j = i + 2; j < n; ++j) {
                if (nums[j] - nums[j - 1] == diff) {
                    res++;
                } else {
                    break;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> tests = {
        {1, 2, 3},           // 1
        {1, 2, 2},           // 0
        {1, 3, 5, 7},        // 3
        {1, 3, 5, 7, 9},     // 6
        {-1, -1, -1},        // 1
        {0, -1, -2, -3},     // 3
        {1, 3, 9, 0},        // 0
        {1, -1, 1, 1, 0, 1}, // 0
    };
    for (auto test : tests) {
        cout << s.countSubarrayIsArithmeticProgression(test) << endl;
    }

    return 0;
}
