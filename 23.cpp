#include <iostream>
#include <queue>
#include <vector>

#include "ListNode.h"

using namespace std;

class Solution {
public:
    struct compare {
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for (auto l : lists) {
            if (l)
                q.push(l);
        }

        ListNode preHead(-1);
        ListNode* prev = &preHead;

        while (!q.empty()) {
            prev->next = q.top();
            q.pop();
            prev = prev->next;
            if (prev->next)
                q.push(prev->next);
        }

        return preHead.next;
    }
};

class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }

        ListNode* mg;
        while (lists.size() > 1) {
            mg = mergeTwo(lists[0], lists[1]);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            lists.push_back(mg);
        }
        return lists[0];
    }

    ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
        ListNode preHead(-1);
        ListNode* prev = &preHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 ? l1 : l2;
        return preHead.next;
    }
};

int main() {}
