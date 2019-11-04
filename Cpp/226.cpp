#include "Tree.h"
#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* right = invertTree(root->left);
        TreeNode* left = invertTree(root->right);
        root->left = left;
        root->right = right;
        return root;
    }
};

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
        }

        return root;
    }
};

int main() {
    TreeEnv t;
    vector<int> list = {4, 2, 7, 1, 3, 6, 9};
    TreeNode* root = t.initialTree(list);
    t.displayTree(root);

    Solution s;
    TreeNode* invertTree = s.invertTree(root);
    t.displayTree(invertTree);
    return 0;
}
