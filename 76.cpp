#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128,0);
        for(auto c:t){
            m[c]++;
        }
        //m[c] means how many c we need in a window.
        int begin=0,end=0,head=0;
        int minLen=INT_MAX;
        int count=t.size();
        while(end<s.size()){
            if(m[s[end]]>0)
                count--;
            m[s[end]]--;
            //irrelevant characters become negative.
            end++;
            //count==0, means got a minmum window, narrow down the window by moving begin point forward.
            while(count==0){
                if(end-begin<minLen){
                    minLen=end-begin;
                    head=begin;
                }
                if(m[s[begin]]==0){
                    count++;
                    //count>0, we still need seek for another character to find a new window.
                }
                m[s[begin]]++;
                begin++;
            }
        }
        return minLen==INT_MAX?"":s.substr(head,minLen);
    }
};

int main(){
	string s1="ADOBECODEBANC";
	string s2="ABC";

	Solution s;
	string res=s.minWindow(s1,s2);
	cout<<res<<endl;

	return 0;
}




