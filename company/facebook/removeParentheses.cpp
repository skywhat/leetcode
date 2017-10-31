/*
 *remove invalid Parentheses just return the longest one in linear time
 */

#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class Solution{
public:
	string remove(string s){
		stack<char> left;
		stack<char> right;
		for(int i=0;i<s.size();++i){
			if(s[i]=='(')
				left.push(i);
			else if(s[i]==')'){
				if(left.empty()){
					right.push(i);
				}
				else{
					left.pop();
				}
			}
		}
		/*
		 you can also use set to store the left and right stack position.
		 check is it exists when you construct a new valid parentheses
		 */
		while(!left.empty()){
			s[left.top()]='*';
			left.pop();
		}
		while(!right.empty()){
			s[right.top()]='*';
			right.pop();
		}
		string res;
		for(auto c:s){
			if(c!='*')
				res+=c;
		}
		return res;
	}
};

int main(){
	Solution s;
	string test="(()(";
	cout<<s.remove(test)<<endl;

	return 0;
}
