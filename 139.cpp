#include<string>
#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution{
public:
	bool wordBreak(string s,vector<string>& wordDict){
		vector<bool> b(s.size()+1,false);
		b[0]=true;
		unordered_set<string> set(wordDict.begin(),wordDict.end());
		for(int i=1;i<=s.size();++i){
			for(int j=i-1;j>=0;--j){
				if(b[j]){
					auto found=set.find(s.substr(j,i-j));
					if(found!=set.end()){
						b[i]=true;
						break;
					}
				}
			}
		}
		return b[s.size()];
	}
};

int main(){
	string test="leetcode";
	vector<string> v={"leet","code"};

	string test1="goalspecial";
	vector<string> v1={"go","goal","special"};

	Solution s;
	cout<<s.wordBreak(test1,v1)<<endl;

	return 0;
}
