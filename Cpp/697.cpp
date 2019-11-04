// Given a non-empty array of non-negative integers nums, the degree of this
// array is defined as the maximum frequency of any one of its elements.
//
// Your task is to find the smallest possible length of a (contiguous) subarray
// of nums, that has the same degree as nums.
//
// Example 1:
// Input: [1, 2, 2, 3, 1]
// Output: 2
// Explanation:
// The input array has a degree of 2 because both elements 1 and 2 appear twice.
// Of the subarrays that have the same degree:
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// The shortest length is 2. So return 2.
// Example 2:
// Input: [1,2,2,3,1,4,2]
// Output: 6
// Note:
//
// nums.length will be between 1 and 50,000.
// nums[i] will be an integer between 0 and 49,999.

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, pair<int, int>> m;
        int cnt = 0;
        int gap = INT_MAX;
        int start = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(nums[i])) {
                m[nums[i]].second++;
                start = m[nums[i]].first;
                if (cnt < m[nums[i]].second) {
                    cnt = m[nums[i]].second;
                    gap = i - start + 1;
                } else if (cnt == m[nums[i]].second) {
                    gap = min(gap, i - start + 1);
                }
            } else {
                m[nums[i]] = make_pair(i, 1);
            }
        }

        return gap == INT_MAX ? 1 : gap;
    }
};

class Solution2 {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]].push_back(i);
        }

        int gap = INT_MAX;
        int cnt = 0;
        for (auto v : m) {
            if (v.second.size() > cnt) {
                gap = v.second.back() - v.second.front() + 1;
                cnt = v.second.size();
            } else if (v.second.size() == cnt) {
                gap = min(gap, v.second.back() - v.second.front() + 1);
            }
        }

        return gap;
    }
};
