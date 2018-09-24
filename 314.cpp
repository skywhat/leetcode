// Given a binary tree, return the vertical order traversal of its nodes'
// values. (ie, from top to bottom, column by column).
//
// If two nodes are in the same row and column, the order should be from left to
// right.
//
// Examples 1:
//
// Input: [3,9,20,null,null,15,7]
//
//    3
//   /\
//  /  \
//  9  20
//     /\
//    /  \
//   15   7
//
// Output:
//
// [
//   [9],
//   [3,15],
//   [20],
//   [7]
// ]
// Examples 2:
//
// Input: [3,9,8,4,0,1,7]
//
//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7
//
// Output:
//
// [
//   [4],
//   [9],
//   [3,0,1],
//   [8],
//   [7]
// ]
// Examples 3:
//
// Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left
// child is 5)
//
//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7
//     /\
//    /  \
//    5   2
//
// Output:
//
// [
//   [4],
//   [9,5],
//   [3,0,1],
//   [8,2],
//   [7]
// ]

#include "Tree.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        if (root) {
            q.push(make_pair(root, 0));
        }
        while (!q.empty()) {
            size_t size = q.size();
            while (size--) {
                pair<TreeNode*, int> temp = q.front();
                q.pop();
                m[temp.second].push_back(temp.first->val);
                if (temp.first->left) {
                    q.push(make_pair(temp.first->left, temp.second - 1));
                }
                if (temp.first->right) {
                    q.push(make_pair(temp.first->right, temp.second + 1));
                }
            }
        }
        vector<vector<int>> res;
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};

int main() {}
