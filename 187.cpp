#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<iterator>

using namespace std;

class Solution{
public:
	vector<string> findRepeatedDnaSequences(string s){
		vector<string> res;
		unordered_map<string,int> m;
		for(int i=0;i<=int(s.size()-10);++i){
			string tmp=s.substr(i,10);
			m[tmp]++;
			if(m[tmp]==2)
				res.push_back(tmp);
		}
		return res;
	}
};

class Solution_1{
public:
	vector<string> findRepeatedDnaSequences(string s){
		vector<string> res;
		int len=s.size();
		cout<<len<<endl;
		if(len<10)
			return res;
		int hashKey=0;
		short *keyMap=new short[1<<20];
		//A,C,G,T they are the 1st,3rd,7th,20th character
		//mod5 can convert to 1,3,2,0
		for(int i=0;i<9;++i){
			hashKey=(hashKey<<2)|(s[i]-'A'+1)%5;
		}
		for(int i=9;i<len;++i){
			hashKey=((hashKey<<2)|(s[i]-'A'+1)%5)&0xfffff;
			keyMap[hashKey]++;
			if(keyMap[hashKey]==2)
				res.push_back(s.substr(i-9,10));
		}
		return res;
	}
};
//This solution beats 97.25 % of cpp submissions.
//19ms

int main(){
	string s="AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		;
	Solution_1 solution;
	vector<string> res=solution.findRepeatedDnaSequences(s);

	copy(res.begin(),res.end(),ostream_iterator<string>(cout,", "));
	return 0;
}




