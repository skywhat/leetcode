#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
int val;
ListNode* next;
ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
	ListNode* oddEvenList(ListNode* head){
		ListNode preHead(-1);
		ListNode *prev=&preHead;
		ListNode *temp=head;
		while(head){
			prev->next=new ListNode(head->val);
			prev=prev->next;
			if(!head->next)
				break;
			head=head->next->next;
		}
		if(temp)
			head=temp->next;
		while(head){
			prev->next=new ListNode(head->val);
			prev=prev->next;
			if(!head->next)
				break;
			head=head->next->next;
		}
		return preHead.next;
	}
	ListNode* initialize(const vector<int>& v){

		ListNode preHead(-1);
		ListNode* prev=&preHead;
		for(int i=0;i<v.size();++i){
			prev->next=new ListNode(v[i]);
			prev=prev->next;
		}
		return preHead.next;
	}
	void showList(ListNode* head){
		while(head){
			cout<<head->val<<" ";
			head=head->next;
		}
		cout<<endl;
	}
};

int main(){
	vector<int> v={1,2,3,4,5,6};
	vector<int> v1={1,2,3,4,5};
	Solution s;
	ListNode* t=s.initialize(v1);
	s.showList(t);

	ListNode* changedLinkedList=s.oddEvenList(t);
	s.showList(changedLinkedList);

	return 0;

}
