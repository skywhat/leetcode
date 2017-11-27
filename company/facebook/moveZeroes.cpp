//Given an array nums, write a function to move all 0's to the end of it while do not have to maintain the relative order of the non-zero elements.

#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]!=0){
                i++;
                continue;
            }
            if(nums[j]==0){
                j--;
                continue;
            }
            swap(nums[i],nums[j]);
            
        }
    }
};
