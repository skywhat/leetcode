#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution{
public:
	int lengthOfLongestSubstring(string s){
		vector<int> pos(256,-1);
		int start=-1;
		int res=0;
		for(int i=0;i<s.size();++i){
			if(pos[s[i]]>start)
				start=pos[s[i]];
			pos[s[i]]=i;
			res=max(res,i-start);
		}	
		return res;
	}
};

int main(){
	string testcase="abcabcbb";
	string testcase1="dvdf";
	Solution s;
	cout<<s.lengthOfLongestSubstring(testcase)<<endl;

	return 0;
}
/*
 *        d     v     d     f
 *  -1    0     1     2     3
 *
 *  start i
 *
 *
 *        d     v     d     f
 *  -1    0     1     2     3
 *
 *  start       i
 *
 *
 *        d     v     d     f
 *  -1    0     1     2     3
 *
 *  start             i
 *(when d appear again, start should be in previous d position.)
 *
 *
 *        d     v     d     f
 *  -1    0     1     2     3
 *
 *      start         i
 *
 *
 *        d     v     d     f
 *  -1    0     1     2     3
 *
 *       start              i
 */

