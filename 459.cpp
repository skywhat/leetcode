#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=1;i<=n/2;++i){
            if(n%i==0){
                string sub=s.substr(0,i);
                if(sub==s.substr(i,i)){
                    int k=2*i;
                    while(k+i<=n){
                        if(sub!=s.substr(k,i))
                        break;
                        k+=i;
                    }
                    if(k==n)
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=1;i<=n/2;++i){
            if(n%i==0){
                if(s.substr(i)==s.substr(0,n-i))
                return true;
            }
        }
        return false;
    }
};

int main(){
    string test="abab";
    Solution s;
    cout<<s.repeatedSubstringPattern(test)<<endl;
    return 0;
}
