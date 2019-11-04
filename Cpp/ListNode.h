#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class ListNodeEnv{
public:
	ListNodeEnv(){}
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
			cout<<head->val<<" -> ";
			head=head->next;
		}
		cout<<"null"<<endl;
	}

};
