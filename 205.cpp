#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
public:
	bool isIsomorphic(string s,string t){
		if(s.size()!=t.size())
			return false;
		vector<int> m1(128,0);
		vector<int> m2(128,0);
		for(int i=0;i<s.size();++i){
			if(m1[s[i]]==0&&m2[t[i]]==0){
				m1[s[i]]=t[i];
				m2[t[i]]=s[i];
			}
			else if(m1[s[i]]!=t[i]||m2[t[i]]!=s[i])
				return false;
		}
		return true;
	}
};

int main(){
	string str1="egg";
	string str2="add";
	Solution s;
	cout<<s.isIsomorphic(str1,str2)<<endl;

	return 0;
}
