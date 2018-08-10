#include<iostream>
#include<vector>
#include "Tree.h"

using namespace std;

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int min_val = INT_MAX;
        int second_min_val = INT_MAX;
        inorder(root, min_val, second_min_val);
        return second_min_val == INT_MAX? -1: second_min_val;
    }
    
    void inorder(TreeNode* root, int& min_val, int& second_min_val){
        if(root){
            inorder(root->left, min_val, second_min_val);
            if(root->val < min_val){
                second_min_val = min_val;
                min_val = root->val;
            }
            else if(root->val > min_val && root->val < second_min_val){
                second_min_val = root->val;
            }
            inorder(root->right, min_val, second_min_val);
        }
    }
};

int main(){
	TreeEnv t;
	vector<int> list={2,2,5,NULL_TREENODE,NULL_TREENODE,5,7};
	TreeNode* root=t.initialTree(list);

	Solution s;
	cout<<s.findSecondMinimumValue(root)<<endl;

	return 0;

}
