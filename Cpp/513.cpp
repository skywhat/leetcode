/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
*/

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> nodes;
        int leftmost_val;
        if (root) {
            nodes.push(root);
        }

        while (!nodes.empty()) {
            int size = nodes.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* cur_node = nodes.front();
                nodes.pop();
                if (i == 0) {
                    leftmost_val = cur_node->val;
                }

                if (cur_node->left) {
                    nodes.push(cur_node->left);
                }
                if (cur_node->right) {
                    nodes.push(cur_node->right);
                }
            }
        }

        return leftmost_val;
    }
};

class Solution2 {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> nodes;
        if (root) {
            nodes.push(root);
        }

        while (!nodes.empty()) {
            root = nodes.front();
            nodes.pop();

            if (root->right) {
                nodes.push(root->right);
            }
            if (root->left) {
                nodes.push(root->left);
            }
        }

        return root->val;
    }
};
