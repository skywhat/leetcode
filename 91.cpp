#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
        return 0;
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[n]=1;
        if(s[n-1]!='0')
        dp[n-1]=1;
        for(int i=n-2;i>=0;--i){
            if(s[i]=='0'){
                dp[i]=0;
                continue;
            }
            if(s[i]=='1'||(s[i]=='2'&&s[i+1]<='6'))
            dp[i]=dp[i+1]+dp[i+2];
            else
            dp[i]=dp[i+1];
        }
        return dp[0];
    }
};

class Solution2 {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(!n)
            return 0;
        if(s[0]=='0')
            return 0;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;++i){
            int one=s[i-1]-'0';
            int two=stoi(s.substr(i-2,2));
            if(one>=1&&one<=9)
                dp[i]+=dp[i-1];
            if(two>=10&&two<=26)
                dp[i]+=dp[i-2];
        }
        return dp[n];
        
    }
};

class Solution3 {
public:
    int numDecodings(string s) {
        int len=s.size();
        if(len==0)
            return 0;
        if(s[0]=='0')
            return 0;
        int pre1=1,pre2=1;
        int sum;
        for(int i=1;i<len;++i){
            int one=s[i]-'0';
            int two=stoi(s.substr(i-1,2));
            sum=(one>=1&&one<=9?pre1:0)+(two>=10&&two<=26?pre2:0);
            pre2=pre1;
            pre1=sum;
        }
        return sum;
        
    }
};

int main(){
	string test="12";
	Solution s;
	cout<<s.numDecodings(test)<<endl;
	return 0;
}


