#include<iostream>
#include<vector>
#include<stack>
#include "Tree.h"

using namespace std;

//recursive
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }
        
        if(p && q){
            return p->val == q->val &&
                isSameTree(p->left, q->left) && 
                isSameTree(p->right, q->right);
        }
        
        return false;
    }
};

//iterative . one stack
class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s;
        s.push(p);
        s.push(q);
        while(!s.empty()){
            TreeNode* cur2=s.top();s.pop();
            TreeNode* cur1=s.top();s.pop();
            if(cur1==nullptr&&cur2==nullptr)
                continue;
            if(cur1==nullptr||cur2==nullptr)
                return false;
            if(cur1->val!=cur2->val)
                return false;
            s.push(cur1->left);
            s.push(cur2->left);
            s.push(cur1->right);
            s.push(cur2->right);
        }
        return true;
    }
};

//iterative . two stacks
class Solution3 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        if(p)
            s1.push(p);
        if(q)
            s2.push(q);
        while(!s1.empty()&&!s2.empty()){
            TreeNode* cur1=s1.top();s1.pop();
            TreeNode* cur2=s2.top();s2.pop();
            if(cur1->val!=cur2->val)
                return false;
            if(cur1->left)
                s1.push(cur1->left);
            if(cur2->left)
                s2.push(cur2->left);
            if(s1.size()!=s2.size())
                return false;
            if(cur1->right)
                s1.push(cur1->right);
            if(cur2->right)
                s2.push(cur2->right);
            if(s1.size()!=s2.size())
                return false;
            
        }
        return s1.size()==s2.size();
    }
};

int main(){

}
