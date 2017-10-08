#include<iostream>
#include<vector>
#include<stack>
#include "Tree.h"

using namespace std;


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
    void inorder(TreeNode* root,vector<int>& res){
        if(root){
            inorder(root->left,res);
            res.push_back(root->val);
            inorder(root->right,res);
        }
    }
};

class Solution2{
public:
    vector<int> inorderTraversal(TreeNode* root){
        stack<TreeNode*> s;
        vector<int> res;
        s.push(root);
        while(root&&!s.empty()){
            while(root->left){
                s.push(root->left);
                root=root->left;
            }
            TreeNode* temp=s.top();
            s.pop();
            res.push_back(temp->val);
            if(temp->right){
                root=temp->right;
                s.push(root);
            }
        }
        return res;
    }
};
