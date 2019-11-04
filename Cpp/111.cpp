// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the
// root node down to the nearest leaf node.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its minimum depth = 2.

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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int depth = 0;
        if (root) {
            q.push(root);
            depth++;
        }

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* temp = q.front();
                q.pop();
                if (!temp->left && !temp->right) {
                    return depth;
                }
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            depth++;
        }

        return depth;
    }
};

class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        if (!root->left) {
            return minDepth(root->right) + 1;
        }

        if (!root->right) {
            return minDepth(root->left) + 1;
        }

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
