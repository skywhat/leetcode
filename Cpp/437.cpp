#include<iostream>
#include<unordered_map>
#include<vector>

#include "Tree.h"

using namespace std;

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> path_sum;
        path_sum[0] = 1;
        int cnt = 0;
        preorder(root, sum, 0, path_sum, cnt);
        return cnt;
    }
    
    void preorder(TreeNode* root, int sum, int prev_sum, unordered_map<int,int>& path_sum, int& cnt){
        if(root){
            prev_sum += root->val;
            if(path_sum.count(prev_sum - sum)){
                cnt += path_sum[prev_sum-sum];
            }
            
            path_sum[prev_sum]++;
            preorder(root->left, sum, prev_sum, path_sum, cnt);
            preorder(root->right, sum, prev_sum, path_sum, cnt);
            path_sum[prev_sum]--;
        }
    }
};

int main(){
}
