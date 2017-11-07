#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for(int a=1;a<=3;++a){
            for(int b=1;b<=3;++b){
                for(int c=1;c<=3;++c){
                    for(int d=1;d<=3;++d){
                        if(a+b+c+d!=s.size())
                            continue;
                        int num1=stoi(s.substr(0,a));
                        int num2=stoi(s.substr(a,b));
                        int num3=stoi(s.substr(a+b,c));
                        int num4=stoi(s.substr(a+b+c,d));
                        if(num1>255||num2>255||num3>255||num4>255)
                            continue;
                        string tmp=to_string(num1)+"."+to_string(num2)+"."+to_string(num3)+"."+to_string(num4);
                        if(tmp.size()==s.size()+3)
                            res.push_back(tmp);
                    }
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<string> restoreIpAddresses(string s) {
        int pow10[]={0,10,100,1000};
        vector<string> res;
        for(int a=1;a<=3;++a){
            for(int b=1;b<=3;++b){
                for(int c=1;c<=3;++c){
                    for(int d=1;d<=3;++d){
                        if(a+b+c+d!=s.size())
                            continue;
                        int num1=stoi(s.substr(0,a));
                        if(num1>255||num1<pow10[a-1])
                            continue;
                        int num2=stoi(s.substr(a,b));
                        if(num2>255||num2<pow10[b-1])
                            continue;
                        int num3=stoi(s.substr(a+b,c));
                        if(num3>255||num3<pow10[c-1])
                            continue;
                        int num4=stoi(s.substr(a+b+c,d));
                        if(num4>255||num4<pow10[d-1])
                            continue;
                        string tmp=s.substr(0,a)+"."+s.substr(a,b)+"."+s.substr(a+b,c)+"."+s.substr(a+b+c,d);
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res;
    }
};
