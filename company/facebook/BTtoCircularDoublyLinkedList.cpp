#include<iostream>
#include<vector>

#include "../../Tree.h"

using namespace std;


class Solution{
public:
	TreeNode* BTtoDLL(TreeNode* root){
		TreeNode* head=nullptr;
		build(root,head);
		return head;
	
	}
	TreeNode* prev=nullptr;
	void build(TreeNode* root,TreeNode*& head){
		if(root==nullptr)
			return;
		build(root->left,head);
		if(prev==nullptr)
			head=root;
		else{
			root->left=prev;
			prev->right=root;
		}
		prev=root;
		build(root->right,head);
		head->left=prev;
		prev->right=head;
	} 
	
	void displayLL(TreeNode* head){
		while(head){
			cout<<head->val<<" <=> ";
			head=head->right;
		}

		cout<<"NULL"<<endl;
	}

};


int main(){
	vector<int> l={10,12,15,25,30,36,NULL_TREENODE};
	TreeEnv t;
	TreeNode* root=t.initialTree(l);
	t.displayTree(root);

	Solution s;
	TreeNode* head=s.BTtoDLL(root);
	s.displayLL(head);

}




