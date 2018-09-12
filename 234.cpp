// Given a singly linked list, determine if it is a palindrome.
//
// Example 1:
//
// Input: 1->2
// Output: false
// Example 2:
//
// Input: 1->2->2->1
// Output: true
// Follow up:
// Could you do it in O(n) time and O(1) space?

#include "ListNode.h"
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* new_head = reverse(slow);
        while (new_head) {
            if (new_head->val != head->val) {
                return false;
            }
            new_head = new_head->next;
            head = head->next;
        }

        return true;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* temp = head->next;
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
slow-3
fast-null

*/
