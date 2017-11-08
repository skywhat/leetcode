#include<iostream>
#include<vector>

#include "../../Tree.h"

using namespace std;

class Solution{
public:
	int maxSubtree(TreeNode* root){
		if(!root)
			return 0;
		int maxSubsum=INT_MIN;
		dfs(root,maxSubsum);
		return maxSubsum;
	}
	int dfs(TreeNode* root,int& maxSubsum){
		if(!root)
			return 0;
		int left=dfs(root->left,maxSubsum);
		int right=dfs(root->right,maxSubsum);
		maxSubsum=max(maxSubsum,left+right+root->val);
		return left+right+root->val;
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
	vector<int> l={1,2,3,NULL_TREENODE,NULL_TREENODE,-5,-6};
	TreeEnv t;
	TreeNode* root=t.initialTree(l);

	Solution s;
	cout<<s.maxSubtree(root)<<endl;

	return 0;

}



