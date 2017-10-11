#include<iostream>

#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    char pair[2]={'(',')'};
    char _pair[2]={')','('};
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        remove(s,0,0,pair,res);
        return res;
    }
    void remove(string s,int last_i,int last_j,char* pair,vector<string>& res){
        int stack=0;
        for(int i=last_i;i<s.size();++i){
            if(s[i]==pair[0])
            stack++;
            else if(s[i]==pair[1])
            stack--;
            if(stack>=0)
            continue;
            for(int j=last_j;j<=i;++j){
                if(s[j]==pair[1]&&(j==last_j||(s[j-1]!=s[j]))){
                    remove(s.substr(0,j)+s.substr(j+1),i,j,pair,res);
                    //if you just want to get only one valid string, add break below.
                    //break;
                }
            }
            return;
            
        }
        reverse(s.begin(),s.end());
        if(pair[0]=='(')
        //still need to check the reversed string to make it legal
            remove(s,0,0,_pair,res);
        else
            res.push_back(s);
        
    }
};

//just need one valid string
class Solution2 {
public:
    char pair[2]={'(',')'};
    char _pair[2]={')','('};
    string removeInvalidParentheses(string s) {
        remove(s,0,0,pair);
        return s;
    }
    void remove(string& s,int last_i,int last_j,char* pair){
        int stack=0;
        for(int i=last_i;i<s.size();++i){
            if(s[i]==pair[0])
                stack++;
            else if(s[i]==pair[1])
                stack--;
            if(stack>=0)
                continue;
            for(int j=last_j;j<=i;++j){
                if(s[j]==pair[1]&&(j==last_j||s[j-1]!=s[j])){
                    s.erase(s.begin()+j);
                    remove(s,i,j,pair);
                    break;
                }
            }
            return;
        }
        reverse(s.begin(),s.end());
        if(pair[0]=='(')
            remove(s,0,0,_pair);
    }
};

int main(){
	string test="(a)())()";	
	Solution2 s;
	string res=s.removeInvalidParentheses(test);
	cout<<res<<endl;

    return 0;

}



