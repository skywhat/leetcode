#include<iostream>
#include<vector>
#include "Tree.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> q;
        if(root){
            q.push(make_pair(root,0));
        }
        while(!q.empty()){
            size_t size=q.size();
            while(size--){
                pair<TreeNode*,int> temp=q.front();
                q.pop();
                m[temp.second].push_back(temp.first->val);
                if(temp.first->left){
                    q.push(make_pair(temp.first->left,temp.second-1));
                }
                if(temp.first->right){
                    q.push(make_pair(temp.first->right,temp.second+1));
                }
            }
        }
        vector<vector<int>> res;
        for(auto it=m.begin();it!=m.end();++it){
            res.push_back(it->second);
        }
        return res;
    }
};

int main(){
}
