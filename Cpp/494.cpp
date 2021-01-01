#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        for(auto&& n:nums)
            sum+=n;
        if(sum<S||(S+sum)&1)
            return 0;
        int s1=(S+sum)/2;
        vector<int> dp(s1+1,0);
        dp[0]=1;
        for(auto&& n:nums){
            for(int i=s1;i>=n;--i){
                //as for dp[i], if not pick n, it's dp[i], otherwise it's dp[i-n], thus dp[i]=dp[i]+dp[i-n]
                dp[i]+=dp[i-n];
            }
        }
        return dp[s1];
    }
};

/*
 
 s1-s2=S
 s1=S+s2
 2*s1=S+s1+s2
 s1=1/2(S+sum)
 
 s1 must be even.
 
 
 */

int main(){

}
