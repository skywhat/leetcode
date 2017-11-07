#include<iostream>
#include<string>
#include<vector>

using namespace std;


//recursive
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> m={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.size()==0)
            return res;
        combine(digits,0,res,m,"");
        return res;
    }
    void combine(string digits,int pos,vector<string>& res,vector<string>& m,string tmp){
        if(pos==digits.size()){
            res.push_back(tmp);
            return;
        }
        for(auto c:m[digits[pos]-'0']){
            combine(digits,pos+1,res,m,tmp+c);
        }
    }
    
};

//iterative
class Solution2 {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0)
            return res;
        vector<string> m={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        res.push_back("");
        for(int i=0;i<digits.size();++i){
            vector<string> tmp;
            for(int j=0;j<m[digits[i]-'0'].size();++j){
                for(int k=0;k<res.size();++k){
                    tmp.push_back(res[k]+m[digits[i]-'0'][j]);
                }
            }
            res=tmp;
        }
        return res;
    }
};

int main(){
    
}
