#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include "Tree.h"

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
        return buildString(root);
    }
    string buildString(TreeNode* root){
        if(!root)
            return "N#";
        string s=to_string(root->val)+"#";
        s+=buildString(root->left);
        s+=buildString(root->right);
        return s;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        for(int i=0;i<data.size();){
            int cnt=1;
            while(data[i+cnt]!='#')
                cnt++;
            q.push(data.substr(i,cnt));
            i+=cnt+1;
        }
        return buildTree(q);
    }
    TreeNode* buildTree(queue<string>& q){
        if(q.empty())
            return nullptr;
        string temp=q.front();
        q.pop();
        if(temp=="N")
            return nullptr;
        TreeNode* root=new TreeNode(stoi(temp));
        root->left=buildTree(q);
        root->right=buildTree(q);
        return root;
    }
};

class Codec2 {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "N ";
        string res;
        res+=to_string(root->val)+" ";
        res+=serialize(root->left);
        res+=serialize(root->right);
        return res;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        istringstream in(data);
        string node;
        while(in>>node)
            nodes.push(node);
        return buildTree(nodes);
    }
    TreeNode* buildTree(queue<string>& nodes){
        if(nodes.empty()){
            return nullptr;
        }
        string node=nodes.front();
        nodes.pop();
        if(node=="N")
            return nullptr;
        TreeNode* root=new TreeNode(stoi(node));
        root->left=buildTree(nodes);
        root->right=buildTree(nodes);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
