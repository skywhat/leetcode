#include<iostream>
#include<vector>
#include "Tree.h"

using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        vector<pair<int,int>> stat;
        dfs(root,1,0,stat);
        int maxWidth=0;
        for(auto&& s:stat){
            maxWidth=max(s.second-s.first+1,maxWidth);
        }
        return maxWidth;
    }
    void dfs(TreeNode* root,int label,int level,vector<pair<int,int>>& stat){
        if(root){
            if(stat.size()==level){
                stat.push_back({label,label});
            }
            else{
                stat[level].first=min(stat[level].first,label);
                stat[level].second=max(stat[level].second,label);
            }
            dfs(root->left,2*label,level+1,stat);
            dfs(root->right,2*label+1,level+1,stat);
        }
    }
};

int main(){

}
