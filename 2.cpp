#include<iostream>
#include "ListNode.h"
using namespace std;


class Solution{
public:
	ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
		ListNode preHead(-1);
		ListNode* prev=&preHead;
		int carry=0;
		while(l1||l2||carry){
			int val=(l1?l1->val:0)+(l2?l2->val:0)+carry;
			carry=val/10;
			prev->next=new ListNode(val%10);
			prev=prev->next;
			l1=l1?l1->next:l1;
			l2=l2?l2->next:l2;
		}
		return preHead.next;
	}
};

int main(){
	ListNodeEnv l;
	vector<int> v1={2,4,3};
	vector<int> v2={5,6,4};
	ListNode* l1=l.initialize(v1);
	ListNode* l2=l.initialize(v2);
	
	Solution s;
	ListNode* res=s.addTwoNumbers(l1,l2);
	l.showList(res);

	return 0;
}
