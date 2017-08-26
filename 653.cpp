#include<iostream>
#include<vector>
#include<unordered_map>
#include "Tree.h"

class Solution{
public:
    bool findTarget(TreeNode* root,int k){
        vector<int> num;
        unordered_map<int,int> m;
        bool res=false;
        helper(root,m,k,res);
        return res;
    }
    void helper(TreeNode* root,unordered_map<int,int>& m,const int& k,bool& res){
        if(root){
            helper(root->left,m,k,res);
            if(m.find(k-root->val)!=m.end()){
                res=true;
                return;
            }
            else{
                m[root->val]=k-root->val;
            }
            helper(root->right,m,k,res);
        }
    }
};

int main(){
    TreeEnv t;
    vector<int> v={5,3,6,2,4,NULL_TREENODE,7};
    TreeNode* root=t.initialTree(v);
    
    Solution s;
    int target=14;
    cout<<s.findTarget(root,target)<<endl;
    
    return 0;
}




