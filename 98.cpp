#include<iostream>
#include<vector>
#include<stack>

#include "Tree.h"

using namespace std;

//iterative
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* prev=nullptr;
        while(root||!s.empty()){
            while(root){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(prev&&prev->val>=root->val){
                return false;
            }
            prev=root;
            root=root->right;
        }
        return true;
    }
};

//recursive
class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root,nullptr,nullptr);
    }
    bool isValid(TreeNode* root,TreeNode* min,TreeNode* max){
        if(!root)
            return true;
        if(min&&root->val<=min->val)
            return false;
        if(max&&root->val>=max->val)
            return false;
        return isValid(root->left,min,root)&&isValid(root->right,root,max);
    }
};

int main(){

}


