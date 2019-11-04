// Given an integer n, generate all structurally unique BST's (binary search
// trees) that store values 1 ... n.
//
// Example:
//
// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return generate(1, n);
    }

    vector<TreeNode*> generate(int start, int end) {
        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            auto left = generate(start, i - 1);
            auto right = generate(i + 1, end);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};
