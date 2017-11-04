#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        s='+'+s+'+';
        istringstream in(s);
        char op;
        int term=0;
        int res=0;
        int num;
        while(in>>op){
            if(op=='+'||op=='-'){
                res+=term;
                in>>term;
                term*=(op=='+'?1:-1);
            }
            else{
                in>>num;
                if(op=='*')
                    term*=num;
                else
                    term/=num;
            }
        }
        return res;
    }
};


int main(){

}
