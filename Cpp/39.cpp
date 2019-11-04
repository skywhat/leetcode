/*
Given a set of candidate numbers (candidates) (without duplicates) and a target
number (target), find all unique combinations in candidates where the candidate
numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of
times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        combine(candidates, target, 0, temp, res);
        return res;
    }

    void combine(vector<int>& candidates,
                 int target,
                 int pos,
                 vector<int>& temp,
                 vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }

        if (target < 0) {
            return;
        }
        for (int i = pos; i < candidates.size(); ++i) {
            temp.push_back(candidates[i]);
            combine(candidates, target - candidates[i], i, temp, res);
            temp.pop_back();
        }
    }
};
