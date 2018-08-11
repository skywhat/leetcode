#include<iostream>
#include "Tree.h"

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s){
            return false;
        }
        
        return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t); 
    }
    
    bool isSameTree(TreeNode* s, TreeNode* t){
        if(!s && !t){
            return true;
        }
        
        if(!s || !t){
            return false;
        }
        
        if(s->val != t->val){
            return false;
        }
        
        return isSameTree(s->left, t->left) && 
            isSameTree(s->right, t->right);
    }
};
