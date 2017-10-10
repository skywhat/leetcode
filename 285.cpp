#include<iostream>
#include<stack>
#include "Tree.h"

using namespace std;

//recursive
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

//iterative O(n)
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

int main(){

}
