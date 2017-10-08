#include<iostream>
#include<vector>
#include "Tree.h"

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q)
        return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left){
            if(right)
            return root;
            else
            return left;
        }
        else
        return right;
    }
};

int main(){

}
