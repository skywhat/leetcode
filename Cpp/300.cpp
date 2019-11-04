// Given an unsorted array of integers, find the length of longest increasing
// subsequence.
//
// Example:
//
// Input: [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
// length is 4. Note:
//
// There may be more than one LIS combination, it is only necessary for you to
// return the length. Your algorithm should run in O(n2) complexity. Follow up:
// Could you improve it to O(n log n) time complexity?

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n, 1);
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && length[i] < length[j] + 1)
                    length[i] = length[j] + 1;
            }
            maxLength = max(maxLength, length[i]);
        }

        return maxLength;
    }
};
// 19ms O(n^2)

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        vector<int> tail(n, 0);
        tail[0] = nums[0];
        int len = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < tail[0]) {
                tail[0] = nums[i];
            } else if (nums[i] > tail[len - 1]) {
                tail[len++] = nums[i];
            } else {
                tail[find(tail, len, nums[i])] = nums[i];
            }
        }

        return len;
    }

    int find(vector<int>& tail, int len, int target) {
        int i = 0, j = len - 1;

        while (i + 1 < j) {
            int mid = i + (j - i) / 2;
            if (tail[mid] > target) {
                j = mid;
            } else {
                i = mid;
            }
        }

        if (tail[i] < target) {
            return j;
        }

        return i;
    }
};
// 3ms O(nlgn)
//
