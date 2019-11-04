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
// space for this problem. You may assume that it is a perfect binary tree (ie,
// all leaves are at the same level, and every parent has two children).
// Example:
//
// Given the following perfect binary tree,
//
//      1
//    /  \
//   2    3
//  / \  / \
// 4  5  6  7
// After calling your function, the tree should look like:
//
//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \  / \
// 4->5->6->7 -> NULL

#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode* root) {
        while (root && root->left) {
            TreeLinkNode* cur = root;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next) {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            root = root->left;
        }
    }
};

class Solution2 {
public:
    void connect(TreeLinkNode* root) {
        queue<TreeLinkNode*> q;
        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node = q.front();
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

class Solution3 {
public:
    void connect(TreeLinkNode* root) {
        if (!root) {
            return;
        }

        if (root->left) {
            root->left->next = root->right;
            if (root->next) {
                root->right->next = root->next->left;
            }
        }

        connect(root->left);
        connect(root->right);
    }
};
