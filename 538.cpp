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
    TreeNode* convertBST(TreeNode* root) {
        int base = 0;
        preorder_backwards(root, base);
        return root;
    }
    
    void preorder_backwards(TreeNode*& root, int& base){
        if(root){
            preorder_backwards(root->right, base);
            base += root->val;
            root->val = base;
            preorder_backwards(root->left, base);
            
        }
    }
};
