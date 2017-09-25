#include<iostream>
#include<vector>
#include "Tree.h"

using namespace std;

class Solution{
public:
	int findSecondMinimumValue(TreeNode* root){
		int Min=INT_MAX;
		int secondMin=-1;
		inorder(root,Min,secondMin);
		return secondMin==INT_MAX?-1:secondMin;
	}
	void inorder(TreeNode* root,int& Min,int& secondMin){
		if(root){
			inorder(root->left,Min,secondMin);
			if(root->val<Min){
                secondMin=Min;
				Min=root->val;
			}
            else if(root->val>Min&&root->val<secondMin){
                secondMin=root->val;
            }
			inorder(root->right,Min,secondMin);
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
