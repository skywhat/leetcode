#include <iostream>
#include <vector>

using namespace std;

// recursive
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        subsets(res, nums, 0, vector<int>());
        return res;
    }
    void subsets(vector<vector<int>>& res,
                 vector<int>& nums,
                 int pos,
                 vector<int> temp) {
        if (pos == nums.size()) {
            res.push_back(temp);
            return;
        }
        subsets(res, nums, pos + 1, temp);
        temp.push_back(nums[pos]);
        subsets(res, nums, pos + 1, temp);
    }
};

// iterative
class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});

        for (int i = 0; i < nums.size(); ++i) {
            int n = res.size();
            for (int j = 0; j < n; ++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }

        return res;
    }
};

// bit manipulation
class Solution3 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int num_set = pow(2, nums.size());
        vector<vector<int>> res(num_set, vector<int>());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < num_set; ++j) {
                if ((j >> i) & 1) {
                    res[j].push_back(nums[i]);
                }
            }
        }
        return res;
    }
};

/*

 1 2 3
 [] [] [] [] [] [] [] []
 [] [1] [] [1] [] [1] [] [1]
 [] [1] [2] [1,2] [] [1] [2] [1,2]
 [] [1] [2] [1,2] [3] [1,3] [2,3] [1,2,3]
 */

int main() {
    vector<int> test = {1, 2, 3};
    Solution s;
    auto res = s.subsets(test);
    for (auto row : res) {
        cout << "[";
        for (auto elem : row) {
            cout << elem << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
