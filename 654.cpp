#include<iostream>
#include<vector>
#include "Tree.h"

using namespace std;

class Solution{
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums){
		return constructMaximumBinaryTree(nums,0,nums.size()-1);
	}
	
	TreeNode* constructMaximumBinaryTree(vector<int>& nums,int left,int right){
		if(left<right){
			int index=left;
			int maxValue=nums[left];
			for(int i=left+1;i<=right;++i){
				if(nums[i]>maxValue){
					maxValue=nums[i];
					index=i;
				}
			}
			TreeNode* root=new TreeNode(maxValue);
			root->left=constructMaximumBinaryTree(nums,left,index-1);
			root->right=constructMaximumBinaryTree(nums,index+1,right);
			return root;
		}else if(left==right)
			return new TreeNode(nums[left]);
		else
			return NULL;
	}

};

int main(){


}
