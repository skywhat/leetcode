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
        int minVal=INT_MAX;
        int prev=INT_MAX;
        int cur;
        dfs(root,minVal,prev,cur);
        return minVal;
    }
    
    void dfs(TreeNode* root,int& minVal,int& prev, int& cur){
        if(root){
            dfs(root->left,minVal,prev,cur);
            cur=root->val;
            minVal=min(minVal,abs(cur-prev));
            prev=cur;
            dfs(root->right,minVal,prev,cur);
        }
    }
};
