// Given a linked list, remove the n-th node from the end of list and return its
// head.
//
// Example:
//
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes
// 1->2->3->5. Note:
//
// Given n will always be valid.
//
// Follow up:
//
// Could you do this in one pass?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode prevHead(-1);
        prevHead.next = head;
        ListNode* prev = &prevHead;

        ListNode* fast = head;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        while (fast) {
            prev = prev->next;
            fast = fast->next;
        }

        prev->next = prev->next->next;
        return prevHead.next;
    }
};
