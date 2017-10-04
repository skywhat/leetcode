/*
 
 
 A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 
 Write a function to determine if a number is strobogrammatic. The number is represented as a string.
 
 For example, the numbers "69", "88", and "818" are all strobogrammatic.
 
 
 */

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution{
public:
	bool isStrobogrammatic(string num){
		unordered_map<char,char> m={
			{'0','0'},{'1','1'},{'6','9'},{'9','6'},{'8','8'}
		};
		int i=0,j=num.size()-1;
		while(i<=j){
			if(num[i++]!=m[num[j--]])
				return false;
		}
		return true;
	}
};

int main(){
	string test="818";
	Solution s;
	cout<<s.isStrobogrammatic(test)<<endl;

	return 0;
}
