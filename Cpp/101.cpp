class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        
        return isSameNode(root->left, root->right);
    }
    
    bool isSameNode(TreeNode* left, TreeNode* right){
        if(!left && !right){
            return true;
        }
        if(!left || !right){
            return false;
        }
        if(left->val != right->val){
            return false;
        }
        
        return isSameNode(left->left, right->right) &&
            isSameNode(left->right, right->left);
    }
};
