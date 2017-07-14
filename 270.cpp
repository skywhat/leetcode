/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note: 
Given target value is a floating point. 
You are guaranteed to have only one unique value in the BST that is closest to the target.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
#include<queue>

using namespace std;

#define NULL_TREENODE INT_MIN

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int closestValue(TreeNode* root, double target) {
		double dist = abs(root->val - target);
		int result = root->val;
		closestValue(root, target, result, dist);
		return result;

	}
	void closestValue(TreeNode* root, const double& target, int &result, double &dist) {
		if (root && root->left == nullptr && root->right == nullptr) {
			return;
		}
		double leftDist = root->left != nullptr ? abs(root->left->val - target) : INT_MAX;
		double rightDist = root->right != nullptr ? abs(root->right->val - target) : INT_MAX;
		if (leftDist < rightDist) {
			if (dist > leftDist) {
				result = root->left->val;
				dist = leftDist;
			}
			closestValue(root->left, target, result, dist);
		}
		else {
			if (dist > rightDist) {
				result = root->right->val;
				dist = rightDist;
			}
			closestValue(root->right, target, result, dist);
		}
	}

};

class TreeEnv {
public:
	TreeNode* initialTree(const vector<int>& treeList) {
		queue<TreeNode*> q;
		TreeNode* root;
		if (!treeList.empty()) {
			root = new TreeNode(treeList[0]);
			q.push(root);
		}
		else
			return NULL;
		int index = 1;
		while (!q.empty()) {
			TreeNode* tmp = q.front();
			q.pop();
			if (index < treeList.size()) {
				if (treeList[index] != NULL_TREENODE) {
					tmp->left = new TreeNode(treeList[index]);
					q.push(tmp->left);
				}
				index++;
			}
			if (index < treeList.size()) {
				if (treeList[index] != NULL_TREENODE) {
					tmp->right = new TreeNode(treeList[index]);
					q.push(tmp->right);
				}
				index++;
			}
		}
		return root;
	}


	void displayTree(TreeNode* root) {
		queue<TreeNode*> q;
		if (root) {
			q.push(root);
			cout << root->val << endl;
		}
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				TreeNode* tmp = q.front();
				q.pop();
				if (tmp->left) {
					q.push(tmp->left);
					cout << tmp->left->val << " ";
				}
				if (tmp->right) {
					q.push(tmp->right);
					cout << tmp->right->val << " ";
				}
			}
			cout << endl;
		}
	}
};

int main() {
	double target = 0.4;
	vector<int> treeListBST = {3,1,5,0,2};
	Solution s;
	TreeEnv t;

	TreeNode* root = t.initialTree(treeListBST);
	t.displayTree(root);
	cout << s.closestValue(root, target) << endl;
	return 0;
}