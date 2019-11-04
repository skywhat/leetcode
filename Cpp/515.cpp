/*
You need to find the largest value in each row of a binary tree.

Example:
Input:

          1
         / \
        3   2
       / \   \
      5   3   9

Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<int> res;
        if (root) {
            nodes.push(root);
        }

        while (!nodes.empty()) {
            int size = nodes.size();
            int max_val = INT_MIN;

            while (size--) {
                TreeNode* node = nodes.front();
                nodes.pop();
                max_val = max(max_val, node->val);
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
            }

            res.push_back(max_val);
        }

        return res;
    }
};
