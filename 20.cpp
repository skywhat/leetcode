#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(i<s.size()){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                if(st.empty() || st.top() != '('){
                    return false;
                }
                st.pop();
            }
            else if(s[i] == ']'){
                if(st.empty() || st.top() != '['){
                    return false;
                }
                st.pop();
            }
            else if(s[i] == '}'){
                if(st.empty() || st.top() != '{'){
                    return false;
                }
                st.pop();
            }
            i++;
        }
        
        return st.empty();
    }
};

int main(){

}
