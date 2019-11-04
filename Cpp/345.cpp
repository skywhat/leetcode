#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
public:
	string reverseVowels(string s){
		vector<bool> c(256,false);
		string vowels="aeiouAEIOU";
		for(auto v:vowels)
			c[v]=true;
		int i=0,j=s.size()-1;
		while(i<j){
			if(c[s[i]]&&c[s[j]]){
				swap(s[i++],s[j--]);
				continue;
			}
			if(!c[s[i]])
				i++;
			if(!c[s[j]])
				j--;
		}
		return s;
	}
};
int main(){
	string test="leetcode";
	Solution s;
	cout<<s.reverseVowels(test)<<endl;

	return 0;
}
