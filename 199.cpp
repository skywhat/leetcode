// Given a binary tree, imagine yourself standing on the right side of it,
// return the values of the nodes you can see ordered from top to bottom.
//
// Example:
//
// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:
//
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto temp = q.front();
                q.pop();

                if (size == 0) {
                    res.push_back(temp->val);
                }

                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }

        return res;
    }
};

class Solution2 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        preorder(root, 1, res);
        return res;
    }

    void preorder(TreeNode* root, int level, vector<int>& res) {
        if (root) {
            if (res.size() < level) {
                res.push_back(root->val);
            }
            preorder(root->right, level + 1, res);
            preorder(root->left, level + 1, res);
        }
    }
};
