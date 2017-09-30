#include<iostream>
#include "ListNode.h"

using namespace std;

class Solution{
public:
	ListNode* insertionSortList(ListNode* head){
		ListNode* preHead=new ListNode(-1);
		preHead->next=head;
		ListNode* prev=preHead;
		ListNode* cur=head;

		while(cur){
			if(cur->next&&cur->val>cur->next->val){
				while(prev->next->val<cur->next->val){
					prev=prev->next;
				}
				ListNode* temp=prev->next;
				prev->next=cur->next;
				cur->next=cur->next->next;
				prev->next->next=temp;

				prev=preHead;
			}else
				cur=cur->next;

		}
		return preHead->next;
	}
};

int main(){
	ListNodeEnv l;	
	vector<int> test={1,5,4,2,3,6,9,7,8};
	ListNode* head=l.initialize(test);
	
	Solution s;

	ListNode* new_head=s.insertionSortList(head);
	l.showList(new_head);

	return 0;
}
