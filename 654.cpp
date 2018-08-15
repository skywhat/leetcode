#include "Tree.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        } else {
            int root_index = left;
            int max_value = nums[left];

            for (int i = left + 1; i <= right; ++i) {
                if (nums[i] > max_value) {
                    max_value = nums[i];
                    root_index = i;
                }
            }

            TreeNode* root = new TreeNode(max_value);
            root->left = constructMaximumBinaryTree(nums, left, root_index - 1);
            root->right = constructMaximumBinaryTree(nums, root_index + 1, right);

            return root;
        }
    }
};

int main() {}
