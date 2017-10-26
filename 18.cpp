/*
 
 Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 
 Note: The solution set must not contain duplicate quadruplets.
 
 For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 
 A solution set is:
 [
 [-1,  0, 0, 1],
 [-2, -1, 1, 2],
 [-2,  0, 0, 2]
 ]
 
 */
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size();
        if(n<4)
            return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i+3<n;++i){
            if(i>0&&nums[i]==nums[i-1])
                continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target){
                break;
            }
            if(nums[i]+nums[n-1]+nums[n-2]+nums[n-3]<target)
                continue;
            for(int j=i+1;j+2<n;++j){
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target)
                    break;
                if(nums[i]+nums[j]+nums[n-1]+nums[n-2]<target)
                    continue;
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target){
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        right--;
                        while(left<right&&nums[right]==nums[right+1])
                            right--;
                        left++;
                        while(left<right&&nums[left]==nums[left-1])
                            left++;
                    }
                    else if(sum>target){
                        right--;
                        while(left<right&&nums[right]==nums[right+1])
                            right--;
                    }
                    else{
                        left++;
                        while(left<right&&nums[left]==nums[left-1])
                            left++;
                    }
                    
                }
            }
        }
        return res;
        
    }
};
