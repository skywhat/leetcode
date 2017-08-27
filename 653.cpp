#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include "Tree.h"

class Solution{
public:
    bool findTarget(TreeNode* root,int k){
		unordered_set<int> s;
		return dfs(root,s,k);
	}
	bool dfs(TreeNode* root,unordered_set<int>& s,const int& k){
		if(root){
			if(s.find(k-root->val)!=s.end())
				return true;
			else
				s.insert(root->val);
			return dfs(root->left,s,k)||dfs(root->right,s,k);
		}else
			return false;
	}
};

class Solution1{
public:
	bool findTarget(TreeNode* root,int k){
		vector<int> v;
		dfs(root,v);
		for(int i=0,j=v.size()-1;i<j;){
			if(v[i]+v[j]==k)
				return true;
			else{
				v[i]+v[j]<k?i++:j--;
			}
		}
		return false;
	}
	void dfs(TreeNode* root,vector<int> &v){
		if(root){
			dfs(root->left,v);
			v.push_back(root->val);
			dfs(root->right,v);
		}
	}

};


int main(){
    TreeEnv t;
    vector<int> v={5,3,6,2,4,NULL_TREENODE,7};
    TreeNode* root=t.initialTree(v);
    
    Solution s;
    int target=13;
    cout<<s.findTarget(root,target)<<endl;
    
    return 0;
}




