#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m=s.size(),n=t.size();
        if(s==t||abs(m-n)>1)
        return false;
        if(m<n)
        return isOneEditDistance(t,s);
        int i=0,j=0;
        while(i<=m&&j<=n){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                return m==n?isAfterOperate(s,t,i+1,j+1):isAfterOperate(s,t,i+1,j);
            }
        }
        return false;
    }
    bool isAfterOperate(string s,string t,int i,int j){
        while(i<=s.size()&&j<=t.size()){
            if(s[i++]!=t[j++])
            return false;
        }
        return true;
    }
    
};
/*
 teach
 teacher
 i
 j
 */

int main(){
    string t1="teacher";
    string t2="teach";
    
    Solution s;
    cout<<s.isOneEditDistance(t1,t2)<<endl;
    
    return 0;
}





