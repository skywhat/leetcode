// Given a binary tree, return the zigzag level order traversal of its nodes'
// values. (ie, from left to right, then right to left for the next level and
// alternate between).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

#include "Tree.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }

        bool rightToleft = false;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                row[rightToleft ? (size - i - 1) : i] = temp->val;

                if (temp->left) {
                    q.push(temp->left);
                }

                if (temp->right) {
                    q.push(temp->right);
                }
            }

            res.push_back(row);
            rightToleft = !rightToleft;
        }

        return res;
    }
};

int main() {
    TreeEnv t;
    vector<int> test = {3, 9, 20, NULL_TREENODE, NULL_TREENODE, 15, 7};
    TreeNode* root = t.initialTree(test);

    Solution s;
    vector<vector<int>> res = s.zigzagLevelOrder(root);
    for (auto row : res) {
        cout << "[";
        for (auto elem : row) {
            cout << elem << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
