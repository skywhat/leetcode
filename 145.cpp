#include<iostream>
#include<stack>
#include "Tree.h"

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }
    void postorder(TreeNode* root,vector<int>& res){
        if(root){
            postorder(root->left,res);
            postorder(root->right,res);
            res.push_back(root->val);
            
        }
    }
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* curNode=root;
        TreeNode* temp;
        while(curNode||!s.empty()){
            if(curNode){
                s.push(curNode);
                curNode=curNode->left;
            }else{
                TreeNode* temp=s.top();
                if(temp->right){
                    curNode=temp->right;
                    temp->right=nullptr;
                }else{
                    res.push_back(temp->val);
                    s.pop();
                }
            }
        }
        return res;
    }
};
