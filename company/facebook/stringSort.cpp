/*
 *given a list of words.
 *sort the words according to the string below
 * htarfbp
 *
 */
#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

class Solution{
public:
	struct compare{
		map<char,int> morder;
		compare(const string& table){	
		for(int i=0;i<table.size();i++)
			morder[table[i]]=i;
		}
		bool operator()(const string& s1,const string& s2){
			int i=0;
			while(i<s1.size()&&i<s2.size()){
				if(s1[i]!=s2[i])
					return morder[s1[i]]<morder[s2[i]];
				i++;
			}
			return s1.size()<s2.size();
		}
	};
	void newOrder(vector<string>& words,string& table){
		sort(words.begin(),words.end(),compare(table));
	}

};

int main(){
	Solution s;
	vector<string> words={"act","face","high","ball","apple","art","ah","aha","ahh","people","red"};
	string table="htarfbpc";
	s.newOrder(words,table);
	cout<<"table: "<<table<<endl;
	copy(words.begin(),words.end(),ostream_iterator<string>(cout,", "));
	cout<<endl;
	return 0;
}








