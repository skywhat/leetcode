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
    int diameterOfBinaryTree(TreeNode* root) {
        int max_path = 0;
        maxDepth(root, max_path);
        return max_path;
    }
    
    int maxDepth(TreeNode* root, int& max_path){
        if(!root){
            return 0;
        }
        
        int left_depth = maxDepth(root->left, max_path);
        int right_depth = maxDepth(root->right, max_path);
        max_path = max(max_path, left_depth + right_depth);
        
        return max(left_depth, right_depth)+1;
    }
};
