#include<iostream>
#include<string>
#include<vector>

using namespace std;


//brute force
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size(),n=needle.size();
        int i=0;
        while(i+n<=m){
            int cnt=0;
            int prev=i;
            while(cnt<n&&haystack[i+cnt]==needle[cnt]){
                cnt++;
            }
            if(cnt==n)
                return i;
            else
                i=prev+1;
        }
        return -1;
    }
};


//KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size(),n=needle.size();
        if(m<n)
            return -1;
        if(m==n)
            return haystack==needle?0:-1;
        auto table=kmp(needle);
        for(auto t:table)
            cout<<t<<", ";
        int i=0,j=0;
        while(n-j+i<=m){//n-j the remaining string we need match,i the current index in haystack.
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==n)
                return i-j;
            if(haystack[i]!=needle[j]){
                if(j>0)
                    j=table[j-1];
                else
                    i++;
            }
        }
        return -1;
    }
    //generate partial match table.
    vector<int> kmp(string& needle){
        int n=needle.size();
        vector<int> table(n,0);
        int i=0,j=1;
        while(j<n){
            if(needle[i]==needle[j]){
                i++;
                table[j]=i;
                j++;
            }
            else if(i>0){
                i=table[i-1];
            }
            else{
                table[j]=0;
                j++;
                
            }
        }
        return table;
    }
};
//a example: partial match table
//a  b  a  b  a  b  c  a  b
//0, 0, 1, 2, 3, 4, 0, 1, 2,

/*
 http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
 http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
 */

int main(){
}
