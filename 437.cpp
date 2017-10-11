#include<iostream>
#include<unordered_map>
#include<vector>

#include "Tree.h"

using namespace std;

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> m;
        m[0]=1;
        int cnt=0;
        path(root,m,sum,0,cnt);
        return cnt;
    }
    void path(TreeNode* root,unordered_map<int,int>& m,int sum,int preSum,int& cnt){
        if(root){
            preSum+=root->val;
            if(m.find(preSum-sum)!=m.end())
            cnt+=m[preSum-sum];
            m[preSum]++;
            path(root->left,m,sum,preSum,cnt);
            path(root->right,m,sum,preSum,cnt);
            m[preSum]--;
        }
    }
};

int main(){
}
