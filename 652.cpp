// Given a binary tree, return all duplicate subtrees. For each kind of
// duplicate subtrees, you only need to return the root node of any one of them.
//
// Two trees are duplicate if they have the same structure with same node
// values.
//
// Example 1:
//
//         1
//        / \
//       2   3
//      /   / \
//     4   2   4
//        /
//       4
// The following are two duplicate subtrees:
//
//       2
//      /
//     4
// and
//
//     4
// Therefore, you need to return above trees' root in the form of a list.

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, vector<TreeNode*>> m;
        vector<TreeNode*> res;
        serialize(root, m, res);
        return res;
    }

    string serialize(TreeNode* root,
                     map<string, vector<TreeNode*>>& m,
                     vector<TreeNode*>& res) {
        if (!root) {
            return "";
        }

        string s = "[" + serialize(root->left, m, res) + to_string(root->val)
                   + serialize(root->right, m, res) + "]";
        if (m[s].size() == 1) {
            res.push_back(root);
        }
        m[s].push_back(root);
        return s;
    }
};

int main() {}
