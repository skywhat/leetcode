#include "Tree.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* new_root = new TreeNode(v);
            new_root->left = root;
            return new_root;
        }

        queue<TreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }

        int depth = 2;
        while (!nodes.empty()) {
            int size = nodes.size();
            while (size--) {
                TreeNode* temp = nodes.front();
                nodes.pop();
                if (depth == d) {
                    TreeNode* new_left = new TreeNode(v);
                    TreeNode* new_right = new TreeNode(v);
                    new_left->left = temp->left;
                    new_right->right = temp->right;
                    temp->left = new_left;
                    temp->right = new_right;
                } else {
                    if (temp->left) {
                        nodes.push(temp->left);
                    }
                    if (temp->right) {
                        nodes.push(temp->right);
                    }
                }
            }
            depth++;
            if (depth > d) {
                break;
            }
        }

        return root;
    }
};

int main() {
    TreeEnv t;
    vector<int> list = {4, 2, 6, 3, 1, 5};
    TreeNode* root = t.initialTree(list);

    Solution s;

    t.displayTree(root);
    TreeNode* newOne = s.addOneRow(root, 1, 4);
    t.displayTree(newOne);

    return 0;
}
