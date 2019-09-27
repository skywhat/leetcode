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

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution2 {
public:
    typedef RandomListNode rln;
    RandomListNode* copyRandomList(RandomListNode* head) {
        unordered_map<rln*, rln*> m;

        rln* old_head = head;
        while (old_head) {
            m[old_head] = new RandomListNode(old_head->label);
            old_head = old_head->next;
        }

        old_head = head;
        while (old_head) {
            if (old_head->next) {
                m[old_head]->next = m[old_head->next];
            }
            if (old_head->random) {
                m[old_head]->random = m[old_head->random];
            }
            old_head = old_head->next;
        }

        return m[head];
    }
};
