#include<iostream>
#include<string>

using namespace std;

class Solution{
public:
	int countSubstrings(string s){
		int count=0;
		for(int i=0;i<s.size();++i){
			extend(s,i,i,count);//odd string
			extend(s,i,i+1,count);//even string
		}
		return count;
	}
	void extend(const string& s,int left,int right,int& count){
		while(left>=0&&right<s.size()&&s[left]==s[right]){
			count++;
			left--;
			right++;
		}
	}
};

int main(){
	string test="abc";
	Solution s;
	cout<<s.countSubstrings(test)<<endl;

	return 0;
}



