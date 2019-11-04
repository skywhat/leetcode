// Serialization is the process of converting a data structure or object into a
// sequence of bits so that it can be stored in a file or memory buffer, or
// transmitted across a network connection link to be reconstructed later in the
// same or another computer environment.
//
// Design an algorithm to serialize and deserialize a binary tree. There is no
// restriction on how your serialization/deserialization algorithm should work.
// You just need to ensure that a binary tree can be serialized to a string and
// this string can be deserialized to the original tree structure.
//
// Example:
//
// You may serialize the following tree:
//
//     1
//    / \
//   2   3
//      / \
//     4   5
//
// as "[1,2,3,null,null,4,5]"
// Clarification: The above format is the same as how LeetCode serializes a
// binary tree. You do not necessarily need to follow this format, so please be
// creative and come up with different approaches yourself.
//
// Note: Do not use class member/global/static variables to store states. Your
// serialize and deserialize algorithms should be stateless.

#include "Tree.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>

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
    string serialize(TreeNode* root) { return buildString(root); }
    string buildString(TreeNode* root) {
        if (!root) {
            return "N#";
        }
        string s = to_string(root->val) + "#";
        s += buildString(root->left);
        s += buildString(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        for (int i = 0; i < data.size();) {
            int cnt = 1;
            while (data[i + cnt] != '#') {
                cnt++;
            }
            q.push(data.substr(i, cnt));
            i += cnt + 1;
        }
        return buildTree(q);
    }
    TreeNode* buildTree(queue<string>& q) {
        if (q.empty()) {
            return nullptr;
        }
        string temp = q.front();
        q.pop();

        if (temp == "N") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(temp));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }
};

class Codec2 {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "N ";
        }

        string res;
        res += to_string(root->val) + " ";
        res += serialize(root->left);
        res += serialize(root->right);

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        string val;
        queue<string> nodes;
        while (ss >> val) {
            nodes.push(val);
        }

        return build(nodes);
    }

    TreeNode* build(queue<string>& nodes) {
        if (nodes.empty()) {
            return nullptr;
        }
        string node = nodes.front();
        nodes.pop();
        if (node == "N") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(node));
        root->left = build(nodes);
        root->right = build(nodes);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
