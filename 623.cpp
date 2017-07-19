#include<iostream>
#include<vector>
#include<queue>
#include "Tree.h"
using namespace std;

class Solution {
public:
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1) {
			TreeNode* newRoot = new TreeNode(v);
			newRoot->left = root;
			return newRoot;
		}
		queue<TreeNode*> q;
		int depth = 2;
		if (root)
			q.push(root);
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				TreeNode* tmp = q.front();
				q.pop();
				if (d == depth) {
					TreeNode* new_left = new TreeNode(v);
					TreeNode* new_right = new TreeNode(v);
					new_left->left = tmp->left;
					new_right->right = tmp->right;
					tmp->left = new_left;
					tmp->right = new_right;

				}
				else {
					if (tmp->left)
						q.push(tmp->left);
					if (tmp->right)
						q.push(tmp->right);
				}
			}
			depth++;
			if (d < depth)
				break;
		}
		return root;
	}
};

int main() {
	TreeEnv t;
	vector<int> list = { 4,2,6,3,1,5 };
	TreeNode* root = t.initialTree(list);

	Solution s;

	t.displayTree(root);
	TreeNode* newOne = s.addOneRow(root, 1, 4);
	t.displayTree(newOne);

	return 0;

}