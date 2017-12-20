#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        return max(rob(nums,0,nums.size()-2),rob(nums,1,nums.size()-1));

    }
        int rob(vector<int>& nums,int i,int j){
        if(i==j){
            return nums[i];
        }
        int n=nums.size();
        vector<vector<int>> dp(2,vector<int>(n,0));
        dp[1][i]=nums[i];
        for(int k=i+1;k<=j;++k){
            dp[0][k]=max(dp[1][k-1],dp[0][k-1]);
            dp[1][k]=dp[0][k-1]+nums[k];
        }
        return max(dp[0][j],dp[1][j]);
    }
};

int main(){
}
