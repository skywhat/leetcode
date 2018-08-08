#include<iostream>
#include<vector>

#include "Tree.h"

using namespace std;

//iterative
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> s;
        int sum_of_left_leaves = 0;
        if(root){
            s.push(root);
        }
        
        while(!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            
            if(cur->left){
                if(!cur->left->left && !cur->left->right){
                    sum_of_left_leaves += cur->left->val;
                }
                else {
                    s.push(cur->left);
                }
            }
            
            if(cur->right){
                s.push(cur->right);
            }
        }
        
        return sum_of_left_leaves;
    }
};

//recursive
class Solution2 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        if(root->left && !root->left->left && !root->left->right){
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

int main(){

}
