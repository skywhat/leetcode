#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        int m=num1.size();
        int n=num2.size();
        string res(m+n,'0');
        for(int i=m-1;i>=0;--i){
            int carry=0;
            for(int j=n-1;j>=0;--j){
                int unit=(num1[i]-'0')*(num2[j]-'0')+(res[i+j+1]-'0')+carry;
                res[i+j+1]=unit%10+'0';
                carry=unit/10;
            }
            res[i]+=carry;
        }
        for(int i=0;i<res.size();++i)
            if(res[i]!='0')
                return res.substr(i);
		return "";
    }
};
/*
1234
   9
m=4
n=1
0 0 0 0 0
  
*/

int main(){

}
