#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> m(128,0);
        int j=-1;
        int res=0;
        int cnt=0;
        for(int i=0;i<s.size();++i){
            cnt+=m[s[i]]==0;
            m[s[i]]++;
            
            while(cnt>2){
                j++;
                m[s[j]]--;
                cnt-=m[s[j]]==0;
            }
            res=max(res,i-j);
        }
        return res;
    }
};
