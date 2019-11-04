/*
 Given preorder and inorder traversal of a tree, construct the binary tree.
 */
#include "Tree.h"
#include <iostream>
#include <vector>

using namespace std;

/*
         1
    2 .       3
 4 .  5 .  6 .   7

 preorder: 1 2 4 5 3 6 7
 inorder:  4 2 5 1 6 3 7
 index:    0 1 2 3 4 5 6

 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0,
                     inorder.size() - 1);
    }
    // four indices: pre start, pre end, in start, in end
    TreeNode* build(const vector<int>& preorder,
                    const vector<int>& inorder,
                    int ps,
                    int pe,
                    int is,
                    int ie) {
        if (ps == pe) {
            return new TreeNode(preorder[ps]);
        }

        for (int i = is; i <= ie; ++i) {
            if (inorder[i] == preorder[ps]) {
                TreeNode* root = new TreeNode(preorder[ps]);
                root->left
                    = build(preorder, inorder, ps + 1, ps + i - is, is, i - 1);
                root->right
                    = build(preorder, inorder, ps + i - is + 1, pe, i + 1, ie);
                return root;
            }
        }

        return nullptr;
    }
};

/*
 Construct BST from given preorder traversal
 preorder: 10 5 1 7 40 50

              10
         5         40
      1      7          50

 */

class SolutionBST {
public:
    TreeNode* buildBST(vector<int>& preorder) {
        return build(preorder, 0, preorder.size() - 1);
    }
    TreeNode* build(const vector<int>& preorder, int start, int end) {
        if (start == end) {
            return new TreeNode(preorder[start]);
        }

        int mid = preorder[start];
        for (int i = start; i < end; ++i) {
            if (preorder[i + 1] > mid) {
                TreeNode* root = new TreeNode(mid);
                root->left = build(preorder, start + 1, i);
                root->right = build(preorder, i + 1, end);
                return root;
            }
        }

        return nullptr;
    }
};

class SolutionBST2 {
public:
    TreeNode* buildBST(vector<int>& preorder) {
        int pos = 0;
        return build(preorder, pos, preorder[0], INT_MIN, INT_MAX);
    }
    TreeNode* build(const vector<int>& preorder,
                    int& pos,
                    int key,
                    int min,
                    int max) {
        if (pos >= preorder.size()) {
            return nullptr;
        }

        if (key <= min || key >= max) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(key);
        pos++;
        if (pos < preorder.size()) {
            root->left = build(preorder, pos, preorder[pos], min, key);
            root->right = build(preorder, pos, preorder[pos], key, max);
        }

        return root;
    }
};

int main() {
    vector<int> test = {10, 5, 1, 7, 40, 50};
    SolutionBST2 s;
    TreeNode* root = s.buildBST(test);

    TreeEnv t;
    t.displayTree(root);

    return 0;
}
