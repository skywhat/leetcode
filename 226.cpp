#include<iostream>
#include "Tree.h"

using namespace std;

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root)
			return nullptr;
		if (!root->left && !root->right)
			return root;
		TreeNode* left = invertTree(root->left);
		TreeNode* right = invertTree(root->right);
		root->left = right;
		root->right = left;
		return root;
	}
};

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
        }
        
        return root;
    }
};

int main() {
	TreeEnv t;
	vector<int> list = {4,2,7,1,3,6,9};
	TreeNode* root=t.initialTree(list);
	t.displayTree(root);

	Solution s;
	TreeNode* invertTree = s.invertTree(root);
	t.displayTree(invertTree);
	return 0;
}

