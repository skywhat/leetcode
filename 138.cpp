// A linked list is given such that each node contains an additional random
// pointer which could point to any node in the list or null.
//
// Return a deep copy of the list.

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    typedef RandomListNode rln;
    RandomListNode* copyRandomList(RandomListNode* head) {
        rln* prev = head;
        rln* next;
        // make a copy of each node.
        while (prev) {
            rln* copy_node = new rln(prev->label);
            next = prev->next;
            prev->next = copy_node;
            copy_node->next = next;
            prev = next;
        }

        // assign the random pointers for the copy list.
        prev = head;
        while (prev) {
            prev->next->random = prev->random ? prev->random->next : nullptr;
            prev = prev->next->next;
        }

        // restore the original list
        // extract the copy list
        rln prevHead(-1);
        prev = &prevHead;
        while (head) {
            prev->next = head->next;
            prev = prev->next;
            head->next = head->next->next;
            head = head->next;
        }

        return prevHead.next;
    }
};
