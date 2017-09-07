#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution{
public:
	string longestPalindrome(string s){
		int start=0,max_len=1;
		for(int i=0;i<s.size();++i){
			if(s.size()-i<max_len/2)
				break;
			int left=i,right=i;
			while(right+1<s.size()&&(s[right+1]==s[right])){
				right++;
			}
			
			while(left>0&&right+1<s.size()&&(s[left-1]==s[right+1])){
				left--;
				right++;
			}
			if(right-left+1>max_len){
				start=left;
				max_len=right-left+1;
			}
		}
		return s.substr(start,max_len);
	}
};

int main(){
	Solution s;
	string test="babad";
	cout<<s.longestPalindrome(test)<<endl;

	return 0;
}
