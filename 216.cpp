/*
Find all possible combinations of k numbers that add up to a number n, given
that only numbers from 1 to 9 can be used and each combination should be a
unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (n > 45 || k >= 10) {
            return {};
        }

        vector<int> temp;
        combine(k, n, temp, res, 1);
        return res;
    }

    void combine(int k,
                 int n,
                 vector<int>& temp,
                 vector<vector<int>>& res,
                 int val) {
        if (temp.size() == k) {
            if (n == 0) {
                res.push_back(temp);
            }
            return;
        }

        if (val >= 10) {
            return;
        }

        combine(k, n, temp, res, val + 1);
        temp.push_back(val);
        combine(k, n - val, temp, res, val + 1);
        temp.pop_back();
    }
};
