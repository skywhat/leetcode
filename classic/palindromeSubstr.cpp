/*
 *
 * Given a string, find all the palindromic substring.
 * input: abacd
 * output: a,b,c,d,aba
 *
 */

#include<algorithm>
#include<unordered_map>
#include<iterator>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<unordered_set>

using namespace std;

class Solution{
public:
	vector<string> alltypes(string s){
		int len=s.size();
		vector<vector<bool>> dp(len,vector<bool>(len,false));
		for(int i=0;i<len;++i){
			dp[i][i]=true;
		}
		for(int j=0;j<len;++j){
			for(int i=0;i<j;++i){
				int left=i+1;
				int right=j-1;
				if(left>=right)
					dp[i][j]=s[i]==s[j];
				else
					dp[i][j]=dp[left][right]&&(s[i]==s[j]);
			}		
		}
		set<string> res;
		for(int i=0;i<len;++i){
			for(int j=i;j<len;++j){
				if(dp[i][j]){
					res.insert(s.substr(i,j-i+1));
				}
			}
		}
		return vector<string>(res.begin(),res.end());	
	}
};
/* 
 * dynamic programing
 *
 * string[m...n]
 * depends on
 * is string[m-1...n-1] palindromic and string[m] equal to string[n]
 *
 * abacd
 *	   0 1 2 3 4 
 *	0  T F T F F
 *	1    T F F F
 *	2      T F F
 *	3        T F
 *	4          T
 */

int main(){
	string test="abaaa";
	Solution s;
	vector<string> res=s.alltypes(test);
   	for(auto r:res)
		cout<<r<<endl;	
	return 0;
}

