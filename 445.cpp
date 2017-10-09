#include<iostream>
#include<vector>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1;
        vector<int> v2;
        while(l1){
            v1.push_back(l1->val);
            l1=l1->next;
        }
        while(l2){
            v2.push_back(l2->val);
            l2=l2->next;
        }
        ListNode preHead(-1);
        ListNode* prev=&preHead;
        int i=v1.size()-1,j=v2.size()-1;
        int carry=0;
        while(i>=0||j>=0||carry){
            int sum=(i>=0?v1[i]:0)+(j>=0?v2[j]:0)+carry;
            ListNode* pos=new ListNode(sum%10);
            carry=sum/10;
            i--;j--;
            ListNode* temp=prev->next;
            prev->next=pos;
            pos->next=temp;
        }
        return preHead.next;
    }
};

int main(){
	vector<int> v1={7,2,4,3};
	vector<int> v2={5,6,4};
	ListNodeEnv l;
	ListNode* l1=l.initialize(v1);
	ListNode* l2=l.initialize(v2);

	Solution s;
	l.showList(l1);
	l.showList(l2);
	ListNode* l3=s.addTwoNumbers(l1,l2);
	l.showList(l3);

	return 0;
}



