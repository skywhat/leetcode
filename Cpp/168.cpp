#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		return n ? convertToTitle((n - 1) / 26) + char((n - 1) % 26 + 'A') : "";
	}
};

int main() {
	int n = 27;
	Solution s;
	cout << s.convertToTitle(n) << endl;

	return 0;
}