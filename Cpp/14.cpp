// Write a function to find the longest common prefix string amongst an array of
// strings.
//
// If there is no common prefix, return an empty string "".
//
// Example 1:
//
// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:
//
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// Note:
//
// All given inputs are in lowercase letters a-z.
#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (!n) {
            return "";
        }

        for (int k = 0; k < strs[0].size(); ++k) {
            for (int i = 1; i < n; ++i) {
                if (strs[i][k] != strs[0][k]) {
					cout<<strs[i][k]<<endl;
                    return strs[0].substr(0, k);
                }
            }
        }

        return strs[0];
    }
};

int main(){
	Solution s;
	vector<string> strs = {"hello", "he", "helloworld"};
	string res = s.longestCommonPrefix(strs);
	cout<<res<<endl;

	return 0;
}
