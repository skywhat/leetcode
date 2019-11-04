// Numbers can be regarded as product of its factors. For example,
//
// 8 = 2 x 2 x 2;
//   = 2 x 4.
// Write a function that takes an integer n and return all possible combinations
// of its factors.
//
// Note:
//
// You may assume that n is always positive.
// Factors should be greater than 1 and less than n.
// Example 1:
//
// Input: 1
// Output: []
// Example 2:
//
// Input: 37
// Output:[]
// Example 3:
//
// Input: 12
// Output:
// [
//   [2, 6],
//   [2, 2, 3],
//   [3, 4]
// ]
// Example 4:
//
// Input: 32
// Output:
// [
//   [2, 16],
//   [2, 2, 8],
//   [2, 2, 2, 4],
//   [2, 2, 2, 2, 2],
//   [2, 4, 4],
//   [4, 8]
// ]

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        dfs(vector<int>(), n, res, 2);
        return res;
    }

    void dfs(vector<int> temp, int rest, vector<vector<int>>& res, int start) {
        if (rest == 1) {
            if (temp.size() > 1) {
                res.push_back(temp);
            }
            return;
        }

        for (int i = start; i <= rest; ++i) {
            if (rest % i == 0) {
                temp.push_back(i);
                dfs(temp, rest / i, res, i);
                temp.pop_back();
            }
        }
    }
};
