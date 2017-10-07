#include<iostream>
#include "Tree.h"

using namespace std;

class Solution{
public:
	ListNode *getIntersectionNode(ListNode *headA,ListNode *headB){
		if(!headA||!headB)
			return nullptr;
		ListNode* l1=headA;
		ListNode* l2=headB;
		while(l1!=l2){
			l1=l1==nullptr?headB:l1->next;
			l2=l2==nullptr?headA:l2->next;
		}
		return l1;
	}	
};

int main(){
	
}
