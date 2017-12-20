#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
public:
	int longest(const string& s1,const string& s2){
		int m=s1.size();
		int n=s2.size();
		vector<vector<int>> dp(m+1,vector<int>(n+1,0));
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				if(s1[i]==s2[j]){
					dp[i+1][j+1]=dp[i][j]+1;
				}
				else{
					dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
				}
			}
		}
		for(auto row:dp){
			for(auto elem:row){
				cout<<elem<<", ";
			}
			cout<<endl;
		}
		return dp[m][n];
	}
};

int main(){

	string s1="DCABCA";
	string s2="DADCAC";
	Solution s;
	cout<<s.longest(s1,s2)<<endl;

	return 0;
}

