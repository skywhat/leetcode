#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        for(auto n:nums)
        sum+=n;
        if(sum<S||((sum+S)&1))
        return 0;
        sum=(sum+S)/2;
        vector<int> dp(sum+1);
        dp[0]=1;
        for(auto n:nums){
            for(int i=sum;i>=n;--i){
                //not pick n, dp[i] is the previous value, pick n, dp[i-n]
                dp[i]+=dp[i-n];
            }
        }
        return dp[sum];
    }
};

int main(){

}
