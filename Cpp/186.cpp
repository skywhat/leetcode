#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void reverseWords(vector<char>& str) {
        int n=str.size();
        reverse(str,0,n-1);
        int i=0,j=0;
        for(;i<n;){
            while(j<n&&str[j]!=' ')
                j++;
            reverse(str,i,j-1);
            i=++j;
        }
    }
    void reverse(vector<char>& str,int i,int j){
        while(i<j){
            char tmp=str[i];
            str[i]=str[j];
            str[j]=tmp;
            i++;
            j--;
        }
    }
};
