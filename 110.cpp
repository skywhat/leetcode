#include<iostream>
#include "Tree.h"

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
    
    int getHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        
        int left = getHeight(root->left);
        if(left == -1){
            return -1;
        }
        
        int right = getHeight(root->right);
        if(right == -1){
            return -1;
        }
        
        if(abs(left - right)>1){
            return -1;
        }
        
        return max(left, right)+1;
    }
};
//in this bottom up approach, each node in the tree only need to be accessed once. Thus the time complexity is O(n)
int main(){

}

