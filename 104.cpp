#include<iostream>
#include<vector>
#include "Tree.h"

class Solution{
public:
	int maxDepth(TreeNode* root){
		if(!root)
			return 0;
		int depth=0;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){
			depth++;
			int size=q.size();
			while(size--){
				TreeNode* temp=q.front();
				q.pop();
				if(temp->left)
					q.push(temp->left);
				if(temp->right)
					q.push(temp->right);
			}
		}
		return depth;
	}
};

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
        return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
