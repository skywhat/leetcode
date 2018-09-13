// Given an integer array nums, find the sum of the elements between indices i
// and j (i ≤ j), inclusive.
//
// The update(i, val) function modifies nums by updating the element at index i
// to val.
//
// Example:
//
// Given nums = [1, 3, 5]
//
// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8
// Note:
//
// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is
// distributed evenly.

class NumArray {
public:
    struct SegmentTreeNode {
        int start;
        int end;
        int sum;
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        SegmentTreeNode(int s, int e, int sm = 0)
          : start(s), end(e), sum(sm), left(nullptr), right(nullptr) {}
    };

    SegmentTreeNode* root;

    NumArray(vector<int> nums) {
        int n = nums.size();
        root = buildTree(nums, 0, n - 1);
    }

    SegmentTreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        SegmentTreeNode* root = new SegmentTreeNode(start, end);
        if (start == end) {
            root->sum = nums[start];
            return root;
        }

        int mid = start + (end - start) / 2;
        root->left = buildTree(nums, start, mid);
        root->right = buildTree(nums, mid + 1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    int updateTree(int i, int val, SegmentTreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int diff;
        if (root->start == i && root->end == i) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }

        int mid = root->start + (root->end - root->start) / 2;
        if (i <= mid) {
            diff = updateTree(i, val, root->left);
        } else {
            diff = updateTree(i, val, root->right);
        }
        root->sum += diff;
        return diff;
    }

    void update(int i, int val) { updateTree(i, val, root); }

    int sumRangeTree(int i, int j, SegmentTreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (i > root->end || j < root->start) {
            return 0;
        }

        if (root->start == i && root->end == j) {
            return root->sum;
        }

        int mid = root->start + (root->end - root->start) / 2;
        if (i > mid) {
            return sumRangeTree(i, j, root->right);
        }
        if (j <= mid) {
            return sumRangeTree(i, j, root->left);
        }

        return sumRangeTree(i, mid, root->left)
               + sumRangeTree(mid + 1, j, root->right);
    }

    int sumRange(int i, int j) { return sumRangeTree(i, j, root); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
