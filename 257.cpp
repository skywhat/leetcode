#include<iostream>
#include<vector>

#include "Tree.h"

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root,res,"");
        return res;
    }
    void dfs(TreeNode* root,vector<string>& res,string temp){
        if(root){
            temp+=to_string(root->val);
            if(!root->left&&!root->right)
            res.push_back(temp);
            else{
                dfs(root->left,res,temp+"->");
                dfs(root->right,res,temp+"->");
            }
        }
    }
};

int main(){

}
