#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		unordered_set<int> s = { d(p1, p2) ,d(p1,p3),d(p1,p4),d(p2,p3),d(p2,p4),d(p3,p4)};
		if (s.size() != 2 || s.count(0))
			return false;
		else
			return true;
	}
	int d(const vector<int>& p1, const vector<int>& p2) {
		return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
	}
};

int main() {
	vector<int> p1 = {0,0};
	vector<int> p2 = {3,4};
	vector<int> p3 = {5,0};
	vector<int> p4 = {8,4};
	Solution s;
	cout << s.validSquare(p1,p2,p3,p4) << endl;
	return 0;
}