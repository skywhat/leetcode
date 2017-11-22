#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

class Solution {
    public:
    int calculate(string s) {
        stack<int> op;
        stack<int> help;
        int number=0;
        int sign=1;
        int res=0;
        for(auto c:s){
            if(isdigit(c)){
                number=number*10+c-'0';
            }
            else{
                res+=number*sign;
                number=0;
                if(c=='+')
                sign=1;
                else if(c=='-')
                sign=-1;
                else if(c=='('){
                    op.push(sign);
                    sign=1;//reset to 1, have a brand new expression.
                    help.push(res);
                    res=0;
                }
                else if(c==')'){
                    res=help.top()+op.top()*res;
                    help.pop();
                    op.pop();
                }
            }
        }
        res+=sign*number;
        return res;
    }
};

/*
 1-(2-(1+2))
 1 2
 - -
 res=-1
 1+-(-1)
 2
 
 */

int main(){

}
