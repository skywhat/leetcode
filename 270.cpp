/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note: 
Given target value is a floating point. 
You are guaranteed to have only one unique value in the BST that is closest to the target.

*/

#include<iostream>
#include<vector>
#include "Tree.h"
using namespace std;

class Solution {
public:
	int closestValue(TreeNode* root, double target) {
		int result = root->val;
		while (root) {
			if (abs(root->val - target) < abs(result - target))
				result = root->val;
			if (root->val < target)
				root = root->right;
			else
				root = root->left;
		}
		return result;
	}
};


int main() {
	double target = -1500000000;
	vector<int> treeListBST = { 1500000000,1400000000 };
	Solution s;
	TreeEnv t;

	TreeNode* root = t.initialTree(treeListBST);
	t.displayTree(root);
	cout << s.closestValue(root, target) << endl;
	return 0;
}