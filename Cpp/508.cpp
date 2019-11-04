/*
Given the root of a tree, you are asked to find the most frequent subtree sum.
The subtree sum of a node is defined as the sum of all the node values formed by
the subtree rooted at that node (including the node itself). So what is the most
frequent subtree sum value? If there is a tie, return all the values with the
highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in
any order. Examples 2 Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit
signed integer.
*/

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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> counts;
        int max_count = 0;
        countFrequency(root, counts, max_count);
        vector<int> res;
        for (auto item : counts) {
            if (item.second == max_count) {
                res.push_back(item.first);
            }
        }

        return res;
    }

    int countFrequency(TreeNode* root,
                       unordered_map<int, int>& counts,
                       int& max_count) {
        if (root == nullptr) {
            return 0;
        }

        int sum = root->val;
        sum += countFrequency(root->left, counts, max_count);
        sum += countFrequency(root->right, counts, max_count);
        max_count = max(++counts[sum], max_count);

        return sum;
    }
};
