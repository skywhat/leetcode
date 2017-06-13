/*
Given two binary trees and imagine that when you put one of them to cover the other, 
some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes 
overlap, then sum node values up as the new value of the merged node. Otherwise, 
the NOT null node will be used as the node of new tree.

Example 1:
Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
Note: The merging process must start from the root nodes of both trees.
*/

#include<iostream>
#include<vector>
#include<iterator>
#include<queue>

using namespace std;

#define NULL_TREENODE INT_MIN

struct TreeNode {
	int val;
	TreeNode* left, *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		TreeNode* root = nullptr;
		merge(root, t1, t2);
		return root;
	}
	void merge(TreeNode* &root, TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr&&t2 == nullptr)
			return;
		root = new TreeNode((t1 ? t1->val : 0) + (t2 ? t2->val : 0));
		merge(root->left, t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
		merge(root->right, t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
	}




	TreeNode* initialTree(const vector<int>& treeList) {
		queue<TreeNode*> q;
		TreeNode* root;
		if (!treeList.empty()) {
			root = new TreeNode(treeList[0]);
			q.push(root);
		}
		else
			return NULL;
		int index = 1;
		while (!q.empty()) {
			TreeNode* tmp = q.front();
			q.pop();
			if (index < treeList.size()) {
				if (treeList[index] != NULL_TREENODE) {
					tmp->left = new TreeNode(treeList[index]);
					q.push(tmp->left);
				}
				index++;
			}
			if (index < treeList.size()) {
				if (treeList[index] != NULL_TREENODE) {
					tmp->right = new TreeNode(treeList[index]);
					q.push(tmp->right);
				}
				index++;
			}
		}
		return root;
	}
	//层序遍历方式输出树root，无法显示出父子节点的关系，有待改进
	void displayTree(TreeNode* root) {
		queue<TreeNode*> q;
		if (root) {
			q.push(root);
			cout << root->val << endl;
		}
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				TreeNode* tmp = q.front();
				q.pop();
				if (tmp->left) {
					q.push(tmp->left);
					cout << tmp->left->val << " ";
				}
				if (tmp->right) {
					q.push(tmp->right);
					cout << tmp->right->val << " ";
				}
			}
			cout << endl;
		}
		cout << "_____________" << endl;
	}
};

int main() {
	Solution s;
	vector<int> v1 = { 1,2,INT_MIN,3 };
	vector<int> v2 = { 1,INT_MIN,2,INT_MIN,3 };
	TreeNode* t1 = s.initialTree(v1);
	TreeNode* t2 = s.initialTree(v2);
	TreeNode* root = s.mergeTrees(t1, t2);
	s.displayTree(root);

	return 0;
}

