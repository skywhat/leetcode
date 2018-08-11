/*
 
 
 A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 
 Write a function to determine if a number is strobogrammatic. The number is represented as a string.
 
 For example, the numbers "69", "88", and "818" are all strobogrammatic.
 
 
 */

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
private:
    string rotate = "01____9_86";
public:
    bool isStrobogrammatic(string num) {
        string upside_down;
        for(int i=num.size()-1;i>=0;--i){
            upside_down += rotate[num[i]-'0'];
        }
        
        return upside_down == num;
    }
};

int main(){
	string test="818";
	Solution s;
	cout<<s.isStrobogrammatic(test)<<endl;

	return 0;
}
