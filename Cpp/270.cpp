/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note: 
Given target value is a floating point. 
You are guaranteed to have only one unique value in the BST that is closest to the target.

*/

#include<iostream>
#include<vector>
#include "Tree.h"
using namespace std;

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        while(root){
            if(abs(closest - target) > abs(root->val - target)){
                closest = root->val;
            }
            root = target < root->val?  root->left:root->right;
        }
        
        return closest;
    }
};

int main() {
	vector<int> treeListBST = { 1500000000,1400000000 };
	double target = -1500000000;

	vector<int> treeListBST1 = { 36,13,37,4,20,INT_MIN,48,1,5,17,33,43,49,0,2,INT_MIN,9,14,18,22,34,40,46,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,3,7,11,INT_MIN,16,INT_MIN,19,21,27,INT_MIN,35,39,42,45,47,INT_MIN,INT_MIN,6,8,10,12,15,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,26,32,INT_MIN,INT_MIN,38,INT_MIN,41,INT_MIN,44,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,24,INT_MIN,28,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,23,25,INT_MIN,29,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,31,30};
	double target1 = 3.142857;

	Solution s;
	TreeEnv t;

	TreeNode* root = t.initialTree(treeListBST1);
	t.displayTree(root);
	cout << s.closestValue(root, target1) << endl;
	return 0;
}
