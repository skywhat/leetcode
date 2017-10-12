#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	bool canPartition(vector<int>& nums){
		int sum=0;
		for(auto n:nums)
			sum+=n;
		if(sum&1)
			return false;
		sum/=2;
		int n=nums.size();
		vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
		dp[0][0]=true;
		for(int j=1;j<sum+1;++j){
			dp[0][j]=false;
		}
		for(int i=1;i<n+1;++i){
			dp[i][0]=true;
		}
		for(int i=1;i<n+1;++i){
			for(int j=1;j<sum+1;++j){
				dp[i][j]=dp[i-1][j];
				if(j>=nums[i-1]){
					dp[i][j]=(dp[i][j]||dp[i-1][j-nums[i-1]]);
				}
			}
		}
        /*
		for(int i=0;i<dp.size();++i){
			for(int j=0;j<dp[i].size();++j){
				cout<<dp[i][j]<<"("<<i<<","<<j<<") ";			
			}
			cout<<endl;
		}
         */
		return dp[n][sum];
	}	

};

class Solution2 {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto n:nums)
        sum+=n;
        if(sum&1)
        return false;
        sum/=2;
        vector<bool> dp(sum+1,false);
        dp[0]=true;
        for(auto n:nums){
            for(int i=sum;i>=n;--i){
                dp[i]=dp[i]||dp[i-n];
            }
        }
        return dp[sum];
    }
};

int main(){
	Solution s;
	vector<int> test={1,5,11,5};

	cout<<s.canPartition(test)<<endl;

	return 0;

}






