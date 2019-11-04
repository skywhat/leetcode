#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution{
public:
	int romanToInt(string s){
		unordered_map<char,int> m;
		vector<char> RomanN={'M','D','C','L','X','V','I'};
		vector<int> nums={1000,500,100,50,10,5,1};	
		for(int i=0;i<RomanN.size();++i)
			m[RomanN[i]]=nums[i];

		int res=0;
		int last=s.size()-1;
		res+=m[s[last]];
		for(int i=last-1;i>=0;--i){
			if(m[s[i+1]]>m[s[i]])
				res-=m[s[i]];
			else
				res+=m[s[i]];
		}
		return res;
	}
};

int main(){
	string R="III";
	
	Solution s;
	cout<<s.romanToInt(R)<<endl;

	return 0;

}



