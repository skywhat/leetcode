class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<=1)
            return 0;
        if(k>=n/2){
            int res=0;
            for(int i=1;i<n;++i){
                if(prices[i]>prices[i-1])
                    res+=prices[i]-prices[i-1];
            }
            return res;
        }
        vector<vector<int>> dp(k+1,vector<int>(n));
        for(int i=1;i<=k;++i){
            int local=INT_MIN;
            for(int j=1;j<n;++j){
                local=max(local,dp[i-1][j-1]-prices[j-1]);
                dp[i][j]=max(dp[i][j-1],prices[j]+local);
            }
        }
        return dp[k][n-1];
    }
};

//https://discuss.leetcode.com/topic/26169/clean-java-dp-solution-with-comment/22
