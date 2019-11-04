#include<iostream>
#include<string>
#include<iterator>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string::iterator begin = s.begin();
        string::iterator end = begin;
        while(end!=s.end()){
            if(*end == ' '){
                reverse(begin, end);
                begin = ++end;
            }
            else{
                end++;
            }
        }
        
        if(begin != end){
            reverse(begin, end);
        }
        
        return s;
    }
};

int main(){
	Solution s;
	string test = "Let's take LeetCode contest";
	string expect = "s'teL ekat edoCteeL tsetnoc";

	cout<< (expect == s.reverseWords(test)) <<endl;

	return 0;
}




