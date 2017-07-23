#include<iostream>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		int a = 1;
		int b = 1;
		for (int i = 2; i <= n; ++i) {
			a = a + b;
			//swap
			a = a + b;
			b = a - b;
			a = a - b;
		}
		return b;
	}
};

int main() {
	int n = 10;
	Solution s;
	cout << s.climbStairs(n) << endl;

	return 0;
}