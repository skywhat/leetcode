#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int p=1000000007;
        if(s.size()==0)
            return 0;
        if(s.size()==1)
            return convert(s);
        if(s[0]=='0')
            return 0;
        long pre1=convert(s.substr(0,1));
        long pre2=1;
        long sum;
        for(int i=1;i<s.size();++i){
            int one=convert(s.substr(i,1));
            int two=convert(s.substr(i-1,2));
            sum=one*pre1+two*pre2;
            pre2=pre1;
            pre1=sum%p;
        }
        return sum%p;
    }
    int convert(const string& s){
        if(s.size()==1){
            if(s[0]=='*')
                return 9;
            return s[0]=='0'?0:1;
        }
        //11-19  21-26
        if(s=="**"){
            return 15;
        }
        if(s[0]=='*'){
            return s[1]<='6'?2:1;
        }
        if(s[1]=='*'){
            if(s[0]=='1')
                return 9;
            if(s[0]=='2')
                return 6;
            return 0;
        }
        if(stoi(s)>=10&&stoi(s)<=26)
            return 1;
        return 0;
    }
};

/*
 2*
 
 1 1
 1*6+1*9=15
 */

int main(){
    
    
}
