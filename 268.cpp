// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find
// the one that is missing from the array.
//
// Example 1:
//
// Input: [3,0,1]
// Output: 2
// Example 2:
//
// Input: [9,6,4,2,3,5,7,0,1]
// Output: 8
// Note:
// Your algorithm should run in linear runtime complexity. Could you implement
// it using only constant extra space complexity?

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (1 + n) * n / 2;
        for (int i = 0; i < nums.size(); ++i) {
            sum -= nums[i];
        }
        return sum;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing_num = 0;
        int i = 0;
        for (; i < nums.size(); ++i) {
            missing_num ^= i ^ nums[i];
        }
        return missing_num ^ i;
    }
};
