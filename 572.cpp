#include<iostream>
#include "Tree.h"


class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==nullptr)
        return false;
        return isSametree(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);
    }
    bool isSametree(TreeNode* s,TreeNode* t){
        if(s==nullptr&&t==nullptr)
        return true;
        if(s==nullptr||t==nullptr)
        return false;
        if(s->val==t->val){
            return isSametree(s->left,t->left)&&isSametree(s->right,t->right);
        }
        else
        return false;
        
    }
};
