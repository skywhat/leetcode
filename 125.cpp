#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
public:
	bool isPalindrome(string s){
		vector<int> m(256,0);
		for(int i='0';i<='9';++i)
			m[i]=i;
		for(int i='a';i<='z';++i)
			m[i]=i;
		for(int i='A';i<='Z';++i)
			m[i]=i-('A'-'a');
		int i=0,j=s.size()-1;
		while(i<j){
			while(m[s[i]]==0)
				i++;
			while(m[s[j]]==0)
				j--;
			if(i>=j)
				break;
			if(m[s[i]]!=m[s[j]])
				return false;
			i++;
			j--;
		}
		return true;
	}
};

int main(){

}
