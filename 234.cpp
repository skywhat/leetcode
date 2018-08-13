#include<iostream>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }
        
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        slow = slow->next;
        while(slow){
            if(head->val != slow->val){
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        
        return true;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(head){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    } 
};
/*
1-2-3-4-5
slow-3
fast-null

1-2-3-4
slow-2
fast-3

*/
