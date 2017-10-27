#include<iostream>
#include<vector>

using namespace std;

struct TreeLinkNode {
int val;
TreeLinkNode *left, *right, *next;
TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        TreeLinkNode* prev=root;
        TreeLinkNode* cur=nullptr;
        while(prev->left){
            cur=prev;
            while(cur){
                cur->left->next=cur->right;
                if(cur->next)
                    cur->right->next=cur->next->left;
                cur=cur->next;
            }
            prev=prev->left;
        }
    }
};

class Solution2 {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        if(root)
            q.push(root);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeLinkNode* tmp=q.front();
                q.pop();
                if(size>0){
                    tmp->next=q.front();
                }
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
        }
    }
};
