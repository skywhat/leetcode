class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2)
            return 0;
        vector<int> first(n,0);
        int minP=prices[0];
        int profit=0;
        for(int i=1;i<n;++i){
            profit=max(profit,prices[i]-minP);
            minP=min(minP,prices[i]);
            first[i]=profit;
        }
        int res=0;
        int maxP=prices[n-1];
        profit=0;
        for(int i=n-2;i>=0;--i){
            profit=max(profit,maxP-prices[i]);
            maxP=max(maxP,prices[i]);
            res=max(res,profit+first[i-1]);
        }
        return res;
        
    }
};
