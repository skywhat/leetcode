#include<iostream>
#include<vector>

#include "Tree.h"
#include "ListNode.h"

class Solution{
public:
	TreeNode* sortedListToBST(ListNode* head){
		return build(head,null);
	}
	TreeNode* build(ListNode* head,ListNode* tail){
		if(head==tail)
			return nullptr;
		if(head->next==tail)
			return head;
		ListNode* slow;
		ListNode* fast;
		while(fast!=tail&&fast->next!=tail){
			fast=fast->next->next;
			slow=slow->next;
		}
		TreeNode* root=new TreeNode(slow->val);
		root->left=build(head,slow);
		root->right=build(slow->next,tail);
		return root;
	}

};

int main(){

}
