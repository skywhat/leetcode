/*
Given a collection of candidate numbers (candidates) and a target number
(target), find all unique combinations in candidates where the candidate numbers
sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]

*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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

        int i = pos;
        while (i < candidates.size()) {
            temp.push_back(candidates[i]);
            combine(candidates, target - candidates[i], i + 1, temp, res);
            temp.pop_back();

            int cnt = 1;
            while (cnt + i < candidates.size()
                   && candidates[i] == candidates[i + cnt]) {
                cnt++;
            }
            i += cnt;
        }
    }
};

class Solution2 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
            if (i > pos && candidates[i] == candidates[i - 1]) {
                continue;
            }
            temp.push_back(candidates[i]);
            combine(candidates, target - candidates[i], i + 1, temp, res);
            temp.pop_back();
        }
    }
};
