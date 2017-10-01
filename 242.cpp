/*
 
 Given two strings s and t, write a function to determine if t is an anagram of s.
 
 For example,
 s = "anagram", t = "nagaram", return true.
 s = "rat", t = "car", return false.
 
 Note:
 You may assume the string contains only lowercase alphabets.
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        vector<int> m(128,0);
        for(auto c:s)
            m[c]++;
        for(auto c:t)
            m[c]--;
        for(int i='a';i<='z';++i)
            if(m[i]!=0)
                return false;
        return true;
    }
};


int main(){

}
