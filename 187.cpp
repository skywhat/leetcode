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

int main(){
	string s="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";	
	Solution solution;
	vector<string> res=solution.findRepeatedDnaSequences(s);

	copy(res.begin(),res.end(),ostream_iterator<string>(cout,", "));
	return 0;
}




