class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (1+n)*n/2;
        for(int i=0;i<nums.size();++i){
            sum-=nums[i];
        }
        return sum;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing_num = 0;
        int i=0;
        for(;i<nums.size();++i){
            missing_num = missing_num^i^nums[i];
        }
        return missing_num^i;
    }
};
