#include<iostream>
#include<vector>
#include<stack>
#include "Tree.h"

using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while(root||!s.empty()){
            while(root){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            k--;
            if(k==0)
                break;
            root=root->right;
        }
        return root->val;
    }
};

int main(){

}
