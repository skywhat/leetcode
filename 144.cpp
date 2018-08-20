#include "Tree.h"
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;

        while (root || !s.empty()) {
            if (root) {
                res.push_back(root->val);
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
    void preorder(TreeNode* root, vector<int>& res) {
        if (root) {
            res.push_back(root->val);
            preorder(root->left, res);
            preorder(root->right, res);
        }
    }
};
