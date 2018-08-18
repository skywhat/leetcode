/*
Given two integers n and k, return all possible combinations of k numbers out of
1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        combine(res, 1, temp, n, k);
        return res;
    }

    void combine(vector<vector<int>>& res,
                 int pos,
                 vector<int>& temp,
                 int n,
                 int k) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }

        for (int i = pos; i <= n; ++i) {
            temp.push_back(i);
            combine(res, i + 1, temp, n, k);
            temp.pop_back();
        }
    }
};
