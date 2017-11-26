#include<iostream>
#include<vector>

#include "Tree.h"

using namespace std;

//recursive
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

//iterative
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        queue<TreeNode*> q;
        queue<string> paths;
        vector<string> res;
        if(root){
            q.push(root);
            paths.push(to_string(root->val));
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeNode* cur=q.front();q.pop();
                string curP=paths.front();paths.pop();
                if(!cur->left&&!cur->right){
                    res.push_back(curP);
                    continue;
                }
                if(cur->left){
                    q.push(cur->left);
                    paths.push(curP+"->"+to_string(cur->left->val));
                }
                if(cur->right){
                    q.push(cur->right);
                    paths.push(curP+"->"+to_string(cur->right->val));
                }
            }
        }
        return res;
    }
};

int main(){

}
