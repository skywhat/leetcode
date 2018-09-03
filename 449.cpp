/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        string res;
        int byte_cnt = sizeof(int);
        char buf[byte_cnt];
        memcpy(buf, &root->val, byte_cnt);
        for (int i = 0; i < byte_cnt; ++i) {
            res += buf[i];
        }
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0;
        return build(data, start, INT_MIN, INT_MAX);
    }

    TreeNode* build(string& data, int& pos, int min_val, int max_val) {
        if (pos >= data.size()) {
            return nullptr;
        }

        int root_val;
        memcpy(&root_val, &data[pos], sizeof(int));
        if (root_val < min_val || root_val > max_val) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(root_val);
        pos += sizeof(int);

        root->left = build(data, pos, min_val, root_val);
        root->right = build(data, pos, root_val, max_val);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
