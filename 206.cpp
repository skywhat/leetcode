#include<iostream>
#include<vector>

#include "ListNode.h"

using namespace std;

class Solution{
public:
	ListNode* reverseList(ListNode* head){
		ListNode* new_head=nullptr;
		ListNode* cur=head;
		ListNode* temp;
		while(cur){
			temp=cur->next;
			cur->next=new_head;
			new_head=cur;
			cur=temp;
		}
		return new_head;
	}
};

class Solution2{
public:
	ListNode* reverseList(ListNode* head){
		if(head==nullptr||head->next==nullptr)
			return head;
		ListNode* tail=reverseList(head->next);
		head->next->next=head;
		head->next=nullptr;
		return tail;
	}
};

int main(){
	vector<int> l={1,2,3,4,5};
	ListNodeEnv env;
	ListNode* head=env.initialize(l);
	cout<<"before reverse the linked list:"<<endl;
	env.showList(head);

	Solution2 s;
	ListNode* new_head=s.reverseList(head);
	cout<<"after reverse the linked list:"<<endl;
	env.showList(new_head);
	

	return 0;
}

