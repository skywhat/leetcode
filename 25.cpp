#include<iostream>
#include "ListNode.h"

using namespace std;

class Solution{
public:
	ListNode* reverseKGroup(ListNode* head,int k){
		if(!head||!head->next)
			return head;
		ListNode preHead(-1);
		ListNode* prev=&preHead;
		prev->next=head;
		
		int sum=0;
		while(head){
			sum++;
			head=head->next;
		}
		ListNode* prevH=prev;
		while(k<=sum){
			ListNode* cur=prevH->next;
			ListNode* then=cur->next;
			ListNode* tail=prevH->next;
			ListNode* temp;
			for(int i=1;i<k;++i){
				prevH->next=then;
				temp=then->next;
				then->next=cur;
				cur=prevH->next;
				then=temp;
			}
			prevH=tail;
			tail->next=then;
			sum-=k;
		}
		return preHead.next;
	}
};

int main(){
	ListNodeEnv l;
	vector<int> v={1,2,3,4,5,6,7,8,9,10};
	ListNode* head=l.initialize(v);
	l.showList(head);
	int k=3;

	Solution s;
	ListNode* newList=s.reverseKGroup(head,k);
	l.showList(newList);

	return 0;
}



