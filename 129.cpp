#include<iostream>
#include<vector>
#include "Tree.h"
using namespace std;

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		int sum = 0;
		get(root,sum,0);
		return sum;
	}
	void get(TreeNode* root,int &sum,int num) {
		if (!root)
			return;
		num = num * 10 + root->val;
		if (!root->left && !root->right)
			sum += num;
		else {
			get(root->left, sum, num);
			get(root->right, sum, num);
		}
	}
};
int main() {
	TreeEnv t;
	vector<int> list = {1,2,3};
	TreeNode* root = t.initialTree(list);
	Solution s;
	cout << s.sumNumbers(root) << endl;

	return 0;

}