/*
 *
 * sort an input string using an arbitrary alphabet
 * for example: custom alphabet: xyzabc
 * input to sort according to custom alphabet: cyxz
 * ouput according to custom alphabet:xyzc
 *
 */


#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
public:
	string customSort(string table,string alpha){
		string res;
		vector<int> count(128,0);
		for(auto a:alpha){
			count[a]++;
		}
		for(auto t:table){
			while(count[t]--){
				res+=t;
			}
		}
		return res;
	}
};

int main(){
	string table="xyzabc";
	string alphabet="cyxz";
	Solution s;

	cout<<s.customSort(table,alphabet)<<endl;

	return 0;
}
