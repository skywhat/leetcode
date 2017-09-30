#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
	bool canConstruct(string ransomNote, string magazine){
		vector<int> dict(256,0);
		for(auto m:magazine)
			dict[m]++;
		for(auto r:ransomNote){
			if(--dict[r]<0)
				return false;
		}
		return true;
	}
};

int main(){
	string ransomNote="aa";
	string magazine="aab";
	Solution s;
	cout<<s.canConstruct(ransomNote,magazine)<<endl;

	return 0;
}
