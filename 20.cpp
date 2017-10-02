#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution{
public:
	bool isValid(string s){
		stack<char> bt;
		for(int i=0;i<s.size();++i){
			if(s[i]=='(')
				bt.push(s[i]);
			else if(s[i]=='{')
				bt.push(s[i]);
			else if(s[i]=='[')
				bt.push(s[i]);
			else if(s[i]==')'){
				if(bt.top()!='(')
					return false;
				else
					bt.pop();
			}
			else if(s[i]=='}'){
				if(bt.top()!='{')
					return false;
				else
					bt.pop();
			}
			else if(s[i]==']'){
				if(bt.top()!='[')
					return false;
				else 
					bt.pop();
			}
		}	
		if(bt.empty())
			return true;
		else
			return false;
	}
};

int main(){


}
