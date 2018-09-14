#include <iostream>
#include <vector>

#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp = head;

        while (head) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
};

int main() {
    vector<int> l = {1, 2, 3, 4, 5};
    ListNodeEnv env;
    ListNode* head = env.initialize(l);
    cout << "before reverse the linked list:" << endl;
    env.showList(head);

    Solution2 s;
    ListNode* new_head = s.reverseList(head);
    cout << "after reverse the linked list:" << endl;
    env.showList(new_head);

    return 0;
}
