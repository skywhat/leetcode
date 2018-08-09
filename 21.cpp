#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode prevHead(-1);
        ListNode* prev = &prevHead;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                prev->next = l1;
                l1 = l1->next;
            }
            else{
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        
        prev->next = l1?l1:l2;
        return prevHead.next;
    }
};


//This solution is not a tail-recursive, the stack will overflow while the list is too long
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
