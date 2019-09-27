/*
Given a binary search tree, write a function kthSmallest to find the kth
smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to
find the kth smallest frequently? How would you optimize the kthSmallest
routine?
*/

#include "Tree.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;

        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (--k == 0) {
                break;
            }
            root = root->right;
        }

        return root->val;
    }
};

class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        int val = INT_MAX;
        inorder(root, k, val);
        return val == INT_MAX ? -1 : val;
    }

    void inorder(TreeNode* root, int& k, int& val) {
        if (root) {
            inorder(root->left, k, val);
            if (--k == 0) {
                val = root->val;
            }
            inorder(root->right, k, val);
        }
    }
};

int main() {}
