#include<iostream>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        ListNode preHead(-1);
        ListNode* prev=&preHead;
        prev->next=head;
        while(head){
            cnt++;
            head=head->next;
        }
        while(cnt>=k){
            ListNode* cur=prev->next;
            ListNode* nex=cur->next;
            for(int i=1;i<k;++i){
                cur->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=cur->next;
            }
            prev=cur;
            cnt-=k;
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



