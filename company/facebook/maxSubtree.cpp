#include<iostream>
#include<vector>

#include "../../Tree.h"

using namespace std;

class Solution{
public:
	int maxSubtree(TreeNode* root){
		if(!root)
			return 0;
		if(!root->left&&!root->right)
			return root->val;
		int left=maxSubtree(root->left);
		int right=maxSubtree(root->right);
		return max(root->val+left+right,max(left,right));	
	}
};

/*
 *     1
 *    .  .
 *  2      3
 *        .  .
 *     -5     -6
 *
 * the max subtree sum is 2
 *
 */

int main(){
	vector<int> l={1,2,3,NULL_TREENODE,NULL_TREENODE,7,-6};
	TreeEnv t;
	TreeNode* root=t.initialTree(l);

	Solution s;
	cout<<s.maxSubtree(root)<<endl;

	return 0;

}



