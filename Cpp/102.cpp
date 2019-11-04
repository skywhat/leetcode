#include "Tree.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (root)
            q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> row;

            while (size--) {
                TreeNode* temp = q.front();
                q.pop();
                row.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }

            res.push_back(row);
        }

        return res;
    }
};

int main() {
    TreeEnv t;
    vector<int> list = {3, 9, 20, NULL_TREENODE, NULL_TREENODE, 15, 7};
    Solution s;

    TreeNode* root = t.initialTree(list);
    vector<vector<int>> res = s.levelOrder(root);

    for (auto row : res) {
        cout << "[";
        for (auto node : row)
            cout << node << ", ";
        cout << "]" << endl;
    }
    cout << endl;

    return 0;
}
