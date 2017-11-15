#include<iostream>
#include<vector>

#include "Tree.h"

using namespace std;

//iterative
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res=0;
        stack<TreeNode*> s;
        if(root)
            s.push(root);
        while(!s.empty()){
            TreeNode* cur=s.top();
            s.pop();
            if(cur->left){
                if(!cur->left->left&&!cur->left->right)
                    res+=cur->left->val;
                else
                    s.push(cur->left);
            }
            if(cur->right){
                if(cur->right->left||cur->right->right)
                    s.push(cur->right);
            }
        }
        return res;
    }
};

//recursive
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        if(root->left){
            if(!root->left->left&&!root->left->right)
                return root->left->val+sumOfLeftLeaves(root->right);
            return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->right);
        
    }
};

int main(){

}
