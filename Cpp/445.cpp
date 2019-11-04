/*
You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contain a single
digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists
is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/

#include "ListNode.h"
#include <iostream>
#include <vector>

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
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* prev = new ListNode(-1);
        int carry = 0;

        while (!s1.empty() || !s2.empty() || carry) {
            int val = carry;
            if (!s1.empty()) {
                val += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                val += s2.top();
                s2.pop();
            }
            carry = val / 10;
            ListNode* temp = new ListNode(val % 10);

            ListNode* next = prev->next;
            prev->next = temp;
            temp->next = next;
        }

        return prev->next;
    }
};

int main() {
    vector<int> v1 = {7, 2, 4, 3};
    vector<int> v2 = {5, 6, 4};
    ListNodeEnv l;
    ListNode* l1 = l.initialize(v1);
    ListNode* l2 = l.initialize(v2);

    Solution s;
    l.showList(l1);
    l.showList(l2);
    ListNode* l3 = s.addTwoNumbers(l1, l2);
    l.showList(l3);

    return 0;
}
