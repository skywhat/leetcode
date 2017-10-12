#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m>n)
        return uniquePaths(n,m);
        vector<int> path(m+1,0);
        path[1]=1;
        for(int j=1;j<=n;++j){
            for(int i=2;i<=m;++i){
                path[i]=path[i]+path[i-1];
            }
        }
        return path[m];
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;++i)
        dp[i][1]=1;
        for(int j=1;j<=n;++j)
        dp[1][j]=1;
        for(int i=2;i<=m;++i){
            for(int j=2;j<=n;++j){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};

int main(){
	int m=3,n=4;
	Solution s;
	cout<<s.uniquePaths(m,n)<<endl;

	return 0;
}
