#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
	int countSegments(string s){
		int ans=0;
		vector<bool> c(256,true);
		c[' ']=false;
		int i=0;
		while(i<s.size()){
			if(c[s[i]]){
				while(i<s.size()&&c[s[i]])
					i++;
				ans++;
			}
			while(i<s.size()&&!c[s[i]])
				i++;
		}
		return ans;
	}
};

int main(){
	string test="Hello, my name is John";
	string test1="love live! mu'sic forever";
	Solution s;
	cout<<s.countSegments(test1)<<endl;

	return 0;
}
