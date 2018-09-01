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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least
       one node. */
    ListNode* head;
    Solution(ListNode* head) { this->head = head; }

    /** Returns a random node's value. */
    int getRandom() {
        int res = this->head->val;
        ListNode* node = this->head->next;
        int i = 2;

        while (node) {
            int j = random() % i++;
            if (j == 0) {
                res = node->val;
            }
            node = node->next;
        }

        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
