#include "ListNode.h"
#include <iostream>
using namespace std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode prevHead(-1);
        ListNode* prev = &prevHead;

        int carry = 0;
        while (l1 || l2 || carry) {
            int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = val / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
            prev->next = new ListNode(val % 10);
            prev = prev->next;
        }

        return prevHead.next;
    }
};

int main() {
    ListNodeEnv l;
    vector<int> v1 = {2, 4, 3};
    vector<int> v2 = {5, 6, 4};
    ListNode* l1 = l.initialize(v1);
    ListNode* l2 = l.initialize(v2);

    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);
    l.showList(res);

    return 0;
}
