/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(slow && fast &&fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }

        return false;
    }
};
