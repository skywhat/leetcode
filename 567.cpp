#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int cnt=s1.size();
        vector<int> m(128,0);
        for(auto c:s1)
            m[c]++;
        int start=0,end=0;
        while(end<s2.size()){
            if(m[s2[end]]>0)
                cnt--;
            m[s2[end]]--;
            end++;
            while(cnt==0){
                if(m[s2[start]]==0)
                    if(end-start==s1.size())
                        return true;
                m[s2[start]]++;
                if(m[s2[start]]>0)
                    cnt++;
                start++;
            }
        }
        return false;
    }
};

int main(){

}
