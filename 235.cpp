#include<iostream>
#include "Tree.h"

using namespace std;


//recursive
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val<p->val&&root->val<q->val)
        	return lowestCommonAncestor(root->right,p,q);
        else if(root->val>p->val&&root->val>q->val)
        	return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};

//iterative
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while((root->val-p->val)*(root->val-q->val)>0)
            root=(p->val>root->val?root->right:root->left);
        return root;
    }
};

int main(){
    
}
