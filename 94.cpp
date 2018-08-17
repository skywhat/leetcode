#include "Tree.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    void inorder(TreeNode* root, vector<int>& res) {
        if (root) {
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;

        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }

        return res;
    }
};
