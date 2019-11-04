#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> m(128,0);
        int j=-1;
        int cnt=0;
        int res=0;
        for(int i=0;i<s.size();++i){
            cnt=cnt+(m[s[i]]==0);
            m[s[i]]++;
            
            while(cnt>k){
                j++;
                m[s[j]]--;
                cnt=cnt-(m[s[j]]==0);
            }
            res=max(res,i-j);
        }
        return res;
    }
};

int main(){

}
