/*
Given a singly linked list, group all odd nodes together followed by the even
nodes. Please note here we are talking about the node number and not the value
in the nodes.

You should try to do it in place. The program should run in O(1) space
complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was
in the input. The first node is considered odd, the second node even and so on
...
*/
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = head->next;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = even_head;
        return head;
    }

    ListNode* initialize(const vector<int>& v) {

        ListNode preHead(-1);
        ListNode* prev = &preHead;
        for (int i = 0; i < v.size(); ++i) {
            prev->next = new ListNode(v[i]);
            prev = prev->next;
        }
        return preHead.next;
    }

    void showList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> v1 = {1, 2, 3, 4, 5};
    Solution s;
    ListNode* t = s.initialize(v1);
    s.showList(t);

    ListNode* changedLinkedList = s.oddEvenList(t);
    s.showList(changedLinkedList);

    return 0;
}
