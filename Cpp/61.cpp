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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return head;
        }

        int len = 0;
        ListNode* cur = head;
        while (cur) {
            len++;
            cur = cur->next;
        }
        k %= len;
        if (!k) {
            return head;
        }

        cur = head;
        int left = len - k;
        while (left-- != 1) {
            cur = cur->next;
        }
        ListNode* new_head = cur->next;
        cur->next = nullptr;
        ListNode* tail = new_head;
        while (tail && tail->next) {
            tail = tail->next;
        }
        tail->next = head;
        return new_head;
    }
};
