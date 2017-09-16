#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int coinChange(vector<int>& coins,int amount){
		vector<int> dp(amount+1,INT_MAX);
		dp[0]=0;
		for(int i=1;i<=amount;++i){
			for(auto c:coins){
				if((i-c>=0)&&dp[i-c]!=INT_MAX)
					dp[i]=min(dp[i],dp[i-c]+1);
			}
		}
		return dp[amount]==INT_MAX?-1:dp[amount];
	}
};

int main(){
	Solution s;
	vector<int> coins={1,2,5};
	int amount=11;
	cout<<s.coinChange(coins,amount)<<endl;

	return 0;
}
