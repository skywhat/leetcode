#include "ListNode.h"
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode prevHead(-1);
        prevHead.next = head;
        ListNode* prev = &prevHead;

        while (head) {
            if (head->next && head->val > head->next->val) {
                while (prev->next->val < head->next->val) {
                    prev = prev->next;
                }
                ListNode* temp = prev->next;
                prev->next = head->next;
                head->next = head->next->next;
                prev->next->next = temp;

                prev = &prevHead;
            } else {
                head = head->next;
            }
        }
        return preHead->next;
    }
};

int main() {
    ListNodeEnv l;
    vector<int> test = {1, 5, 4, 2, 3, 6, 9, 7, 8};
    ListNode* head = l.initialize(test);

    Solution s;

    ListNode* new_head = s.insertionSortList(head);
    l.showList(new_head);

    return 0;
}
