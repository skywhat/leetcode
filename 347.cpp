/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the
array's size.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto n : nums) {
            m[n]++;
        }

        priority_queue<pair<int, int>> freq;
        vector<int> res;

        for (auto item : m) {
            freq.push(make_pair(item.second, item.first));
            if (freq.size() > m.size() - k) {
                res.push_back(freq.top().second);
                freq.pop();
            }
        }

        return res;
    }
};
