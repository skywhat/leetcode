#include<iostream>
#include<stack>
#include "Tree.h"

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* curNode=root;
        while(curNode||!s.empty()){
            if(curNode){
                res.push_back(curNode->val);
                s.push(curNode);
                curNode=curNode->left;
            }else{
                curNode=s.top();
                s.pop();
                curNode=curNode->right;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }
    void preorder(TreeNode* root,vector<int>& res){
        if(root){
            res.push_back(root->val);
            preorder(root->left,res);
            preorder(root->right,res);
        }
    }
};
