/*
 
 
 Given an absolute path for a file (Unix-style), simplify it.
 
 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"
 
 
 */


#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        for(int i=0;i<path.size();++i)
            if(path[i]=='/')
                path[i]=' ';
        istringstream in(path);
        string unit;
        vector<string> collect;
        while(in>>unit){
            collect.push_back(unit);
        }
        string res;
        for(int i=collect.size()-1,skip=0;i>=0;--i){
            if(collect[i]==".")
                continue;
            if(collect[i]==".."){
                skip++;
                continue;
            }
            if(skip>0){
                skip--;
                continue;
            }
            res=collect[i]+(res.size()?"/":"")+res;
        }
        return "/"+res;
    }
};

int main(){

}
