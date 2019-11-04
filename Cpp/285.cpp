#include<iostream>
#include<stack>
#include "Tree.h"

using namespace std;

//recursive O(lgn)
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root||!p)
        return nullptr;
        if(root->val<=p->val)
        return inorderSuccessor(root->right,p);
        else
        {
            TreeNode* successor=inorderSuccessor(root->left,p);
            return successor?successor:root;
        }
    }
};

//iterative O(lgn)
class Solution2 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root||!p)
        return nullptr;
        TreeNode* successor=nullptr;
        while(root){
            if(root->val<=p->val)
            root=root->right;
            else{
                successor=root;
                root=root->left;
            }
        }
        return successor;
    }
};

//iterative O(n) if the tree is not a binary search one.
class Solution3 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        TreeNode* curNode=root;
        TreeNode* successor=nullptr;
        bool flag=false;
        
        while(!s.empty()||curNode){
            if(curNode){
                s.push(curNode);
                curNode=curNode->left;
            }
            else{
                curNode=s.top();
                s.pop();
                if(curNode==p){
                    flag=true;
                }
                if(flag&&curNode!=p){
                    successor=curNode;
                    break;
                }
                curNode=curNode->right;
            }
            
        }
        return successor;
    }
};

//recursive O(n) if the tree is not a binary search one.
class Solution4 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> help={nullptr,nullptr};
        TreeNode* res=nullptr;
        inorder(root,help,res,p);
        return res;
    }
    void inorder(TreeNode* root,vector<TreeNode*>& help,TreeNode*& res,TreeNode* p){
        if(root){
            inorder(root->right,help,res,p);
            help[0]=help[1];
            help[1]=root;
            if(help[1]==p){
                res=help[0];
                return;
            }
            inorder(root->left,help,res,p);
        }
    }
};

int main(){

}
