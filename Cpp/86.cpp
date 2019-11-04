// Given a linked list and a value x, partition it such that all nodes less than
// x come before nodes greater than or equal to x.
//
// You should preserve the original relative order of the nodes in each of the
// two partitions.
//
// Example:
//
// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5

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
    ListNode* partition(ListNode* head, int x) {
        ListNode LessHead(-1);
        ListNode* prevLess = &LessHead;
        ListNode GreaterHead(-1);
        ListNode* prevGreater = &GreaterHead;

        while (head) {
            if (head->val < x) {
                prevLess->next = head;
                prevLess = prevLess->next;
            } else {
                prevGreater->next = head;
                prevGreater = prevGreater->next;
            }
            head = head->next;
        }
        
        prevLess->next = GreaterHead.next;
        prevGreater->next = nullptr;

        return LessHead.next;
    }
};
