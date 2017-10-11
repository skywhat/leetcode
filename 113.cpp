#include<iostream>
#include<vector>

#include "Tree.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> temp;
        path(root,res,temp,sum);
        return res;
    }
    void path(TreeNode* root,vector<vector<int>>& res,vector<int>& temp,int sum){
        if(root){
            temp.push_back(root->val);
            sum-=root->val;
            if(!root->left&&!root->right){
                if(sum==0)
                res.push_back(temp);
            }
            else{
                path(root->left,res,temp,sum);
                path(root->right,res,temp,sum);
            }
            temp.pop_back();
        }
    }
};

int main(){
    
}
