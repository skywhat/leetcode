#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int size=nums.size();
        vector<vector<int>> dp(2,vector<int>(size,0));
        //dp[0][i] means don't rob ith house
        //dp[1][i] means rob ith house
        dp[1][0]=nums[0];
        for(int i=1;i<size;++i){
            dp[0][i]=max(dp[1][i-1],dp[0][i-1]);
            dp[1][i]=max(dp[0][i-1]+nums[i],dp[1][i-1]);
        }
        return max(dp[0][size-1],dp[1][size-1]);
    }
};

int main(){
    Solution s;
    vector<int> house={5,1,1,7,1};
    cout<<s.rob(house)<<endl;

    return 0;
}
