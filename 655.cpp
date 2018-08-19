#include "Tree.h"
#include <iostream>
#include <queue>
#include <string>
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
    vector<vector<string>> printTree(TreeNode* root) {
        int total_depth = getDepth(root);
        int width = (1 << total_depth) - 1;
        vector<vector<string>> res(total_depth, vector<string>(width, ""));
        queue<TreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }
        int depth = 0;
        int gap = width;

        while (!nodes.empty() && depth < total_depth) {
            int size = nodes.size();
            gap = gap / 2;
            int pos = gap;

            while (size--) {
                TreeNode* node = nodes.front();
                nodes.pop();
                if (node) {
                    nodes.push(node->left);
                    nodes.push(node->right);
                } else {
                    nodes.push(nullptr);
                    nodes.push(nullptr);
                }
                if (node) {
                    res[depth][pos] = to_string(node->val);
                }
                pos += 2 * gap + 2;
            }

            depth++;
        }

        return res;
    }

    int getDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
};

int main() {
    TreeEnv t;
    vector<int> list = {1,2,5,3,NULL_TREENODE,NULL_TREENODE,NULL_TREENODE,4,NULL_TREENODE};
    vector<int> list1
        = {3,  NULL_TREENODE, 30, 10, NULL_TREENODE, NULL_TREENODE,
           15, NULL_TREENODE, 45};
    TreeNode* root = t.initialTree(list);
    Solution s;

    vector<vector<string>> res = s.printTree(root);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
 [3,null,30,10,null,null,15,null,45]
 */
