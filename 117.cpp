// Given a binary tree
//
// struct TreeLinkNode {
//   TreeLinkNode *left;
//   TreeLinkNode *right;
//   TreeLinkNode *next;
// }
// Populate each next pointer to point to its next right node. If there is no
// next right node, the next pointer should be set to NULL.
//
// Initially, all next pointers are set to NULL.
//
// Note:
//
// You may only use constant extra space.
// Recursive approach is fine, implicit stack space does not count as extra
// space for this problem. Example:
//
// Given the following binary tree,
//
//      1
//    /  \
//   2    3
//  / \    \
// 4   5    7
// After calling your function, the tree should look like:
//
//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \    \
// 4-> 5 -> 7 -> NULL

#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *next, *left, *right;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    typedef TreeLinkNode tln;
    void connect(TreeLinkNode* root) {
        tln* cur = root;
        tln* head = nullptr;
        tln* prev = nullptr;
        while (cur) {
            while (cur) {
                if (cur->left) {
                    if (prev == nullptr)
                        head = cur->left;
                    else
                        prev->next = cur->left;
                    prev = cur->left;
                }
                if (cur->right) {
                    if (prev == nullptr)
                        head = cur->right;
                    else
                        prev->next = cur->right;
                    prev = cur->right;
                }
                cur = cur->next; // move to next node
            }
            cur = head; // move to next level
            head = nullptr;
            prev = nullptr;
        }
    }
};

class Solution2 {
public:
    typedef TreeLinkNode tln;

    void connect(TreeLinkNode* root) {
        queue<tln*> q;
        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                tln* node = q.front();
                q.pop();
                if (size > 0) {
                    node->next = q.front();
                }

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
    }
};

int main() {}
