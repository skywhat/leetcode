#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int i, j;
		for (i = 0, j = 0; i < t.size() && j < s.size(); ++i) {
			if (s[j] == t[i])
				j++;
		}
		if (j >= s.size())
			return true;
		else
			return false;
	}
};

int main() {
	string s = "abc";
	string t = "ahbgdc";
	Solution solution;
	cout << solution.isSubsequence(s, t) << endl;

	return 0;
}