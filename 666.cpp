#include "Tree.h"
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    int pathSum(vector<int>& nums) {
        map<pair<int, int>, int> m;
        for (auto n : nums) {
            int x = n / 100;
            int y = n % 100 / 10;
            int pos = n % 10;
            pair<int, int> p = make_pair(x, y);
            m[p] = pos;
        }
        TreeNode* root = construct(m, 1, 1);
        // TreeEnv t;
        // t.displayTree(root);
        int sum = 0;
        path(root, 0, sum);
        return sum;
    }
    TreeNode* construct(const map<pair<int, int>, int>& m, int x, int y) {
        TreeNode* root = nullptr;
        pair<int, int> p = make_pair(x, y);
        auto it = m.find(p);
        if (it != m.end()) {
            root = new TreeNode(it->second);
            root->left = construct(m, x + 1, 2 * y - 1);
            root->right = construct(m, x + 1, 2 * y);
        }
        return root;
    }
    void path(TreeNode* root, int pathsum, int& sum) {
        if (root) {
            pathsum += root->val;
            if (!root->left && !root->right) {
                sum += pathsum;
            } else {
                path(root->left, pathsum, sum);
                path(root->right, pathsum, sum);
            }
        }
    }
};

class Solution2 {
public:
    int pathSum(vector<int>& nums) {
        map<pair<int, int>, int> tree_map;
        for (auto n : nums) {
            int row = n / 100;
            int col = n % 100 / 10;
            int val = n % 10;
            tree_map[make_pair(row, col)] = val;
        }
        int sum = 0;
        path(tree_map, sum, 0, 1, 1);
        return sum;
    }

    void path(map<pair<int, int>, int>& tree_map,
              int& sum,
              int path_sum,
              int row,
              int col) {
        auto root = make_pair(row, col);
        auto it = tree_map.find(root);
        if (it != tree_map.end()) {
            path_sum += it->second;

            if (tree_map.find(make_pair(row + 1, 2 * col - 1)) == tree_map.end()
                && tree_map.find(make_pair(row + 1, 2 * col))
                       == tree_map.end()) {
                sum += path_sum;
                return;
            }

            path(tree_map, sum, path_sum, row + 1, 2 * col - 1);
            path(tree_map, sum, path_sum, row + 1, 2 * col);
        }
    }
};

int main() {
    vector<int> test = {115, 215, 224, 325, 336, 446, 458};

    Solution s;
    cout << s.pathSum(test) << endl;

    return 0;
}
