#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        
        string res;
        for(int i=0;i<strs[0].size();++i){
            for(int j=1;j<strs.size();++j){
                if(strs[j].size()<=i || strs[j][i] != strs[0][i]){
                    return res;
                }
            }
            res += strs[0][i];
        }
        
        return res;
    }
};
