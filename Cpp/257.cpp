#include<iostream>
#include<vector>

#include "Tree.h"

using namespace std;

//recursive
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;
        preorder(root, path, res);
        return res;
    }
    
    void preorder(TreeNode* root, string path, vector<string>& res){
        if(root){
            if(!root->left && !root->right){
                res.push_back(path+to_string(root->val));
                return;
            }
            
            preorder(root->left, path+to_string(root->val)+"->", res);
            preorder(root->right, path+to_string(root->val)+"->", res);
        }
    }
};

//iterative
class Solution2 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        queue<string> paths;
        queue<TreeNode*> nodes;
        vector<string> res;
        if(root){
            nodes.push(root);
            paths.push(to_string(root->val));
        }
        
        while(!nodes.empty()){
            int size = nodes.size();
            while(size--){
                TreeNode* cur_node = nodes.front();
                nodes.pop();
                string cur_path = paths.front();
                paths.pop();
                
                if(!cur_node->left && !cur_node->right){
                    res.push_back(cur_path);
                    continue;
                }
                
                if(cur_node->left){
                    nodes.push(cur_node->left);
                    paths.push(cur_path+"->"+to_string(cur_node->left->val));
                }
                if(cur_node->right){
                    nodes.push(cur_node->right);
                    paths.push(cur_path+"->"+to_string(cur_node->right->val));
                }
            }
        }
        
        return res;
    }
};

int main(){

}
