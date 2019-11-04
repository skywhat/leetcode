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
    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX;
        int prev = INT_MAX;        
        preorder(root, prev, min_diff);
        return min_diff;
    }
    
    void preorder(TreeNode* root, int& prev, int& min_diff){
        if(root){
            preorder(root->left, prev, min_diff);
            min_diff = min(min_diff, abs(root->val-prev));
            prev = root->val;
            preorder(root->right, prev, min_diff);
        }
    }
};
