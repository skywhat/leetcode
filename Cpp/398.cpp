#include<iostream>

class Solution {
public:
    vector<int> _nums;
    Solution(vector<int> nums) {
        _nums=nums;
    }
    
    int pick(int target) {
        while(true){
            int ind=rand()%_nums.size();
            if(_nums[ind]==target)
            return ind;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
