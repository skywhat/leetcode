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
		if (root&&!root->left && !root->right)
			return root->val;
		double distance = abs(root->val-target);
		double left_distance = root->left ? abs(root->left->val - target) : INT_MAX;
		double right_distance = root->right? abs(root->right->val-target):INT_MAX;
		if (distance < left_distance&&distance < right_distance)
			return root->val;
		else if (left_distance < right_distance)
			return closestValue(root->left, target);
		else
			return closestValue(root->right, target);
	}
};

class TreeEnv {
public:
	//Convert an array where elements are sorted in ascending order to binary search tree
	TreeNode* initialBinarySearchTree(const vector<int>& treeList) {
		if (!treeList.empty()) {
			return initialBinarySearchTree(treeList, 0, treeList.size() - 1);
		}
		else
			return NULL;
	}
	TreeNode* initialBinarySearchTree(const vector<int>& treeList,int left,int right) {
		if (left > right)
			return NULL;
		if (left == right) {
			return new TreeNode(treeList[left]);
		}
		int mid = (left + right) / 2;
		TreeNode* root = new TreeNode(treeList[mid]);
		root->left = initialBinarySearchTree(treeList,left,mid-1);
		root->right = initialBinarySearchTree(treeList,mid+1,right);
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
	double target = 2.1;
	vector<int> treeListBST = {1,2,3,4,5,6,7};
	Solution s;
	TreeEnv t;
	TreeNode* rootBST = t.initialBinarySearchTree(treeListBST);
	t.displayTree(rootBST);
	cout << s.closestValue(rootBST, target) << endl;
	return 0;
}
