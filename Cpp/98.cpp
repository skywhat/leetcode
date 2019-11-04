// Given a binary tree, determine if it is a valid binary search tree (BST).
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than the node's
// key. The right subtree of a node contains only nodes with keys greater than
// the node's key. Both the left and right subtrees must also be binary search
// trees. Example 1:
//
// Input:
//     2
//    / \
//   1   3
// Output: true
// Example 2:
//
//     5
//    / \
//   1   4
//      / \
//     3   6
// Output: false
// Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
//              is 5 but its right child's value is 4.

#include <stack>
#include <vector>

#include "Tree.h"

using namespace std;

// iterative
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;

        TreeNode* prev = nullptr;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (prev && prev->val >= root->val) {
                return false;
            }
            prev = root;
            root = root->right;
        }

        return true;
    }
};

// recursive
class Solution {
public:
    bool isValidBST(TreeNode* root) { return isValid(root, nullptr, nullptr); }

    bool isValid(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == nullptr) {
            return true;
        }
        if (min && root->val <= min->val) {
            return false;
        }
        if (max && root->val >= max->val) {
            return false;
        }

        return isValid(root->left, min, root)
               && isValid(root->right, root, max);
    }
};

int main() {}
