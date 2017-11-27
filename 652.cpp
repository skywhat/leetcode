#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        map<string,vector<TreeNode*>> m;
        serialize(root,m);
        for(auto item:m){
            if(item.second.size()>1){
                res.push_back(item.second[0]);
            }
        }
        return res;
    }
    string serialize(TreeNode* root,map<string,vector<TreeNode*>>& m){
        if(!root)
            return "";
        string s="("+serialize(root->left,m)+to_string(root->val)+serialize(root->right,m)+")";
        m[s].push_back(root);
        return s;
    }
};

int main(){


}
