#include<iostream>
#include "Tree.h"

using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return hasSum(root,sum);
    }
    bool hasSum(TreeNode* root,int sum){
        if(root){
            sum-=root->val;
            if(!root->left&&!root->right){
                return sum==0;
            }
            else{
                return hasSum(root->left,sum)||hasSum(root->right,sum);
            }
        }
        return false;
    }
};

int main(){
    
}
